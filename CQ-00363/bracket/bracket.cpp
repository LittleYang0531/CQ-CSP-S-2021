#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 505;
const int MOD = 1e9+7;
int n,k,l,r,x,cnt,ord[MAXN];
char s[MAXN];
bool last[MAXN];

template <typename T>
void read(T &s)
{
	s = 0;
	bool w = false;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
		w = true;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		s = (s<<3) + (s<<1) + (ch^48);
		ch = getchar();
	}
	s = w ? -s:s;
	return;
}

inline long long dfs(int now)
{
	if(now > n && l == r)
	{
		return 1;
	}
	else if(now > n)
	{
		return 0;
	}
	long long ans = 0;
	if(s[now] == '(')
	{
		l++;
		if(x > 0)
		{
			last[l] = true;
		}
		x = 0,ans = dfs(now+1),l--;
	}
	else if(s[now] == ')')
	{
//		if(last[l] == true && s[now+1] == '*')
//		return 0;
		x = 0,r++,ans = dfs(now+1),r--;
	}
	else if(s[now] == '*')
	{
		x++,ans = dfs(now+1),x--;
	}
	else
	{
		if(l - r - 1 > ord[now])
			return 0;
		int a = x;
		if(l > r && !(last[l] == true && s[now+1] == '*'))
		{
			x = 0;
			r++;
			s[now] = ')';
			ans = (ans + dfs(now+1)) % MOD;
			s[now] = '?';
			r--;
			x = a;
		}
		if(l - r <= ord[now])
		{
			l++;
			if(x > 0)
			{
				last[l] = true;
			}
			x = 0;
			s[now] = '(';
			ans = (ans + dfs(now+1)) % MOD;
			s[now] = '?';
			l--;
			x = a;
		}
		if(x + 1 <= k)
		{
			x++;
			s[now] = '*';
			ans = (ans + dfs(now+1)) % MOD;
			s[now] = '?';
			x = a;
		}
	}
	return (ans + MOD) % MOD;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	read(n);
	read(k);
	scanf("%s",s+1);
	if(s[n] == '?')
	s[n] = ')';
	else if(s[n] != ')')
	{
		printf("0\n");
		return 0;
	}
	if(s[1] == '?')
	s[1] = '(';
	else if(s[1] != '(')
	{
		printf("0\n");
		return 0;
	}
	for(int i = n;i >= 1;i--)
	{
		if(s[i] == '?')
		ord[i] = ++cnt;
	}
	printf("%d\n",dfs(1) % MOD);
	return 0;
}

