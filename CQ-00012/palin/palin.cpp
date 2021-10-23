#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 105;
int q[MAXN];
int a[MAXN], n;
bool ans, vis[MAXN];
bool dfs1(int i, int j, int sum) {
	if (sum == 2 * n) {
		for (int k = 1; k <= n; k++) {
			if (q[k] != q[2 * n - k + 1]) return 0;
		}
		return 1;
	}
	if (!vis[a[i]] || sum >= n - 1) {
		vis[a[i]] = 1;
		q[sum + 1] = a[i];
		if (dfs1(i + 1, j, sum + 1)) {
			printf("L");
			ans = 1;
			return 1;
		}
		vis[a[i]] = 0;
	}
	if (!vis[a[j]] || sum >= n - 1) {
		vis[a[j]] = 1;
		q[sum + 1] = a[j];
		if (dfs1(i, j - 1, sum + 1)) {
			printf("R");
			ans = 1;
			return 1;
		}
		vis[a[j]] = 0;
	}
	return 0;
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		memset(vis, 0, sizeof(vis));
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i++) {
			scanf("%d", &a[i]);
		}
		ans = 0;
		dfs1(1, 2 * n, 0);
		if (!ans) printf("-1");
		printf("\n");
	}
	return 0;
}
