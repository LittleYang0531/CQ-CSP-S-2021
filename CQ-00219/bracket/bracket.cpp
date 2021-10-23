/*+Rainybunny+*/

#include <bits/stdc++.h>

#define rep( i, l, r ) for ( int i = l, rep##i = r; i <= rep##i; ++i )
#define per( i, r, l ) for ( int i = r, per##i = l; i >= per##i; --i )

const int MAXN = 500, MOD = 1e9 + 7;
int n, m, lef[MAXN + 5], rig[MAXN + 5];
int f[MAXN + 5][MAXN + 5][2];
int pre[MAXN + 5][MAXN + 5], suf[MAXN + 5][MAXN + 5]; // for f[][][0].
char str[MAXN + 5];

inline int imax( const int u, const int v ) { return u < v ? v : u; }
inline int imin( const int u, const int v ) { return u < v ? u : v; }
inline int mul( const int u, const int v ) { return 1ll * u * v % MOD; }
inline int sub( int u, const int v ) { return ( u -= v ) < 0 ? u + MOD : u; }
inline int add( int u, const int v ) { return ( u += v ) < MOD ? u : u - MOD; }
inline void addeq( int& u, const int v ) { ( u += v ) >= MOD && ( u -= MOD ); }

int main() {
	freopen( "bracket.in", "r", stdin );
	freopen( "bracket.out", "w", stdout );
	
	scanf( "%d %d %s", &n, &m, str + 1 );
	
	rep ( i, 1, n ) {
		if ( str[i] == '?' || str[i] == '*' ) {
			lef[i] = imax( lef[i - 1] ? lef[i - 1] : i, i - m + 1 );
		}
	}
	per ( i, n, 1 ) {
		if ( str[i] == '?' || str[i] == '*' ) {
			rig[i] = imin( rig[i + 1] ? rig[i + 1] : i, i + m - 1 );
		}
	}
	
	rep ( len, 1, n ) {
		for ( int l = 1, r = len; r <= n; ++l, ++r ) {
			if ( str[l] != '(' && str[l] != '?' ) continue;
			if ( str[r] != ')' && str[r] != '?' ) continue;
			rep ( p, l + 1, r ) { // l as '(' matched r as ')'.
				if ( str[p] != ')' && str[p] != '?' ) continue;
				int lv = l + 2 > p ? 1 :
				  add( f[l + 1][p - 1][0], f[l + 1][p - 1][1] );
				if ( rig[l + 1] ) {
					addeq( lv, sub( pre[l + 2][p - 1],
					  pre[rig[l + 1] + 2][p - 1] ) );
				}
				if ( lef[p - 1] ) {
					addeq( lv, sub( suf[l + 1][p - 2],
					  suf[l + 1][imax( lef[p - 1] - 2, 0 )] )  );
				}
				if ( l + 1 < p && rig[l + 1] >= p - 1 ) addeq( lv, 1 );
				
				addeq( f[l][r][0], mul( lv, p < r ? f[p + 1][r][0] : 1 ) );
				if ( p < r ) {
					int rv = f[p + 1][r][1];
					if ( rig[p + 1] ) {
						addeq( rv, sub( pre[p + 2][r],
						  pre[rig[p + 1] + 2][r] ) );
					}
					addeq( f[l][r][1], mul( lv, rv ) );
				}
			}
		}
		rep ( r, len, n ) {
			pre[r - len + 1][r]
			  = add( pre[r - len + 2][r], f[r - len + 1][r][0] );
		}
		per ( l, n - len + 1, 1 ) {
			suf[l][l + len - 1]
			  = add( suf[l][l + len - 2], f[l][l + len - 1][0] );
		}
	}
	printf( "%d\n", add( f[1][n][0], f[1][n][1] ) );
	return 0;
}

/*
7 3
(*??*??
2 1
??
10 2
???(*??(?)
*/

