#include<bits/stdc++.h>
using namespace std;
int n,K,mx=1;
long long f[2][510][510][3],lms[2][510],rms[2][510];
const long long MOD=1000000007;
string s;
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>K>>s;
	if (s[0]!='?'&&s[0]!='(')
	{
		cout<<0;
		return 0;
	}
	f[0][1][0][0]=1;
	for (int i=1;i<n;i++)
	{
		int now=i%2,lst=!now;
		for (int j=0;j<=i;j++)
			for (int k=0;k<=K;k++)
				for (int l=0;l<3;l++)
					f[now][j][k][l]=0;
		for (int j=0;j<=i;j++)
		{
			lms[now][j]=0;
			rms[now][j]=0;
		}
		if (s[i]=='('||s[i]=='?')
		{
			for (int j=0;j<=i;j++)
			{
				f[now][j+1][0][0]=f[lst][j][0][0]+f[lst][j][0][1];
				for (int k=1;k<=K;k++)
				{
					f[now][j+1][0][0]+=f[lst][j][k][2];
					lms[now][j+1]+=f[lst][j][k][2];
				}
				lms[now][j+1]%=MOD;
				f[now][j+1][0][0]%=MOD;
			}
		}
		if (s[i]==')'||s[i]=='?')
		{
			for (int j=0;j<i;j++)
			{
				rms[now][j]=lms[lst][j+1];
				f[now][j][0][1]=f[lst][j+1][0][1]+f[lst][j+1][0][0];
				for (int k=1;k<=K;k++)f[now][j][0][1]+=f[lst][j+1][k][2];
				f[now][j][0][1]%=MOD;
			}
		}
		if (s[i]=='*'||s[i]=='?')
		{
			for (int j=0;j<=i;j++)
			{
				for (int k=1;k<=K;k++)
				{
					f[now][j][k][2]=f[lst][j][k-1][2];
					f[now][j][k][2]%=MOD;
				}
				f[now][j][1][2]+=f[lst][j][0][0]+f[lst][j][0][1]-rms[now][j];
				f[now][j][1][2]%=MOD;
			}
		}
	}
	cout<<f[(n-1)%2][0][0][1]%MOD;
}
//CCF Au coach sto sto ZZS orz orz
