#include <cstdio>
const int p = 1e9 + 7;
int n, k, ans, dp[502][502][502];
char s[502];
int check() {
	int kh = 0, xh = 0, flag = 1;
	for(int i = 1; i <= n; ++i) {
		if(s[i] == '(') ++kh, xh = 0;
		if(s[i] == ')') --kh, xh = 0;
		if(s[i] == '*') ++xh;
		if(kh < 0 || xh > k) return 0;
		if((s[i] == '*' && (s[i - 1] == '(' || s[i - 1] == ')')) || ((s[i] == '(' || s[i] == ')') && s[i - 1] == '*')) ++flag;
	}
	if(kh) return 0;
	if(flag & 1) {
//		puts(s + 1);
		return 1;
	}
	return flag & 1;
}
int dfs(int pos, int x, int v) {
	if(pos == n + 1) return dp[pos][x][v] = check();
	if(s[pos] == '(') ++x, v = 0;
	if(s[pos] == ')') --x, v = 0;
	if(s[pos] == '*') ++v;
	if(n - pos < x - 1 || v > k || x < 0) return 0;
//	printf("%d,%d,%d:%s\n", pos, x, v, s + 1);
	if(s[pos] == '?') {
		int ret = 0;
		if(n - pos > x) {
			s[pos] = '(';
			ret = (ret + dfs(pos + 1, x + 1, 0)) % p;
		}
		if(x) {
			s[pos] = ')';
			ret = (ret + dfs(pos + 1, x - 1, 0)) % p;
		}
		if(v < k) {
			s[pos] = '*';
			ret = (ret + dfs(pos + 1, x, v + 1)) % p;
		}
		s[pos] = '?';
		return dp[pos][x][v] = ret;
	}
	return dp[pos][x][v] = dfs(pos + 1, x, v);
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d%s", &n, &k, s + 1);
//	dp[0][0][0] = 1;
//	for(int i = 1; i <= n; ++i)
//		if(s[i] == '?') {
//			for(int j = 0; j <= n; ++j)
//				for(int l = 0; l <= k; ++l) {
//					if(j < n) dp[i][j + 1][0][0] = (dp[i][j + 1][0][0] + (dp[i - 1][j][l][0] + dp[i - 1][j][l][1]) % p) % p, dp[i][j + 1][0][1] = (dp[i][j + 1][0][1] + (dp[i - 1][j][l][0] + dp[i - 1][j][l][1]) % p) % p;//(
//					if(j > 0) dp[i][j - 1][0][0] = (dp[i][j - 1][0][0] + (dp[i - 1][j][l][0] + dp[i - 1][j][l][1]) % p) % p;//)
//					if(l < k) dp[i][j][l + 1][0] = (dp[i][j][l + 1][0] + dp[i - 1][j][l][1]) % p;//*
//				}
//		}
//		else {
//			if(s[i] == '(') for(int j = 0; j < n; ++j) for(int l = 0; l <= k; ++l) dp[i][j + 1][0] += dp[i - 1][j][l];
//			else if(s[i] == ')') for(int j = 1; j <= n; ++j) for(int l = 0; l <= k; ++l) dp[i][j - 1][0] += dp[i - 1][j][l];
//			else if(s[i] == '*') for(int j = 0; j <= n; ++j) for(int l = 0; l < k; ++l) dp[i][j][l + 1] += dp[i - 1][j][l];
//		}
//	for(int i = 1; i <= n; ++i)
//		for(int j = 0; j <= n; ++j)
//			for(int l = 0; l <= k; ++l)
//				if(dp[i][j][l] && n - i >= j) printf("%d,%d,%d:%d\n", i, j, l, dp[i][j][l]);
//	for(int i = 0; i <= k; ++i) ans = (ans + dp[n][0][k]) % p;
	printf("%d", dfs(1, 0, 0));
	return 0;
}
