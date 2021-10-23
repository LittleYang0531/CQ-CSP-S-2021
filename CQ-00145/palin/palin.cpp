#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 5e5 + 5;

int t;
bool flaged;
int n, a[MAXN << 1], b[MAXN << 1], mov[MAXN << 1];
inline void dfs(int l, int r, int tot) {
	if (flaged) return;
	if (l > r) {
		for (int i = 1; i <= n << 1; i++)
			putchar(mov[i] == 1 ? 'L' : 'R');
		putchar('\n');
		flaged = true;
		return;
	}
	if (l <= n << 1) {
		if ((tot > n && b[(n << 1) - tot + 1] == a[l]) || tot <= n) {
			b[tot] = a[l];
			mov[tot] = 1;
			dfs(l + 1, r, tot + 1);
			b[tot] = mov[tot] = 0;
		}
	}
	if (r >= 1) {
		if ((tot > n && b[(n << 1) - tot + 1] == a[r]) || tot <= n) {
			b[tot] = a[r];
			mov[tot] = 2;
			dfs(l, r - 1, tot + 1);
			b[tot] = mov[tot] = 0;
		}
	}
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while (t--) {
		flaged = false;
		scanf("%d", &n);
		for (int i = 1; i <= n << 1; i++)
			scanf("%d", &a[i]);
		dfs(1, n << 1, 1);
		if (!flaged) puts("-1");
	}
	return 0;
}
