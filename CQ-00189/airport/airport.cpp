#include<stdio.h>
#include<string.h>
#include<iostream>
#include<algorithm>
#define maxm 100001
using namespace std;
struct data{int start,end;}c[maxm],u[maxm];
int n,m,mm;
bool cmp(data aaa,data bbb)
{
	if(aaa.start==bbb.start) return aaa.end<bbb.end;
	return aaa.start<bbb.start;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m,&mm);
	for(int i=1;i<=m;++i) scanf("%d %d",&c[i].start,&c[i].end);
	for(int i=1;i<=mm;++i) scanf("%d %d",&u[i].start,&u[i].end);
	sort(c+1,c+m+1,cmp);
	sort(u+1,u+mm+1,cmp);
	int Maxc=1,Maxu=1,ans=0,anss=0;
	for(int i=2;i<=m;++i)
	{
		int j;
		for(j=i+1;j<=m;++j)
		{
			if(c[j].start>c[i].end) break;
		}
		ans=max(ans,j-i);
	}
	for(int i=2;i<=mm;++i)
	{
		int j;
		for(j=i+1;j<=mm;++j)
		{
			if(u[j].start>u[i].end) break;
		}
		anss=max(anss,j-i);
	}
	printf("%d",m+mm-(ans+anss-n));
	return 0;
}
