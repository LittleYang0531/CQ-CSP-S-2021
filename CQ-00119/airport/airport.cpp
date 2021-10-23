#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define re register

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

int n,m1,m2,ans;
int lasts;
int time1[100005];
int time2[100005];

struct t{
	int st,en;
} ch[100000],fo[100000];

bool cmp(t x,t y)
{
	return x.st < y.st;
}

inline int cheak(int x)
{
	int la=0,be=0;
	int ans = 0;
	int y = x-1;
	sort(ch+1,ch+1+m1,cmp);
	for(re int i = 1;i <= m1;++i)
	{
		++la;
		time1[la] = ch[i].en;
		if(ch[i].st >= time1[be])
		{
			++be;
			if(y < x)
				++y;
		}
		if(y)
			--y,++ans;
	}
	fill(time1+1,time1+1+m1,0);
	return ans;
}

inline int cheak1(int x)
{
	int ans = 0;
	int la=0,be=0;
	int y = x-1;
	sort(fo+1,fo+1+m2,cmp);
	for(re int i = 1;i <= m2;++i)
	{
		++la;
		time2[la] = fo[i].en;
		if(fo[i].st >= time2[be])
		{
			if(y < x)
				++y;
			++be;
		}
		if(y)
			--y,++ans;
	}
	fill(time2+1,time2+1+m2,0);
	return ans;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n = read();
	m1 = read();
	m2 = read();
	for(re int i = 1;i <= m1;++i)
	{
		ch[i].st = read();
		ch[i].en = read();
		lasts = max(lasts,ch[i].en);
	}
	for(re int i = 1;i <= m2;++i)
	{
		fo[i].st = read();
		fo[i].en = read();
	}
	for(int i = 0;i <= n;++i)
	{
		int p = cheak(i);
		int q = cheak1(n-i);
		ans = max(ans,p+q);
	}
	printf("%d",ans);
	return 0;
}
