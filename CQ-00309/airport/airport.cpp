#include <set>
#include <queue>
#include <cstdio>
#include <algorithm>

#define Maxn 100005

using namespace std;

int n, m1, m2;
int pre1[Maxn], pre2[Maxn], v1[Maxn], v2[Maxn], son1[Maxn], son2[Maxn];

struct Node {
	int arv, lev;
	friend bool operator < (Node x, Node y) {
		return x.arv < y.arv;
	}
} a[Maxn], b[Maxn];

set < int > s1, s2;

int Max (int a, int b) { return a > b ? a : b; }

struct Union_Find_Set {
	int fa[Maxn];
	
	void Make_Set () {
		for (int i = 1; i <= Max (m1, m2) + 1; i ++) {
			fa[i] = i;
		}
	}
	
	int Find_Set (int u) {
		return fa[u] == u ? u : fa[u] = Find_Set (fa[u]);
	}
	
	void Union (int u, int v) {
		u = Find_Set (u);
		v = Find_Set (v);
		if (u == v) return ;
		fa[u] = v;
	}	
} sa, sb;

int main () {
	freopen ("airport.in", "r", stdin);
	freopen ("airport.out", "w", stdout);

	scanf ("%d %d %d", &n, &m1, &m2);
	
	for (int i = 1; i <= m1; i ++) {
		scanf ("%d %d", &a[i].arv, &a[i].lev);
		pre1[i] = m1;
	}
	
	for (int i = 1; i <= m2; i ++) {
		scanf ("%d %d", &b[i].arv, &b[i].lev);
		pre2[i] = m2;
	}
	
	sort (a + 1, a + 1 + m1);
	sort (b + 1, b + 1 + m2);
	
	for (int i = 1; i <= m1; i ++) {
		v1[i] = a[i].arv;
		s1.insert (i);
	}
	v1[m1 + 1] = 1e9;
	
	for (int i = 1; i <= m2; i ++) {
		v2[i] = b[i].arv;
		s2.insert (i);
	}
	v2[m2 + 1] = 1e9;
	
	sa.Make_Set ();
	int i = 1;
	for ( ; s1.size (); ) {
		int x = upper_bound (v1 + i + 1, v1 + 1 + m1 + 1, a[i].lev) - v1;
//		printf ("--- %d %d(%d)\n", i, sa.Find_Set (x), x);
		x = sa.Find_Set (x);
		son1[i] = x;
		s1.erase (s1.find (i));
		i = x;
		if (i == m1 + 1) {
			if (s1.size ()) i = *s1.begin ();
			continue;
		}		
		sa.Union (x, x + 1);
	}
	
	int id = 0;
	for (int i = 1; i <= m1; i ++) {
		if (sa.fa[i] == i) {
			++ id;
			pre1[id] = 0;
			int now = i;
			while (now != m1 + 1) {
				pre1[id] ++;
				now = son1[now];
			}
			pre1[id] += pre1[id - 1];
		}
		if (id == n) break;
	}
	
//	for (int i = 1; i <= n; i ++) {
//		printf ("%d ", pre1[i]);
//	}
//	printf ("\n");
	
	sb.Make_Set ();
	i = 1;
	for ( ; s2.size (); ) {
		int x = upper_bound (v2 + i + 1, v2 + 1 + m2 + 1, b[i].lev) - v2;
//		printf ("--- %d %d(%d)\n", i, sb.Find_Set (x), x);
		x = sb.Find_Set (x);
		son2[i] = x;
		s2.erase (s2.find (i));
		i = x;
		if (i == m2 + 1) {
			if (s2.size ()) i = *s2.begin ();
			continue;
		}		
		sb.Union (x, x + 1);	
	}
	
	id = 0;
	for (int i = 1; i <= m2; i ++) {
		if (sb.fa[i] == i) {
			++ id;
			pre2[id] = 0;
			int now = i;
			while (now != m2 + 1) {
				pre2[id] ++;
				now = son2[now];
			}
			pre2[id] += pre2[id - 1];
		}
		if (id == n) break;
	}
	
//	for (int i = 1; i <= n; i ++) {
//		printf ("%d ", pre2[i]);
//	}
//	printf ("\n");
	
	int ans = 0;
	for (int i = 0; i <= n; i ++) {
//		printf ("[%d , %d]  %d  %d\n", i, n - i, pre1[i], pre2[n - i]);
		ans = Max (ans, pre1[i] + pre2[n - i]);
	}

	printf ("%d", ans);
	return 0;
}

