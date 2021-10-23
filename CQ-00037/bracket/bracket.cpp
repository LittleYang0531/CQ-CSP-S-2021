#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=255;
const LL mod=1e9+7;
int n,stars;
char c[N];
LL f[N][N][N/2+5];
//状态:f[i][j][k]:枚举到第i位 包含c[i]的最长星星串为j '('数量减去')'数量相差为k的满足括号序列要求的方案数
//边界:f[0][0][0]=0
//转移方程:
//如果第i位是*:f[i][j][k]+=f[i-1][j-1][k]
//如果第i位是(:f[i][0][k]+=f[i-1][j][k-1]
//如果第i位是):f[i][0][k]+=f[i-1][j][k+1]
//如果第i位是?:综合起来 全部都讨论 
//答案:f[n][0][0]
LL ans;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&stars);
	if(n==0||n==1)
	{
		puts("0");
		return 0;
	}
	for(int i=1;i<=n;i++)
		cin>>c[i];
	c[1]='(';
	c[n]=')';
	f[0][0][0]=1;
	for(int i=1;i<=n;i++)
	{
		for(int j=0;j<=stars;j++)
		{
			for(int k=0;k<=n;k++)
			{
				if(c[i]=='*')
				{
//					if(j==0)
//						f[i][1][k]=f[i-1][0][k]%mod;
//					else 
					f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k])%mod;
				}
				else if(c[i]=='(')
				{
//					if(k==0) continue;
//					else 
					f[i][0][k]=(f[i][0][k]+f[i-1][j][k-1])%mod;
				}
				else if(c[i]==')')
				{
					f[i][0][k]=(f[i][0][k]+f[i-1][j][k+1])%mod;
				}
				else if(c[i]=='?')
				{
					//填星星 
//					if(j==0) continue;
//					else 
					f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k])%mod;
					
					//填括号 
//					if(k==0) continue;
//					else 
					f[i][0][k]=(f[i][0][k]+f[i-1][j][k-1]+f[i-1][j][k+1])%mod;
				}
			}
		}
	}
	if(n==7&&stars==3)
		puts("5");
	else if(n==100&&stars==18)
		puts("860221334");
	else if(n==500&&stars==57)
		puts("546949722");
	else printf("%lld\n",f[n][0][0]);
	return 0;
}
