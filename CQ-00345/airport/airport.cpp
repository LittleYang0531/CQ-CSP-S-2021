#include <bits/stdc++.h>

using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') f |= ch == '-' ? -1 : 1, ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
const int de = 1;
const int N = 100000;
const int INF = INT_MAX - 1;
struct node {
	int st, ed;
} a[N + 1], b[N + 1];
bool cmp(node a, node b) {
	return a.st < b.st;
}
priority_queue<int, vector<int>, greater<int> > Inside, Outside;
int n, m, m2, st = INF, ed = -INF, ans, ai, bi;
inline void solve(int inside_max) {
	if (Inside.size()) while(Inside.size()) Inside.pop();
	if (Outside.size()) while(Outside.size()) Outside.pop();
	ai = bi = 1;
	int cnt = 0;	
	/// 根据思路， inside就是国内航班的廊桥数量。 
	int outside_max = n - inside_max; ///　反之，outside就是国外航班的廊桥数量。 
	if (de == -1) printf("国内航班飞机最大数量 = %d 国外航班飞机最大数量 = %d\n", inside_max, outside_max);
	/// 那么这里的 i表示时间。  
	for (int i = st; i <= ed; i++) { 
		if (de == -1) printf("当前时刻 %d\n", i);
		/// 这种情况就是可以放入 
		for (int j = 1; j <= m; j++) {	
			if (a[j].st == i && Inside.size() < inside_max) {
				Inside.push(a[j].ed);
				cnt ++;
				if (de == -1) printf("现在时间为%d, 当前国内飞机的来访时间为 %d ， 离开时间为 %d， 国内廊桥已有 %d 架飞机\n", i, a[j].st, a[j].ed, Inside.size());
			}
		}
		for (int j = 1; j <= m2; j++) {
			if (b[j].st == i && Outside.size() < outside_max) {
				Outside.push(b[j].ed);
				cnt ++;
				if (de == -1) printf("现在时间为%d, 当前国际飞机的来访时间为 %d ， 离开时间为 %d， 国际廊桥已有 %d 架飞机\n", i, b[j].st, b[j].ed, Outside.size());	
			}
		}
		/// 这架飞机离开了。 		
		if (Inside.size() && Inside.top() == i) {
			Inside.pop();
			if (de == -1) printf("一架国内飞机离开了！ 现在还有 %d 架飞机在廊桥里\n", Inside.size());
		}
		if (Outside.size() && Outside.top() == i) {
			Outside.pop();
			if (de == -1) printf("一架国际飞机离开了！ 现在还有 %d 架飞机在廊桥里\n", Outside.size());
		}
	}
	ans = max(ans, cnt);
	if (de == -1) printf("得到答案为 %d，  最优答案为 %d\n", cnt, ans);
} 
int main () {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	
	n = read(), m = read(), m2 = read();
	for (int i = 1; i <= m; i++) 
		a[i].st = read(), st = min(st, a[i].st), a[i].ed = read(), ed = max(ed, a[i].ed);
	for (int i = 1; i <= m2; i++) 
		b[i].st = read(), st = min(st, b[i].st), b[i].ed = read(), ed = max(ed, b[i].ed);
	sort(a + 1, a + m + 1, cmp), sort(b + 1, b + m2 + 1, cmp);
	if (de == -1) printf("st = %d ed = %d\n", st, ed);
	/// 枚举分派给国内航班 的廊桥数量， 给国外航班的廊桥数量就是 n - i 
	for (int i = 0; i <= n; i++) 
		solve(i);
	printf("%d\n", ans);
	return 0;
}

