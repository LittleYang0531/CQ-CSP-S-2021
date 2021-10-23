#include <queue>
#include <cstdio>
#include <algorithm>
using namespace std;
#define maxn 100005
priority_queue < int, vector < int >, greater < int > > q;
struct node { int l, r; }a[maxn], b[maxn];
int n, m1, m2;

int calc( int x ) {
	int ans = 0;
	while( ! q.empty() ) q.pop();
	for( int i = 1;i <= m1;i ++ ) {
		while( ! q.empty() and q.top() < a[i].l ) q.pop();
		if( (int)q.size() < x ) ans ++, q.push( a[i].r );
	}
	while( ! q.empty() ) q.pop();
	for( int i = 1;i <= m2;i ++ ) {
		while( ! q.empty() and q.top() < b[i].l ) q.pop();
		if( (int)q.size() < n - x ) ans ++, q.push( b[i].r );
	}
	return ans;
}

int main() {
	freopen( "airport.in", "r", stdin );
	freopen( "airport.out", "w", stdout );
	scanf( "%d %d %d", &n, &m1, &m2 );
	for( int i = 1;i <= m1;i ++ ) scanf( "%d %d", &a[i].l, &a[i].r );
	for( int i = 1;i <= m2;i ++ ) scanf( "%d %d", &b[i].l, &b[i].r );
	sort( a + 1, a + m1 + 1, []( node x, node y ) { return x.l < y.l; } );
	sort( b + 1, b + m2 + 1, []( node x, node y ) { return x.l < y.l; } );
	int l = 0, r = n;
	while( l + 1 < r ) {
		int mid1 = l + ( r - l + 1 ) / 3;
		int mid2 = l + ( r - l + 1 ) / 3 * 2;
//		printf( "%d %d[%d %d]\n", mid1, mid2, l, r );
		if( calc( mid1 ) > calc( mid2 ) ) r = mid2 - 1;
		else l = mid1 + 1;
	}
	printf( "%d\n", max( calc( l ), calc( r ) ) );
	return 0;
}
