#include <bits/stdc++.h>
using namespace std;
template<typename L, typename R>
L& maximize(L& l, const R& r) {
  return l < r ? l = r : l;
}
template<typename L, typename R>
L& minimize(L& l, const R& r) {
  return l > r ? l = r : l;
}
#define int long long
#define moL(expr) [&](auto&& _) {return expr;}
#define compL(expr) [&](auto&& _1, auto&& _2) {return expr;}
constexpr int maxn = 510, maxm = maxn * maxn * 2;
struct Edge {
  int v, w, nxt;
} edgs[maxm];
int newp = 1, head[maxn * maxn], cur[maxn * maxn];
inline void addEdge(int u, int v, int w) {
  edgs[++newp] = {v, w, head[u]};
  head[u] = newp;
}
int n, m;

void clear() {
  memset(edgs, 0, sizeof(edgs));
  memset(head, 0, sizeof(head));
  newp = 1;
}
int S, T;
int dis[maxn * maxn];
bool bfs() {
  memset(dis, 0, sizeof(dis));
  memcpy(cur, head, sizeof(head));
  queue<int> q;
  q.push(S);
  dis[S] = 1;
  while (!q.empty()) {
    const int u = q.front();
    q.pop();
    for (int i = head[u]; i; i = edgs[i].nxt) {
      const int v = edgs[i].v, w = edgs[i].w;
      if (dis[v] || !w)
        continue;
      dis[v] = dis[u] + 1;
      q.push(v);
    }
  }
  return dis[T];
}
int dfs(int u, int delta) {
  if (u == T)
    return delta;
  int pasf = 0;
  for (int &i = cur[u]; i && delta > 0; i = edgs[i].nxt) {
    const int v = edgs[i].v, w = edgs[i].w;
    if (dis[v] != dis[u] + 1)
      continue;
    const int f = dfs(v, min(delta, w));
    delta -= f;
    pasf += f;
    edgs[i].w -= f;
    edgs[i ^ 1].w += f;
  }
  return pasf;
}
int mcmf() {
  int ans = 0;
  while (bfs()) {
    const int del = dfs(S, INT_MAX); 
    ans += del;
    if (!del)
      return ans;
  }
  return ans;
}
int down[maxn][maxn], rgt[maxn][maxn];
int id(int x, int y) {
  return (x - 1) * m + y;
}
int trans(int x) {
  if (x <= m)
    return id(1, x);
  else if (x <= n + m)
    return id(x - m, m);
  else if (x <= 2 * m + n)
    return id(n, 2 * m + n - x + 1);
  else
    return id(2 * (m + n) - x + 1, 1);
}
int32_t main() {
  freopen("traffic.in", "r", stdin);
  freopen("traffic.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int ta;
  cin >> n >> m >> ta;
  for (int i = 1; i < n; ++i) {
    for (int j = 1; j <= m; ++j)
      cin >> down[i][j];
  }
  for (int i = 1; i <= n; ++i) {
    for (int j = 1; j < m; ++j)
      cin >> rgt[i][j];
  }
  while (ta--) {
    clear();
    int k, a[2], w[2], col[2];
    cin >> k;
    for (int i = 0; i < k; ++i)
      cin >> w[i] >> a[i] >> col[i];
    if (col[1] == col[0]) {
      cout << 0 << '\n';
      continue;
    }
    S = n * m + 1, T = n * m + 2;
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= m; ++j)  {
        if (i < n) {
          addEdge(id(i, j), id(i + 1, j), down[i][j]);
        addEdge(id(i + 1, j), id(i, j), down[i][j]);
        }
        if (j < m) {
          addEdge(id(i, j + 1), id(i, j), rgt[i][j]);
        addEdge(id(i, j), id(i, j + 1), rgt[i][j]);
        }
        
      }
    }
    addEdge(S, trans(a[0]), w[0]);
    addEdge(trans(a[0]), S, 0);
    addEdge(trans(a[1]), T, w[1]);
    addEdge(T, trans(a[1]), 0);
    cout << mcmf() << '\n';
  }
  return 0;
}
