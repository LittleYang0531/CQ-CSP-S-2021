#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXV = 1e6 + 5, MAXE = 5e6 + 5, MAXN = 505;

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

int down[MAXN][MAXN], rig[MAXN][MAXN];

int N, M, K;

namespace Flow
{
    const int INF = 0x3f3f3f3f;

    struct Edge
    {
        int to, nxt, c;
    }Graph[MAXE << 1];

    int q[MAXV];

    int head[MAXV], cur[MAXV], dep[MAXV];
    int tot, cnt;

    void AddEdge( const int from, const int to, const int C )
    {
        Graph[++ cnt].to = to, Graph[cnt].nxt = head[from];
        Graph[cnt].c = C, head[from] = cnt;
    }

    void AddE( const int from, const int to, const int C )
    { AddEdge( from, to, C ), AddEdge( to, from, 0 ); }

    void AddEUndir( const int from, const int to, const int C )
    { AddEdge( from, to, C ), AddEdge( to, from, C ); }

    void Clear( const int n )
    {
        tot = n, cnt = 1;
        rep( i, 1, tot ) head[i] = 0;
    }

    bool BFS( const int S, const int T )
    {
        int h = 1, t = 0, u, v;
        rep( i, 1, tot ) dep[i] = INF;
        dep[q[++ t] = S] = 0;
        while( h <= t )
        {
            u = q[h ++];
            for( int i = head[u] ; i ; i = Graph[i].nxt )
                if( Graph[i].c && dep[v = Graph[i].to] > dep[u] + 1 )
                    dep[q[++ t] = v] = dep[u] + 1;
        }
        return dep[T] < INF;
    }

    int DFS( const int u, const int lin, const int T )
    {
        if( u == T ) return lin;
        int ret, used = 0, v, c;
        for( int &i = cur[u] ; i ; i = Graph[i].nxt )
        {
            v = Graph[i].to, c = Graph[i].c;
            if( c && dep[v] == dep[u] + 1 && ( ret = DFS( v, MIN( lin - used, c ), T ) ) )
            {
                used += ret, Graph[i].c -= ret, Graph[i ^ 1].c += ret;
                if( used == lin ) break;
            }
        }
        if( used < lin ) dep[u] = INF;
        return used;
    }

    int Dinic( const int S, const int T )
    {
        int ret = 0;
        while( BFS( S, T ) )
        {
            rep( i, 1, tot ) cur[i] = head[i];
            ret += DFS( S, INF, T );
        }
        return ret;
    }
}

#define ID( x, y ) ( ( (x) - 1 ) * M + y )

void Solve()
{
    read( K );
    int &ntot = Flow :: tot;
    ntot = N * M + K;
    const int s = ++ ntot, t = ++ ntot;
    Flow :: Clear( ntot );
    rep( i, 1, N - 1 ) rep( j, 1, M )
        Flow :: AddEUndir( ID( i, j ), ID( i + 1, j ), down[i][j] );
    rep( i, 1, N ) rep( j, 1, M - 1 )
        Flow :: AddEUndir( ID( i, j ), ID( i, j + 1 ), rig[i][j] );
    rep( i, 1, K )
    {
        int coe, pos, col;
        read( coe ), read( pos ), read( col );
        if( 1 <= pos && pos <= M )
            Flow :: AddEUndir( N * M + i, ID( 1, pos ), coe );
        else if( pos <= N + M )
            Flow :: AddEUndir( N * M + i, ID( pos - M, M ), coe );
        else if( pos <= 2 * M + N )
            Flow :: AddEUndir( N * M + i, ID( N, ( M + 1 ) - ( pos - N - M ) ), coe );
        else 
            Flow :: AddEUndir( N * M + i, ID( ( N + 1 ) - ( pos - 2 * M - N ), 1 ), coe );
        if( ! col ) Flow :: AddE( s, N * M + i, Flow :: INF );
        else Flow :: AddE( N * M + i, t, Flow :: INF );
    }
    write( Flow :: Dinic( s, t ) ), putchar( '\n' );
}

int main()
{
    freopen( "traffic.in", "r", stdin );
    freopen( "traffic.out", "w", stdout );
    int T;
    read( N ), read( M ), read( T );
    rep( i, 1, N - 1 ) rep( j, 1, M )
        read( down[i][j] );
    rep( i, 1, N ) rep( j, 1, M - 1 )
        read( rig[i][j] );
    while( T -- ) Solve();
    return 0;
}