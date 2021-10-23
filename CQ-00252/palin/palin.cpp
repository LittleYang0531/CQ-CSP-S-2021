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

const int maxn = 5e5 * 2;

int a[maxn + 5], n;

inline void input() {
    readin(n); n <<= 1;
    rep(i, 1, n) readin(a[i]);
}

char ans[maxn + 5];
bool yes;
int b[maxn + 5];
inline void check() {
    int pl = 1, pr = n;
    rep(i, 1, n) {
        if(ans[i] == 'L') b[i] = a[pl++];
        else b[i] = a[pr--];
    }
    pl = 1, pr = n;
    while(pl < pr) {
        if(b[pl] != b[pr]) return;
        ++pl, --pr;
    }
    yes = true;
}
void dfs(int pos) {
    if(pos == n + 1) return check();
    ans[pos] = 'L';
    dfs(pos + 1);
    if(yes) return;
    ans[pos] = 'R';
    dfs(pos + 1);
}

inline void work() {
    input();
    yes = false;
    dfs(1);
    if(!yes) puts("-1");
    else puts(ans + 1);
}

signed main() {
    freopen("palin.in", "r", stdin);
    freopen("palin.out", "w", stdout);
    rep(_, 1, readret(1)) work();
    return 0;
}