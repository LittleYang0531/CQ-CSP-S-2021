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

const int maxn = 1e1;
const int maxl = 2 * maxn + 4;
const int maxs = 1<<maxn;

int T, n, dt_a[maxl];
int obj[maxl];

inline void simulate(int msk) {
	int L = 1, R = n<<1;
	rr (i, n<<1) {
		int c = !!(msk&(1<<(i - 1)));
		if (c) obj[i] = dt_a[R--];
		else obj[i] = dt_a[L++];
	}
}

inline bool palin() {
	r (i, n) {
		if (obj[i] != obj[(n<<1) - i + 1]) {
			return false;
		}
	}
	return true;
}

inline void solve() {
	cin >> n;
	r (i, n<<1) cin >> dt_a[i];
	int S = 1<<(n<<1);
	re (i, 0, S - 1) {
		simulate(i);
		if (palin()) {
			rr (j, n<<1) {
				if (i&(1<<(j - 1))) putchar('R');
				else putchar('L');
			}
			putchar('\n');
			return;
		}
	}
	puts("-1");
}

int main() {
	Resetio("palin");
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> T;
	while (T--) solve();
	return 0;
}
