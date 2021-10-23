#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;
typedef long long ll;
inline ll Min(ll x, ll y) {return x < y ? x : y;}

ll ans = 1e18, x1[505][505], x2[505][505], x3[55], gb[250005];
int n, m, k, p[55], t[55];

inline void dfs(int now) {
	if (now == n * m + 1) {
		ll tot = 0;
		for (int i = 1; i <= n; i++)
			for (int j = 1; j <= m; j++) {
				int gjy = m * (i - 1) + j;
				if (gb[gjy] != gb[gjy + 1] && gb[gjy + 1] != -1) tot += x2[i][j];
				if (gb[gjy] != gb[gjy + m] && gb[gjy + m] != -1) tot += x1[i][j];
			}
		for (int i = 1; i <= k; i++) {
			if (p[i] <= m && gb[p[i]] != t[i]) tot += x3[i];
			if (p[i] > m && p[i] <= m + n && gb[m * (p[i] - m)] != t[i]) tot += x3[i];
			if (p[i] > m + n && p[i] <= m * 2 + n && gb[m * (n - 1) + m - (p[i] - m - n) + 1] != t[i]) tot += x3[i];
			if (p[i] > m * 2 + n && gb[m * (n - (p[i] - m * 2 - n)) + 1] != t[i]) tot += x3[i];
		}
		ans = Min(ans, tot);
		return;
	}
	gb[now] = 0;
	dfs(now + 1);
	gb[now] = 1;
	dfs(now + 1);
}

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	int T;
	scanf("%d %d %d", &n, &m, &T);
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++) scanf("%lld", &x1[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++) scanf("%lld", &x2[i][j]);
	memset(gb, -1, sizeof(gb));
	while (T--) {
		scanf("%d", &k);
		for (int i = 1; i <= k; i++) scanf("%lld %d %d", &x3[i], &p[i], &t[i]);
		dfs(1);
		printf("%lld\n", ans);
		ans = 1e18;
	}
	return 0;
}
