#include <bits/stdc++.h>

typedef long long ll;
typedef std::pair<ll, int> pli;

const int N = 520;
const int S = N * N;
const ll INF = ll(1E12);

ll A[55][55], lx[55], ly[55], slk[55];
int mx[55], my[55], vx[55], vy[55], tot;
bool dfs(int x) {
	vx[x] = true;
	for (int i = 1; i <= tot; i++) if (!vy[i]) {
		if (lx[x] + ly[i] == A[x][i]) {
			vy[i] = true;
			if (!my[i] || dfs(my[i])) {
				mx[x] = i, my[i] = x;
				return true;
			}
		} else {
			slk[i] = std::min(slk[i], lx[x] + ly[i] - A[x][i]);
		}
	}
	return false;
}
ll calc() {
	/*
	if (tot == 0) return 0;
	else if (tot == 1) return A[1][1];
	*/
	
	for (int i = 1; i <= tot; i++) for (int j = 1; j <= tot; j++)
		A[i][j] = INF - A[i][j];
	for (int i = 1; i <= tot; i++) lx[i] = INF, ly[i] = 0, mx[i] = my[i] = 0;
	for (int i = 1; i <= tot; i++) {
		for (int j = 1; j <= tot; j++)
			vx[j] = vy[j] = false, slk[j] = (1ll << 60);
		while (!dfs(i)) {
			ll del = (1ll << 60);
			for (int j = 1; j <= tot; j++) if (!vy[j])
				del = std::min(del, slk[j]);
			for (int j = 1; j <= tot; j++) {
				if (vx[j]) lx[j] -= del;
				if (vy[j]) ly[j] += del;
			}			
			for (int j = 1; j <= tot; j++)
				vx[j] = vy[j] = false, slk[j] = (1ll << 18);
		}
	}
	
	ll ans = 0;
	for (int i = 1; i <= tot; i++) ans += (lx[i] + ly[i]);
	return tot * INF - ans;
}

int to[10*S + 5], d[10*S + 5], cnt, cnte;
std::vector<int>G[S + 5];
void adde(int u, int v, int w) {
	int p = (cnte++), q = (cnte++);
	to[p] = v, d[p] = w, G[u].push_back(p);
	to[q] = u, d[q] = w, G[v].push_back(q);
//	printf("%d %d %d\n", u, v, w);
}
ll dis[S + 5];
void dijkstra(int s) {
	for (int i = 1; i <= cnt; i++) dis[i] = INF;
	std::priority_queue<pli, std::vector<pli>, std::greater<pli> >que;
	que.push(std::make_pair(dis[s] = 0, s));
	while (!que.empty()) {
		pli t = que.top(); int x = t.second; que.pop();
		if (dis[x] < t.first) continue;
		for (unsigned i = 0; i < G[x].size(); i++) {
			int e = G[x][i];
			if (dis[to[e]] > dis[x] + d[e])
				que.push(std::make_pair(dis[to[e]] = dis[x] + d[e], to[e]));
		}
	}
}

struct node{
	int x3, p, t;
	bool friend operator < (const node &a, const node &b) {
		return a.p < b.p;
	}
}a[55]; int k;
void solve() {
	static int id[55]; int tot1 = 0, tot2 = 0;
	for (int i = 1; i <= k; i++) {
		if (i == k) {
			if (a[i].t == 1 && a[1].t == 0) {
				id[i] = (++tot1);
			} else if (a[i].t == 0 && a[1].t == 1) {
				id[i] = -(++tot2);
			}
		} else {
			if (a[i].t == 1 && a[i + 1].t == 0) {
				id[i] = (++tot1);
			} else if (a[i].t == 0 && a[i + 1].t == 1) {
				id[i] = -(++tot2);
			}
		}
	}
	assert (tot1 == tot2); tot = tot1;
	for (int i = 1; i <= k; i++) if (id[i] > 0) {
		dijkstra(i);
		for (int j = 1; j <= k; j++) if (id[j] < 0)
			A[id[i]][-id[j]] = dis[j];
	}
	printf("%lld\n", calc());
}
int x1[N + 5][N + 5], x2[N + 5][N + 5], n, m, T;
void build() {
	static int pi[2*N + 5], pj[2*N + 5], id[N + 5][N + 5]; cnt = cnte = 0;
	for (int t = 1; t <= m; t++) pi[t] = 0, pj[t] = t;
	for (int t = m + 1; t <= m + n; t++) pi[t] = t - m, pj[t] = m;
	for (int t = m + n + 1; t <= 2*m + n; t++) pi[t] = n, pj[t] = 2*m + n - t;
	for (int t = 2*m + n + 1; t <= 2*m + 2*n; t++) pi[t] = 2*m + 2*n - t, pj[t] = 0;
	
	std::sort(a + 1, a + k + 1);
	for (int i = 1; i <= k; i++) {
		G[++cnt].clear();
		if (i != k) {
			for (int j = a[i].p; j < a[i + 1].p; j++)
				id[pi[j]][pj[j]] = i;
		} else {
			for (int j = a[i].p; j <= 2*n + 2*m; j++)
				id[pi[j]][pj[j]] = i;
			for (int j = 1; j < a[1].p; j++)
				id[pi[j]][pj[j]] = i;
		}
		
		if (i != 1) adde(i - 1, i, a[i].x3);
		else adde(k, i, a[i].x3);
	}
	for (int i = 1; i < n; i++) for (int j = 1; j < m; j++)
		G[id[i][j] = (++cnt)].clear();	
	
	for (int i = 1; i < n; i++) for (int j = 1; j <= m; j++)
		adde(id[i][j - 1], id[i][j], x1[i][j]);
	for (int i = 1; i <= n; i++) for (int j = 1; j < m; j++)
		adde(id[i - 1][j], id[i][j], x2[i][j]);
}
int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);

	scanf("%d%d%d", &n, &m, &T);
	for (int i = 1; i < n; i++) for (int j = 1; j <= m; j++)
		scanf("%d", &x1[i][j]);
	for (int i = 1; i <= n; i++) for (int j = 1; j < m; j++)
		scanf("%d", &x2[i][j]);
	for (int i = 1; i <= T; i++) {
		scanf("%d", &k);
		for (int i = 1; i <= k; i++)
			scanf("%d%d%d", &a[i].x3, &a[i].p, &a[i].t);
		build(), solve();
	}
}
