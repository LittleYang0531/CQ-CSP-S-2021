#include <iostream>
#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
int n, m1, m2, tot1, tot2, sum1[100005], sum2[100005], ans;
bool book1[100005], book2[100005];
struct e
{
	int l, r;
}a[100005], b[100005];
struct r
{
	int last, num;
}bri1[100005], bri2[100005];
bool cmp(e x, e y)
{
	return x.l<y.l;
}
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for (int p=1;p<=m1;p++)
	{
		scanf("%d %d", &a[p].l, &a[p].r);
	}
	stable_sort(a+1, a+m1+1, cmp);
	for (int p=1;p<=m2;p++)
	{
		scanf("%d %d", &b[p].l, &b[p].r);
	}
	stable_sort(b+1, b+m2+1, cmp);
	for (int p=1;p<=m1;p++)
	{
		bool flag = 0;
		for (int k=1;k<=tot1;k++)
		{
			if (bri1[k].last<a[p].l)
			{
				flag = 1;
				bri1[k].last = a[p].r;
				bri1[k].num++;
				break;
			}
		}
		if (!flag)
		{
			tot1++;
			bri1[tot1].last = a[p].r;
			bri1[tot1].num = 1;
		}
	}
	for (int p=1;p<=m2;p++)
	{
		bool flag = 0;
		for (int k=1;k<=tot2;k++)
		{
			if (bri2[k].last<b[p].l)
			{
				flag = 1;
				bri2[k].last = b[p].r;
				bri2[k].num++;
				break;
			}
		}
		if (!flag)
		{
			tot2++;
			bri2[tot2].last = b[p].r;
			bri2[tot2].num = 1;
		}
	}
	for (int p=1;p<=n;p++)
	{
		sum1[p] = sum1[p-1]+bri1[p].num;
		sum2[p] = sum2[p-1]+bri2[p].num;
	}
	for (int p=1;p<=n;p++)
	{
		ans = max(ans, sum1[p]+sum2[n-p]);
	}
	printf("%d", ans);
	return 0;
}
