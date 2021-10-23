#include <cstdio>
#define maxn 500005
int T, n, flag;
int a[maxn], num[maxn], op[maxn], cnt[maxn];

void dfs2( int x, int l, int r ) {
	if( flag ) return;
	if( x == 1 ) {
		op[n + n] = 0;
		flag = 1;
		return;
	}
	if( a[l] == num[x] ) op[n + n - x + 1] = 0, dfs2( x - 1, l + 1, r );
	if( a[r] == num[x] ) op[n + n - x + 1] = 1, dfs2( x - 1, l, r - 1 );
}

void dfs1( int x, int l, int r ) {
	if( flag ) return;
	
	if( x > n ) {
		flag = 0;
		dfs2( n, l, r );
		return;
	}
	
	op[x] = 0;
	num[x] = a[l];
	cnt[a[l]] ++;
	if( cnt[a[l]] == 1 ) dfs1( x + 1, l + 1, r );
	cnt[a[l]] --;
	
	if( flag ) return;
	
	op[x] = 1;
	num[x] = a[r];
	cnt[a[r]] ++;
	if( cnt[a[r]] == 1 ) dfs1( x + 1, l, r - 1 );
	cnt[a[r]] --;
	
	if( flag ) return;
}

void subtask1() {
	flag = 0;
	dfs1( 1, 1, n << 1 );
	if( flag ) {
		for( int i = 1;i <= ( n << 1 );i ++ ) 
			if( op[i] ) printf( "R" ); 
			else printf( "L" );
	}
	else printf( "-1" );
	printf( "\n" );
}

int main() {
	freopen( "palin.in", "r", stdin );
	freopen( "palin.out", "w", stdout );
	scanf( "%d", &T );
	while( T -- ) {
		scanf( "%d", &n );
		for( int i = 1;i <= ( n << 1 );i ++ ) scanf( "%d", &a[i] );
		if( n <= 20 ) subtask1();
		else {
			flag = 1;
			for( int i = 1;i <= n;i ++ ) 
				if( a[i] ^ a[n + n - i + 1] ) {
					flag = 0;
					break;
				}
			if( flag ) for( int i = 1;i <= ( n << 1 );i ++ ) printf( "L" );
			else printf( "-1" );
			printf( "\n" );
		}
	}
	return 0;
}
