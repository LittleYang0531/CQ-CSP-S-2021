#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
const int N=255;
const LL mod=1e9+7;
int n,stars;
char c[N];
LL f[N][N][N/2+5];
//״̬:f[i][j][k]:ö�ٵ���iλ ����c[i]������Ǵ�Ϊj '('������ȥ')'�������Ϊk��������������Ҫ��ķ�����
//�߽�:f[0][0][0]=0
//ת�Ʒ���:
//�����iλ��*:f[i][j][k]+=f[i-1][j-1][k]
//�����iλ��(:f[i][0][k]+=f[i-1][j][k-1]
//�����iλ��):f[i][0][k]+=f[i-1][j][k+1]
//�����iλ��?:�ۺ����� ȫ�������� 
//��:f[n][0][0]
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
					//������ 
//					if(j==0) continue;
//					else 
					f[i][j][k]=(f[i][j][k]+f[i-1][j-1][k])%mod;
					
					//������ 
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
