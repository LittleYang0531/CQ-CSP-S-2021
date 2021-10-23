#include <cstdio>
using namespace std;
const int MAXN = 20;
int take[MAXN];
int vis[MAXN]; char res[MAXN << 1];
int a[MAXN << 2], n; bool ac;
void dfs2(int l, int r) {
//	printf("2 %d %d %s\n", l, r, res);
	if (l > r) {
		ac = 1;
		puts(res);
	}
	else {
		if (a[l] == take[r - l + 1]) {
			res[n + n - r + l - 1] = 'L';
			dfs2(l + 1, r);
			if (ac) return;
		}
		if (a[r] == take[r - l + 1]) {
			res[n + n - r + l - 1] = 'R';
			dfs2(l, r - 1);
			if (ac) return;
		}
	}
}
void dfs1(int l, int r) {
//	printf("1 %d %d\n", l, r);
	if (r - l == n - 1) {
		dfs2(l, r);
		if (ac) return;
	}
	if (vis[a[l]] == 0) {
		vis[a[l]] = 1;
		res[n + n - r + l - 1] = 'L';
		take[n + n - r + l] = a[l];
		dfs1(l + 1, r);
		vis[a[l]] = 0;
		if (ac) return;
	}
	if (vis[a[r]] == 0) {
		vis[a[r]] = 1;
		res[n + n - r + l - 1] = 'R';
		take[n + n - r + l] = a[r];
		dfs1(l, r - 1);
		vis[a[r]] = 0;
		if (ac) return;
	}
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while (t--) {
		ac = 0;
		scanf("%d", &n);
		for (int i = 1; i <= n << 1; i++) {
			scanf("%d", &a[i]);
		}
		dfs1(1, n << 1);
		if (ac == 0) puts("-1");
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
