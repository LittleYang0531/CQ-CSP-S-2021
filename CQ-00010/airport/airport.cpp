#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int MAXN = 200005;

int n, cnt, m1, m2, sum1, sum2, now1, now2, ans;
bool vis[MAXN];

struct node {
	int val, opt, id;
} a[MAXN], b[MAXN];

bool cmp(node x, node y) {
	return x.val < y.val;
}

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	cnt = 0;
	for (int i = 1, x, y; i <= m1; i++) {
		scanf("%d %d", &x, &y);
		a[++cnt].val = x, a[cnt].opt = 1, a[cnt].id = i;
		a[++cnt].val = y, a[cnt].opt = -1, a[cnt].id = i;
	}
	cnt = 0;
	for (int i = 1, x, y; i <= m2; i++) {
		scanf("%d %d", &x, &y);
		b[++cnt].val = x, b[cnt].opt = 1, b[cnt].id = i;
		b[++cnt].val = y, b[cnt].opt = -1, b[cnt].id = i;
	}
	m1 *= 2, m2 *= 2;
	sort(a + 1, a + 1 + m1, cmp);
	sort(b + 1, b + 1 + m2, cmp);
	
	for (int t = 0; t <= n; t++) {
		
		sum1 = sum2 = now1 = now2 = 0;
		
		for (int i = 1; i <= m1; i++) {
			if (now1 + a[i].opt > t || (a[i].opt == -1 && vis[a[i].id] == 0)) continue;
			now1 += a[i].opt;
			if (vis[a[i].id] == 1) vis[a[i].id] = 0;
			else vis[a[i].id] = 1, sum1++;
		}
		
		for (int i = 1; i <= m2; i++) {
			if (now2 + b[i].opt > n - t || (b[i].opt == -1 && vis[b[i].id] == 0)) continue;
			now2 += b[i].opt;
			if (vis[b[i].id] == 1) vis[b[i].id] = 0;
			else vis[b[i].id] = 1, sum2++;
		}
		
		ans = max(ans, sum1 + sum2);
		
	}
	
	printf("%d\n", ans);
	
	return 0;
}
