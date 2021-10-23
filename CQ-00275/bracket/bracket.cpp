#include <cstdio>
#include <cstring>

const int MAXN = 500 , Mod = 1e9 + 7;
int Add( int x , int y ) { x += y; return x >= Mod ? x - Mod : x; }
int Mul( int x , int y ) { return 1ll * x * y % Mod; }

bool equ( char s , char t ) {
	if( s == '?' ) return 1;
	return s == t;
}

int n , k , chk[ MAXN + 5 ][ MAXN + 5 ]; char str[ MAXN + 5 ];
int Check( int l , int r ) {
	if( r - l + 1 > k ) return 0;
	if( ~chk[ l ][ r ] ) return chk[ l ][ r ];
	for( int i = l ; i <= r ; i ++ ) if( !equ( str[ i ] , '*' ) ) return chk[ l ][ r ] = 0;
	return chk[ l ][ r ] = 1;
}

int dp[ 2 ][ MAXN + 5 ][ MAXN + 5 ] , s[ MAXN + 5 ][ MAXN + 5 ]; //ÊÇ·ñÎª´óÀ¨ºÅ 
int main( ) {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	scanf("%d %d",&n,&k);
	scanf("%s", str + 1 );
	
	memset( chk , -1 , sizeof( chk ) );
	for( int l = 1 ; l <= n ; l ++ )
		for( int r = l + 1 ; r <= n ; r ++ )
			if( Check( l + 1 , r - 1 ) && equ( str[ l ] , '(' ) && equ( str[ r ] , ')' ) )
				dp[ 1 ][ l ][ r ] = 1;
	for( int len = 1 ; len <= n ; len ++ )
		for( int l = 1 , r ; ( r = l + len - 1 ) <= n ; l ++ ) {
			if( equ( str[ l ] , '(' ) && equ( str[ r ] , ')' ) ) {
				dp[ 1 ][ l ][ r ] = Add( dp[ 1 ][ l ][ r ] , Add( dp[ 0 ][ l + 1 ][ r - 1 ] , dp[ 1 ][ l + 1 ][ r - 1 ] ) );
				
				for( int a = l + 1 ; a <= r - 1 ; a ++ )
					dp[ 0 ][ l ][ r ] = Add( dp[ 0 ][ l ][ r ] , Mul( dp[ 1 ][ l ][ a ] , s[ a ][ r ] ) );
					
				for( int k = l + 1 ; k <= r - 2 ; k ++ )
					if( Check( k + 1 , r - 1 ) ) dp[ 1 ][ l ][ r ] = Add( dp[ 1 ][ l ][ r ] , Add( dp[ 0 ][ l + 1 ][ k ] , dp[ 1 ][ l + 1 ][ k ] ) );
				for( int k = r - 1 ; k >= l + 2 ; k -- )
					if( Check( l + 1 , k - 1 ) ) dp[ 1 ][ l ][ r ] = Add( dp[ 1 ][ l ][ r ] , Add( dp[ 0 ][ k ][ r - 1 ] , dp[ 1 ][ k ][ r - 1 ] ) );
			}
			for( int k = l + 1 ; k <= r - 1 ; k ++ ) s[ l ][ r ] = Add( s[ l ][ r ] , Check( l + 1 , k - 1 ) * Add( dp[ 0 ][ k ][ r ] , dp[ 1 ][ k ][ r ] ) );
		}
	printf("%d\n", Add( dp[ 0 ][ 1 ][ n ] , dp[ 1 ][ 1 ][ n ] ) );
	return 0;
}
/*
7 3
(*??*??

10 2
???(*??(?)

10 1
(()*()*())

*/
