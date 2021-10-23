#include <bits/stdc++.h>
using namespace std;
const int mod=1000000007;
char s[501];
int ans=0;
char a[501];
int len,n;
int q;
int u;
void check()
{
	q=0;
	if (a[0]=='*' || a[len-1]=='*') return ;
	for (int i=0; i<len; i++)
	{
		if (a[i-1]=='*' && a[i]=='*') u++;
		else if (a[i]=='(')
		{
			q+=1;
			u=0;
		}
		else if (a[i]==')')
		{
			u=0;
			if (q==0)
			{
				return ;
			}
			else
			{
				q--;
				if (a[i-1]=='(' && q) return ;
			}
		}
		if (u>n-1) 
		{
			return ;
		}
		
	}
	if (q) 
	{
		return ;
	}
	ans++;
	ans%=mod;
}
void dfs(int k)
{
	if (k>=len)
	{
		check();
	}
	else
	{
		if (s[k]=='?')
		{
			a[k]='(';
			dfs(k+1);
			a[k]=')';
			dfs(k+1);
			a[k]='*';
			dfs(k+1);
		}
		else
		{
			a[k]=s[k];
			dfs(k+1);
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>len>>n;
	cin>>s;
	for (int i=0; i<len; i++) a[i]=s[i];
	dfs(0);
	printf("%d",ans % mod);
	return 0;
}
