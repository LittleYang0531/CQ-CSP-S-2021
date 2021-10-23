/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep( i, l, r ) for ( int i = l, rep##i = r; i <= rep##i; ++i )
#define per( i, r, l ) for ( int i = r, per##i = l; i >= per##i; --i )

typedef std::pair<int, int> PII;
#define fi first
#define se second

inline int rint() {
	int x = 0, s = getchar();
	for ( ; s < '0' || '9' < s; s = getchar() );
	for ( ; '0' <= s && s <= '9'; s = getchar() ) x = x * 10 + ( s ^ '0' );
	return x;
}

const int MAXN = 1e5;
int n, m[2], ans[2][MAXN + 5];
PII a[2][MAXN + 5];

/*
inline int calc( const int m, const PII* ar, const int x ) {
	int res = x, ret = 0;
	static std::priority_queue<int, std::vector<int>, std::greater<int> > heap;
	while ( !heap.empty() ) heap.pop();
	rep ( i, 1, m ) {
		while ( !heap.empty() && heap.top() < ar[i].fi ) heap.pop(), ++res;
		if ( res ) heap.push( ar[i].se ), ++ret, --res;
	}
	return ret;
}
*/

struct BIT {
	int val[MAXN + 5];
	inline void add( int x, const int k ) {
		for ( ; x <= n; x += x & -x ) val[x] += k;
	}
	inline int sum( int x ) {
		int ret = 0;
		for ( ; x; x -= x & -x ) ret += val[x];
		return ret;
	}
} bit;

int main() {
	freopen( "airport.in", "r", stdin );
	freopen( "airport.out", "w", stdout );
	
	n = rint(), m[0] = rint(), m[1] = rint();
	rep ( i, 0, 1 ) rep ( j, 1, m[i] ) {
		a[i][j].fi = rint(), a[i][j].se = rint();
	}
	
	std::sort( a[0] + 1, a[0] + m[0] + 1 );
	std::sort( a[1] + 1, a[1] + m[1] + 1 );
	
	rep ( i, 0, 1 ) {
		rep ( j, 0, n ) bit.val[j] = 0;
		static std::priority_queue<PII, std::vector<PII>,
		  std::greater<PII> > heap;
		while ( !heap.empty() ) heap.pop(); // can be optimized to O(n).
		rep ( j, 1, m[i] ) {
			while ( !heap.empty() && heap.top().fi < a[i][j].fi ) {
				bit.add( heap.top().se, -1 ), heap.pop();
			}
			int l = 1, r = j;
			while ( l < r ) { // can be optimized to O(nlogn).
				int mid = l + r >> 1;
				if ( bit.sum( mid ) < mid ) r = mid;
				else l = mid + 1;
			}
//			printf( "(%d,%d): %d\n", i, j, l );
			++ans[i][l], bit.add( l, 1 ), heap.push( { a[i][j].se, l } );
		}
	}
	
	rep ( i, 0, 1 ) rep ( j, 1, n ) ans[i][j] += ans[i][j - 1];
	
	int mx = 0;
	rep ( i, 0, n ) mx = std::max( mx, ans[0][i] + ans[1][n - i] );
	printf( "%d\n", mx );
	return 0;
}

