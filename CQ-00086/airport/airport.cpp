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

namespace Dev_Ns_Predefs {
	
	typedef long long intx;
	typedef unsigned long long inte;
	
	inline int Max(int a, int b) { return a > b ? a : b; }
	inline intx Max(intx a, intx b) { return a > b ? a : b; }
	inline int Min(int a, int b) { return a < b ? a : b; }
	inline intx Min(int a, intx b) { return a < b ? a : b; }
	
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

const int maxn = 1e5 + 4;
const int maxm = 1e5 + 4;
const int maxa = 1e8;
const int maxlog = 20;

int n, m1, m2;
Pi p1[maxm], p2[maxm];

int pos[maxm * 2], posc;
unordered_map<int, int> refl(maxm * 2);
intx fwt[maxm * 2];

int s1[maxn], s2[maxn];

inline void mark(int a, intx b) {
	for (; a <= posc; a += (a&(-a))) fwt[a] += b;
}

inline intx getsum(int a) {
	intx res = 0; 
	for (; a; a -= (a&(-a))) res += fwt[a];
	return res;
}

inline int detect(int a) {
	rre (i, 0, maxlog - 1) {
		int b = a + (1<<i);
		if (b > posc) continue;
		if (getsum(b) == getsum(a)) a = b;
	}
	return a;
}

inline void simulate(Pi *a, int len, int *res) {
	memset(fwt, 0, sizeof fwt);
	r (i, len) mark(a[i].fst, a[i].snd);
	r (i, n) {
		int p = detect(0) + 1;
		while (p <= posc) {
			++res[i];
			int ptv = getsum(p) - getsum(p - 1);
			mark(p, -ptv), p = detect(ptv) + 1;
		}
		res[i] += res[i - 1];
	}
}

int main() {
	Resetio("airport");
	ios::sync_with_stdio(false), cin.tie(0);
	cin >> n >> m1 >> m2;
	// n = fr(), m1 = fr(), m2 = fr();
	r (i, m1) {
		cin >> p1[i].fst >> p1[i].snd;
		pos[++posc] = p1[i].fst;// = fr();
		pos[++posc] = p1[i].snd;// = fr();
	}
	r (i, m2) {
		cin >> p2[i].fst >> p2[i].snd;
		pos[++posc] = p2[i].fst;// = fr();
		pos[++posc] = p2[i].snd;// = fr();
	}
	sort(pos + 1, pos + 1 + posc);
	posc = unique(pos + 1, pos + 1 + posc) - pos - 1;
	r (i, posc) refl[pos[i]] = i;
	r (i, m1) p1[i] = mp(refl[p1[i].fst], refl[p1[i].snd]);
	r (i, m2) p2[i] = mp(refl[p2[i].fst], refl[p2[i].snd]);
	sort(p1 + 1, p1 + 1 + m1);
	sort(p2 + 1, p2 + 1 + m2);
	simulate(p1, m1, s1);
	simulate(p2, m2, s2);
	int ans = 0;
	re (i, 0, n) ans = Max(ans, s1[i] + s2[n - i]);
	wrtl(ans);
	return 0;
}
