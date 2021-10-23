#include <cstdio>
#include <algorithm>
using namespace std;
const int MAXN = 20;
int mp[MAXN][MAXN], r[MAXN][MAXN], c[MAXN][MAXN];
int jkn[MAXN << 2], ckn[MAXN << 2];
int n, m;
int qwq;
void dfs(int x, int y, int sc) {
	if (x == n && y == m + 1) {
		qwq = min(qwq,sc);
//		printf("%d\n", qwq);
//		for (int i = 1; i <= n; i++) {
//			for (int j = 1; j <= m; j++) {
//				printf("%d ", mp[i][j]);
//			}
//			puts("");
//		}
		return;
	}
	if (y == m + 1) y = 1, x++;
	if (sc >= qwq) return;
	int oc = sc;
	//1
	mp[x][y] = 1;
	if (x != 1 && mp[x - 1][y] == 0) {
		sc += r[x - 1][y];
	}
	if (y != 1 && mp[x][y - 1] == 0) {
		sc += c[x][y - 1];
	}
	if (x == 1 && jkn[y] && ckn[y] == 0) {
		sc += jkn[y];
	}
	if (y == m && jkn[m + x] && ckn[m + x] == 0) {
		sc += jkn[m + x];
	}
	if (x == n && jkn[m + n + m - y + 1] && ckn[m + n + m - y + 1] == 0) {
		sc += jkn[m + n + m - y + 1];
	}
	if (y == 1 && jkn[m + n + m + n - x + 1] && ckn[m + n + m + n - x + 1] == 0) {
		sc += jkn[m + n + m + n - x + 1];
	}
	dfs(x, y + 1, sc);
	
	//0
	sc = oc;
	mp[x][y] = 0;
	if (x != 1 && mp[x - 1][y] == 1) {
		sc += r[x - 1][y];
	}
	if (y != 1 && mp[x][y - 1] == 1) {
		sc += c[x][y - 1];
	}
	if (x == 1 && jkn[y] && ckn[y] == 1) {
		sc += jkn[y];
	}
	if (y == m && jkn[m + x] && ckn[m + x] == 1) {
		sc += jkn[m + x];
	}
	if (x == n && jkn[m + n + m - y + 1] && ckn[m + n + m - y + 1] == 1) {
		sc += jkn[m + n + m - y + 1];
	}
	if (y == 1 && jkn[m + n + m + n - x + 1] && ckn[m + n + m + n - x + 1] == 1) {
		sc += jkn[m + n + m + n - x + 1];
	}
	dfs(x, y + 1, sc);
	
}
int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	int t;
	scanf("%d %d %d", &n, &m, &t);
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= m; j++) {
			scanf("%d", &r[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m - 1; j++) {
			scanf("%d", &c[i][j]);
		}
	}
	while (t--) {
		int k;
		scanf("%d", &k);
		while (k--) {
			int a, b, c;
			scanf("%d %d %d", &a, &b, &c);
			jkn[b] = a;
			ckn[b] = c;
		}
		qwq = 0x7fffffff;
		dfs(1, 1, 0);
		printf("%d\n", qwq);
	}
	return 0;
}
/*
2 3 1 
9 4 7 
3 8 
10 5 
2 
19 3 1 
17 9 0 
*/
