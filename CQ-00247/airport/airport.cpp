#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
#include<queue>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
#define fi first
#define se second
#define PII pair<int,int>
const int N=1e5+5,INF=0x3f3f3f3f,mod=1e9+7;
int read()
{
	int r=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)) r=r*10+(ch^48),ch=getchar();
	return r*f;
}
using namespace std;
namespace ss
{
	
}
int n,m1,m2;
pair<int,int>a[N],b[N];
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	FOR(i,1,m1)	{	a[i].fi=read(),a[i].se=read();}
	FOR(i,1,m2) b[i].fi=read(),b[i].se=read();
	sort(a+1,a+m1+1);sort(b+1,b+m2+1);
	int ans=0;
	FOR(i,0,n)
	{
		int sum=0,cnt;
		if(i>0)
		{
			while(!q.empty())q.pop();
			sum++;cnt=1;
			q.push(a[1].se);
			FOR(j,2,m1)
			{
				if(a[j].fi<q.top()&&cnt<i) q.push(a[j].se),sum++,cnt++;
				else if(a[j].fi>q.top()) q.pop(),q.push(a[j].se),sum++;
				
			}
		}
		if(i<n)
		{
			cnt=1;
			sum++;
			while(!q.empty())q.pop();
			q.push(b[1].se);
			FOR(j,2,m2)
			{
				if(b[j].fi<q.top()&&cnt<(n-i)) q.push(b[j].se),sum++,cnt++;
				else if(b[j].fi>q.top()) q.pop(),q.push(b[j].se),sum++;
				
			}
		}
		ans=max(ans,sum);
	}
	printf("%d",ans);
//	FOR(i,1,m1)
//	{
//		if(vis[i]) continue;
//		vis[i]=1;
//		int val=1,j=i;
//		while(1)
//		{
//			int p=upper_bound(x+j+1,x+m1+1,make_pair(x[i].se,0))-x;
//		if(p>m1) break;
//		vis[p]=1;val++;j=p;
//		}
//		q1[++q1[0]]=val;
//	}
//	FOR(i,1,m2)y[i].fi=read(),y[i].se=read();
//	sort(y+1,y+m2+1);
//	FOR(i,1,m2)
//	{
//		if(vis[i]) continue;
//		vis[i]=1;
//		int val=1,j=i;
//		while(1)
//		{
//			int p=upper_bound(y+j+1,y+m2+1,make_pair(y[i].se,0))-y;
//		if(p>m2) break;
//		vis[p]=1;val++;j=p;
//		}
//		q2[++q2[0]]=val;
//	}
//	int sum=0;
//	FOR(i,1,n) sum+=q1[i];
//	int ans=sum;
//	for(int i=n;i>=1;i--)
//	{
//		sum-=q1[i];
//		sum+=q2[n-i+1];
//		ans=max(ans,sum);
//	}
//	printf("%d",ans);
	return 0;
}

