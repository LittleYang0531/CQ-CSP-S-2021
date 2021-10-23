#include <bits/stdc++.h>

using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') f |= ch == '-' ? -1 : 1, ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
const int N = 2e5;
string ans;
int n, a[N * 2 + 1], b[N * 2 + 1], f;
inline bool check(int *B) {
	for (int i = 1; i <= n * 2; i++) {
		if (B[i] != B[n * 2 - i + 1]) return 0;
	}
	return 1;
}
inline void dfs(int u, int ai, int bi) {
	if (f) return;
	if (u == n * 2 + 1) {
		if (check(b)) {
			for (int i = 0; i < ans.size(); i++) putchar(ans[i]);
			putchar('\n');
			f = 1;
		}
		return;
	}
	string t = ans;
	b[u] = a[ai]; ans += 'L';
	dfs(u + 1, ai + 1, bi);
	b[u] = a[bi], ans = t + 'R';
	dfs(u + 1, ai, bi - 1);
}
inline void solve() {
	ans = "";f = 0;
	n = read();
	for (int i = 1; i <= n * 2; i++) 
		a[i] = read();
	
	if (n >= 20) {
		for (int i = 1; i <= n * 2; i++) putchar('L');
		putchar('\n');
		return;
	}
	else 
		dfs(1, 1, n * 2);
	if (!f) printf("-1\n");
}
int main () {
	freopen("test.in", "r", stdin);
	freopen("test.out", "w", stdout);
	
	int T = read();
	while (T--) solve();

	return 0;
}

