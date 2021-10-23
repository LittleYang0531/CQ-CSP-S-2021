#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
struct abc
{
	int start,end;
}a[100005],b[100005];
int f[100005][2];
bool vis[100005][2];
bool cmp(abc a,abc b)
{
	if(a.start==b.start)return a.end<b.end;
	return a.start<b.start;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d %d",&a[i].start,&a[i].end);
	for(int i=1;i<=m2;i++)scanf("%d %d",&b[i].start,&b[i].end);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	f[0][0]=f[0][1]=0;
	int p,k;
	int cnt1=0;
	while(1)
	{
		bool flag=0;
		for(int i=1;i<=m1;i++)
		{
			if(!vis[i][0])
			{
				k=i;
				flag=1;
				break;
			}
		}
		if(flag==0)break;
		p=0;
		cnt1++;
		for(int i=k;i<=m1;i++)
		{
			if(a[i].start>=p && !vis[i][0])
			{
				f[cnt1][0]++;
				p=a[i].end;
				vis[i][0]=1;
			}
		}
		if(cnt1>=n)break;
	}
	int cnt2=0;
	while(1)
	{
		bool flag=0;
		for(int i=1;i<=m2;i++)
		{
			if(!vis[i][1])
			{
				k=i,flag=1;
				break;
			}
		}
		if(flag==0)break;
		p=0;
		cnt2++;
		for(int i=k;i<=m2;i++)
		{
			if(b[i].start>=p && !vis[i][1])
			{
				f[cnt2][1]++;
				p=b[i].end;
				vis[i][1]=1;
			}
		}
		if(cnt2>=n)break;
	}
	int maxn=0;
	for(int i=1;i<=n;i++)
	{
		f[i][0]+=f[i-1][0];
		f[i][1]+=f[i-1][1];
//		printf("%d %d\n",f[i][0],f[i][1]);
	}
	for(int i=0;i<=n;i++)
	{
		maxn=max(maxn,f[i][0]+f[n-i][1]);
	}
	printf("%d",maxn);
	return 0;
}

