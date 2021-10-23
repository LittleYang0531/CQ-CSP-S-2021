#include <bits/stdc++.h>
using namespace std;
const int N = 2e5;
int T, n, b[N], c[N], id[N], pos[N][3], vis[N], d[N], fl;
void dfs(int x) {
  if(fl) return;
  if(x == 2 * n + 1){
    int tot = 0;
    int l = 1, r = 2 * n;
    for(int i = 1; i <= 2 * n; i++) {
      if(id[i] == 0) d[++tot] = b[l], l++;
      else d[++tot] = b[r], r--;
    }
    for(int i = 1; i <= n; i++) {
      if(d[i] != d[2 * n + 1 - i]) return;
    }
    fl = 1;
    for(int i = 1; i <= 2 * n; i++) {
      if(id[i] == 0) cout << "L";
      else cout << "R";
    }
    return;
  }
  id[x] = 0;
  dfs(x + 1);
  id[x] = 1;
  if(fl) return;
  dfs(x + 1);
}

signed main () {
  freopen("palin.in", "r", stdin);
  freopen("palin.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> T;
  while(T--) {
    cin >> n;
    fl = 0;
    int num = 2 * n;
    for(int i = 1; i <= 2 * n; i++){
      cin >> b[i];
      c[i] = b[i];
    }
    sort(c + 1, c + num + 1);
    num = unique(c + 1, c + num + 1) - (c + 1);
    for(int i = 1; i <= 2 * n; i++) b[i] = lower_bound(c + 1, c + num + 1, b[i]) - c;
    if(n <= 10) {
      dfs(1);
      if(!fl) cout << -1;
      cout << "\n";
    }
    else{
      cout << -1 <<"\n";
    }
  }
  return 0;
}

