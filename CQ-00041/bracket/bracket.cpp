#include<bits/stdc++.h>
using namespace std;
long long n,m,dp[505][505],l[505][505];
char s[505];
long long mod=1000000007;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld%lld\n",&n,&m);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		for(int j=i-1;j>=1;j--){
			dp[i][j]=1;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n&&j-i+1<=m;j++)
			if(s[j]=='*'||s[j]=='?') l[i][j]=1;
			else break;
	}
	for(int l1=2;l1<=n;l1++)
		for(int i=1;l1+i-1<=n;i++){
			int j=l1+i-1;
			if((s[i]=='('||s[i]=='?')&&(s[j]=='?'||s[j]==')')){
				if(l[i+1][j-1]==1) dp[i][j]+=1;
				dp[i][j]+=dp[i+1][j-1];
				dp[i][j]%=mod;
				for(int k=i+1;k+1<=j-1;k++){
					if((l[i+1][k]==1&&dp[k+1][j-1]>=1)||(dp[i+1][k]>=1&&l[k+1][j-1]==1)){
						dp[i][j]+=dp[i+1][k]+dp[k+1][j-1];
					}
					if(dp[i][k]>=1&&dp[k+1][j]>=1)
						dp[i][j]+=dp[i][k]*dp[k+1][j]; 
					dp[i][j]%=mod;
				}
				for(int x=i+1;x<=j-1;x++){
					for(int y=x;y<=j-1;y++)
					if(l[x][y]==1&&dp[i][x-1]>=1&&dp[y+1][j]>=1) dp[i][j]+=dp[i][x-1]*dp[y+1][j];
					dp[i][j]%=mod;
				}
			}
			dp[i][j]%=mod;
		}
	printf("%lld",dp[1][n]);
	return 0;
}
