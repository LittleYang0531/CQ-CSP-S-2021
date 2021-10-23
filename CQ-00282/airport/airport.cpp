#include <bits/stdc++.h>
using namespace std;
const int maxn = 100005;
int n, m1, m2;
struct data {
	int a, b;
} p1[maxn], p2[maxn];
struct mycmp {
	bool operator()(const int &x, const int &y) {
		return x > y;
	}
};
bool cmp(const data &x, const data &y) {
	return x.a < y.a;
}
int check(int mid) {
	int res = 0;
	priority_queue<int, vector<int>, mycmp> q;
	for(int i = 1; i <= m1; i++) {
		while(!q.empty() && q.top() < p1[i].a) q.pop();
		if((int)q.size() < mid) {
			res++;
			q.push(p1[i].b);
		}
	}
	while(!q.empty()) q.pop();
	for(int i = 1; i <= m2; i++) {
		while(!q.empty() && q.top() < p2[i].a) q.pop();
		if((int)q.size() < n - mid) {
			res++;
			q.push(p2[i].b);
		}
	}
	return res;
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	for(int i = 1; i <= m1; i++) scanf("%d%d", &p1[i].a, &p1[i].b);
	for(int i = 1; i <= m2; i++) scanf("%d%d", &p2[i].a, &p2[i].b);
	sort(p1 + 1, p1 + 1 + m1, cmp);
	sort(p2 + 1, p2 + 1 + m2, cmp);
	int ans = 0;
	for(int i = 0; i <= n; i++) ans = max(ans, check(i));
	printf("%d\n", ans);
//	for(int i = 0; i <= n; i++) printf("%d ", check(i));
//	int l = 0, r = n, ans = 0;
//	while(l <= r) {
//		int mid = (l + r) >> 1;
//		if(mid + 1 > r) {
//			ans = mid;
//			break;
//		}
//		if(check(mid) >= check(mid + 1)) ans = mid, r = mid - 1;
//		else ans = mid + 1, l = mid + 1;
//	}
//	printf("%d\n", check(ans));
	return 0;
}
