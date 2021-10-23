#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define pii pair< int , int >
#define fi first
#define sc second
#define mp make_pair
#define iter set< pii >::iterator

const int MAXN = 1e5 , Inf = 0x3f3f3f3f;
int n , m[ 2 ] , val[ 2 ][ MAXN + 5 ];
pii p[ 2 ][ MAXN + 5 ];

set< pii > S[ 2 ];
void Solve( bool f ) {
	sort( p[ f ] + 1 , p[ f ] + m[ f ] + 1 );
	for( int i = 1 ; !S[ f ].empty() ; i ++ ) {
		int lst = 0;
		do {
			iter it = S[ f ].lower_bound( mp( lst , 0 ) );
			if( it == S[ f ].end() ) break;
			val[ f ][ i ] ++; lst = it->sc; S[ f ].erase( it );
		}while( 1 );
		val[ f ][ i ] += val[ f ][ i - 1 ];//printf("%d %d %d\n", f , i , val[ f ][ i ] );
	}
}
int main( ) {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	scanf("%d %d %d",&n,&m[ 0 ],&m[ 1 ]);
	for( int i = 1 , l , r ; i <= m[ 0 ] ; i ++ ) scanf("%d %d",&l,&r) , S[ 0 ].insert( mp( l , r ) );
	for( int i = 1 , l , r ; i <= m[ 1 ] ; i ++ ) scanf("%d %d",&l,&r) , S[ 1 ].insert( mp( l , r ) );
	Solve( 0 ); Solve( 1 );
	int Ans = 0;
	for( int i = 0 ; i <= n ; i ++ ) Ans = max( Ans , val[ 0 ][ i ] + val[ 1 ][ n - i ] );
	printf("%d\n", Ans );
	return 0;
}
