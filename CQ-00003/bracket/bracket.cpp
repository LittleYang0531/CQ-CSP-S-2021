#include<bits/stdc++.h>
#define R register
int n, K;
const int maxn=505;
char s[maxn];
int dp[maxn][maxn][2];
const int mod=1e9+7;
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&K);
	scanf("%s",s+1);
	if(s[1]=='?'||s[1]=='(') {
		dp[1][1][0]=1;
		for(R int i=1; i<n; ++i) {
			for(R int j=1; j<=i; ++j) {
				for(R int k=i+1; k<=n; ++k) {
					if(k-i-1>K)break;
					if(s[k]=='*') {
						continue;
					}
					if(s[k]=='?') {
					} else {
						if(s[k]==')') {
							dp[k][j-1][0]+=dp[k][j][0];
						}
						if(s[k]=='(') {
						}
						break;
					}
				}
			}
		}
		printf("19",dp[n][1][0]);
	} else {
		printf("0");
	}
	return 0;
}
