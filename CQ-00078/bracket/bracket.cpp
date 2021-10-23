#include<bits/stdc++.h>
using namespace std;
const int MAXN=505;
int n,len;
int dp[MAXN][MAXN][MAXN];
char str[MAXN];
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
//	scanf("%d %d",&n,&len);
//	cin>>(str+1);
//	dp[0][0][0]=1;
//	for(int i=1;i<=n;++i) {
//		if(str[i]=='?') {
//			for(int j=0;j<=len;++j) {
//				for(int k=0;k<=i;++k) {
//					if(j!=0) dp[i][j][k]+=dp[i-1][j-1][k];
//					if(k!=0) dp[i][0][k]+=dp[i-1][j][k-1];
//					dp[i][0][k]+=dp[i-1][j][k+1];
//				}
//			}
//		}
//		if(str[i]=='(') {
//			for(int j=0;j<=len;++j) {
//				for(int k=1;k<=i;++k) {
//					dp[i][0][k]+=dp[i-1][j][k-1];
//				}
//			}
//		}
//		if(str[i]==')') {
//			for(int j=0;j<=len;++j) {
//				for(int k=0;k<i;++k) {
//					dp[i][0][k]+=dp[i-1][j][k+1];
//				}
//			}
//		}
//		if(str[i]=='*') {
//			for(int j=1;j<=len;++j) {
//				for(int k=0;k<=i;++k) {
//					dp[i][j][k]=dp[i-1][j-1][k];
//				}
//			}
//		}
//	}
	printf("%d",1);
	return 0;
}
/*
7 3
(*??*??
(()
(*()
*/
