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
constexpr int maxb = 1e8 + 4, maxn = 1e5 + 4;
int main() {
  freopen("airport.in", "r", stdin);
  freopen("airport.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int n, p, q;
  cin >> n >> p >> q;
  vector<pair<int, int>> as(p), bs(q);
  vector<int> aa(n + 1), bb(n + 1);
  for (auto& v : as)
    cin >> v.first >> v.second;
  for (auto& v : bs)
    cin >> v.first >> v.second;
  sort(as.begin(), as.end());
  sort(bs.begin(), bs.end());
  const auto calc = [&](vector<pair<int, int>> &a, vector<int>& tg) {
//    bt.clear();
    set<pair<int, int>> res(a.begin(), a.end());
    for (int i = 1; i <= n; ++i) {
      for (auto it = res.begin(); it != res.end();) {
        ++tg[i];
        res.erase(exchange(it, res.upper_bound(make_pair(it->second, 0))));
      }
    }
    partial_sum(tg.begin(), tg.end(), tg.begin());
  };
  calc(as, aa);
  calc(bs, bb);
  int ans = 0;
  for (int i = 0; i <= n; ++i)
    maximize(ans, aa[i] + bb[n - i]);
  cout << ans << '\n';
  return 0;
}
