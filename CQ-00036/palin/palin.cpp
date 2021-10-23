#include <bits/stdc++.h>
#define rep1(i, j, n) for (int i(j); i <= n; ++i)
#define rep2(i, j, n) for (int i(j); i >= n; --i)
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch & 15); ch = getchar();}
	x *= f;
}
const int N = 5e5 + 5;
int t, n, a[N << 1], f[N << 1], b[N], c[N << 1]; bool vis[N];
inline bool dfs(int step) {
	if (step > n) {
		rep1(i, 1, n) b[i] = c[i], b[(n << 1) - i + 1] = c[i];
		int le = 1, ri = (n << 1); string s = "";
		rep1(i, 1, (n << 1)) {
			if (a[le] != b[i] && a[ri] != b[i]) return false;
			if (a[le] == b[i]) ++le, s += "L"; else --ri, s += "R";
		}
		cout << s << endl;
		return true;
	}
	rep1(i, 1, n) {
		if (!vis[i]) {
			vis[i] = 1; c[step] = i;
			if (dfs(step + 1)) return true;
			vis[i] = 0;
		}
	}
	return false;
}
main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	read(t);
	while (t--) {
		read(n);
		rep1(i, 1, (n << 1)) read(a[i]); bool flg = 1;
		rep1(i, 1, n) if (a[i] != a[(n << 1) - i + 1]) {flg = 0; break;}
		if (flg) {rep1(i, 1, n) putchar('L'); rep1(i, 1, n) putchar('R'); puts("");continue;}
		if (n == 1) {puts("LL"); continue;}
		else if (n == 2) {if (a[1] == a[2] && a[3] == a[4]) puts("LRRL"); else puts("-1"); continue;}
		else {
			memset(vis, 0, sizeof vis);
			if (dfs(1)) continue;
			else puts("-1");
		}
	}
}

