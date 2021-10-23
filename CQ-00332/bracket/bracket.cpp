#include <cstdio>

const int mod = 1e9 + 7;

char str[505];
int dp[505][505], f[505][505], sum[505][505], n, m;
inline void add(int& x, const int y) {
	if ((x += y) >= mod) x -= mod;
	if (x < 0) x += mod;
}

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d", &n, &m);
	char ch = '\0';
	while (ch != '(' && ch != ')' && ch != '*' && ch != '?') ch = getchar();
	str[1] = ch;
	for (int i = 2; i <= n; ++ i) str[i] = getchar();
	for (int i = 1; i < n; ++ i)
		if ((str[i] == '(' || str[i] == '?') && (str[i + 1] == ')' || str[i + 1] == '?'))
			sum[i][i + 1] = dp[i][i + 1] = f[i][i + 1] = 1;
	for (register int r = 2; r <= n; ++ r) {
		for (register int l = r - 2; l; -- l) {
			int& ans = dp[l][r];
			if ((str[l] == '(' || str[l] == '?') && (str[r] == ')' || str[r] == '?')) {
				ans = dp[l + 1][r - 1];
				if (r - l - 1 <= m) {
					bool flag = true;
					for (register int k = l + 1; k < r; ++ k)
						if (str[k] != '*' && str[k] != '?') {
							flag = false; break;
						}
					if (flag) add(ans, 1);
				}
				for (register int k = l + 1; k < r - 2 && k <= l + m && (str[k] == '*' || str[k] == '?'); ++ k)
					add(ans, dp[k + 1][r - 1]);
				for (register int k = r - 1; k > l + 2 && k >= r - m && (str[k] == '*' || str[k] == '?'); -- k)
					add(ans, dp[l + 1][k - 1]);
			}
			f[l][r] = ans;
			for (register int i = l + 1, j = l + 1; i < r - 1; ++ i) {
				if (j <= i) {
					++ j;
					while (j < r && j <= i + m + 1 && (str[j] == '*' || str[j] == '?')) ++ j;
				}
				add(ans, (int)(1LL * dp[l][i] * (sum[i + 2][r] - sum[j + 1][r]) % mod));
				add(ans, (int)(1LL * (f[l][i] * dp[i + 1][r]) % mod + (1LL * dp[l][i] * f[i + 1][r] % mod) - (1LL * f[l][i] * f[i][r + 1]) % mod));
			}
			sum[l][r] = (sum[l + 1][r] + ans) % mod;
		}
	}
	printf("%d", (dp[1][n] + mod) % mod);
	return 0;
}
