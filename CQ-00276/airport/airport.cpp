#include <bits/stdc++.h>
using namespace std;
#define R register
typedef long long ll;
const int MAXN = 1e5 + 5;
int n,m1,m2;
int Next[3][MAXN],Last[3][MAXN],Head[3];
struct node
{
	int s,t;
};
node a[2 * MAXN],b[2 * MAXN];
int c[2 * MAXN],cnt;
inline int getid(int x)
{
	return lower_bound(c + 1,c + 1 + cnt,x) - c;
}
inline bool cmp(node x,node y)
{
	return x.s < y.s;
}
int C[3][MAXN];
inline int lowbit(int x)
{
	return x & (-x);
}
inline void insert(int x,int d,int w)
{
	for(R int i = x; i <= cnt; i += lowbit(i))
		C[w][i] += d;
}
inline int getans(int x,int w)
{
	int ans = 0;
	for(R int i = x; i; i -= lowbit(i))
		ans += C[w][i];
	return ans;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for(R int i = 1; i <= m1; i++)
	{
		scanf("%d %d", &a[i].s, &a[i].t);
		c[++cnt] = a[i].s;
		c[++cnt] = a[i].t;
	}
	for(R int i = 1; i <= m2; i++)
	{
		scanf("%d %d", &b[i].s, &b[i].t);
		c[++cnt] = b[i].s;
		c[++cnt] = b[i].t;
	}
	sort(a + 1,a + 1 + m1,cmp);
	sort(b + 1,b + 1 + m2,cmp);
	sort(c + 1,c + 1 + cnt);
	cnt = unique(c + 1,c + 1 + cnt) - (c + 1);
	for(R int i = 1; i <= m1; i++)
		a[i].s = getid(a[i].s),a[i].t = getid(a[i].t);
	for(R int i = 1; i <= m2; i++)
		b[i].s = getid(b[i].s),b[i].t = getid(b[i].t);
	int maxn = 0,ans = 0,La = 0;
	for(R int i = 1; i <= m1; i++)
	{
		if(getans(a[i].s,1) < n)
		{
			ans++;
			insert(a[i].s,1,1);
			insert(a[i].t,-1,1);
			if(La != 0)
			{
				Next[1][La] = i;
				Last[1][i] = La;
			}
			else Head[1] = i;
			La = i;
		}
	}
	maxn = ans;
	Head[0] = 1;
	for(R int i = 1; i <= m2; i++)
	{
		if(i != 1)Last[0][i] = i - 1;
		if(i != m2)Next[0][i] = i + 1;
	}
	for(R int j = n - 1; j >= 0; j--)
	{
		for(R int i = Head[1]; i; i = Next[1][i])
		{
			if(getans(a[i].s,1) > j)
			{
				ans--;
				insert(a[i].s,-1,1);
				insert(a[i].t,1,1);
				if(Head[1] == i)Head[1] = Next[1][Head[1]];
				Next[1][Last[1][i]] = Next[1][i];
				Last[1][Next[1][i]] = Last[1][i];
			}
		}
		for(R int i = Head[0]; i; i = Next[0][i])
		{
			if(getans(b[i].s,0) < n - j)
			{
				ans++;
				insert(b[i].s,1,0);
				insert(b[i].t,-1,0);
				if(Head[0] == i)Head[0] = Next[0][Head[0]];
				Next[0][Last[0][i]] = Next[0][i];
				Last[0][Next[0][i]] = Last[0][i];
			}
		}
		maxn = max(maxn,ans);
	}
	printf("%d\n", maxn);
	return 0;
}
