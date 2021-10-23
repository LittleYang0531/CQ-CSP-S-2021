#include <bits/stdc++.h>
using namespace std;
namespace cyyh {
	template <typename T>
	inline void read(T &x) {
		int f = 1; char ch; x = 0;
		while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}
}
using namespace cyyh;
const int N = 10e5 + 5;
int T, n, a[N], mark[N], t[N], l, r, cnt;
bool vis[N];
//map <vector <int>, bool> mp;
bool dfs(int dep) {
	++cnt;
//	vector <int> v;
//	for (int i = 1; i <= 2 * n; ++i) v.push_back(mark[i]);
//	if (mp[v]) return false;
//	mp[v] = 1;
//	if (cnt > 350000000) return puts("-1"), 1;
//	cout << cnt << endl;
//	for (int i = 1; i <= 2 * n; ++i) cout << mark[i] << ' ';
//	puts("");
//	for (int i = 1; i <= 2 * n; ++i) cout << t[i] << ' ';
//	puts("");
	if (dep > 2 * n) {
		for (int i = 1; i <= n; ++i) {
			if (mark[i] ^ mark[2 * n + 1 - i]) return false;
		}
//		for (int i = 1; i <= 2*n; ++i) printf("%d ", mark[i]);
//		puts("");
		for (int i = 1; i <= 2 * n; ++i) 
			if (t[i]) putchar('R');
			else putchar('L');
		putchar('\n');
//		cout << cnt << endl;
		return true;
	}
	if (!vis[l]) t[dep] = 0, mark[dep] = a[l], vis[l] = 1, ++l;
	if (dfs(dep + 1)) return true;
	--l, vis[l] = 0;
	if (!vis[r]) t[dep] = 1, mark[dep] = a[r], vis[r] = 1;
	--r;
	if (dfs(dep + 1)) return true;
	++r, vis[r] = 0;
	t[dep] = 0;
	return false;
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	read(T);
	while (T--) {
		read(n);
		for (int i = 1; i <= 2 * n; ++i) read(a[i]);
		l = 1, r = 2 * n, cnt = 0;
		memset(mark, 0, sizeof mark), memset(t, 0, sizeof t), memset(vis, 0, sizeof vis);
		if (!dfs(1)) puts("-1");
	}
	return 0;
}

