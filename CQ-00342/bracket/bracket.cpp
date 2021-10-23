#include<bits/stdc++.h>
using namespace std;

const int mod=1e9+7;
int a[105],n,k,ans,sta[105],las[105];
char s[105];

inline bool check()
{
	int top=0;
	for(int i=1;i<=n;i++)
	{
		if( a[i]==1 ) sta[++top]=i;
		if( a[i]==2 )
			if( !top ) return false;
			else las[i]=sta[top--];
	}
	if( top ) return false;
	int cnt=0;
	if( a[1]==3 || a[n]==3 ) return false;
	for(int i=1;i<=n;i++)
	{
		if( a[i]==1 ) cnt=0;
		if( a[i]==2 )
		{
			cnt=0;
//			if( a[i+1]==3 && a[las[i]-1]==3 ) return false;
		}
		if( a[i]==3 )
		{
			cnt++;
			if( cnt > k ) return false;
		}
	}
	return true;
}

inline void dfs(int stp)
{
	if( stp==n+1 )
	{
//		for(int i=1;i<=n;i++) cout<<a[i]<<" "; cout<<check()<<" "; cout<<endl;
		if( check() ) ans++,ans%=mod;
		return;
	}
	if( a[stp] ) dfs(stp+1);
	else
	{
		for(int i=1;i<=3;i++)
		{
			a[stp]=i;
			dfs(stp+1);
			a[stp]=0;
		}
	}
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	cin>>n>>k;
	cin>>s;
	for(int i=1;i<=n;i++)
	{
		if( s[i-1]=='(' ) a[i]=1;
		else if( s[i-1]==')' ) a[i]=2;
		else if( s[i-1]=='*' ) a[i]=3;
		else a[i]=0;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
