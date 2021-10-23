#include <iostream>
#include <cstdio>
const int mod = 1e9 + 7;
int add(int a, int b) {
	return a + b >= mod ? a + b - mod : a + b;
}
int sub(int a, int b) {
	return a < b ? a - b + mod : a - b;
}
int mul(int a, int b) {
	return 1ll * a * b % mod;
}
const int nn = 505;
int f[nn][nn], g[nn][nn];
int n, k, sum[nn], tot[nn];
char str[nn];
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d %d", &n, &k);
	scanf("%s", str + 1);
	for (int i = 1; i <= n; i++)
		sum[i] = sum[i - 1] + (str[i] == '(' || str[i] == ')');
	for (int len = 1; len < n; len++) {
		for (int l = 1, r = l + len; r <= n; l++, r++) {
			// ( + ) or ( + S + )
			if (str[l] != ')' && str[l] != '*' && str[r] != '(' && str[r] != '*' && r - l - 1 <= k && sum[r - 1] == sum[l]) f[l][r] = g[l][r] = 1;
			// A + B
			for (int s = l; s < r; s++)
				f[l][r] = add(f[l][r], mul(f[l][s], g[s + 1][r]));
			// A + S + B
			tot[l - 1] = 0;
			for (int i = l; i <= r; i++)
				tot[i] = add(tot[i - 1], g[i][r]);
			for (int R = l + 1, L = R; R <= r; R++) {
				if ((str[R] != '*' && str[R] != '?') || R == r) {
					if (L <= R - 1) {
						for (int s = L; s < R; s++) {
							f[l][r] = add(f[l][r], mul(f[l][s - 1], sub(tot[std::min(R, s + k)], tot[s])));
						}
					}
					L = R + 1;
				}
			}
			if (str[l] != ')' && str[l] != '*' && str[r] != '(' && str[r] != '*') {
				// ( + A + )
				f[l][r] = add(f[l][r], f[l + 1][r - 1]);
				g[l][r] = add(g[l][r], f[l + 1][r - 1]);
				// ( + S + A + )
				for (int s = l + 1; s < r - 1 && s - l <= k; s++)
					if (sum[s] == sum[l]) {
						f[l][r] = add(f[l][r], f[s + 1][r - 1]);
						g[l][r] = add(g[l][r], f[s + 1][r - 1]);
					}
				// ( + A + S + )
				for (int s = r - 1; s > l + 1 && r - s <= k; s--)
					if (sum[r - 1] == sum[s - 1]) {
						f[l][r] = add(f[l][r], f[l + 1][s - 1]);
						g[l][r] = add(g[l][r], f[l + 1][s - 1]);
					}
			}
		}
	}
//	for (int i = 1; i <= n; i++)
//		for (int j = 1; j <= n; j++)
//			printf("%d%c", f[i][j], j < n ? ' ' : '\n');
	printf("%d", f[1][n]);
	return 0;
}
