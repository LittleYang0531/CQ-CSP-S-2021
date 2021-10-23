#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
using namespace std;
#define int long long
#define maxn 505
struct node {
	int val, x, y, c;
	bool operator < ( const node &t ) const {
		return val > t.val;
	}
};
priority_queue < node > q;
int n, m, T;
int row[maxn][maxn], col[maxn][maxn], color[maxn][maxn];
int w[maxn], id[maxn], c[maxn];
int dx[4] = { 1, -1, 0, 0 }, dy[4] = { 0, 0, 1, -1 };

bool inside( int x, int y ) {
	if( x < 1 or x > n or y < 1 or y > m ) return 0;
	return 1;
}

signed main() {
	freopen( "traffic.in", "r", stdin );
	freopen( "traffic.out", "w", stdout );
	scanf( "%lld %lld %lld", &n, &m, &T );
	for( int i = 1;i < n;i ++ )
		for( int j = 1;j <= m;j ++ )
			scanf( "%lld", &row[i][j] );
	for( int i = 1;i <= n;i ++ )
		for( int j = 1;j < m;j ++ )
			scanf( "%lld", &col[i][j] );
	while( T -- ) {
		int K;
		scanf( "%lld", &K );
		for( int i = 1;i <= K;i ++ )
			scanf( "%lld %lld %lld", &w[i], &id[i], &c[i] );
		if( c[1] == c[2] ) printf( "0\n" );
		else {
			int ans = min( w[1], w[2] ), sum = 0;
			int row1, col1, row2, col2;
			if( id[1] <= m ) row1 = 1, col1 = id[1];
			else if( id[1] <= n + m ) row1 = id[1] - m, col1 = m;
			else if( id[1] <= n + m + m ) row1 = n, col1 = 2 * m + n - id[1];
			else row1 = 2 * m + 2 * n + 1 - id[1], col1 = 1;
			
			if( id[2] <= m ) row2 = 1, col2 = id[2];
			else if( id[2] <= n + m ) row2 = id[2] - m, col2 = m;
			else if( id[2] <= n + m + m ) row2 = n, col2 = 2 * m + n - id[2];
			else row2 = 2 * m + 2 * n + 1 - id[2], col2 = 1;
			
			memset( color, -1, sizeof( color ) );
			color[row1][col1] = c[1], color[row2][col2] = c[2];
			
			if( inside( row1 - 1, col1 ) ) q.push( { row[row1 - 1][col1], row1 - 1, col1, c[1] } );
			if( inside( row1 + 1, col1 ) ) q.push( { row[row1][col1], row1 + 1, col1, c[1] } );
			if( inside( row1, col1 - 1 ) ) q.push( { col[row1][col1 - 1], row1, col1 - 1, c[1] } );
			if( inside( row1, col1 + 1 ) ) q.push( { col[row1][col1], row1, col1 + 1, c[1] } );
			
			if( inside( row2 - 1, col2 ) ) q.push( { row[row2 - 1][col2], row2 - 1, col2, c[2] } );
			if( inside( row2 + 1, col2 ) ) q.push( { row[row2][col2], row2 + 1, col2, c[2] } );
			if( inside( row2, col2 - 1 ) ) q.push( { col[row2][col2 - 1], row2, col2 - 1, c[2] } );
			if( inside( row2, col2 + 1 ) ) q.push( { col[row2][col2], row2, col2 + 1, c[2] } );
			
			while( ! q.empty() ) {
				node now = q.top(); q.pop();
				int x = now.x, y = now.y, c = now.c;
				color[x][y] = c;
				if( color[x - 1][y] == -1 and inside( x - 1, y ) ) q.push( { row[x - 1][y], x - 1, y, c } );
				if( color[x + 1][y] == -1 and inside( x + 1, y ) ) q.push( { row[x][y], x + 1, y, c } );
				if( color[x][y - 1] == -1 and inside( x, y - 1 ) ) q.push( { col[x][y - 1], x, y - 1, c } );
				if( color[x][y + 1] == -1 and inside( x, y + 1 ) ) q.push( { col[x][y], x, y + 1, c } );
			}
			
			for( int i = 1;i <= n;i ++ )
				for( int j = 1;j <= m;j ++ ) {
					if( i < n and color[i][j] ^ color[i + 1][j] ) sum += row[i][j];
					if( j < m and color[i][j] ^ color[i][j + 1] ) sum += col[i][j];
				}
				
			printf( "%lld\n", min( sum, ans ) );
		}
	}
	return 0;
}
