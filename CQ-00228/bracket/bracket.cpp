#include <cstdio>
#define maxn 505
#define int long long
#define mod 1000000007
int n, m;
char s[maxn];
int f[maxn][maxn], dp[maxn][maxn];
bool g[maxn][maxn];

signed main() {
	freopen( "bracket.in", "r", stdin );
	freopen( "bracket.out", "w", stdout );
	scanf( "%lld %lld %s", &n, &m, s + 1 );
	for( int i = 1;i <= n;i ++ ) {
		if( s[i] == '*' or s[i] == '?' ) g[i][i] = 1;
		g[i][i - 1] = 1;
	}
	//g[i][j]:i-j这一段能否全为** 
	for( int len = 2;len <= m;len ++ )
		for( int i = 1;i + len - 1 <= n;i ++ ) {
			int j = i + len - 1;
			if( s[i] == '*' or s[i] == '?' ) g[i][j] |= g[i + 1][j];
			if( s[j] == '*' or s[j] == '?' ) g[i][j] |= g[i][j - 1];
		}
	for( int i = 1;i < n;i ++ )
		if( s[i] == ')' or s[i] == '*' or s[i + 1] == '(' or s[i + 1] == '*' ) continue;
		else f[i][i + 1] = dp[i][i + 1] = 1;
	//f[i,j]:i为左括号 j为右括号的合法超级序列方案数 强制i,j匹配 dp[i,j]无所谓 
	for( int len = 3;len <= n;len ++ ) 
		for( int i = 1;i + len - 1 <= n;i ++ ) {
			int j = i + len - 1;
			
			if( s[i] == ')' or s[i] == '*' or s[j] == '(' or s[j] == '*' ) continue;
			
			f[i][j] = ( f[i][j] + dp[i + 1][j - 1] ) % mod; //括号嵌括号 
			
			if( j - 1 - ( i + 1 ) + 1 <= m ) f[i][j] = ( f[i][j] + g[i + 1][j - 1] ) % mod; //括号嵌** 
			
//			printf( "\nf[%d][%d]:\n", i, j );
			for( int k = i + 2;k < j - 1;k ++ ) //左边一段全是* 
				if( k - 1 - ( i + 1 ) + 1 > m ) break;
				else 
//				printf( "(%d %d)  **{%d %d}:g=%d  +%d\n", k, j - 1, i + 1, k - 1, g[i + 1][k - 1], f[k][j - 1] ),
					f[i][j] = ( f[i][j] + g[i + 1][k - 1] * dp[k][j - 1] ) % mod;
			for( int k = j - 2;k > i + 1;k -- ) //右边一段全是* 
				if( ( j - 1 ) - ( k + 1 ) + 1 > m ) break;
				else 
//				printf( "(%d %d)  **{%d %d}:g=%d  +%d\n", i+1,k,k+1,j-1,g[k+1][j-1],f[i+1][k]),
					f[i][j] = ( f[i][j] + g[k + 1][j - 1] * dp[i + 1][k] ) % mod;
			
//			printf( "[%lld, %lld] ------ %lld[][]\n", i, j, f[i][j] );
				
			for( int k = i + 1;k < j - 1;k ++ ) //匹配不同()**() 
				for( int t = 0;t <= m;t ++ )
					if( k + t + 1 >= j ) break;
					else 
//					printf( "%lld %lld %lld |||| %lld %lld %lld ||| [%d]\n", i, k, f[i][k], k + t + 1, j, f[k + t + 1][j], g[k + 1][k + t] ),
						dp[i][j] = ( dp[i][j] + f[i][k] * dp[k + t + 1][j] * g[k + 1][k + t] ) % mod;
				
//			printf( "[%lld, %lld] ------ %lld[][]%lld\n", i, j, f[i][j], dp[i][j] );
			dp[i][j] = ( dp[i][j] + f[i][j] ) % mod;
				
		}
	printf( "%lld\n", dp[1][n] );
	return 0;
}
