#include <bits/stdc++.h>

typedef std::pair<int, int> pii;

const int N = 100000;

int n;
void solve(int *ans, int m) {
	static pii a[2*N + 5]; static int b[N + 5];
	for (int i = 0; i < m; i++) {
		scanf("%d%d", &a[i << 1].first, &a[i << 1 | 1].first);
		b[a[i << 1].second = a[i << 1 | 1].second = i] = 0;
	}
	std::sort(a, a + (m << 1));
	
	std::priority_queue<int, std::vector<int>, std::greater<int> >que;
	for (int i = 1; i <= n; i++) que.push(i);
	for (int i = 0; i < (m << 1); i++) {
		int x = a[i].second;
		if (!b[x]) {
			if (que.empty()) b[x] = n + 1;
			else b[x] = que.top(), que.pop();
		} else {
			que.push(b[x]);
		}
	}
	for (int i = 0; i < m; i++) assert (b[i]), ans[b[i]]++;
	for (int i = 1; i <= n; i++) ans[i] += ans[i - 1];
}

int ans1[N + 5], ans2[N + 5], m1, m2;
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	
//	std::cerr << clock() << "\n";
	
	scanf("%d%d%d", &n, &m1, &m2);
	solve(ans1, m1), solve(ans2, m2);
/*	
	for (int i = 0; i <= n; i++) {
		printf("%d %d\n", ans1[i], ans2[i]);
	}
*/	
	int res = 0;
	for (int i = 0; i <= n; i++)
		res = std::max(res, ans1[i] + ans2[n - i]);
	printf("%d\n", res);
	
//	std::cerr << clock() << "\n";
}
