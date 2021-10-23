/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep( i, l, r ) for ( int i = l, rep##i = r; i <= rep##i; ++i )
#define per( i, r, l ) for ( int i = r, per##i = l; i >= per##i; --i )

inline int rint() {
	int x = 0, s = getchar();
	for ( ; s < '0' || '9' < s; s = getchar() );
	for ( ; '0' <= s && s <= '9'; s = getchar() ) x = x * 10 + ( s ^ '0' );
	return x;
}

const int MAXN = 5e5;
int n, a[MAXN * 2 + 5], pos[MAXN + 5][2];
char ans[MAXN * 2 + 5];

#define oth( x ) ( pos[a[x]][0] ^ pos[a[x]][1] ^ x )

int main() {
	freopen( "palin.in", "r", stdin );
	freopen( "palin.out", "w", stdout );

	for ( int T = rint(); T--; ) {
		n = rint();
		rep ( i, 1, n ) pos[i][0] = pos[i][1] = 0;
		rep ( i, 1, n << 1 ) {
			a[i] = rint();
			pos[a[i]][!!pos[a[i]][0]] = i;
		}
		
		if ( oth( 1 ) == 2 * n ) {
			bool flg = true;
			rep ( i, 1, n ) flg &= a[i] == a[2 * n - i + 1];
			if ( !flg ) puts( "-1" );
			else {
				rep ( i, 1, 2 * n ) putchar( 'L' );
				putchar( '\n' );
			}
			continue;
		}
		
		int idx = 1, l = 2, r = 2 * n, p = oth( 1 ) - 1, q = oth( 1 ) + 1;
		ans[idx] = ans[2 * n - idx + 1] = 'L', ++idx;
		bool flg = true;
		while ( l <= p || q <= r ) {
			if ( l < p && a[l] == a[p] ) {
				ans[idx] = ans[2 * n - idx + 1] = 'L', ++idx;
				++l, --p;
			} else if ( l <= p && a[l] == a[q] ) {
				ans[idx] = 'L', ans[2 * n - idx + 1] = 'R', ++idx;
				++l, ++q;
			} else if ( q <= r && a[r] == a[p] ) {
				ans[idx] = 'R', ans[2 * n - idx + 1] = 'L', ++idx;
				--p, --r;
			} else if ( q < r && a[r] == a[q] ) {
				ans[idx] = ans[2 * n - idx + 1] = 'R', ++idx;
				--r, ++q;
			} else { flg = false; break; }
		}
		
		if ( flg ) {
			rep ( i, 1, 2 * n ) putchar( ans[i] );
			putchar( '\n' );
			continue;
		}
		
		idx = 1, l = 1, r = 2 * n - 1;
		p = oth( 2 * n ) - 1, q = oth( 2 * n ) + 1;
		flg = true;
		ans[idx] = 'R', ans[2 * n - idx + 1] = 'L', ++idx;
		while ( l <= p || q <= r ) {
			if ( l < p && a[l] == a[p] ) {
				ans[idx] = ans[2 * n - idx + 1] = 'L', ++idx;
				++l, --p;
			} else if ( l <= p && a[l] == a[q] ) {
				ans[idx] = 'L', ans[2 * n - idx + 1] = 'R', ++idx;
				++l, ++q;
			} else if ( q <= r && a[r] == a[p] ) {
				ans[idx] = 'R', ans[2 * n - idx + 1] = 'L', ++idx;
				--p, --r;
			} else if ( q < r && a[r] == a[q] ) {
				ans[idx] = ans[2 * n - idx + 1] = 'R', ++idx;
				--r, ++q;
			} else { flg = false; break; }
		}
		
		if ( flg ) {
			rep ( i, 1, 2 * n ) putchar( ans[i] );
			putchar( '\n' );
			continue;
		}
		
		puts( "-1" );
	}
	return 0;
}

