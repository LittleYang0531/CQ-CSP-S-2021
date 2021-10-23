#include <map>
#include <set>
#include <ctime>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
#define mp make_pair
int read () {
	int x = 0, f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x * 10 + ch - '0');
		ch = getchar ();
	}
	return x * f;
}
void write (int x) {
	if (x < 0) x = -x, putchar ('-');
	if (x >= 10) write (x / 10);
	putchar (x % 10 + '0');
}
int dx[8] = {0, 0, 0, 1, -1};
int dy[8] = {0, 1, -1, 0, 0};
int e1[505][505], e2[505][505]; 
int s, t;

int tot = 1;
struct Edge {
	int v, nxt;
	long long e;
}edge[4000005];

int head[600005], cur[600005], dep[600005], vis[600005];
void addedge (int u, int v, long long e) {
	edge[++tot].v = v;
	edge[tot].e = e;
	edge[tot].nxt = head[u];
	head[u] = tot;
}
void Addedge (int u, int v, long long e) {
	addedge (u, v, e);
	addedge (v, u, 0);
}
int bfs () {
	for (int i = 0; i <= t; i++) dep[i] = 1e9, cur[i] = head[i], vis[i] = 0;
	queue <int> Q;
	Q.push(s);
	vis[s] = 0;
	dep[s] = 1;
	while (!Q.empty()) {
		int x = Q.front();
		Q.pop();
		vis[x] = 0;
		for (int i = head[x]; i; i = edge[i].nxt) {
			int y = edge[i].v;
			if (dep[y] > dep[x] + 1 && edge[i].e) {
				dep[y] = dep[x] + 1;
				if (vis[y] == 0) {
					vis[y] = 1;
					Q.push(y);
				} 
			}
		}
	} 
	return dep[0] != dep[t];
}
long long dfs (int x, long long e) {
	if (x == t) {
		return e;
	}
	long long used = 0, now = 0;
	for (int i = cur[x]; i; i = edge[i].nxt) {
		int y = edge[i].v;
		cur[x] = i;
		if (dep[y] == dep[x] + 1 && edge[i].e) {
			now = dfs (y, min (edge[i].e, e - used));
			if (now) {
				edge[i].e -= now;
				edge[i^1].e += now;
				used += now;
				if (used == e) break;
			}
		}
	}
	return used;
}
long long Dinic () {
	long long Ans = 0;
	while (bfs ()) {
		Ans += dfs (s, 1e16);
	}
	return Ans;
}

int n, m, T;
int get_id (int x, int y) {
	return (x - 1) * m + y;
}
void solve () {
	tot = 1;
	memset (head, 0, sizeof head);
	int num = read ();
	s = 2 * (n * m + num) + 1, t = s + 1;
	int N = n * m + num;
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= m; j++) {
			int one = get_id (i, j), ano = get_id (i + 1, j);
			Addedge (one, ano + N, e1[i][j]);
			Addedge (ano, one + N, e1[i][j]);
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j < m; j++) {
			int one = get_id (i, j), ano = get_id (i, j + 1);
			Addedge (one, ano + N, e2[i][j]);
			Addedge (ano, one + N, e2[i][j]);
		}
	} 
	for (int i = 1; i <= num; i++) {
		int E = read (), p = read (), col = read ();
		int ad = 0;
		if (p <= m) ad = get_id (1, p);
		if (p >= m + 1 && p <= m + n) ad = get_id (p - m, m);
		if (p >= n + m + 1 && p <= 2 * m + n) ad = get_id (n, m - (p - n - m) + 1);
		if (p >= 2 * m + n + 1) ad = get_id (n - (p - 2 * m - n) + 1, 1); 
		if (col == 0) {
			Addedge (s, i + n * m, 1e16);
			Addedge (i + n * m, ad + N, E);
		}
		else {
			Addedge (i + n * m + N, t, 1e16);
			Addedge (ad, i + n * m + N, E);
		}
	}
	for (int i = 1; i <= n * m; i++) Addedge (s, i, 1e8), Addedge (i, i + N, 1e16), Addedge (i + N, t, 1e8); 
	printf ("%lld\n", Dinic () - 100000000ll * n * m);
}
int main () {
	freopen ("traffic.in", "r", stdin);
	freopen ("traffic.out", "w", stdout);
	n = read (), m = read (), T = read ();
	for (int i = 1; i < n; i++) for (int j = 1; j <= m; j++) e1[i][j] = read ();
	for (int i = 1; i <= n; i++) for (int j = 1; j < m; j++) e2[i][j] = read ();
	while (T--) solve ();
	return 0;
}
/*
恶心，先打暴力 
算了，暴力10分，不如不打
注意到 k <= 50 
这题有点网络流的味道
将每一个点拆分为 A, B, A 表示该点选 0，B 表示该点选 1
最后要求总权值最小，可以最小割 (S, A, 1e8) (B, T, 1e8) (A, B, 1e100000000) 其它点边按照边权连
啊，骗分好 
艹，假了 
吓死我了，还以为假了
估摸着50分的样子 

在考虑一下是否有什么特殊性质？？？
还是那个问题，每一次的询问中 k 非常的小，算了，随缘，检查一下前面的题 

稍微检查了一下，接着想。
根据经验，可能只有在最外面一圈的才有一丁点用

换句话说，外面的附加点如果不想要贡献，就必须把贡献转移到里面
哦，k <= 2 的好像可以做，k == 1 或 k == 2但两个同色贡献为 0，k == 2 时，如果两个异色，该如何处理？
两种情况：一人单独接盘/两个人一起扛
一人接盘简单，就是取min，两个人一起扛，其实就是找到一个墙，将两人隔开 
好，现在问题变成了怎么去找墙 
哦，k 更大也是这个道理，要么抗，要么找墙 
啊，k 为 2 用最小生成树 
*/
