// #ifdef TIME_MESSURE
// #include <ctime>
// #endif

#include <cstdio>
#include <utility>
#include <algorithm>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 2e5 + 5;

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

template<typename _T>
_T MAX( const _T a, const _T b )
{
    return a > b ? a : b;
}

struct Event
{
    int t, delt, id;

    Event(): t( 0 ), delt( 0 ), id( 0 ) {}
    Event( int T, int D, int I ): t( T ), delt( D ), id( I ) {}
    bool operator < ( const Event &q ) const { return t == q.t ? delt < q.delt : t < q.t; }
};

Event dom[MAXN], inter[MAXN];

int domPre[MAXN], interPre[MAXN];

int BIT[MAXN];
int domTim[MAXN], interTim[MAXN];

int tot1, tot2;
int N, M1, M2;

inline void Up( int &x ) { x += x & ( -x ); }
inline void Down( int &x ) { x -= x & ( -x ); }
inline void Clear() { rep( i, 0, N ) BIT[i] = 0; }
inline void Update( int x, int v ) { for( ; x <= N ; Up( x ) ) BIT[x] += v; }
inline int Query( int x ) { int ret = 0; for( ; x ; Down( x ) ) ret += BIT[x]; return ret; }

int main()
{
    freopen( "airport.in", "r", stdin );
    freopen( "airport.out", "w", stdout );
    read( N ), read( M1 ), read( M2 );
    rep( i, 1, M1 )
    {
        int a, b;
        read( a ), read( b );
        dom[++ tot1] = Event( a, 1, i );
        dom[++ tot1] = Event( b, -1, i );
    }
    rep( i, 1, M2 )
    {
        int a, b;
        read( a ), read( b );
        inter[++ tot2] = Event( a, 1, i );
        inter[++ tot2] = Event( b, -1, i );
    }
    std :: sort( dom + 1, dom + 1 + tot1 );
    std :: sort( inter + 1, inter + 1 + tot2 );

    Clear();
    rep( i, 1, tot1 )
    {
        int u = dom[i].id;
        if( dom[i].delt == 1 )
        {
            if( Query( N ) + 1 > N ) 
                domTim[u] = N + 1;
            // not able to land.
            else
            {
                int l = 1, r = N, mid;
                while( l < r )
                {
                    mid = ( l + r ) >> 1;
                    if( Query( mid ) + 1 <= mid ) r = mid;
                    else l = mid + 1;
                }
                Update( domTim[u] = l, 1 );
            }
            // O( m log^2 n ), enough
        }
        else if( domTim[u] <= N )
            Update( domTim[u], -1 );
    }
    Clear();
    rep( i, 1, tot2 )
    {
        int u = inter[i].id;
        if( inter[i].delt == 1 )
        {
            if( Query( N ) + 1 > N )
                interTim[u] = N + 1;
            else
            {
                int l = 1, r = N, mid;
                while( l < r )
                {
                    mid = ( l + r ) >> 1;
                    if( Query( mid ) + 1 <= mid ) r = mid;
                    else l = mid + 1;
                }
                Update( interTim[u] = l, 1 );
            }
        }
        else if( interTim[u] <= N )
            Update( interTim[u], -1 );
    }
    int ans = 0;
    rep( i, 1, M1 ) domPre[domTim[i]] ++;
    rep( i, 1, M2 ) interPre[interTim[i]] ++;
    rep( i, 1, N ) domPre[i] += domPre[i - 1];
    rep( i, 1, N ) interPre[i] += interPre[i - 1];
    rep( i, 0, N ) ans = MAX( ans, domPre[i] + interPre[N - i] );
    write( ans ), putchar( '\n' );
// #ifdef TIME_MESSURE
//     fprintf( stderr, "Run time: %.3fs\n", 1.0 * clock() / CLOCKS_PER_SEC );
// #endif
    return 0;
}