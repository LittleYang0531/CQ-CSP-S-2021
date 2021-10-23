#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<cstring>
#include<algorithm>
#define N 100005
#define INF 0x7fffffff
using namespace std;
struct airplane
{
	int s,t;
}C[N],O[N];
int vstc[N],vsto[N];
int cg[N],og[N];
int n,m1,m2;
bool cmp(airplane a,airplane b)
{
	return a.s<b.s;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d %d",&C[i].s,&C[i].t);
	for(int i=1;i<=m2;i++) scanf("%d %d",&O[i].s,&O[i].t);
	sort(C+1,C+m1+1,cmp);
	sort(O+1,O+m2+1,cmp);
	int Cnum=m1,Onum=m2;
	int carr=0,oarr=0;
	while(Cnum)
	{
		cg[++carr]=1;
		if(carr>n) break;
		int first;
		for(int i=1;i<=m1;i++)
		{
			if(!vstc[i]) 
			{
				first=i;
				vstc[i]=1;
				Cnum--;
				break;
			}
		}
		int Ed=C[first].t;
		for(int j=first+1;j<=m1;j++)
		{
			if(!vstc[j] && C[j].s>Ed) 
			{
				vstc[j]=1;
				Ed=C[j].t;
				cg[carr]++;
				Cnum--;
			}
		}
	}
	while(Onum)
	{
		if(oarr>n) break;
		og[++oarr]=1;
		int first;
		for(int i=1;i<=m2;i++)
		{
			if(!vsto[i]) 
			{
				first=i;
				vsto[i]=1;
				Onum--;
				break;
			}
		}
		int Ed=O[first].t;
		for(int j=first+1;j<=m2;j++)
		{
			if(!vsto[j] && O[j].s>Ed)
			{
				vsto[j]=1;
				Ed=O[j].t;
				og[oarr]++;
				Onum--;
			}
		}
	}
	int maxx=0;
	for(int i=1;i<=n;i++)
	{
		cg[i]+=cg[i-1];
		og[i]+=og[i-1];
	}
	for(int cf=0;cf<=n;cf++)
	{
		int of=n-cf;
		maxx=max(maxx,og[of]+cg[cf]);
	}
	printf("%d",maxx);
	return 0;
}
