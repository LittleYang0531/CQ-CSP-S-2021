#include <cstdio>
#define LL long long
const int MAXN = 1e2 + 5;
const int MOD = 1e9 + 7;
LL dp[MAXN][MAXN][MAXN];
char s[MAXN];
int n, k;
bool f[MAXN][MAXN];
void Markk(int x, int y) {
	for (int i = x; i <= y; i++)
		for (int j = x; j <= i; j++)
			if (i - j + 1 <= k) f[j][i] = 1;
}
bool Check(int l, int r) {
	return (s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?');
}
void Solve1(int l, int r) {
	int L = l + 1, R = r - 1;
	if (f[L][R]) dp[l][r][1] = (dp[l][r][1] + 1) % MOD;
//	if (l == 1 && r == 7) printf("A %d\n", dp[1][7]);
}
void Solve2(int l, int r) {
//	printf("%d %d\n", l, r);
	for (int L = l + 1; L <= r - 1; L++) {
		for (int R = L + 2; R <= r - 1; R++) {
			if (f[L + 1][R - 1]) dp[l][r][1] = (dp[l][L][0] * dp[R][r][0] % MOD + dp[l][r][1]) % MOD;
		}
	}
	int R = l + 1;
	for (R = l + 1; R <= r - 1; R++) {
//		if (l == 1 && r == 8) printf("QAQ %d %d %d\n", l, R, dp[l][R][1]);
		for (int i = 2; i <= r - l + 1; i++) {
			dp[l][r][i] = (dp[l][r][i] + dp[l][R][1] * dp[R + 1][r][i - 1]) % MOD;
		}
	}
}
void Solve3(int l, int r) {
	for (int L = l + 2; L <= r - 1; L++) {
		if (f[l + 1][L - 1]) dp[l][r][1] = (dp[l][r][1] + dp[L][r - 1][0]) % MOD;
//		printf("%d %d\n", L, r - 1);
	}
	for (int R = l + 1; R <= r - 2; R++) {
		if (f[R + 1][r - 1]) dp[l][r][1] = (dp[l][r][1] + dp[l + 1][R][0]) % MOD;
//		printf("%d %d\n", l + 1, R);
	}
	dp[l][r][1] = (dp[l][r][1] + dp[l + 1][r - 1][0]) % MOD;
//	if (l == 1 && r == 7) printf("C %d\n", dp[1][7]);
//	printf("\n");
}
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d %d", &n, &k);
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++) {
		if (s[i] != '*' && s[i] != '?') continue;
		int j = i;
		for (j = i; j <= n; j++) {
			if (s[j + 1] != '*' && s[j + 1] != '?') break;
		}
		Markk(i, j);
		i = j;
	}
	for (int i = 1; i < n; i++) {
		if (Check(i, i + 1)) dp[i][i + 1][0] = dp[i][i + 1][1] = 1;
	}
	for (int len = 3; len <= n; len++) {
		for (int l = 1; l <= n - len + 1; l++) {
			int r = l + len - 1;
			if (Check(l, r)) Solve1(l, r);
			Solve2(l, r);
			if (Check(l, r)) Solve3(l, r);
			for (int i = 1; i <= r - l + 1; i++) dp[l][r][0] = (dp[l][r][0] + dp[l][r][i]);
		}
	}
	printf("%d", dp[1][n][0]);
	return 0;
}
