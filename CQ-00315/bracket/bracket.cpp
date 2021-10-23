#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, k, d[505][505], dp[505][505][4];
char a[505];
const int mod = 1e9+7;
bool check(int l, int r)
{
	if (d[l][r]!=-1)
	{
		return d[l][r];
	}
	if (r-l+1>k)
	{
		return d[l][r]=0;
	}
	if (l>r)
	{
		return d[l][r]=1;
	}
	if ((a[l]=='*'||a[l]=='?')&&(a[r]=='*'||a[r]=='?'))
	{
		return d[l][r]=check(l+1, r-1);
	}
	else
	{
		return d[l][r]=0;
	}
}
int dfs(int l, int r, int o)
{
	if (dp[l][r][o]!=-1)
	{
		return dp[l][r][o];
	}
	if (l>=r)
	{
		return dp[l][r][o]=0;
	}
	int ans = 0;
	if (o==0)
	{
		bool flag = ((a[l]=='('||a[l]=='?')&&(a[r]==')'||a[r]=='?'));
		if (flag)
		{
			if (check(l+1, r-1))
			{
				ans++;
			}
			ans+=dfs(l+1, r-1, 0);
			ans%=mod;
			ans+=dfs(l+1, r-1, 1);
			ans%=mod;
			ans+=dfs(l+1, r-1, 2);
			ans%=mod;
		}
		else
		{
			return dp[l][r][o]=0;
		}
		for (int p=l;p<r;p++)
		{
			ans+=((((long long int)dfs(l, p, 3))*dfs(p+1, r, 0))%mod);
			ans%=mod;
			ans+=((((long long int)dfs(l, p, 3))*dfs(p+1, r, 1))%mod);
			ans%=mod;
		}
	}
	else if (o==1)
	{
		for (int p=l;p<r;p++)
		{
			if (check(l, p))
			{
				ans+=dfs(p+1, r, 0);
				ans%=mod;
			}
			else
			{
				break;
			}
		}
	}
	else if (o==2)
	{
		for (int p=r;p>l;p--)
		{
			if (check(p, r))
			{
				ans+=dfs(l, p-1, 0);
				ans%=mod;
			}
			else
			{
				break;
			}
		}
	}
	else if (o==3)
	{
		bool flag = ((a[l]=='('||a[l]=='?')&&(a[r]==')'||a[r]=='?'));
		if (flag)
		{
			if (check(l+1, r-1))
			{
				ans++;
			}
			ans+=dfs(l+1, r-1, 0);
			ans%=mod;
			ans+=dfs(l+1, r-1, 1);
			ans%=mod;
			ans+=dfs(l+1, r-1, 2);
			ans%=mod;
		}
		else
		{
			return dp[l][r][o]=0;
		}
	}
	return dp[l][r][o]=ans;
}
int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	memset(dp, -1, sizeof(dp));
	memset(d, -1, sizeof(d));
	scanf("%d %d\n", &n, &k);
	for (int p=1;p<=n;p++)
	{
		scanf("%c", &a[p]);
	}
	printf("%d", dfs(1, n, 0));
	return 0;
}
