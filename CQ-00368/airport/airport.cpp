#include <bits/stdc++.h>

using namespace std;

struct Air {
	int st, ed;
}a[100005], b[100005];
int n, m1, m2, c[200005], x[200005], cnt;
inline bool cmp(Air x, Air y) {return x.st < y.st;}

void modify(int x, int k, int mx)
{
	for (; x <= mx * 2; x += (x & -x)) c[x] += k;
}

int query(int x)
{
	int ans = 0;
	for (; x >= 1; x -= (x & -x)) ans += c[x];
	return ans;
}

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	srand(time(0));
    scanf("%d%d%d", &n, &m1, &m2);
    for (int i = 1; i <= m1; i++) scanf("%d%d", &a[i].st, &a[i].ed), x[++cnt] = a[i].st, x[++cnt] = a[i].ed;
    sort(a + 1, a + m1 + 1, cmp), sort(x + 1, x + cnt + 1);
    for (int i = 1; i <= m1; i++) 
	{
    	a[i].st = lower_bound(x + 1, x + cnt + 1, a[i].st) - x;
    	a[i].ed = lower_bound(x + 1, x + cnt + 1, a[i].ed) - x;
	} cnt = 0;
    for (int i = 1; i <= m2; i++) scanf("%d%d", &b[i].st, &b[i].ed), x[++cnt] = b[i].st, x[++cnt] = b[i].ed;
    sort(b + 1, b + m2 + 1, cmp), sort(x + 1, x + cnt + 1);
	for (int i = 1; i <= m2; i++)
	{
		b[i].st = lower_bound(x + 1, x + cnt + 1, b[i].st) - x;
    	b[i].ed = lower_bound(x + 1, x + cnt + 1, b[i].ed) - x;
	} int ans = 0;
	if (n >= 5001) 
	{
		int cnt = 10000000 / n;
		while (cnt--)
		{
			int lim = rand() * rand() % (n + 1);
			int res = 0;
		    for (int i = 1; i <= m1; i++)
		    {
			    int now = query(a[i].st);
			    if (now == lim) continue;
			    modify(a[i].st, 1, m1), modify(a[i].ed + 1, -1, m1), ++res;
		    } memset(c, 0, sizeof c);
		    for (int i = 1; i <= m2; i++)
		    {
			    int now = query(b[i].st);
			    if (now == n - lim) continue;
			    modify(b[i].st, 1, m2), modify(b[i].ed + 1, -1, m2), ++res;
		    } memset(c, 0, sizeof c);
		    ans = max(ans, res);
		} printf("%d\n", ans); return 0;
	}
	for (int lim = 0; lim <= n; lim++)
	{
		int res = 0;
		for (int i = 1; i <= m1; i++)
		{
			int now = query(a[i].st);
			if (now == lim) continue;
			modify(a[i].st, 1, m1), modify(a[i].ed + 1, -1, m1), ++res;
		} for (int i = 1; i <= m1 * 2; i++) c[i] = 0;
		for (int i = 1; i <= m2; i++)
		{
			int now = query(b[i].st);
			if (now == n - lim) continue;
			modify(b[i].st, 1, m2), modify(b[i].ed + 1, -1, m2), ++res;
		} for (int i = 1; i <= m2 * 2; i++) c[i] = 0;
		ans = max(ans, res);
	} printf("%d\n", ans);
}
