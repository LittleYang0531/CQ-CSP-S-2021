#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 500
#define INF 1000000007

long long dp[MAXN + 5][MAXN + 5];
long long dp2[MAXN + 5][MAXN + 5];
int snext[MAXN + 5];
char c[MAXN + 5];
long long su[MAXN + 5];

int main () {
	freopen ("bracket.in", "r", stdin);
	freopen ("bracket.out", "w", stdout);
	
	int n, m;
	
	scanf ("%d %d", &n, &m);
	scanf ("%s", c + 1);
	for (int i = n, h = n + 1; i >= 1; i --) {
		snext[i] = h;
		if (c[i] == '(' || c[i] == ')') {
			h = i;
		}
	}
	for (int i = 2; i <= n; i ++) {
		for (int j = 1; j <= n - i + 1; j ++) {
			int l = j, r = j + i - 1;
			
			if ((c[l] == '(' || c[l] == '?') && (c[r] == ')' || c[r] == '?')) {
				if (r - l - 1 <= m) {
					bool bl = 1;
					
					for (int k = l + 1; k < r; k ++) {
						if (c[k] == '(' || c[k] == ')') {
							bl = 0;
							
							break;
						}
					}
					if (bl) {
						dp[l][r] ++;
					}
				}
				dp[l][r] += dp[l + 1][r - 1];
				dp[l][r] %= INF;
				for (int k = 1; k <= m && k < r - l - 1; k ++) {
					if (c[l + k] == '(' || c[l + k] == ')') {
						break;
					}
					dp[l][r] += dp[l + k + 1][r - 1];
					dp[l][r] %= INF;
				}
				for (int k = 1; k <= m && k < r - l - 1; k ++) {
					if (c[r - k] == '(' || c[r - k] == ')') {
						break;
					}
					dp[l][r] += dp[l + 1][r - k - 1];
					dp[l][r] %= INF;
				}
			}
			dp2[l][r] = dp[l][r];
			su[l] = 0;
			for (int i = l + 1; i <= r; i ++) {
				su[i] = su[i - 1] + dp[i][r];
				su[i] %= INF;
			}
			for (int i = l; i <= r; i ++) {
				dp[l][r] += dp2[l][i] * (((su[min (min (snext[i], i + m + 1), r)] - su[i]) % INF + INF) % INF) % INF;
				dp[l][r] %= INF;
			}
		}
	}
	printf ("%lld", dp[1][n]);
	
	return 0;
}
