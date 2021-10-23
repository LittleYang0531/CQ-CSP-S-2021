#include <bits/stdc++.h>
#define rep1(i, j, n) for (int i(j); i <= n; ++i)
#define rep2(i, j, n) for (int i(j); i >= n; --i)
using namespace std;
const int N = 3e5 + 5;
template <typename T>
inline void read(T &x) {
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch & 15); ch = getchar();}
	x *= f;
}
struct node {
	int l, r;
	inline bool operator < (const node &x) const {return l < x.l;}
} a[N], b[N];
struct node1 {int val, pos; inline bool operator < (const node1 &x) const {return val < x.val;}} ls[N << 1];
int n, m1, m2, cnt[N << 1], a1, a2;
inline int work(node *c, int len) { //ÀëÉ¢»¯
	int tot = 0;
	rep1(i, 1, len) ls[++tot].val = c[i].l, ls[tot].pos = tot, ls[++tot].val = c[i].r, ls[tot].pos = tot;
	sort(ls + 1, ls + 1 + tot);
	rep1(i, 1, tot) {
		int k = (ls[i].pos + 1) >> 1;
		if (ls[i].pos & 1) c[k].l = i; else c[k].r = i;
	}
	memset(cnt, 0, sizeof cnt);
	rep1(i, 1, len) cnt[c[i].l]++, cnt[c[i].r]--;
	int ans = 0, d = 0;
	rep1(i, 1, tot) d = max(d, ans), ans += cnt[i];
	d = max(d, ans);
	return d;
}
struct trer {int l, r, ma, tag;} t[N << 3];
inline int lson(int x) {return x << 1;}
inline int rson(int x) {return x << 1 | 1;}
inline void pushup(int x) {t[x].ma = max(t[lson(x)].ma, t[rson(x)].ma);}
inline void buildtree(int x, int l, int r) {
	t[x].l = l; t[x].r = r; t[x].tag = 0;
	if (t[x].l == t[x].r) {t[x].ma = 0; return ;}
	int mid = (l + r) >> 1;
	buildtree(lson(x), l, mid);
	buildtree(rson(x), mid + 1, r);
	pushup(x);
}
inline void pushdown(int x) {
	t[lson(x)].ma += t[x].tag;
	t[rson(x)].ma += t[x].tag;
	t[lson(x)].tag += t[x].tag;
	t[rson(x)].tag += t[x].tag;
	t[x].tag = 0;
}
inline int query(int x, int L, int R) {
	if (t[x].l >= L && t[x].r <= R) return t[x].ma;
	int mid = (t[x].l + t[x].r) >> 1, ans = 0; pushdown(x);
	if (L <= mid) ans = max(ans, query(lson(x), L, R));
	if (R > mid) ans = max(ans, query(rson(x), L, R));
	return ans;
}
inline void update(int x, int L, int R) {
	if (t[x].l >= L && t[x].r <= R) {
		++t[x].ma;
		t[x].tag++;
		return ;
	}
	int mid = (t[x].l + t[x].r) >> 1; pushdown(x);
	if (L <= mid) update(lson(x), L, R);
	if (R > mid) update(rson(x), L, R);
	pushup(x);
}
inline int solve(node *k, int c, int len) {
	sort(k + 1, k + 1 + len); 
	buildtree(1, 1, (len << 1)); int sum = 0;
	rep1(i, 1, len) {
		if (query(1, k[i].l, k[i].r) < c) update(1, k[i].l, k[i].r), ++sum;
	}
	return sum;
}
main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n); read(m1); read(m2);
	rep1(i, 1, m1) read(a[i].l), read(a[i].r);
	int d2 = work(a, m1);
	rep1(i, 1, m2) read(b[i].l), read(b[i].r);
	int d1 = work(b, m2);
	int ans = 0;
	for (int i = 0; i <= min(n, max(d1, d2)); ++i) 
		ans = max(ans, solve(a, n - i, m1) + solve(b, i, m2));
	printf("%d\n", ans);
}
