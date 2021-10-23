#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,m;
int f[505][505][2][2],g[505][505],w[505][505];
char s[505];
void add(int &x,int k){x=(x+k)%mod;}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d %s",&n,&m,s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='*'||s[i]=='?')f[i][i][1][1]=1;
		f[i+1][i][0][0]=1;
	}
	for(int len=2;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			if((s[l]=='('||s[l]=='?')&&(s[r]==')'||s[r]=='?'))
			{
				add(f[l][r][0][0],f[l+1][r-1][0][0]);
				add(f[l][r][0][0],f[l+1][r-1][1][1]);
				add(f[l][r][0][0],f[l+1][r-1][0][1]);
				add(f[l][r][0][0],f[l+1][r-1][1][0]);
			}
			w[l][r]=f[l][r][0][0];
			for(int k=l;k<r;k++)
			{
				if(f[k+1][r][1][1])add(f[l][r][0][1],f[l][k][0][0]);
				if(f[l][k][1][1])add(f[l][r][1][0],f[k+1][r][0][0]);
				if(f[l][k][1][1]&&f[k+1][r][1][1]&&(r-l+1)<=m)f[l][r][1][1]=1;
				add(f[l][r][0][0],1ll*g[l][k]*w[k+1][r]%mod);
			}
			g[l][r]=f[l][r][0][0];
			for(int k=l;k<r;k++)add(f[l][r][0][0],1ll*f[l][k][0][1]*g[k+1][r]%mod);
		}
	}
	printf("%d",f[1][n][0][0]);
	return 0;
}
