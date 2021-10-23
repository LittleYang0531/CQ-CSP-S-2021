/*
n^2 的想法应该很快就出来了
但是无用的操作太多了，考虑怎么避免
链表！每次加入互不影响的所有飞机，然后链表维护
也不行啊，还是n^2的呀
lower_bound就可以不去遍历了
再来给小指针，时间复杂度nlogn的，应该可以
又要加一个map，可能要晋升log^2 n 但是不慌，还是可以
二分不对，想不来正解了。可能40pts了/ll
*/
#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10, INF = 1e8 + 10;
int n, m1, m2, ans1[N], ans2[N];
int a1[N], b1[N], a2[N], b2[N], ans;
bool vis[N], sig[N];
map<int, int> rev;
struct mdzz {
	int a, b;
	bool operator < (const mdzz &it) const {
		return (a == it.a) ? (b < it.b) : (a < it.a);
	}
} p1[N], p2[N];
inline ll read() {
	char ch = getchar();
	ll s = 0, w = 1;
	while (ch < '0' || ch > '9') {if(ch == '-') w = -1; ch = getchar();}
	while (ch >= '0' && ch <= '9') {s = (s << 3) + (s << 1) + ch - '0'; ch = getchar();}
	return s * w;
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(); m1 = read(); m2 = read();
	//printf("%d %d %d\n", n, m1, m2);
	for (int i = 1; i <= m1; ++i) {
		p1[i].a = read(); p1[i].b = read();
	}
	sort(p1 + 1, p1 + 1 + m1);
	for (int i = 1; i <= m1; ++i) {
		a1[i] = p1[i].a; b1[i] = p1[i].b;
		rev[a1[i]] = i;
	}
	a1[m1 + 1] = b1[m1 + 1] = INF;
	rev[INF] = m1 + 1;
	int it = 1, id = 1, num = 1;
	while (it <= m1) {
		id = it;
		while (id <= m1) {
			vis[id] = 1;
			++ans1[num];
			id = rev[*lower_bound(a1 + id, a1 + 1 + m1, b1[id])];
			for (int i = id; i <= m1 + 1; ++i) {
				if (!vis[i]) {id = i; break;}
			}
		}
		++num;
		for (int i = it; i <= m1 + 1; ++i) {
			it = i;
			if (!vis[i]) break;
		}
	}
	for (int i = 1; i <= m1; ++i) {
		rev[a1[i]] = 0;
	}
	rev[INF] = 0;
	for (int i = 1; i <= m2; ++i) {
		p2[i].a = read(); p2[i].b = read();
	}
	sort(p2 + 1, p2 + 1 + m2);
	for (int i = 1; i <= m1; ++i) {
		a2[i] = p2[i].a; b2[i] = p2[i].b;
		rev[a2[i]] = i;
	}
	a2[m2 + 1] = b2[m2 + 1] = INF;
	rev[INF] = m2 + 1;
	it = 1, id = 1, num = 1;
	while (it <= m2) {
		id = it;
		while (id <= m2) {
			sig[id] = 1;
			++ans2[num];
			id = rev[*lower_bound(a2 + id, a2 + 1 + m2, b2[id])];
			for (int i = id; i <= m2 + 1; ++i) {
				if (!sig[i]) {id = i; break;}
			}
		}
		++num;
		for (int i = it; i <= m2 + 1; ++i) {
			it = i;
			if (!sig[i]) break;
		}
	}
	for (int i = 1; i <= n; ++i) {
		ans1[i] += ans1[i - 1];
		ans2[i] += ans2[i - 1];
	}
	for (int i = 0; i <= n; ++i) {
		ans = max(ans, ans1[i] + ans2[n - i]);
	}
	printf("%d\n", ans);
	return 0;
}
