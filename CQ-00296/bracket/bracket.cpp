#include <bits/stdc++.h>

const int p = 1e9 + 7;

int n,t;
int dp[510][510][510];
char S[510];

int main () {
	freopen ("bracket.in","r",stdin);
	freopen ("bracket.out","w",stdout);
	
	scanf ("%d%d",&n,&t);
	scanf ("\n%s",S + 1);
	
	dp[1][1][0] = 1;
	for (int i = 2;i <= n;++ i) {
		for (int j = 0;j <= n;++ j) {
			for (int k = 0;k <= t;++ k) {
				if ((S[i] == '(' || S[i] == '?')) {
					if (j >= 1) dp[i][j][k] += dp[i - 1][j - 1][k];
				}
				if ((S[i] == ')' || S[i] == '?')) {
					if (j < n) dp[i][j][k] += dp[i - 1][j + 1][k];
				}
				if ((S[i] == '*' || S[i] == '?')) {
					if (k >= 1) dp[i][j][k] += dp[i - 1][j][k - 1];
				}
				dp[i][j][k] %= p;
			}
		}
	}
	
	printf ("%d\n",dp[n][0][0]);
	
	return 0;
}
