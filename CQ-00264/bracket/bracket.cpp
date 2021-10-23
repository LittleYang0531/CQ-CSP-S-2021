#include <cstdio>
const int MAXN = 505, mod = 1e9 + 7;
int n, K, dp[MAXN][MAXN], dp2[MAXN][MAXN];
char a[MAXN];
bool f[MAXN][MAXN];
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d %d %s", &n, &K, a + 1), f[n + 1][n] = true, dp[n + 1][n] = 1;
	for(int i = 1; i <= n; i++) {
		f[i][i - 1] = true, dp[i][i - 1] = 1;
		for(int j = i; j < i + K; j++) {
			if(a[j] == '(' || a[j] == ')') break;
			f[i][j] = true;
		}
	}
	for(int i = 1; i < n; i++) {
		for(int j = 1; i + j <= n; j++) {
			if((a[j] == '(' || a[j] == '?') && (a[i + j] == ')' || a[i + j] == '?')) {
				dp[j][i + j] = f[j + 1][i + j - 1];
				for(int k = j + 1; k <= j + K + 1 && k < i + j; k++) {
					if(f[j + 1][k - 1])
//						printf("(%d %d)%d", k, i + j - 1, dp[j][i + j]),
						dp[j][i + j] = (dp[j][i + j] + dp[k][i + j - 1]) % mod;
					else break;
				}
				for(int k = i + j - 2; k >= i + j - K - 1 && k > j; k--) {
					if(f[k + 1][i + j - 1])
//						printf("(%d %d)%d", j + 1, k, dp[j][i + j]),
						dp[j][i + j] = (dp[j][i + j] + dp[j + 1][k]) % mod;
					else break;
				}
				for(int k = j + 1; k < i + j; k++) {
					for(int l = 1; l <= K + 1 && k + l < i + j; l++)
						if(f[k + 1][k + l - 1])
//							printf("(%d %d %d %d)%d", j, k, k + l, i + j, dp[j][i + j]),
							dp[j][i + j] = (dp[j][i + j] + (long long)dp[j][k] * dp[k + l][i + j] % mod) % mod;
						else break;
				}
			}
//			printf("%d %d %d\n", j, i + j, dp[j][i + j]);
		}
	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= i; j++) {
//			for(int k = 1; k <= n; k++) 
//		}
//	}
//	for(int i = 1; i <= n; i++) {
//		for(int j = 1; j <= n; j++) printf("%d ", dp[i][j]);
//		printf("\n");
//	}
	printf("%d", dp[1][n]);
	return 0;
}
