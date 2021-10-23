#include<bits/stdc++.h>
using namespace std;
#define ll long long
#define pi pair<int,int>
#define mp make_pair
#define X first
#define Y second
#define rg register
inline ll read()
{
	ll x=0,f=1;
	char ch=getchar();
	while(ch<'0'||'9'<ch)
	{
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
#define rid(g) g=read()
int ans,to1[100010],to2[100010];
pi s1[100010],s2[100010],w1[200010],w2[200010];
main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int rid(n),rid(m1),rid(m2);
	const int m=min(max(m1,m2),n);
	for(rg int z=1; z<=m1; ++z)
	{
		w1[z*2]=mp(rid(s1[z].X),z);
		w1[z*2+1]=mp(rid(s1[z].Y),-z);
	}
	for(rg int z=1; z<=m2; ++z)
	{
		w2[z*2]=mp(rid(s2[z].X),z);
		w2[z*2+1]=mp(rid(s2[z].Y),-z);
	}
	sort(s1,s1+m1),sort(s2,s2+m2),sort(w1,w1+2*m1+2),sort(w2,w2+2*m2+2);
	for(rg int z=2; z<m1*2+2; z+=2)
	{
		if(w1[z].Y<0)
			to1[-w1[z].Y]=z;
		if(w1[z+1].Y<0)
			to1[-w1[z+1].Y]=z+1;
	}
	for(rg int z=2; z<m2*2+2; z+=2)
	{
		if(w2[z].Y<0)
			to2[-w2[z].Y]=z;
		if(w2[z+1].Y<0)
			to2[-w2[z+1].Y]=z+1;
	}
	for(rg int z=0; z<=m; ++z)
	{
		int now=0,got=0;
		for(rg int y=2; z&&y<m1*2+2; y+=2)
		{
			now+=(w1[y].Y>0?1:(w1[y].Y<0?-1:0));
			if(now>z)now=z,w1[to1[w1[y].Y]].Y=0;
			else got+=(w1[y].Y>0);
			now+=(w1[y+1].Y>0?1:(w1[y+1].Y<0?-1:0));
			if(now>z)now=z,w1[to1[w1[y+1].Y]].Y=0;
			else got+=(w1[y+1].Y>0);
		}
		for(rg int y=2; n-z&&y<m2*2+2; y+=2)
		{
			now+=(w2[y].Y>0?1:(w2[y].Y<0?-1:0));
			if(now>n-z)now=n-z,w2[to2[w2[y].Y]].Y=0;
			else got+=(w2[y].Y>0);
			now+=(w2[y+1].Y>0?1:(w2[y+1].Y<0?-1:0));
			if(now>n-z)now=n-z,w2[to2[w2[y+1].Y]].Y=0;
			else got+=(w2[y+1].Y>0);
		}
		ans=max(ans,got);
		for(rg int z=2; z<m1*2+2; z+=2)
		{
			if(w1[z].Y>0)
				w1[to1[w1[z].Y]].Y=-1;
			if(w1[z+1].Y>0)
				w1[to1[w1[z+1].Y]].Y=-1;
		}
		for(rg int z=2; z<m2*2+2; z+=2)
		{
			if(w2[z].Y>0)
				w2[to2[w2[z].Y]].Y=-1;
			if(w2[z+1].Y>0)
				w2[to2[w2[z+1].Y]].Y=-1;
		}
	}
	printf("%lld",ans);
	return 0;
}
