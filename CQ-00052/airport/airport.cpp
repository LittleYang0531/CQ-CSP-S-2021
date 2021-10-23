#include <cstdio>
#include <algorithm>
#include <queue>
using namespace std;
const int Max=1e5+5;
int n,m1,m2,mx;
struct Plane{
	int s,e;
	bool operator < (const Plane& x) const {return s<x.s;}
}p1[Max],p2[Max];

inline int read()
{
	int x=0,f=1;
	char ch=getchar();
	for(;ch<'0'||ch>'9';ch=getchar()) f= ch=='-' ? -1:1;
	for(;ch<='9'&&ch>='0';ch=getchar()) x=(x<<1)+(x<<3)+(ch-'0');
	return x*f;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) p1[i].s=read(),p1[i].e=read();
	for(int i=1;i<=m2;i++) p2[i].s=read(),p2[i].e=read();
	sort(p1+1,p1+1+m1);
	sort(p2+1,p2+1+m2);
	
	for(int i=0;i<=n;i++) 
	{
		//i表p1的站台数 
		int sum1=0;
		if(i)
		{
		queue <int> ol;//online
		int l=0;
		while(l<m1)
		{
			if(!ol.empty()&&ol.front()<p1[l+1].s) ol.pop();
			if(ol.size()<i) ol.push(p1[l+1].e),sum1++;
			l++;
		}
		}
		int sum2=0;
		if(i!=n)
		{
		queue <int> ol;//online
		int l=0;
		while(l<m2)
		{
			if(!ol.empty()&&ol.front()<p2[l+1].s) ol.pop();
			if(ol.size()<n-i) ol.push(p2[1+l].e),sum1++;
			l++;
		}
		}
		mx=max(mx,sum1+sum2);
	}
	printf("%d\n",mx);
	return 0;
}
