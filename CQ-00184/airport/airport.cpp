#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
const int nn = 1e5 + 5;
struct plane {
	int l, r, id, mark;
	int operator< (const plane &rhs)const {
		return l < rhs.l;
	}
} a[nn], b[nn];
std::set<plane> list1, list2;
int n, m1, m2;
int ans1[nn], ans2[nn];
void dfs1(int p, int &res) {
	if (a[p].mark) return; res++;
	std::set<plane>::iterator pt1 = list1.find(a[p]);
//	printf("%d %d %d\n", p, a[p].l, a[p].r);
	std::set<plane>::iterator pt2 = list1.upper_bound((plane){a[p].r, 0, 0, 0});
	list1.erase(pt1); a[p].mark = 1;
	if (pt2 != list1.end()) dfs1(pt2 -> id, res);
}
void dfs2(int p, int &res) {
	if (b[p].mark) return; res++;
	std::set<plane>::iterator pt1 = list2.find(b[p]);
	std::set<plane>::iterator pt2 = list2.upper_bound((plane){b[p].r, 0, 0, 0});
	list2.erase(pt1); b[p].mark = 1;
	if (pt2 != list2.end()) dfs2(pt2 -> id, res);
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for (int i = 1; i <= m1; i++)
		scanf("%d %d", &a[i].l, &a[i].r);
	for (int i = 1; i <= m2; i++)
		scanf("%d %d", &b[i].l, &b[i].r);
	std::sort(a + 1, a + m1 + 1);
	std::sort(b + 1, b + m2 + 1);
	for (int i = 1; i <= m1; i++) {
		a[i].id = i;
		list1.insert(a[i]);
	}
	for (int i = 1; i <= m2; i++) {
		b[i].id = i;
		list2.insert(b[i]);
	}
	int cnt = 0;
	for (int i = 1; i <= m1; i++) {
//		if (i % 100 == 0) printf("%d\n", i);
		if (!a[i].mark) {
			ans1[cnt + 1] = ans1[cnt];
			dfs1(i, ans1[cnt + 1]);
			cnt++;
		}
	}
	for (int i = cnt + 1; i <= n; i++)
		ans1[i] = ans1[cnt];
	cnt = 0;
	for (int i = 1; i <= m2; i++) {
		if (!b[i].mark) {
			ans2[cnt + 1] = ans2[cnt];
			dfs2(i, ans2[cnt + 1]);
			cnt++;
		}
	}
	for (int i = cnt + 1; i <= n; i++)
		ans2[i] = ans2[cnt];
	int ans = 0;
	for (int i = 0; i <= n; i++)
		ans = std::max(ans, ans1[i] + ans2[n - i]);
	printf("%d", ans);
	return 0;
}
