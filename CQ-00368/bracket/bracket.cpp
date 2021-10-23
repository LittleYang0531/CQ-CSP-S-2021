#include <bits/stdc++.h>

using namespace std;

const int mod = 1e9 + 7;

char ch[505], ans[505];
bool con[505], mk[505];
int sum[505], suml[505], sumr[505];
int n, k, res;

bool check()
{
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == '*')
		{   
		    bool flg = 0;
		    for (int j = i + 1; j <= n; j++) if (ans[j] == ')') {flg = 1; break;}
			if (!flg) return 0;
			bool flg1 = 0, flg2 = 0;
			for (int j = i - 1; j >= 1; j--)
			{
				if (ans[j] == '*') continue;
				flg1 = (ans[j] == ')' ? 1 : 0);
				break; 
			}
			if (!flg1) continue;
			for (int j = i + 1; j <= n; j++)
			{
				if (ans[j] == '*') continue;
				flg2 = (ans[j] == '(' ? 1 : 0);
				break;
			}
            con[i] = flg2;			
		}
	}
	for (int i = 1; i <= n; i++)
	{
		if (ans[i] == '*')
		{
			if (ans[i - 1] == '*') continue;
			bool flg = 0;
			for (int j = i + 1; j <= n; j++) if (ans[j] == ')') {flg = 1; break;}
			if (!flg) return 0;
		}
		if (ans[i] == '(') 
		{
			int r;
			for (r = i + 1; r <= n; r++) if (ans[r] == ')') break;
			if ((ans[i - 1] == '*' && !con[i - 1]) && (ans[r + 1] == '*' && !con[r + 1])) return 0;
		}
	} return 1;
}

void dfs(int now, int l, int r, int S)
{
	if ((S && !l) || r > l || S > k || r + sum[now] + sumr[now] < l + suml[now]) return;
	if (now == n + 1)
	{
		if (l ^ r) return;
		if (check()) ++res; 
		res %= mod;
		return;
	}
	if (ch[now] == '?')
	{
		ans[now] = '(', dfs(now + 1, l + 1, r, 0);
		ans[now] = ')', dfs(now + 1, l, r + 1, 0);
		ans[now] = '*', dfs(now + 1, l, r, S + 1);
	}
	else
	{
		if (ch[now] == '(') ans[now] = '(', dfs(now + 1, l + 1, r, 0);
		if (ch[now] == ')') ans[now] = ')', dfs(now + 1, l, r + 1, 0);
		if (ch[now] == '*') ans[now] = '*', dfs(now + 1, l, r, S + 1);
	}
}

int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d", &n, &k);
	ans[n + 1] = 0;
	scanf("%s", ch + 1);
	for (int i = n; i >= 1; i--) 
	{
		sum[i] = sum[i + 1];
		suml[i] = suml[i + 1];
		sumr[i] = sumr[i + 1];
		if (ch[i] == '?') ++sum[i];
		if (ch[i] == '(') ++suml[i];
		if (ch[i] == ')') ++sumr[i];
	} dfs(1, 0, 0, 0);
	printf("%d\n", res);
}
