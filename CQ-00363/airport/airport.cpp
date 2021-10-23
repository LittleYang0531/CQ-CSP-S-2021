#include <cstdio>
#include <iostream>
#include <cstring>
#include <algorithm>
using namespace std;
const int MAXN = 1e5+5;
int x[MAXN],y[MAXN],n,m1,m2,now,nowx,nowy,ans,cnt,tot;

struct p
{
	int l,r;
	bool vis;
	bool operator < (const p &a) const
	{
		if(l == a.l)
		return r < a.r;
		return l < a.l;
	}
}gn[MAXN],gw[MAXN];

template <typename T>
void read(T &s)
{
	s = 0;
	bool w = false;
	char ch = getchar();
	while(ch < '0' || ch > '9')
	{
		if(ch == '-')
		w = true;
		ch = getchar();
	}
	while(ch >= '0' && ch <= '9')
	{
		s = (s<<3) + (s<<1) + (ch^48);
		ch = getchar();
	}
	s = w ? -s:s;
	return;
}

void turn_gn()
{
	now = -1;
	cnt++;
	for(int j = 1;j <= m1;j++)
	{
		if(now < gn[j].l && !gn[j].vis)
		{
			x[cnt]++;
			now = gn[j].r;
			gn[j].vis = true;
		}
	}
	return;
}

void turn_gw()
{
	now = -1;
	tot++;
	for(int j = 1;j <= m2;j++)
	{
		if(now < gw[j].l && !gw[j].vis)
		{
			y[tot]++;
			now = gw[j].r;
			gw[j].vis = true;
		}
	}
	return;
}

bool com(int a,int b)
{
	if(a > cnt)
		turn_gn();
	if(b > tot)
		turn_gw();
	if(a > n || b > n)
	return true;
	if(x[a] > y[b])
		return true;
	if(x[a] < y[b])
		return false;
	return com(a+1,b+1);
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);
	read(m1);
	read(m2);
	for(int i = 1;i <= m1;i++)
	{
		read(gn[i].l);
		read(gn[i].r);
	}
	for(int i = 1;i <= m2;i++)
	{
		read(gw[i].l);
		read(gw[i].r);
	}
	sort(gn+1,gn+1+m1);
	sort(gw+1,gw+1+m2);
	nowx = 1,nowy = 1;
	for(int i = 1;i <= n;i++)
	{
		if(nowx > cnt)
		turn_gn();
		if(nowy > tot)
		turn_gw();
		if(com(nowx,nowy) == true)
		{
			ans += x[nowx];
			nowx++;
		}
		else
		{
			ans += y[nowy];
			nowy++;
		}
	}
	printf("%d\n",ans);
	return 0;
}
