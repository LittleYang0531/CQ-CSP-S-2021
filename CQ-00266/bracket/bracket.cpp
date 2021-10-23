#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#define ll long long
using namespace std;
const int N=510;
const int mod=1e9+7;
int n,k;
ll f[N][N][4],g[N][N];
char s[N];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout); 
	scanf("%d%d",&n,&k);
	cin>>s+1;
	for(int len=1;len<=n;len++)
	{
		for(int i=1;i+len-1<=n;i++)
		{
			int j=i+len-1;
			if((s[i]=='('||s[i]=='?')&&(s[j]==')'||s[j]=='?'))
			{
				g[i][j]=f[i][j][0]=(f[i+1][j-1][0]+f[i+1][j-1][1]+f[i+1][j-1][2]+f[i+1][j-1][3])%mod;
				if(len==2)g[i][j]=f[i][j][0]=1;
				
				for(int k=i+1;k<j-1;k++)f[i][j][0]=(f[i][j][0]+g[i][k]*f[k+1][j][2]%mod+g[i][k]*f[k+1][j][0])%mod;
			}
			f[i][j][1]=(j-i+1)<=k;
			for(int p=i;p<=j;p++)if(s[p]!='?'&&s[p]!='*')f[i][j][1]=0;
			for(int p=i;p<=j&&p-i+1<=k;p++)f[i][j][2]=(f[i][j][2]+f[i][p][1]*f[p+1][j][0]%mod)%mod;
			for(int p=j;p>=i&&j-p+1<=k;p--)f[i][j][3]=(f[i][j][3]+f[i][p-1][0]*f[p][j][1]%mod)%mod;
		}
	}
	printf("%lld",f[1][n][0]%mod);
	return 0;
}

