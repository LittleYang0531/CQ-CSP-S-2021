#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int t, n, a[2005], place[2005];
int book[2005], tot;
bool flag;
void dfs(int l, int r)
{
	if (tot==n)
	{
		for (int p=1;p<=n;p++)
		{
			if (book[p]==1)
			{
				printf("L");
			}
			else
			{
				printf("R");
			}
		}
		flag = 1;
		return ;
	}
	if (!place[a[l]])
	{
		tot++;
		book[tot] = 1;
		place[a[l]] = n-tot+1;
		dfs(l+1, r);
		if (flag)
		{
			return ;
		}
		tot--;
		place[a[l]] = 0;
	}
	else
	{
		if (tot+1==place[a[l]])
		{
			tot++;
			book[tot] = 1;
			dfs(l+1, r);
			if (flag)
			{
				return ;
			}
			tot--;
		}
	}
	if (!place[a[r]])
	{
		tot++;
		book[tot] = 2;
		place[a[r]] = n-tot+1;
		dfs(l, r-1);
		if (flag)
		{
			return ;
		}
		tot--;
		place[a[r]] = 0;
	}
	else
	{
		if (tot+1==place[a[r]])
		{
			tot++;
			book[tot] = 2;
			dfs(l, r-1);
			if (flag)
			{
				return ;
			}
			tot--;
		}
	}
	return ;
}
int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	for (int zqw=1;zqw<=t;zqw++)
	{
		flag = 0;
		tot = 0;
		memset(place, 0, sizeof(place));
		scanf("%d", &n);
		n*=2;
		for (int p=1;p<=n;p++)
		{
			scanf("%d", &a[p]);
		}
		dfs(1, n);
		if (!flag)
		{
			printf("-1");
		}
		printf("\n");
	}
	return 0;
}
