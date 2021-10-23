#include<bits/stdc++.h>
#define N 505
using namespace std;
const int mod=1e9+7;
const unsigned long long inf=15e18;
int n,k,f[N][N],g[N][N],h[N][N],bl[N][N];
int dp[N][N],F[N][N];
//Dp:all
//F:(A)(A)...(A)(A)
//f:(A)
//g:SA
//h:AS
char s[N],S[N];
int Mod(int x) {return x<mod?x:x-mod;}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,s+1);
	for(int i=1; i<=n; ++i)bl[i][i]=(s[i]=='*'||s[i]=='?');
	for(int i=1; i<=n; ++i)
		for(int j=i+1; j<i+k; ++j)bl[i][j]=bl[i][j-1]&&(s[j]=='*'||s[j]=='?');
	for(int i=n; i>=1; --i)
		for(int j=i; j<=n; ++j) {
			if(i==j)continue;
			if(j==i+1) {
				f[i][j]=(s[i]=='('||s[i]=='?')&&(s[j]==')'||s[j]=='?');//()
				dp[i][j]=F[i][j]=f[i][j];
				continue;
			}
			if((s[i]=='('||s[i]=='?')&&(s[j]==')'||s[j]=='?')) {
				f[i][j]=Mod(f[i][j]+bl[i+1][j-1]);//(S)
				f[i][j]=Mod(f[i][j]+dp[i+1][j-1]);//(A)
				f[i][j]=Mod(f[i][j]+g[i+1][j-1]);//(SA)
				f[i][j]=Mod(f[i][j]+h[i+1][j-1]);//(AS)
			}
			unsigned long long tmp=f[i][j];
			for(int l=i; l<j; ++l) {
				tmp+=1ull*f[i][l]*F[l+1][j];//AB
				if(tmp>=inf)tmp%=mod;
			}
			F[i][j]=tmp%mod;
			for(int l=i; l<j; ++l) {
				tmp+=1ull*F[i][l]*g[l+1][j];//ASB
				if(tmp>=inf)tmp%=mod;
			}
			dp[i][j]=tmp%mod;
			for(int l=i; l<=j; ++l)
				if(bl[i][l])g[i][j]=Mod(g[i][j]+dp[l+1][j]);//SA
				else break;
			for(int l=j; l>=i; --l)
				if(bl[l][j])h[i][j]=Mod(h[i][j]+dp[i][l-1]);//AS
				else break;
		}
	cout<<dp[1][n]<"\n";
	return 0;
}
