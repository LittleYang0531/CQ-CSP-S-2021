#include <cstdio>
#include <map>
#include <utility>
#include <cstring>
#include <algorithm>

#define Maxn 505

using namespace std;

int n, m, q;
int k[Maxn], ans;
int vis[Maxn][Maxn];
int op[Maxn * 4];
int a[Maxn][Maxn], b[Maxn][Maxn], pa[Maxn], pb[Maxn];

struct Node {
	int dis, p, col;
} s[Maxn];

map < int , pair < int , int > > mp, nod;

int Get (int k) {
	int ret = 0;
	memset (pa, 0, sizeof pa);
	memset (pb, 0, sizeof pb);
	for (int j = 1; j <= m; j ++) {
		for (int i = 1; i < n; i ++) {
			pa[j + 1] = pa[j] + a[i][j];
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j < m; j ++) {
			pb[i + 1] = pb[i] + b[i][j];
		}
	}
	for (int i = 1; i <= k; i ++) {
		if (op[s[i].p] == 1) {
			pa[1] = s[i].dis;
			for (int j = 1; j < n; j ++) pa[j + 1] = pa[j] + a[j][nod[s[i].p].second];
		} else if (op[s[i].p] == 2) {
			pb[m + 1] = pb[m] + s[i].dis;
		} else if (op[s[i].p] == 3) {
			pa[n + 1] = pa[n] + s[i].dis;
		} else if (op[s[i].p] == 4) {
			pb[1] = s[i].dis;
			for (int j = 1; j < m; j ++) pb[j + 1] = pb[j] + b[nod[s[i].p].first][j];
		}
	}
	for (int i = 1; i <= n; i ++) {
		int pre = 1;
		for (int j = 1; j < m; j ++) {
			if (vis[i][j] ^ vis[i][pre]) {
				ret += pb[j] - pb[pre];
				pre = j;
			}
		}
	}
	for (int j = 1; j <= m; j ++) {
		int pre = 1;
		for (int i = 1; i < n; i ++) {
			if (vis[i][j] ^ vis[pre][j]) {
				ret += pa[j] - pa[pre];
				pre = i;
			}
		}
	}
	return ret;
}

void Dfs (int x, int y, int k) {
	if (y == m + 1) {
		x ++;
		y = 1;
	}
	if (x == n + 1) {
		ans = min (ans, Get (k));
		return ;
	}
	vis[x][y] = 1;
	Dfs (x + 1, y, k);
	vis[x][y] = 0;
	Dfs (x + 1, y, k);
}

int main () {
	freopen ("traffic.in", "r", stdin);
	freopen ("traffic.out", "w", stdout);
	
	scanf ("%d %d %d", &n, &m, &q);
	
	for (int i = 1; i < n; i ++) {
		for (int j = 1; j <= m; j ++) {
			scanf ("%d", &a[i][j]);
		}
	}
	
	for (int j = 1; j <= m; j ++) {
		for (int i = 1; i < n; i ++) {
			pa[j + 1] = pa[j] + a[i][j];
		}
	}
	
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j < m; j ++) {
			scanf ("%d", &b[i][j]);
			pb[i + 1] = pb[i] + b[i][j];
		}
	}
	
	for (int i = 1; i <= m; i ++) {
		op[i] = 1;
		op[n + m + i] = 3;
		mp[i] = make_pair (1, i);
		nod[i] = make_pair (0, i);
		mp[n + m + i] = make_pair (n, i);
		nod[n + m + i] = make_pair (n + 1, i);
	}
	for (int i = 1; i <= n; i ++) {
		op[m + i] = 2;
		op[n + 2 * m + i] = 4;
		mp[m + i] = make_pair (i, m);
		nod[m + i] = make_pair (i, m + 1);
		mp[n + 2 * m + i] = make_pair (i, 1);
		nod[n + 2 * m + i] = make_pair (i, 0);
	}
	
	
	for (int r = 1; r <= q; r ++) {
		scanf ("%d", &k[r]);
		for (int i = 1; i <= k[r]; i ++) {
			scanf ("%d %d %d", &s[i].dis, &s[i].p, &s[i].col);
			vis[nod[s[i].p].first][nod[s[i].p].second] = s[i].col;
		}
		ans = 0x3f3f3f3f;
		Dfs (1, 1, k[r]);
		memset (vis, 0, sizeof vis);
		printf ("%d\n", ans);
	}
	return 0;
}

