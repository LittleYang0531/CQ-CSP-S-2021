#include<bits/stdc++.h>
using namespace std;
int n,K,dp[505][505][505],dp1[505][505][505],ans;//填到第i位时还剩j个括号有连续k个* 
string s;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>K;
	cin>>s;
	s=' '+s; 
	dp[0][0][0]=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='?'){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=K;k++){
					if(k-1>=0) dp[i][j][k]+=dp[i-1][j][k-1]; //*
					if(j-1>=0){
					//(
						dp[i][j][0]+=dp[i-1][j-1][k];
						if(k!=0) dp1[i][j][0]+=dp[i-1][j-1][k];
						dp1[i][j][0]+=dp1[i-1][j-1][k];
						
					}
					dp[i][j][0]+=dp1[i-1][j+1][k];  //) 
					if(k!=0) dp[i][j][0]+=dp[i-1][j+1][k];
					dp1[i][j][0]+=dp[i-1][j+1][k]+dp1[i-1][j+1][k];
				}
			}
		}
		else if(s[i]=='*'){
			for(int j=0;j<=n;j++){
				for(int k=1;k<=n;k++){
					dp[i][j][k]+=dp[i-1][j][k-1];
				}
			}
		}
		else if(s[i]=='('){
			for(int j=1;j<=n;j++){
				for(int k=0;k<=n;k++){
				//(
					dp[i][j][0]+=dp[i-1][j-1][k];
					if(k!=0) dp1[i][j][0]+=dp[i-1][j-1][k];
					dp1[i][j][0]+=dp1[i-1][j-1][k];
				}
			}
		}
		else if(s[i]==')'){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					dp[i][j][0]+=dp1[i-1][j+1][k];
					if(k!=0) dp[i][j][0]+=dp[i-1][j+1][k];
					dp1[i][j][0]+=dp[i-1][j+1][k]+dp1[i-1][j+1][k];
				}
			}
		}
	}
//	for(int i=0;i<=n;i++){
//		for(int j=0;j<=n;j++){
//			for(int k=0;k<=n;k++){
//				if(dp[i][j][k]){
//					printf("在第%d位剩%d个括号连续%d个*的方案数: %d\n",i,j,k,dp[i][j][k]);
//				}
//				if(dp1[i][j][k]){
//					printf("1在第%d位剩%d个括号连续%d个*的方案数: %d\n",i,j,k,dp1[i][j][k]);
//				}
//			}
//		} 
//		cout<<endl;
//	}
	cout<<dp[n][0][0];
}
