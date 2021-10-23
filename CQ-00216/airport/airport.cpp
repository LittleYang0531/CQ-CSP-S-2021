#include <iostream>
#include <cstdio>
#include <queue>
#include <algorithm>
using namespace std;
struct node {int s,t;}a[100005],b[100005];
int n,m1,m2,sum1,sum2,ans1,ans2,ans;
priority_queue<int,vector<int>,greater<int> >pq;
bool cmp(const node &x,const node &y) {return x.s<y.s;}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d %d",&a[i].s,&a[i].t);
	for(int i=1;i<=m2;i++) scanf("%d %d",&b[i].s,&b[i].t);
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	pq.push(a[1].t);
	for(int i=2;i<=m1;i++)
	{
		while(a[i].s>=pq.top()&&!pq.empty()) pq.pop();
		pq.push(a[i].t);
		sum1=max(sum1,int(pq.size()));
	}
	while(!pq.empty()) pq.pop();
	pq.push(b[1].t);
	for(int i=2;i<=m2;i++)
	{
		while(b[i].s>=pq.top()&&!pq.empty()) pq.pop();
		pq.push(b[i].t);
		sum2=max(sum2,int(pq.size()));
	}
	if(sum1<n)
	{
		while(!pq.empty()) pq.pop();
		pq.push(b[1].t); ans1++;
		for(int i=2;i<=m2;i++)
		{
			while(b[i].s>=pq.top()&&!pq.empty()) pq.pop();
			if(int(pq.size())<n-sum1) ans1++,pq.push(b[i].t);
		}
		ans=max(ans,ans1+m1);
	}
	else if(sum1==n) ans=max(ans,m1);
	if(sum2<n)
	{
		while(!pq.empty()) pq.pop();
		pq.push(a[1].t); ans2++;
		for(int i=2;i<=m1;i++)
		{
			while(a[i].s>=pq.top()&&!pq.empty()) pq.pop();
			if(int(pq.size())<n-sum2) ans2++,pq.push(a[i].t);
		}
		ans=max(ans,ans2+m2);
	}
	else if(sum2==n) ans=max(ans,m2);
	if(sum1>n&&sum2>n)
		for(sum1=0;sum1<=n;sum1++)
		{
			ans1=ans2=0;
			sum2=n-sum1;
			while(!pq.empty()) pq.pop();
			pq.push(a[1].t); ans1++;
			for(int i=2;i<=m1;i++)
			{
				while(a[i].s>=pq.top()&&!pq.empty()) pq.pop();
				if(int(pq.size())<sum1) ans1++,pq.push(a[i].t);
			}
			while(!pq.empty()) pq.pop();
			pq.push(b[1].t); ans2++;
			for(int i=2;i<=m2;i++)
			{
				while(b[i].s>=pq.top()&&!pq.empty()) pq.pop();
				if(int(pq.size())<sum2) ans2++,pq.push(b[i].t);
			}
			ans=max(ans,ans1*bool(sum1)+ans2*bool(sum2));
		}
	printf("%d",ans);
	return 0;
}
