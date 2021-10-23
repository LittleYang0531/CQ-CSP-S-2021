#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long n,k,ans,dp[505][505][505],ans;
char a[505];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(long long i=1; i<=n; ++i)  cin>>a[i];
	hanshu(1,0,0,0);
	dp[0][0][0]=1;
	for(long long i=1; i<=n; ++i)
	{
		if(a[i]=='*') for(int q=1; q<min(i,k); ++q) for(int j=0; j<=i; ++j) dp[q][j][i]=(dp[q][j][i]+dp[q-1][j][i-1])%mod;
		else if(a[i]=='(') for(int q=0; q<=min(i,k); ++q) for(int j=1; j<=i; ++j) dp[0][j][i]=(dp[0][j][i]+dp[q][j-1][i-1])%mod;
		else if(a[i]==')') for(int q=0; q<=min(i,k); ++q) for(int j=0; j<=i; ++j) dp[0][j][i]=(dp[0][j][i]+dp[q][j+1][i-1])%mod;
		else if(a[i]=='?')
		{
			for(int q=0; q<=min(i,k); ++q) for(int j=0; j<=i; ++j) dp[0][j][i]=(dp[0][j][i]+dp[q][j+1][i-1])%mod;
			for(int q=0; q<=min(i,k); ++q) for(int j=1; j<=i; ++j) dp[0][j][i]=(dp[0][j][i]+dp[q][j-1][i-1])%mod;
			for(int q=1; q<=min(i,k); ++q) for(int j=0; j<=i; ++j) dp[q][j][i]=(dp[q][j][i]+dp[q-1][j][i-1])%mod;
		}
	}
	cout<<dp[0][0][n]%mod;
	cout<<ans;
	return 0;
}
