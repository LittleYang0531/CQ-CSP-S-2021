#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 1e5 + 5;
struct Node {
	int id, tim, flag;
};
Node c[MAXN];
bool cmp(Node x, Node y) {
	return x.tim < y.tim;
}
int n, m[2];
int dp[2][MAXN], bkt[2][MAXN], z[MAXN];
struct Tree {
	int l, r, sum, tag;
	#define ls (pos << 1)
	#define rs (pos << 1 | 1)
};
Tree t[MAXN << 2];
void Push_Up(int pos) {
	t[pos].sum = t[ls].sum + t[rs].sum;
}
void Push_Down(int pos) {
	if (t[pos].tag) {
		t[ls].tag += t[pos].tag;
		t[rs].tag += t[pos].tag;
		t[ls].sum += t[pos].tag * (t[ls].r - t[ls].l + 1);
		t[rs].sum += t[pos].tag * (t[rs].r - t[rs].l + 1);
		t[pos].tag = 0;
	}
}
void Build(int pos, int l, int r) {
	t[pos].l = l, t[pos].r = r, t[pos].tag = 0;
	if (l == r) {
		t[pos].sum = l;
		return;
	}
	int mid = (l + r) >> 1;
	Build(ls, l, mid);
	Build(rs, mid + 1, r);
	Push_Up(pos);
}
void Update(int pos, int l, int r, int x) {
	if (l <= t[pos].l && t[pos].r <= r) {
		t[pos].tag += x;
		t[pos].sum += x * (t[pos].r - t[pos].l + 1);
		return;
	}
	Push_Down(pos);
	if (t[ls].r >= l) Update(ls, l, r, x);
	if (t[rs].l <= r) Update(rs, l, r, x);
	Push_Up(pos);
}
int Query(int pos) {
	if (t[pos].l == t[pos].r) return t[pos].l;
	Push_Down(pos);
	if (t[ls].sum) return Query(ls);
	return Query(rs);
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m[0], &m[1]);
	for (int k = 0; k < 2; k++) {
		int tot = 0;
		for (int i = 1, a, b; i <= m[k]; i++) {
			scanf("%d %d", &a, &b);
			c[++tot].flag = 0;
			c[tot].id = i;
			c[tot].tim = a;
			
			c[++tot].flag = 1;
			c[tot].id = i;
			c[tot].tim = b;
		}
		sort(c + 1, c + 1 + tot, cmp);
		Build(1, 1, m[k]);
		for (int i = 1; i <= tot; i++) {
			if (c[i].flag) {
				Update(1, dp[k][c[i].id], m[k], 1);
			}
			else {
				dp[k][c[i].id] = Query(1);
				Update(1, dp[k][c[i].id], m[k], -1);
			}
		}
		for (int i = 1; i <= max(n, m[k]); i++) bkt[k][dp[k][i]]++;
		for (int i = 1; i <= max(n, m[k]); i++) bkt[k][i] += bkt[k][i - 1];
	}
	int ans = 0;
	for (int i = 0; i <= n; i++) {
		ans = max(ans, bkt[0][i] + bkt[1][n - i]);
	}
	printf("%d", ans);
	return 0;
}
