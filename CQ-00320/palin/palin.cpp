// If you let me AC, I will give you 100000 yuan in 2051.

#include <bits/stdc++.h>
using namespace std;
#define MAXN 500005
int n;
int a[MAXN];
char ans[2 * MAXN];
int cnt[MAXN];
int num[MAXN];
bool getans;
void dfs2(int l, int r, int dep)
{
	if(getans)
		return ;
	if(dep > n)
	{
		printf("%s\n", ans + 1);
		getans = true;
		return;
	}
	if(a[l] == num[n - dep + 1])
	{
		ans[n + dep] = 'L';
		dfs2(l + 1, r, dep + 1);
	}
	if(a[r] == num[n - dep + 1])
	{
		ans[n + dep] = 'R';
		dfs2(l, r - 1, dep + 1);
	}
}
void dfs1(int l, int r, int dep)
{
	if(dep > n)
		dfs2(l, r, 1);
	if(getans)
		return;
	if(cnt[a[l]] == 0)
	{
		num[dep] = a[l];
		ans[dep] = 'L';
		cnt[a[l]]++;
		dfs1(l + 1, r, dep + 1); 
		cnt[a[l]]--;
	}
	if(cnt[a[r]] == 0)
	{
		num[dep] = a[r];
		ans[dep] = 'R';
		cnt[a[r]]++;
		dfs1(l, r - 1, dep + 1);
		cnt[a[r]]--; 
	}
	return ;
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n; i++)
			scanf("%d", &a[i]);
		getans = false;
		dfs1(1, 2 * n, 1);
		if(!getans)
			printf("-1");
	}
	return 0;
}
