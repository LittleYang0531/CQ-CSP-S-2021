#include <bits/stdc++.h>

using namespace std;

char ans[500005];
int t, n, a[500005], hd, bk, lst[500005];
bool flg;

void dfs(int now)
{
	if (now == n + 1) 
	{
		flg = 1;
		return;
	} if (flg) return;
	if (lst[a[hd]])
	{
		if (lst[a[hd]] + now == n + 1) ans[now] = 'L', ++hd, dfs(now + 1), --hd; 
	} else ans[now] = 'L', lst[a[hd]] = now, ++hd, dfs(now + 1), lst[a[--hd]] = 0;
	if (flg) return;
	if (lst[a[bk]])
	{
		if (lst[a[bk]] + now == n + 1) ans[now] = 'R', --bk, dfs(now + 1), ++bk;
	} else ans[now] = 'R', lst[a[bk]] = now, --bk, dfs(now + 1), lst[a[++bk]] = 0;
}

inline void solve()
{
	flg = 0, scanf("%d", &n), n <<= 1, hd = 1, bk = n;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	dfs(1);
	if (!flg) puts("-1");
	else printf("%s\n", ans + 1);
}

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w" , stdout);
	scanf("%d", &t);
	while (t--) solve();
}
