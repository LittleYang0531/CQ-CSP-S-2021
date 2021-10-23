#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<map>
#include<queue>
#include<set>
#define ll long long
using namespace std;
const int N=100010;
struct MSQWQ{
	int st,en;
}a[N],b[N];
int n,m1,m2;
int ans1[N],ans2[N];
int v[N];
bool cmp(MSQWQ x,MSQWQ y){return x.st<y.st;}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].st,&a[i].en);
	for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].st,&b[i].en);
	sort(a+1,a+1+m1,cmp),sort(b+1,b+1+m2,cmp);
	ans1[0]=ans2[0]=0;
	for(int i=1;i<=n;i++)
	{
		ans1[i]=ans1[i-1];
		int now,time;
		for(int j=1;j<=m1;j++)
		{
			if(!v[j])
			{
				now=j,v[j]=1,time=a[j].en,ans1[i]++;
				break;
			}
		}
		for(int j=now+1;j<=m1;j++)
		{
			if(a[j].st>time&&!v[j])
			{
				ans1[i]++;
				time=a[j].en;
				v[j]=1;
			}
		}
		if(ans1[i]==m1)
		{
			for(int j=i+1;j<=m1;j++)ans1[j]=m1;
			break;
		}
	}
	memset(v,0,sizeof(v));
	for(int i=1;i<=n;i++)
	{
		ans2[i]=ans2[i-1];
		int now,time;
		for(int j=1;j<=m2;j++)
		{
			if(!v[j])
			{
				now=j,v[j]=1,time=b[j].en,ans2[i]++;
				break;
			}
		}
		for(int j=now+1;j<=m2;j++)
		{
			if(b[j].st>time&&!v[j])
			{
				ans2[i]++;
				time=b[j].en;
				v[j]=1;
			}
		}
		if(ans2[i]==m2)
		{
			for(int j=i+1;j<=m2;j++)ans2[j]=m2;
			break;
		}
	}

	int ans=0;
	for(int i=0;i<=n;i++)ans=max(ans,ans1[i]+ans2[n-i]);
	printf("%d",ans);
	return 0;	
}
