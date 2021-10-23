#include<bits/stdc++.h>
using namespace std;
int ans,n,m1,m2,cnt,cnt2,l,r,h[100005],h2[100005];
bool u[100005];
struct X
{
	int r,bh,cnt;
}j;
priority_queue<X> q;
bool operator <(X a,X b)
{
	return a.r>b.r;
}
struct X2
{
	int r,bh,cnt;
}j2;
priority_queue<X2> q2;
bool operator <(X2 a,X2 b)
{
	return a.bh>b.bh;
}
struct Y
{
	int l,r;
}px[100005];
bool cmp(Y a,Y b)
{
	return a.l<b.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int a=1;a<=m1;a++)
	{
		scanf("%d%d",&px[a].l,&px[a].r);
	}
	sort(px+1,px+1+m1,cmp);
	for(int a=1;a<=m1;a++)
	{
		l=px[a].l;
		r=px[a].r;
		while(!q.empty()&&q.top().r<l)
		{
			j2.bh=q.top().bh;
			j2.r=q.top().r;
			j2.cnt=q.top().cnt;
			q.pop();
			q2.push(j2);
		}
		if(!q2.empty())
		{
			j.r=r;
			j.bh=q2.top().bh;
			j.cnt=q2.top().cnt+1;
			q2.pop();
			q.push(j);
		}
		else 
		{
			j.r=r;
			j.bh=++cnt;
			j.cnt=1;
			q.push(j);
		}
	}
	while(!q.empty())
	{
		h[q.top().bh]=q.top().cnt;
		q.pop();
	}
	while(!q2.empty())
	{
		h[q2.top().bh]=q2.top().cnt;
		q2.pop();
	}
	for(int a=1;a<=m2;a++)
	{
		scanf("%d%d",&px[a].l,&px[a].r);	
	}
	sort(px+1,px+1+m2,cmp);
	for(int a=1;a<=m2;a++)
	{
		l=px[a].l;
		r=px[a].r;
		while(!q.empty()&&q.top().r<l)
		{
			j2.bh=q.top().bh;
			j2.r=q.top().r;
			j2.cnt=q.top().cnt;
			q.pop();
			q2.push(j2);
		}
		if(!q2.empty())
		{
			j.r=r;
			j.bh=q2.top().bh;
			j.cnt=q2.top().cnt+1;
			q2.pop();
			q.push(j);
		}
		else 
		{
			j.r=r;
			j.bh=++cnt2;
			j.cnt=1;
			q.push(j);
		}
	}
	while(!q.empty())
	{
		h2[q.top().bh]=q.top().cnt;
		q.pop();
	}
	while(!q2.empty())
	{
		h2[q2.top().bh]=q2.top().cnt;
		q2.pop();
	}
	for(int a=1;a<=n;a++) h[a]+=h[a-1];
	for(int a=1;a<=n;a++) h2[a]+=h2[a-1];
	for(int a=0;a<=n;a++)
	{
		ans=max(ans,h[a]+h2[n-a]);
	}
	printf("%d",ans);
	return 0;
}
