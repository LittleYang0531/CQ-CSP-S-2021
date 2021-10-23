#include<bits/stdc++.h>
#define N 510
using namespace std;
const int mod=1e9+7;
int n,m;
char a[N];
int f[N][N],g[N][N],h[N][N],ff[N][N];
int main()
{
freopen("bracket.in","r",stdin);
freopen("bracket.out","w",stdout);
scanf("%d%d",&n,&m);
scanf("%s",a+1);

for(int k=1;k<=m;k++)
	for(int i=1,j;i<=n-k+1;i++)
	{
		j=i+k-1;
		if(k==1)
		{
			if(a[i]=='*'||a[i]=='?')
			h[i][j]=1;
		}
		else
		{
			if(h[i][i]&&h[i+1][j])
			h[i][j]=1;
		}
	}
for(int i=0;i<=n;i++)h[i+1][i]=1;

for(int k=2;k<=n;k++)
	for(int i=1,j;i<=n-k+1;i++)
	{
		j=i+k-1;
		for(int o=i;o<j;o++)
		(g[i][j]+=1ll*f[i][o]*h[o+1][j]%mod)%=mod;
		for(int o=i;o<j;o++)
		(f[i][j]+=1ll*(f[i][o]+g[i][o])%mod*ff[o+1][j]%mod)%=mod;
		if((a[i]!=')'&&a[i]!='*')&&(a[j]!='('&&a[j]!='*'))
		{
			(ff[i][j]+=f[i+1][j-1]+g[i+1][j-1]+h[i+1][j-1])%=mod;
			for(int o=i+1;o<j-1;o++)
			(ff[i][j]+=1ll*h[i+1][o]*f[o+1][j-1]%mod)%=mod;
			(f[i][j]+=ff[i][j])%=mod;
		}
	}
printf("%d",f[1][n]);


return 0;
}
