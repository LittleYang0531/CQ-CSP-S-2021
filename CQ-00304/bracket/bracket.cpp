#include <bits/stdc++.h>
using namespace std;
const int N = 900, mod = 1e9 + 7;
int n, k, id[N], num, a[N];
char s[N];
int st[N], tp, ans;
void dfs(int x) {
  if(x == num + 1) {
    tp = 0;
    int cnt = 0, fl = 0, pp = 0;
    for(int i = 1; i <= n; i++) {
      if(a[i] == 1) {
        //fl++;
        cnt = 0;
        if(!tp) return;
        else tp--;
      }
      if(a[i] == 0) {
        tp++;
        cnt = 0;
      }
      if(a[i] == 2) {
        pp = fl;
        cnt++;
        if(cnt > k) return;
      }
    }
    if(tp || cnt) return;
    ans++;
    return;
  }
  for(int i = 0; i <= 2; i++) {
    a[id[x]] = i;
    dfs(x + 1);
  }
}
signed main () {
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> k;
  cin >> (s + 1);
  int las = 0;
  for(int i = 1; i <= n; i++) {
    if(s[i] == '?') id[++num] = i;
    else{
      if(s[i] == '(') a[i] = 0;
      if(s[i] == ')') a[i] = 1;
      if(s[i] == '*') a[i] = 2;
    }
  }
  dfs(1);
  cout << ans << "\n";
  return 0;
}
