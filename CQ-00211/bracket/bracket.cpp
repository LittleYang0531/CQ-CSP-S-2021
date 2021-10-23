#include <bits/stdc++.h>

#define check(x, ch) (s[x] == ch || s[x] == '?')

typedef long long ll;

const int N = 500;
const int P = int(1E9) + 7;

int norm(const int &x) {return x >= P ? x - P : x;}
int reduce(const int &x) {return x < 0 ? x + P : x;}
void add(int &x, const int &y) {if ((x += y) >= P) x -= P;}
void sub(int &x, const int &y) {if ((x -= y) < 0) x += P;}

int f[N + 5][N + 5], g[N + 5][N + 5], sf[N + 5][N + 5];

char s[N + 5]; int l[N + 5], r[N + 5], n, k;
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	
//	std::cerr << clock() << "\n";
	
	scanf("%d%d%s", &n, &k, s + 1);
	for (int i = n; i >= 1; i--)
		if (check(i, '*')) l[i] = std::min(l[i + 1] + 1, k);
	for (int i = 1; i <= n; i++)
		if (check(i, '*')) r[i] = std::min(r[i - 1] + 1, k);
	
	for (int i = n; i >= 1; i--) for (int j = i + 1; j <= n; j++) {
		if (check(i, '(') && check(j, ')')) {
			if (l[i + 1] >= j - i - 1) add(g[i][j], 1);
			for (int p = i + 1; p <= j - 2 && p <= i + 1 + l[i + 1]; p++)
				add(g[i][j], f[p][j - 1]);
			for (int p = j - 2; p >= i + 2 && p >= j - 1 - r[j - 1]; p--)
				add(g[i][j], f[i + 1][p]);
			
			add(f[i][j], g[i][j]);
			for (int p = i + 1; p <= j - 2; p++) {
				int lim = std::min(j - 1, p + 1 + l[p + 1]);
				int sum = reduce(sf[p + 1][j] - sf[lim + 1][j]);
				f[i][j] = (f[i][j] + (ll)g[i][p] * sum) % P;
				/*
				for (int q = p + 1; q <= lim; q++) {
					f[i][j] = (f[i][j] + (ll)g[i][p] * f[q][j]) % P;
				}
				*/
			}
		}
		sf[i][j] = norm(sf[i + 1][j] + f[i][j]);
	}
	printf("%d\n", f[1][n]);
	
//	std::cerr << clock() << "\n";
}
