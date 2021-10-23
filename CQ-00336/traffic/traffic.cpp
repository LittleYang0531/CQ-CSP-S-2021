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
���ģ��ȴ��� 
���ˣ�����10�֣����粻��
ע�⵽ k <= 50 
�����е���������ζ��
��ÿһ������Ϊ A, B, A ��ʾ�õ�ѡ 0��B ��ʾ�õ�ѡ 1
���Ҫ����Ȩֵ��С��������С�� (S, A, 1e8) (B, T, 1e8) (A, B, 1e100000000) ������߰��ձ�Ȩ��
����ƭ�ֺ� 
ܳ������ 
�������ˣ�����Ϊ����
������50�ֵ����� 

�ڿ���һ���Ƿ���ʲô�������ʣ�����
�����Ǹ����⣬ÿһ�ε�ѯ���� k �ǳ���С�����ˣ���Ե�����һ��ǰ����� 

��΢�����һ�£������롣
���ݾ��飬����ֻ����������һȦ�Ĳ���һ������

���仰˵������ĸ��ӵ��������Ҫ���ף��ͱ���ѹ���ת�Ƶ�����
Ŷ��k <= 2 �ĺ����������k == 1 �� k == 2������ͬɫ����Ϊ 0��k == 2 ʱ�����������ɫ������δ���
���������һ�˵�������/������һ��
һ�˽��̼򵥣�����ȡmin��������һ�𿸣���ʵ�����ҵ�һ��ǽ�������˸��� 
�ã���������������ôȥ��ǽ 
Ŷ��k ����Ҳ���������Ҫô����Ҫô��ǽ 
����k Ϊ 2 ����С������ 
*/
