#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
const int MAXN = 5005;
pair<int, int> a[MAXN], b[MAXN];
priority_queue<int, vector<int>, greater<int> > wq;
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	int n, m1, m2;
	scanf("%d %d %d", &n, &m1, &m2);
	for (int i = 1; i <= m1; i++) {
		scanf("%d %d", &a[i].first, &a[i].second);
	}
	for (int i = 1; i <= m2; i++) {
		scanf("%d %d", &b[i].first, &b[i].second);
	}
	sort(a + 1, a + 1 + m1);
	sort(b + 1, b + 1 + m2);
	int qw = 0;
	for (int i = 0; i <= n; i++) {
		int gt = i, ans = 0;
		while (wq.empty() == 0) wq.pop();
		for (int j = 1; j <= m1; j++) {
			while (wq.empty() == 0 && wq.top() < a[j].first) {
				wq.pop();
				gt++;
			}
			if (gt) {
				gt--;
				ans++;
				wq.push(a[j].second);
			}
		}
		gt = n - i;
		while (wq.empty() == 0) wq.pop();
		for (int j = 1; j <= m2; j++) {
			while (wq.empty() == 0 && wq.top() < b[j].first) {
				wq.pop();
				gt++;
			}
			if (gt) {
				gt--;
				ans++;
				wq.push(b[j].second);
			}
		}
		qw = max(qw, ans);
	}
	printf("%d\n", qw);
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16
*/
