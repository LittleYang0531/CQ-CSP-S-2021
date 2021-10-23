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
#define moL(expr) [&](auto&& _) {return expr;}
#define compL(expr) [&](auto&& _1, auto&& _2) {return expr;}
constexpr int maxn = 504, mods = 1e9 + 7;
#define int int64_t
int f[maxn][maxn][2][2], g[maxn][maxn], h[maxn][maxn];
char str[maxn];
inline bool pcm(char a, char b) {
  return a == '?' || a == b;
}
int32_t main() {
  freopen("bracket.in", "r", stdin);
  freopen("bracket.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, k;
  cin >> n >> k;
  cin >> (str + 1);
  for (int i = 1; i <= n + 1; ++i) {
    h[i][i - 1] = 1;
    for (int j = i; j <= n && j <= i + k - 1; ++j) {
      f[i][j][1][1] = h[i][j] = h[i][j - 1] && pcm(str[j], '*');
    }
  }
  for (int i = 1; i <= n; ++i)
    f[i][i][1][1] = h[i][i];
  for (int l = 1; l < n; ++l) {
    for (int i = 1; i + l <= n; ++i) {
      const int j = i + l;
      for (int s = 1; s < l - 1; ++s) {
        (g[i][j] += h[i + 1][i + s] * f[i + s + 1][j - 1][0][0]) %= mods;
        (g[i][j] += h[j - s + 1][j - 1] * f[i + 1][j - s][0][0]) %= mods;
      }
        g[i][j] += h[i + 1][j - 1];
      f[i][j][0][0] = g[i][j] = (pcm(str[i], '(') && pcm(str[j], ')') ? g[i][j] : 0);
      for (int s = i + 1; s <= j; ++s) {
        (f[i][j][0][0] += (f[i][s - 1][0][0] + f[i][s - 1][0][1]) * g[s][j]) %= mods;
        (f[i][j][0][1] += (f[i][s - 1][0][0]) * h[s][j]) %= mods;
        (f[i][j][1][0] += (f[i][s - 1][1][0] + f[i][s - 1][1][1]) * g[s][j]) %= mods;
        (f[i][j][1][1] += (f[i][s - 1][1][0]) * h[s][j]) %= mods;
      }
    }
  }
  cout << f[1][n][0][0] << '\n';
  return 0;
}
