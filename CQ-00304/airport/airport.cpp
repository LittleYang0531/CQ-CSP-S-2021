#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N = 1e6; 
int n, m1, m2, num;
struct node { int l, r;} a[N], b[N], c[N];
int cmp(node x, node y) {
  if(x.l != y.l) return x.l < y.l;
  return x.r < y.r;
}
int f[N], dp[N];
int qc[N], bel;
int mm;
struct np{
  int val, id;
  np(int a = 0,int b = 0) {
    val = a, id = b;
  }
  bool operator < (np const &B) const{
    return val < B.val;
  }
}se[N];
int ls(int p) { return p << 1;}
int rs(int p) { return p << 1 | 1;}
void push_up(int p) {
 if(se[ls(p)].val < se[rs(p)].val) se[p] = se[ls(p)];
 else se[p] = se[rs(p)]; 
}
void build(int p,int l,int r) {
  if(l == r) { se[p].val = m1 + m2, se[p].id = l; return;}
  int mid = (l + r) >> 1;
  build(ls(p), l, mid), build(rs(p), mid + 1, r);
  push_up(p);
}
void change(int p,int l,int r,int x,int v) {
  if(r < x || l > x) return;
  if(l == r) { se[p].val = v, se[p].id = l; return;}
  int mid = (l + r) >> 1;
  change(ls(p), l, mid, x, v), change(rs(p), mid + 1, r, x, v);
  push_up(p);
}
np ask(int p,int l,int r,int nx,int ny) {
  if(nx <= l && r <= ny) return se[p];
  int mid = (l + r) >> 1; 
  np ans = np(m1 + m2, m1 + m2);
  if(nx <= mid) ans = min(ans, ask(ls(p), l, mid, nx, ny));
  if(ny > mid) ans = min(ans, ask(rs(p), mid + 1, r, nx, ny));
  push_up(p);
  return ans;
}
signed main () {
  freopen("airport.in", "r", stdin);
  freopen("airport.out", "w", stdout);
  ios::sync_with_stdio(0);
  cin.tie(0), cout.tie(0);
  cin >> n >> m1 >> m2;
  for(int i = 1; i <= m1; i++) cin >> a[i].l >> a[i].r, qc[++bel] = a[i].l, qc[++bel] = a[i].r;
  for(int i = 1; i <= m2; i++) cin >> b[i].l >> b[i].r, qc[++bel] = b[i].l, qc[++bel] = b[i].r;
  sort(qc + 1, qc + bel + 1);
  bel = unique(qc + 1, qc + bel + 1) - (qc + 1);
  for(int i = 1; i <= m1; i++) {
    a[i].l = lower_bound(qc + 1, qc + bel + 1, a[i].l) - qc;
    a[i].r = lower_bound(qc + 1, qc + bel + 1, a[i].r) - qc;
    mm = max(mm, a[i].l), mm = max(a[i].r, mm);
  }
  for(int i = 1; i <= m2; i++) {
    b[i].l = lower_bound(qc + 1, qc + bel + 1, b[i].l) - qc;
    b[i].r = lower_bound(qc + 1, qc + bel + 1, b[i].r) - qc;
    mm = max(b[i].l,mm), mm = max(b[i].r, mm);
  }
  sort(a + 1, a + m1 + 1, cmp), sort(b + 1, b + m2 + 1, cmp);
  build(1, 1, mm);
  int cnt = 0;
  for(int i = 1; i <= m1; i++) {
    np now = ask(1, 1, mm, 1, a[i].l);
    if(now.val > cnt) {
      cnt++;
      change(1, 1, mm, a[i].r, cnt);
      dp[cnt]++;
    }
    else{
      dp[now.val]++;
      change(1, 1, mm, now.id, mm);
      change(1, 1, mm, a[i].r, now.val);
    }
  }
  build(1, 1, mm);
  cnt = 0;
  for(int i = 1; i <= m2; i++) {
    np now = ask(1, 1, mm, 1, b[i].l);
    if(now.val > cnt) {
      cnt++;
      change(1, 1, mm, b[i].r, cnt);
      f[cnt]++;
    }
    else{
      f[now.val]++;
      change(1, 1, mm, now.id, mm);
      change(1, 1, mm, b[i].r, now.val);
    }
  }
  for(int i = 1; i <= n; i++) {
    dp[i] += dp[i - 1];
    f[i] += f[i - 1];
  }
  int ans = 0;
  for(int i = 0; i <= n; i++) {
    ans = max(ans, dp[i] + f[n - i]);
  }
  cout << ans << "\n";
  return 0;
}
