/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep( i, l, r ) for ( int i = l, rep##i = r; i <= rep##i; ++i )
#define per( i, r, l ) for ( int i = r, per##i = l; i >= per##i; --i )

typedef long long LL;

namespace FlowGraph {

const int MAXND = 3e5, MAXEG = 10 * MAXND;
int ecnt = 1, head[MAXND + 5];
struct Edge { int to, flw, cst, nxt; } graph[MAXEG + 5];

inline void link( const int s, const int t, const int f, const int w ) {
	graph[++ecnt] = { t, f, w, head[s] }, head[s] = ecnt;
	graph[++ecnt] = { s, 0, -w, head[t] }, head[t] = ecnt;
}

inline bool spfa() {
	
}

inline LL dfs() {
	
}

inline LL dinic() {
	
}

} using namespace FlowGraph;

int main() {
//	freopen( "traffic.in", "r", stdin );
//	freopen( "traffic.out", "w", stdout );
	return 0;
}

