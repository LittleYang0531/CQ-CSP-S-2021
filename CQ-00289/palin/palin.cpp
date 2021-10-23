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
bool checkback(deque<int> &d, int v) {
  return !d.empty() && d.back() == v;
}
bool checkself(deque<int>& d) {
  return d.size() >= 2 && d.back() == d.front();
}
int main() {
  freopen("palin.in", "r", stdin);
  freopen("palin.out", "w", stdout);
  ios::sync_with_stdio(false);
  cin.tie(0);
  int T;
  cin >> T;
  while (T--) {
    int n;
    cin >> n;
    vector<int> a(2 * n);
    for (int& v : a) {
      cin >> v;
    }
    auto calc = [&](deque<int> &&da, deque<int>&& db) {
      reverse(db.begin(), db.end());
      vector<char> op1, op2;
      for (int i = 1; i < n; ++i) {
        if (!da.empty() && (checkback(db, da.front()) || checkself(da))) {
          op1.push_back('L');
          if (checkself(da))
            op2.push_back('L'), da.pop_back();
          else
            op2.push_back('R'), db.pop_back();
          da.pop_front();
        } else if (!db.empty() && (checkback(da, db.front()) || checkself(db))) {
          op1.push_back('R');
          if (checkself(db))
            op2.push_back('R'), db.pop_back();
          else
            op2.push_back('L'), da.pop_back();
          db.pop_front();
        } else {
          throw exception();
        }
      }
      reverse(op2.begin(), op2.end());
      for (int x : op2)
        op1.push_back(x);
      return op1;
    };
    bool flag = false;
    vector<char> ans;
    if (n == 1) {
      cout << "LR\n";
    continue;
    }
    try {
      auto it = find(a.begin() + 1, a.end(), a.front());
      ans = calc(deque<int>(a.begin() + 1, it), deque<int>(it + 1, a.end()));
      ans.insert(ans.begin(), 'L');
      ans.push_back('L');
      flag = true;
    } catch(...) {}
    try {
      auto it = find(a.begin(), a.end(), a.back());
      auto t = calc(deque<int>(a.begin(), it), deque<int>(it + 1, a.end() - 1));
      t.insert(t.begin(), 'R');
      t.push_back('L');
      if (!flag || ans > t)
        ans = t;
      flag = true;
    } catch(...) {}
    if (flag) {
      for (char c : ans)
        cout << c;
      cout << endl;
    } else {
      cout << -1 << endl;
    }
  }
  return 0;
}
