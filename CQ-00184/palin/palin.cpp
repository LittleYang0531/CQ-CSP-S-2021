#include <iostream>
#include <cstdio>
const int nn = 1e6 + 5;
int t, n, a[nn], b[nn];
int pos[nn][2], ans[nn], tans[nn];
int check() {
	int pt1 = 0, pt2 = n + 1;
	for (int i = 1; i <= n * 2; i++)
		if (tans[i]) b[i] = a[++pt1];
		else b[i] = a[--pt2];
	for (int i = 1; i <= n; i++)
		if (b[i] != b[n + n - i + 1])
			return 0;
	return 1;
}
int flag = 0;
void update() {
	flag = 1;
	for (int i = 1; i <= n * 2; i++) {
		if (ans[i] > tans[i]) return;
		if (ans[i] < tans[i]) break;
	}
	for (int i = 1; i <= n * 2; i++)
		ans[i] = tans[i];
}
void dfs(int p) {
	if (p > n + n) {
		if (check()) update();
		return;
	}
	tans[p] = 1;
	dfs(p + 1);
	tans[p] = 0;
	dfs(p + 1);
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		scanf("%d", &n);
		for (int i = 1; i <= n * 2; i++) {
			scanf("%d", a + i);
		}
		dfs(1);
		if (flag) {
			for (int i = 1; i <= n * 2; i++)
				putchar(tans[i] ? 'L' : 'R');
			puts("");
		} else puts("-1");
	}
}
