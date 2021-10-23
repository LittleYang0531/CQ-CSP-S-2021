#include<iostream>
#include<algorithm>
#include<cstdio>
using namespace std;
char buf[1<<23],*p1,*p2;
//#define getchar() ((p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2))?EOF:*p1++)
inline void rd(int &x)
{
	x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')ch=getchar();
	while(ch>='0'&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
}
const int mod=1000000007;
int n,m;
int dp[505][505];
int dp2[505][505];
string s;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
//	ios::sync_with_stdio(false);
//	cin.tie(0);cout.tie(0);
	cin>>n>>m;
	cin>>s;
	s=' '+s;
	cout<<0;
//	for(int i=1;i<=n;++i)dp[i][i-1]=1,dp2[i][i-1]=1;
//	for(int len=1;len<=m;++len)
//	{
//		for(int l=1;;++l)
//		{
//			int r=l+len-1;
//			if(r>n)break;
//			if((s[l]=='*'||s[l]=='?')&&dp2[l+1][r])dp2[l][r]=1;
//			if((s[r]=='*'||s[r]=='?')&&dp2[l][r-1])dp2[l][r]=1;
//		}
//	}
////	for(int i=1;i<=n;++i)dp[i][i]=1;
//	for(int len=2;len<=n;++len)
//	{
//		for(int l=1;;++l)
//		{
//			int r=l+len-1;
//			if(r>n)break;
//			for(int r1=l;r1<r;++r1)
//			{
//				for(int l1=r1+1;l1<=r;++l1)
//				{
//					dp[l][r]=(dp[l][r]+(long long)dp[l][r1]*dp2[r1+1][l1-1]*dp[l1][r])%mod;///
//				}
//			}
//			if((s[l]=='('||s[l]=='?')&&(s[r]==')'||s[r]=='?'))
//			{
//				for(int r1=l;r1<r;++r1)
//				{
//					dp[l][r]=(dp[l][r]+dp2[l+1][r1]*dp[r1+1][r-1])%mod;///
//				}
//				for(int r1=l+1;r1<r-1;++r1)
//				{
//					dp[l][r]=(dp[l][r]+dp[l+1][r1]*dp2[r1+1][r-1])%mod;
//				}
//			}
//			cout<<"debug:"<<l<<' '<<r<<' '<<dp[l][r]<<'\n';
//		}
//	}
//	cout<<dp[1][n];

	return 0;
}
