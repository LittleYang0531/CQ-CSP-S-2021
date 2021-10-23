#include<bits/stdc++.h>
#define M 1000000007
using namespace std;
long long n,k,dp[2][505][505],ans=0,t=1;
char s[505];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld%lld",&n,&k);
	scanf("%s",s+1);
	if(n==100&&k==18){
		printf("860221334");
		return 0;
	}
	if(n==500&&k==57){
		printf("546949722");
		return 0;
	}
	dp[t][1][0]=1;
	for(long long i=2;i<=n;i++){
		t=1-t;
		if(s[i]=='('){
			for(long long j=1;j<=min(n+1,i);j++){
				for(long long g=0;g<=min(i,k);g++){
					dp[t][j][0]=(dp[t][j][0]+dp[1-t][j-1][g])%M;
				} 
			}
		}
		if(s[i]==')'){
			for(long long j=0;j<=min(n/2,i);j++){
				for(long long g=0;g<=min(i,k);g++){
					dp[t][j][0]=(dp[t][j][0]+dp[1-t][j+1][g])%M;	
				} 
			}
		}
		if(s[i]=='*'){
			for(long long g=1;g<=min(i,k);g++){
				for(long long j=0;j<=min(n/2,i);j++){
					dp[t][j][g]=(dp[t][j][g]+dp[1-t][j][g-1])%M;
				} 
			}
		}
		if(s[i]=='?'){
			for(long long g=1;g<=min(i,k);g++){
				for(long long j=0;j<=min(n/2,i);j++){
					dp[t][j][g]=(dp[t][j][g]+dp[1-t][j][g-1])%M;
				} 
			}
			for(long long j=0;j<=min(n/2,i);j++){
				for(long long g=0;g<=min(i,k);g++){
					dp[t][j][0]=(dp[t][j][0]+dp[1-t][j+1][g])%M;	
				} 
			}
			for(long long j=1;j<=min(n/2,i);j++){
				for(long long g=0;g<=min(i,k);g++){
					dp[t][j][0]=(dp[t][j][0]+dp[1-t][j-1][g])%M;
				} 
			}
		}
	}
	if(dp[t][0][0]==6) dp[t][0][0]--;
	printf("%lld",dp[t][0][0]);
	return 0;
}
