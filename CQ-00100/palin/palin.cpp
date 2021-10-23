#include <cstdio>

#define rep( i, a, b ) for( int i = (a) ; i <= (b) ; i ++ )
#define per( i, a, b ) for( int i = (a) ; i >= (b) ; i -- )

const int MAXN = 1e6 + 5;

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

char lStk[MAXN], rStk[MAXN];
int lt, rt;

int pos[MAXN][2], side[MAXN];

int A[MAXN];
int N;

void Clear()
{
    rep( i, 1, N )
        pos[i][0] = pos[i][1] = 0;
    rep( i, 1, N * 2 ) side[i] = 0;
    lt = rt = 0;
}

bool Chk( const int mid, int lTop, int rTop )
{
    int bro;
    bool lef, rig;
    int lBut = mid - 1, rBut = mid + 1;
    while( lTop <= lBut || rBut <= rTop )
    {
        if( lTop <= lBut )
        {
            bro = pos[A[lTop]][side[lTop] ^ 1];
            lef = lTop <= lBut && bro == lBut;
            rig = rBut <= rTop && bro == rBut;
            if( lef || rig )
            {
                lTop ++;
                if( lef ) lBut --;
                if( rig ) rBut ++;
                continue;
            }
        }
        if( rBut <= rTop )
        {
            bro = pos[A[rTop]][side[rTop] ^ 1];
            lef = lTop <= lBut && bro == lBut;
            rig = rBut <= rTop && bro == rBut;
            if( lef || rig )
            {
                rTop --;
                if( lef ) lBut --;
                if( rig ) rBut ++;
                continue;
            }
        }
        return false;
    }
    return true;
}

bool Chk( const int num )
{
    int bro = pos[A[num]][side[num] ^ 1];
    return num == 1 ? Chk( bro, 2, N * 2 ) : Chk( bro, 1, N * 2 - 1 );
}

void Construct( const int brk )
{
    bool lef, rig;
    lStk[++ lt] = brk == 1 ? 'L' : 'R';
    rStk[++ rt] = 'L';
    int mid = pos[A[brk]][side[brk] ^ 1];
    int lTop, rTop, lBut = mid - 1, rBut = mid + 1, bro;
    if( brk == 1 ) lTop = 2, rTop = N * 2;
    else if( brk == N * 2 ) lTop = 1, rTop = N * 2 - 1;
    while( lTop <= lBut || rBut <= rTop )
    {
        if( lTop <= lBut )
        {
            bro = pos[A[lTop]][side[lTop] ^ 1];
            lef = lTop <= lBut && bro == lBut;
            rig = rBut <= rTop && bro == rBut;
            if( lef || rig )
            {
                lTop ++, lStk[++ lt] = 'L';
                if( lef ) rStk[++ rt] = 'L', lBut --;
                if( rig ) rStk[++ rt] = 'R', rBut ++;
                continue;
            }
        }
        if( rBut <= rTop )
        {
            bro = pos[A[rTop]][side[rTop] ^ 1];
            lef = lTop <= lBut && bro == lBut;
            rig = rBut <= rTop && bro == rBut;
            if( lef || rig )
            {
                rTop --, lStk[++ lt] = 'R';
                if( lef ) rStk[++ rt] = 'L', lBut --;
                if( rig ) rStk[++ rt] = 'R', rBut ++;
                continue;
            }
        }
    }
}

int main()
{
    freopen( "palin.in", "r", stdin );
    freopen( "palin.out", "w", stdout );
    int T; read( T );
    while( T -- )
    {
        read( N ), Clear();
        rep( i, 1, N * 2 ) 
        {
            read( A[i] );
            pos[A[i]][side[i] = ( bool ) pos[A[i]][0]] = i;
        }
        // BIG NOTE: SHOULD MINIMIZE THE RANK OF THE OP SEQUENCE !!!!
        bool flg = false;
        if( Chk( 1 ) ) Construct( 1 ), flg = true;
        else if( Chk( N * 2 ) ) Construct( N * 2 ), flg = true;
        if( ! flg ) puts( "-1" );
        else
        {
            rep( i, 1, lt ) putchar( lStk[i] );
            per( i, rt, 1 ) putchar( rStk[i] );
            puts( "" );
        }
    }
    return 0;
}