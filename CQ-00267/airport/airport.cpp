#include <bits/stdc++.h>
#define re register
//#define int long long
#define mp(a, b) make_pair(a, b)
using namespace std;
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
//char buf[1 << 21], *p1 = buf, *p2 = buf;
inline int read()
{
	re int x = 0;
	bool f = 0;
	re char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = 1;ch = getchar();}
	while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
	return f ? -x : x;
}
const int N = 1e5 + 5;
int n, m1, m2;
int q1[N], q2[N], num1, num2;
bool vis[N];
pair<int, int> a[N];
signed main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read(), m1 = read(), m2 = read();
	for (re int i = 1; i <= m1; ++i) a[i].first = read(), a[i].second = read();
	sort(a + 1, a + m1 + 1);
	for (re int i = 1; i <= m1; ++i)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		int val = 1;
		int j = i;
		while (1)
		{
			int p = lower_bound(a + j + 1, a + m1 + 1, mp(a[j].second, 0)) - a;
			while (vis[p]) ++p;
			if (p > m1) break;
			vis[p] = 1, val++, j = p;
		}
		q1[++num1] = val;
	}
	
	for (re int i = 1; i <= m2; ++i) a[i].first = read(), a[i].second = read(), vis[i] = 0;
	sort(a + 1, a + m2 + 1);
	for (re int i = 1; i <= m2; ++i)
	{
		if (vis[i]) continue;
		vis[i] = 1;
		int val = 1;
		int j = i;
		while (1)
		{
			int p = lower_bound(a + j + 1, a + m2 + 1, mp(a[j].second, 0)) - a;
			while (vis[p]) ++p;
			if (p > m2) break;
			vis[p] = 1, val++, j = p;
		}
		q2[++num2] = val;
	}
	int sum = 0;
	for (re int i = 1; i <= n; ++i) sum += q1[i];
	int ans = sum;
	for (re int i = n; i; --i)
	{
		sum -= q1[i];
		sum += q2[n - i + 1];
		ans = max(ans, sum);
	}
	printf("%d", ans);
	return 0;
}
