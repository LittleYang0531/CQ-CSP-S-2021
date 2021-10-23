#include <cstdio>

const int MAXN = 1e6;
int T , n , a[ MAXN + 5 ] , b[ MAXN + 5 ];

bool f; char op[ MAXN + 5 ] , Ans[ MAXN + 5 ];
bool Check( ) {
	for( int i = 1 , l = 1 , r = 2 * n ; i <= 2 * n ; i ++ ) {
		if( op[ i ] == 'L' ) b[ i ] = a[ l ++ ];
		if( op[ i ] == 'R' ) b[ i ] = a[ r -- ];	
	}
	for( int i = 1 ; i <= n ; i ++ ) if( b[ i ] != b[ 2 * n - i + 1 ] ) return 0;
	return 1;
}
void dfs( int pos ) {
	if( pos == 2 * n + 1 ) {
		if( Check() ) {
			if( !f ) {
				f = 1;
				for( int i = 1 ; i <= 2 * n ; i ++ ) Ans[ i ] = op[ i ];
			}
			else {
				bool chk;
				for( int i = 1 ; i <= 2 * n ; i ++ ) {
					if( Ans[ i ] != op[ i ] ) {
						chk = ( Ans[ i ] > op[ i ] );
						break;
					}
				}				
				if( chk ) {
					for( int i = 1 ; i <= 2 * n ; i ++ ) Ans[ i ] = op[ i ];
				}
			}
		}
		return;
	}
	op[ pos ] = 'L'; dfs( pos + 1 );
	op[ pos ] = 'R'; dfs( pos + 1 );
}

int main( ) {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	scanf("%d",&T);
	while( T -- ) {
		scanf("%d",&n);
		for( int i = 1 ; i <= 2 * n ; i ++ ) scanf("%d",&a[ i ]);
		if( n <= 10 ) {
			f = 0; dfs( 1 );
			if( f ) {
				for( int i = 1 ; i <= 2 * n ; i ++ ) printf("%c", Ans[ i ] ); puts("");
			}
			else printf("-1\n");
		}
		else {
			for( int i = 1 ; i <= 2 * n ; i ++ ) putchar( i <= n ? 'L' : 'R' ); puts("");
		}
	}
	return 0;
}
