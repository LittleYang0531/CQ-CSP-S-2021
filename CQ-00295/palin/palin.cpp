#include <cstdio>
#include <iostream>
using namespace std;

int n, tim, a[1000005], b[1000005], gb[1000005], ans[1000005];

inline bool is_pal() {
	for (int i = 1; i <= n; i++)
		if (b[i] != b[n * 2 - i + 1]) return false;
	return true;
}

inline void dfs(int now) {
	tim++;
	if (tim >= 3e6) return;
	if (now == n * 2 + 1) {
		int l = 1, r = n * 2;
		for (int i = 1; i <= n * 2; i++) {
			if (gb[i] & 1) b[i] = a[l], l++;
			else b[i] = a[r], r--;
		}
		if (is_pal()) {
			bool flag = false, eq = true;
			for (int i = 1; i <= n * 2; i++) {
				if (gb[i] < ans[i]) {flag = true; break;}
				if (gb[i] > ans[i]) break;
			}
			if (!flag) return;
			for (int i = 1; i <= n * 2; i++) ans[i] = gb[i];
			return;
		}
		return;
	}
	gb[now] = 1;
	dfs(now + 1);
	gb[now] = 2;
	dfs(now + 1);
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T--) {
		scanf("%d", &n);
		for (int i = 1; i <= n * 2; i++) scanf("%d", &a[i]), ans[i] = 1e9;
		dfs(1);
		if (ans[1] == 1e9) {puts("-1"); continue;}
		for (int i = 1; i <= n * 2; i++) putchar(ans[i] & 1 ? 'L' : 'R');
		puts("");
	}
	return 0;
}
