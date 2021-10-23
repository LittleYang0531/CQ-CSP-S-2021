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
const int maxk = 2e0 + 4;
const int dx[] = {-1, 1, 0, 0};
const int dy[] = {0, 0, -1, 1};

int n, m, T, K;
int qid[maxk], qcol[maxk];
intx qw[maxk];
intx dw[maxn][maxn][4];

inline Pi anaq(int id, int &d) {
	if (id <= m) return d = 0, mp(1, id);
	if (id > n + m && id <= n + (m<<1)) return d = 1, mp(n, (m<<1) - id + n + 1);
	if (id > n + (m<<1)) return d = 2, mp((n<<1) + (m<<1) - id + 1, 1);
	if (id > m && id <= n + m) return d = 3, mp(id - m, m);
}

inline void solveI() {
	r (i, n - 1) r (j, m) {
		intx w; cin >> w;
		dw[i][j][1] = dw[i + 1][j][0] = w;
	}
	r (i, n) r (j, m - 1) {
		intx w; cin >> w;
		dw[i][j][3] = dw[i][j + 1][2] = w;
	}
	r (tc, T) {
		int K; cin >> K;
		assert(K <= 2);
		r (i, K) cin >> qw[i] >> qid[i] >> qcol[i];
		if (K == 1 || qcol[1] == qcol[2]) { puts("0"); continue; }
		r (i, K) {
			int d; Pi cpos = anaq(qid[i], d);
			dw[cpos.fst][cpos.snd][d] = qw[i];
			dw[cpos.fst + dx[d]][cpos.snd + dy[d]][d^1] = qw[i];
		}
		
		r (i, K) {
			int d; Pi cpos = anaq(qid[i], d);
			dw[cpos.fst][cpos.snd][d] = 0;
			dw[cpos.fst + dx[d]][cpos.snd + dy[d]][d^1] = 0;
		}
	}
}

int main() {
	Resetio("traffic");
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m >> T, solveI();
	return 0;
}
