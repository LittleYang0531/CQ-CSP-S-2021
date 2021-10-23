#include <bits/stdc++.h>
using namespace std;

// #define NDEBUG

namespace Elaina {

#define rep(i, l, r) for(int i = l, i##_end_ = r; i <= i##_end_; ++i)
#define drep(i, l, r) for(int i = l, i##_end_ = r; i >= i##_end_; --i)
#define fi first
#define se second
#define Endl putchar('\n')

    typedef long long ll;
    typedef std::pair<int, int> pii;

    template<class T> inline T fab(T x) { return x < 0 ? -x : x; }
    template<class T> inline void getmax(T& x, const T& rhs) { x = max(x, rhs); }
    template<class T> inline void getmin(T& x, const T& rhs) { x = min(x, rhs); }

    template<class T> inline T readret(T x) {
        x = 0; char c; bool f = false;
        while((c = getchar()) < '0' || '9' < c) if(c == '-') f = true;
        for(x = (c ^ 48); '0' <= (c = getchar()) && c <= '9'; x = (x << 1) + (x << 3) + (c ^ 48));
        return f ? -x : x;
    }
    template<class T> inline void readin(T& x) {
        x = 0; char c; bool f = false;
        while((c = getchar()) < '0' || '9' < c) if(c == '-') f = true;
        for(x = (c ^ 48); '0' <= (c = getchar()) && c <= '9'; x = (x << 1) + (x << 3) + (c ^ 48));
        if(f) x = -x;
    }
    template<class T, class... Args> inline void readin(T& x, Args&... args) {
        readin(x), readin(args...);
    }

} using namespace Elaina;

signed main() {
    // freopen("bracket.in", "r", stdin);
    // freopen("bracket.out", "w", stdout);
    
    return 0;
}