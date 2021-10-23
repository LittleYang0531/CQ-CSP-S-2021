#include <bits/stdc++.h>
using namespace std;
#define R register
typedef long long ll;
const int MAXN = 505;
const ll Mod = 1e9 + 7;
ll dp[505][255][255][2];
int n,k;
char s[MAXN];
ll ans = 0;
stack <int> S;
void dfs(int x,int q,int h,int now)
{
	if(now > k || q < h)return;
	if(x > n)
	{
		while(!S.empty())S.pop();
		for(R int i = 1; i <= strlen(s + 1); i++)
			if(s[i] == '*' && (i == 1 || i == strlen(s + 1)))return;
		for(R int i = 1; i <= strlen(s + 1); i++)
		{
			if(s[i] != '*')
			{
				if(s[i] == ')' && !S.empty())
				{
					int j = S.top();
					if(s[j - 1] == '*' && s[i + 1] == '*')return;
					S.pop();
				}
				else S.push(i);
			}
		}
		int len = S.size();
		if(len != 0)return;
		ans++;
		if(ans >= Mod)ans -= Mod;
		return;
	}
	if(s[x] == ')')dfs(x + 1,q,h + 1,0);
	else if(s[x] == '(')dfs(x + 1,q + 1,h,0);
	else if(s[x] == '*')dfs(x + 1,q,h,now + 1);
	else
	{
		s[x] = ')';
		dfs(x + 1,q,h + 1,0);
		s[x] = '(';
		dfs(x + 1,q + 1,h,0);
		s[x] = '*';
		dfs(x + 1,q,h,now + 1);
		s[x] = '?';
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
	if(n > 15)
	{
		dp[0][0][0][0] = dp[0][0][0][1] = 1;
		for(R int i = 1; i <= n; i++)
		{
			if(s[i] == '?')
			{
				for(R int j = 0; j <= (n + 1) / 2; j++)
				{
					for(R int k = 0; k <= j; k++)
					{
						for(R int s = 0; s <= k; s++)
							if(i - 1 - s > 0 && j - 1 >= k)dp[i][j][k][0] = (dp[i][j][k][0] + (dp[i - 1 - s][j - 1][k][1] + dp[i - 1][j - 1][k][0] % Mod)) % Mod;
						for(R int s = 0; s <= k; s++)
							if(i - 1 - s > 0 && j >= k - 1)dp[i][j][k][1] = (dp[i][j][k][1] + (dp[i - 1 - s][j][k - 1][0] + dp[i - 1][j][k - 1][1] % Mod)) % Mod;
					}
				}
			}
		}
		for(R int i = 0; i <= (n + 1) / 2; i++)
			ans = (ans + dp[n][i][i][1]) % Mod;
		printf("%lld\n", ans);
	}
	else
	{
		dfs(1,0,0,0);
		printf("%lld\n", ans);
	}
	return 0;
}
