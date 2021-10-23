#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
long long ge[100001][2],cnt1,cnt2;
long long bj[100001][2];
long long sum[100001][2],b[100001];
long long maxx;
long long n,im,om;
long long ans;
struct ut
{
	long long h,t;
}ne[100001],wa[100001];
bool cmp(ut a,ut b)
{
	return a.h<b.h;
}
void dfs1(long long x)
{
	ans++;
	bj[x][0]=1;
	if(ne[im].h<ne[x].t)return ;
	long long wei=-1;
	for(long long i=lower_bound(b+x+1,b+im+1,ne[x].t)-b;i<=im;i++)
	{
		if(bj[i][0]==1)continue;
		wei=i;
		break;
	}
	if(wei==-1)return ;
	dfs1(wei);
}
void dfs2(long long x)
{
	ans++;
	bj[x][1]=1;
	if(wa[om].h<wa[x].t)return ;
	long long wei=-1;
	for(long long i=lower_bound(b+x+1,b+om+1,wa[x].t)-b;i<=om;i++)
	{
		if(bj[i][1]==1)continue;
		wei=i;
		break;
	}
	if(wei==-1)return ;
	dfs2(wei);
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&im,&om);
	for(long long i=1;i<=im;i++)scanf("%lld%lld",&ne[i].h,&ne[i].t);
	for(long long i=1;i<=om;i++)scanf("%lld%lld",&wa[i].h,&wa[i].t);
	sort(ne+1,ne+im+1,cmp);
	sort(wa+1,wa+om+1,cmp);
	for(long long i=1;i<=im;i++)b[i]=ne[i].h;
	for(long long i=1;i<=im;i++)
	{
		if(bj[i][0]==0)
		{
			ans=0;
			dfs1(i);
			ge[++cnt1][0]=ans;
		}
	}
	for(long long i=1;i<=om;i++)b[i]=wa[i].h;
	for(long long i=1;i<=om;i++)
	{
		if(bj[i][1]==0)
		{
			ans=0;
			dfs2(i);
			ge[++cnt2][1]=ans;
		}
	}
	for(long long i=1;i<=n;i++)sum[i][0]=sum[i-1][0]+ge[i][0];
	for(long long i=1;i<=n;i++)sum[i][1]=sum[i-1][1]+ge[i][1];
	for(long long i=0;i<=n;i++)
	{
		if(sum[i][0]+sum[n-i][1]>maxx)maxx=sum[i][0]+sum[n-i][1];
	}
	printf("%lld",maxx);
	return 0;
}
