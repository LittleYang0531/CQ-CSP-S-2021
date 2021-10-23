// #pragma GCC optimize(2)
#include <bits/stdc++.h>
using namespace std;

namespace Dev_Ns_Macros {
	
	#define r(i, j) for (int i = 1; i <= (j); ++i)
	#define re(i, j, k) for (int i = (j); i <= (k); ++i)
	#define rr(i, j) for (int i = (j); i >= 1; --i)
	#define rre(i, j, k) for (int i = (k); i >= (j); --i)
	
	#define Pi pair<int, int>
	#define Pl pair<long long, long long>
	#define mp make_pair
	#define Lb lower_bound
	#define Ub upper_bound
	#define fst first
	#define snd second
	
	#define Reseti(x) freopen(x, "r", stdin)
	#define Reseto(x) freopen(x, "w", stdout)
	#define Resetio(x) freopen(x".in", "r", stdin), freopen(x".out", "w", stdout)
	#define inline [[gnu::always_inline]] inline
	
}

const int modn = 1e9 + 7;

namespace Dev_Ns_Predefs {
	
	typedef long long intx;
	typedef unsigned long long inte;
	
	inline int Max(int a, int b) { return a > b ? a : b; }
	inline intx Max(intx a, intx b) { return a > b ? a : b; }
	inline int Min(int a, int b) { return a < b ? a : b; }
	inline intx Min(int a, intx b) { return a < b ? a : b; }
	inline int amod(int a, int p = modn) { return a >= p ? a - p : a; }
	inline int smod(int a, int p = modn) { return a < 0 ? a + p : a; }
	inline void addmod(int &a, int b, int p = modn) { a = amod(a + b, p); }
	inline void submod(int &a, int b, int p = modn) { a = smod(a - b, p); }
	
	inline intx fr() {
		intx res = 0; int sym = 1; char c = 0;
		while (!isdigit(c))
			sym = c == '-' ? -1 : 1, c = getchar();
		while (isdigit(c))
			res = res * 10 + c - '0', c = getchar();
		return res * sym;
	}
	
	inline void wrtl(intx a) {
		static int stk[40], top; top = 0;
		if (a < 0) putchar('-'), a = -a;
		if (!a) stk[top++] = 0;
		while (a) stk[top++] = a % 10, a /= 10;
		while (top) putchar(stk[--top] + '0');
	}
	
}
using namespace Dev_Ns_Predefs;

const int maxn = 5e2 + 4;

int n, K;
string S;

int f[maxn][maxn], g[maxn][maxn], h[maxn][maxn];
bool pmatch[maxn][maxn];

inline bool match(char a, char p) {
	return p == '?' || a == p;
}

int main() {
	Resetio("bracket");
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> K >> S, S = " " + S;
	
	r (i, n) {
		pmatch[i][i - 1] = true;
		int Rborder = Min(n, i + K - 1);
		re (j, i, Rborder) pmatch[i][j] = pmatch[i][j - 1] & match('*', S[j]);
	}
	r (k, n) r (i, n - k + 1) {
		int j = i + k - 1;
		if (match('(', S[i])) for (int l = i + 1; l < j; ++l) if (match(')', S[l])) {
			int lupdv = amod(amod(g[i + 1][l - 1] + h[i + 1][l - 1])
				+ amod(f[i + 1][l - 1] + pmatch[i + 1][l - 1]));
			int rupdv = amod(g[l + 1][j] + f[l + 1][j]);
			int updv = 1ll * lupdv * rupdv % modn; addmod(f[i][j], updv);
		}
		if (match('(', S[i]) && match(')', S[j])) {
			addmod(f[i][j], amod(amod(g[i + 1][j - 1] + h[i + 1][j - 1])
				+ amod(f[i + 1][j - 1] + pmatch[i + 1][j - 1])));
		}
		int sprlen = Min(K, j - i + 1);
		re (l, i, i + sprlen - 1) {
			if (!match('*', S[l])) break;
			addmod(g[i][j], f[l + 1][j]);
		}
		rre (l, j - sprlen + 1, j) {
			if (!match('*', S[l])) break;
			addmod(h[i][j], f[i][l - 1]);
		}
	}
	
	// r (i, n) { re (j, i, n) wrtl(pmatch[i][j]), putchar(' '); putchar('\n'); } putchar('\n');
	// r (i, n) { re (j, i, n) wrtl(f[i][j]), putchar(' '); putchar('\n'); } putchar('\n');
	// r (i, n) { re (j, i, n) wrtl(g[i][j]), putchar(' '); putchar('\n'); } putchar('\n');
	// r (i, n) { re (j, i, n) wrtl(h[i][j]), putchar(' '); putchar('\n'); } putchar('\n');
	
	wrtl(f[1][n]);
	
	return 0;
}
