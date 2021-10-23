#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 100005;
struct str { int a, b; } a[2][MAXN];
bool cmp(str x, str y) { return x.a < y.a; }
int n, m1, m2, lst[2][MAXN], nxt[2][MAXN], h[2][MAXN], th[2], s[2][MAXN], fa[MAXN], ans;
bool flag[MAXN];
int find(int x) {
	if(fa[x] == x) return x;
	return fa[x] = find(fa[x]);
}
void hb(int x, int y) {
	x = find(x), y = find(y);
	if(x == y) return; fa[x] = y;
}
void f(int m, int x) {
	int sum = 0; flag[0] = true;
	while(sum < m) {
		int p = find(0) + 1, q = 0, l, r, mid, tot = 0;
		while(p <= m) {
//			printf("%d ", p);
			if(!q) h[x][++th[x]] = p;
			else lst[x][p] = q, nxt[x][q] = p;
			q = p, sum++, tot++, flag[p] = true;
			if(flag[p - 1]) hb(p - 1, p); if(flag[p + 1]) hb(p, p + 1);
			l = p + 1, r = m + 1;
			while(l < r) {
				mid = (l + r) >> 1;
				if(a[x][mid].a < a[x][p].b) l = mid + 1;
				else r = mid;
			}
			p = l; if(flag[p]) p = find(p) + 1;
		}
//		printf("\n");
		s[x][th[x]] = tot;
	}
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for(int i = 1; i <= m1; i++) scanf("%d %d", &a[0][i].a, &a[0][i].b);
	for(int i = 1; i <= m2; i++) scanf("%d %d", &a[1][i].a, &a[1][i].b);
	sort(a[0] + 1, a[0] + m1 + 1, cmp), sort(a[1] + 1, a[1] + m2 + 1, cmp), a[0][m1 + 1].a = a[1][m2 + 1].a = 0x7fffffff;
	for(int i = 0; i <= m1; i++) fa[i] = i; f(m1, 0);
	for(int i = 0; i <= m2; i++) fa[i] = i; memset(flag, false, sizeof(flag)), f(m2, 1);
//	for(int i = 1; i <= m1; i++) printf("%d:%d %d\n", i, lst[0][i], nxt[0][i]);
//	for(int i = 1; i <= m2; i++) printf("%d:%d %d\n", i, lst[1][i], nxt[1][i]);
	for(int i = 2; i <= th[0]; i++) s[0][i] += s[0][i - 1], s[1][i] += s[1][i - 1];
	for(int i = 0; i <= n && i <= th[0]; i++) ans = max(ans, s[0][i] + s[1][min(n - i, m2)]);
	printf("%d", ans);
	return 0;
}
