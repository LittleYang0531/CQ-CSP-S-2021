#include <cstdio>
#include <iostream>
using namespace std;
#define int long long
const int M = 505;
const int MOD = 1e9+7;
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int n,m,sx[M],pr[M],nx[M];char s[M];
int dp[M][M],s1[M][M],s2[M][M];
void work(int l,int r)
{
	for(int k=l;k<r;k++)
	if(s[k]=='(' || s[k]=='?')
	{
		int fl=0,fr=0;
		if(k==l) fl=1;//special case
		else
		{
			int i=max(l+1,pr[k-1]);
			fl=s1[l][k-1]-s1[l][i-2];
		}
		if(k==r-1) fr=1;
		else
		{
			//all */?
			if(sx[r-1]-sx[k]==r-k-1)
				fr=(r-k-1)<=m;
			//right */?
			int i=max(k+1,pr[r-1]);
			fr=(fr+s1[k+1][r-1]-s1[k+1][i-2])%MOD;
			//left */?
			i=min(r-1,nx[k+1]);
			fr=(fr+s2[k+1][r-1]-s2[i+2][r-1])%MOD;
			fr=(fr-dp[k+1][r-1])%MOD;//we cal it twice
		}
		dp[l][r]=(dp[l][r]+fl*fr)%MOD;
		dp[l][r]=(dp[l][r]+MOD)%MOD;
	}
}
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();m=read();
	scanf("%s",s+1);
	//initalize
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='(' || s[i]==')')
		{
			pr[i]=i+1;nx[i]=i-1;
			continue;
		}
		int j=i,k=i;
		while(j>1 && (s[j-1]=='*' || s[j-1]=='?')) j--;
		while(k<n && (s[k+1]=='*' || s[k+1]=='?')) k++;
		pr[i]=max(i-m+1,j);
		nx[i]=min(i+m-1,k);
		sx[i]=sx[i-1]+(s[i]=='*' || s[i]=='?');
	}
	//dp
	for(int l=n;l>=1;l--)
		for(int r=l;r<=n;r++)
		{
			if(s[r]==')' || s[r]=='?') work(l,r);
			s1[l][r]=(s1[l][r-1]+dp[l][r])%MOD;
			s2[l][r]=(s2[l+1][r]+dp[l][r])%MOD;
		}
	printf("%lld\n",dp[1][n]);
}
