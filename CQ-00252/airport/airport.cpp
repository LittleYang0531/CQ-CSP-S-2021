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

const int maxn = 100000;

namespace saya {

    int mn[maxn << 2 | 2];

#define ls (i << 1)
#define rs (i << 1 | 1)
#define mid ((l + r) >> 1)
#define _lhs ls, l, mid
#define _rhs rs, mid + 1, r

    void build(int i, int l, int r) {
        mn[i] = 0;
        if(l == r) return;
        build(_lhs), build(_rhs);
    }
    inline void pushup(int i) { mn[i] = min(mn[ls], mn[rs]); }
    int query(int val, int changeto, int i, int l, int r) {
        if(l == r) { // here it is
            mn[i] = changeto;
            return l;
        }
        int ret = -1;
        if(mn[ls] < val) ret = query(val, changeto, _lhs);
        else ret = query(val, changeto, _rhs);
        return pushup(i), ret;
    }

#undef ls
#undef rs
#undef mid
#undef _lhs
#undef _rhs

}

inline void solve(int* f, vector<pii>& plane, int n, int m) {
    sort(plane.begin(), plane.end(), [](const pii& a, const pii& b) {
        return a.fi < b.fi;
    });
    saya::build(1, 1, n);
    for(int i = 0; i < m; ++i) {
        // enough position
        if(saya::mn[1] < plane[i].fi) {
            int pos = saya::query(plane[i].fi, plane[i].se, 1, 1, n);
            ++f[pos];
        }
    }
    for(int i = 1; i <= n; ++i) f[i] += f[i - 1];
}

int n, m1, m2;
vector<pii> in, out;

inline void input() {
    readin(n, m1, m2);
    int a, b;
    rep(i, 1, m1) {
        readin(a, b);
        in.push_back({a, b});
    }
    rep(i, 1, m2) {
        readin(a, b);
        out.push_back({a, b});
    }
}

int prein[maxn + 5], preout[maxn + 5];

signed main() {
    freopen("airport.in", "r", stdin);
    freopen("airport.out", "w", stdout);
    input();
    // puts("finished part 1");
    solve(prein, in, n, m1);
    solve(preout, out, n, m2);
    int ans = 0;
    for(int i = 0; i <= n; ++i)
        getmax(ans, prein[i] + preout[n - i]);
    printf("%d\n", ans);
    return 0;
}