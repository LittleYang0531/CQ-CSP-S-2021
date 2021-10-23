#include <bits/stdc++.h>
int n, m1, m2, cnt1, cnt2, ans, pos, ans1[100005], ans2[100005], last1[100005], last2[100005], sum1[100005], sum2[100005];
std::pair<int, int> a[100005], b[100005];
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	for(int i = 1; i <= m1; ++i) scanf("%d%d", &a[i].first, &a[i].second);
	for(int i = 1; i <= m2; ++i) scanf("%d%d", &b[i].first, &b[i].second);
	std::sort(a + 1, a + 1 + m1);
	std::sort(b + 1, b + 1 + m2);
	for(int i = 1; i <= m1; ++i) {
		pos = -1;
		for(int j = 1; j <= cnt1 && !(~pos); ++j)
			if(last1[j] <= a[i].first) pos = j;
		if(!(~pos)) pos = ++cnt1;
		last1[pos] = a[i].second, ++ans1[pos];
	}
	for(int i = 1; i <= m2; ++i) {
		pos = -1;
		for(int j = 1; j <= cnt2 && !(~pos); ++j)
			if(last2[j] <= b[i].first) pos = j;
		if(!(~pos)) pos = ++cnt2;
		last2[pos] = b[i].second, ++ans2[pos];
	}
	for(int i = 1; i <= n; ++i) sum1[i] = sum1[i - 1] + ans1[i], sum2[i] = sum2[i - 1] + ans2[i];
	for(int i = 0; i <= n; ++i) ans = std::max(ans, sum1[i] + sum2[n - i]);
	printf("%d", ans);
	return 0;
}
