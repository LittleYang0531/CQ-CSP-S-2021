#include<bits/stdc++.h>
using namespace std;
int n,k,f[501][501],g[501][501],h[501][501];
bool c[501][501];
char s[501];
const int mod=1e9+7;
inline bool check(int i,char c)
{
	return s[i]=='?'||s[i]==c;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>k;
	cin>>(s+1);
	for(int i=1;i<n;++i)
		if(check(i,'(')&&check(i+1,')'))
		{
			f[i][i+1]=1;
			for(int j=i+2;j<=min(n,i+1+k);++j)
			{
				if(!check(j,'*'))
					break;
				++g[i][j];
			}
			for(int j=i-1;j>=max(1,i-k);--j)
			{
				if(!check(j,'*'))
					break;
				++h[j][i+1];
			}
		}
	for(int i=1;i<=n;++i)
		for(int j=i;j<=min(i+k-1,n);++j)
		{
			if(!check(j,'*'))
				break;
			c[i][j]=1;
		}
	for(int len=3;len<=n;++len)
		for(int i=1,j=len;j<=n;++i,++j)
			if(check(i,'(')&&check(j,')'))
			{
				f[i][j]=(f[i][j]+f[i+1][j-1]+c[i+1][j-1])%mod;
				f[i][j]=(f[i][j]+g[i+1][j-1])%mod;
				f[i][j]=(f[i][j]+h[i+1][j-1])%mod;
				for(int u=i+1;u<j-1;++u)
				{
					if(check(u,')'))
					{
						if(i+1==u)
							f[i][j]=(f[i][j]+(f[u+1][j]+h[u+1][j])%mod)%mod;
						else
						{
							f[i][j]=(f[i][j]+1ll*f[i+1][u-1]*(f[u+1][j]+h[u+1][j])%mod)%mod;
							f[i][j]=(f[i][j]+1ll*c[i+1][u-1]*(f[u+1][j]+h[u+1][j])%mod)%mod;
							f[i][j]=(f[i][j]+1ll*g[i+1][u-1]*(f[u+1][j]+h[u+1][j])%mod)%mod;
							f[i][j]=(f[i][j]+1ll*h[i+1][u-1]*(f[u+1][j]+h[u+1][j])%mod)%mod;
						}
					}
				}
				for(int u=j+1;u<=min(n,j+k);++u)
				{
					if(!check(u,'*'))
						break;
					g[i][u]=(g[i][u]+f[i][j])%mod;
				}
				for(int u=i-1;u>=max(1,i-k);--u)
				{
					if(!check(u,'*'))
						break;
					h[u][j]=(h[u][j]+f[i][j])%mod;
				}
			}
	cout<<f[1][n]<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
