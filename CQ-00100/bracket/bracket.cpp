#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int mod = 1e9 + 7;
const int MAXN = 505;

template<typename _T>
void read( _T &x )
{
    x = 0; char s = getchar(); bool f = false;
    while( s < '0' || '9' < s ) { f = s == '-', s = getchar(); }
    while( '0' <= s && s <= '9' ) { x = ( x << 3 ) + ( x << 1 ) + ( s - '0' ), s = getchar(); }
    if( f ) x = -x;
}

template<typename _T>
void write( _T x )
{
    if( x < 0 ) putchar( '-' ), x = -x;
    if( 9 < x ) write( x / 10 );
    putchar( x % 10 + '0' );
}

template<typename _T>
_T MIN( const _T a, const _T b )
{
    return a < b ? a : b;
}

int f[MAXN][MAXN], g[MAXN][MAXN], suG[MAXN][MAXN];
// g[][] state must be surrounded by ()

int cnt[MAXN];
int rig[MAXN];

char str[MAXN];
int N, K;

inline int Mul( int x, int v ) { return 1ll * x * v % mod; }
inline int Sub( int x, int v ) { return ( x -= v ) < 0 ? x + mod : x; }
inline int Add( int x, int v ) { return ( x += v ) >= mod ? x - mod : x; }
inline void Upt( int &x, const int v ) { x = Add( x, v ); }

bool LeftBra( const int x ) { return str[x] == '(' || str[x] == '?'; }
bool RightBra( const int x ) { return str[x] == ')' || str[x] == '?'; }
bool Legal( const int l, const int r ) { return cnt[r] - cnt[l - 1] == 0 && r - l + 1 <= K; }

int main()
{
    freopen( "bracket.in", "r", stdin );
    freopen( "bracket.out", "w", stdout );
    read( N ), read( K );
    scanf( "%s", str + 1 );
    rep( i, 1, N ) cnt[i] = cnt[i - 1] + ( str[i] == '(' || str[i] == ')' );
    // dp[i][j] > 0 if and only if s_i can be '(' and s_j can be ')'

    for( int i = 1 ; i <= N ; i ++ )
        for( int j = i + 1 ; j <= N ; j ++ )
            if( j == i + 1 || Legal( i + 1, j - 1 ) )
                rig[i] = j;

    per( i, N, 1 )
    {
        if( ! LeftBra( i ) )
        {
            rep( j, i, N ) suG[i][j] = suG[i + 1][j];
            continue;
        }
        f[i][i + 1] = g[i][i + 1] = RightBra( i + 1 );
        // ()
        rep( j, i + 2, N )
        {
            if( ! RightBra( j ) ) continue;
            f[i][j] = g[i][j] = Legal( i + 1, j - 1 );
            // (S) or not

            // rep( a, i + 1, j - 2 )
            //     rep( b, a + 1, j - 1 )
            //         if( b == a + 1 || Legal( a + 1, b - 1 ) )
            //             Upt( f[i][j], Mul( f[i][a], g[b][j] ) );
            rep( a, i + 1, j - 2 ) if( rig[a] > a )
            {
                int lim = MIN( rig[a], j - 1 );
                Upt( f[i][j], Mul( f[i][a], Sub( suG[a + 1][j], suG[lim + 1][j] ) ) );
                // ( a, lim ]
            }
            // AB or ASB
            Upt( f[i][j], f[i + 1][j - 1] );
            Upt( g[i][j], f[i + 1][j - 1] );
            rep( k, i + 2, j - 1 )
                if( Legal( i + 1, k - 1 ) )
                {
                    Upt( f[i][j], f[k][j - 1] );
                    Upt( g[i][j], f[k][j - 1] );
                }
            rep( k, i + 1, j - 2 )
                if( Legal( k + 1, j - 1 ) )
                {
                    Upt( f[i][j], f[i + 1][k] );
                    Upt( g[i][j], f[i + 1][k] );
                }
            // (A) or (SA) or (AS)
        }
        rep( j, i, N ) 
			suG[i][j] = Add( suG[i + 1][j], g[i][j] );
    }
    write( f[1][N] ), putchar( '\n' );
    return 0;
}
