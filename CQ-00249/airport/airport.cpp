#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m1,m2;
int m;
struct node{
	int l,r;
	int op;
}a1[MAXN],a2[MAXN],a[MAXN];
bool cmp(node x,node y)
{
	if(x.l==y.l)
	{
		return x.r<y.r;
	}
	return x.l<y.l;
}
priority_queue<int,vector<int>,greater<int> >q1,q2,q;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d %d",&a1[i].l,&a1[i].r);
		a[i]=a1[i];
		a[i].op=1;
	}
	sort(a1+1,a1+1+m1,cmp);
	for(int i=1;i<=m2;i++)
	{
		scanf("%d %d",&a2[i].l,&a2[i].r);
		a[i+m1]=a2[i];
		a[i+m1].op=2;
	}
	sort(a2+1,a2+1+m2,cmp);
	m=m1+m2;
	sort(a+1,a+1+m,cmp);
	int ans=0;
	for(int i=1;i<=n;i++)
	{
		int tot=0;
		while(q.size())
		{
			q.pop();
		}
		for(int j=1;j<=m1;j++)
		{
			while(q.size())
			{
				if(q.top()<a1[j].l)
				{
					q.pop();
				}
				else
				{
					break;
				}
			}
			if(q.size()<i)
			{
				tot++;
				q.push(a1[j].r);
			}
		}
		while(q.size())
		{
			q.pop();
		}
		for(int j=1;j<=m2;j++)
		{
			while(q.size())
			{
				if(q.top()<a2[j].l)
				{
					q.pop();
				}
				else
				{
					break;
				}
			}
			if(q.size()<(n-i))
			{
				tot++;
				q.push(a2[j].r);
			}
		}
		ans=max(ans,tot);
	}
	printf("%d",ans);
	return 0;
}
