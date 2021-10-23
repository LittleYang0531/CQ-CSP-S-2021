#include<bits/stdc++.h>
using namespace std;
long long n,m,sum,cnt,pam,m1,maxx;
struct sb{
	int ks,js,sy;
}a[100001];
struct node{
	int dd,lk,y;
}b[100001];
int sb(int x,int y)
{
	int tent=0,md=0,g=1,h=1,cmp=1,mn=1,hop=0x7ffff,f=0,d=0,cap=0x7ffff,sm[100001]={0},ms[100001]={0},my[100001]={0},yy[100001]={0};
	sm[mn]=a[g].js;
	a[1].sy=1;
	b[1].y=1;
	for(int i=2;i<=m;i++)
	{
		for(int j=1;j<=mn;j++)
		{
			if(sm[j]<hop&&yy[j]==0)
			{
				hop=sm[j];
				d=j;
			}
		}
		if(a[i].ks<hop&&g<x)
		{
			g++;
			hop=a[i].js;
			a[i].sy=1;
		}
		if(a[i].ks>=hop){
		    yy[d]=1;
			hop=a[i].js;
			a[i].sy=1;
		}
    }
	ms[cmp]=a[h].js;
	for(int i=2;i<=m1;i++)
    {
    	for(int j=1;j<=cmp;j++)
    	{
    		if(cap<ms[j]&&my[j]==0)
    		{
    			cap=ms[j];
    			f=j;
			}
		}
		
		if(b[i].dd<cap&&h<y)
		{
		    h++;
		    cap=b[i].lk;
			b[i].y=1;
		}
		if(b[i].dd>=cap){
			my[f]=1;
			cap=b[i].lk;
			b[i].y=1;
		}
	}
    for(int i=1;i<=m;i++)
    {
    	if(a[i].sy==1)
    	tent++;
	}
	for(int i=1;i<=m1;i++)
    {
    	if(b[i].y==1)
    	md++;
	}
	if(x==0)
	{
		tent=0;
	}
	if(y==0)
	{
		md=0;
	}
	return (tent+md);
}	
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m,&m1);
	for(int i=1;i<=m;i++)
	{
		scanf("%d%d",&a[i].ks,&a[i].js);
	}
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&b[i].dd,&b[i].lk);
	}
	
	for(int i=0;i<=n;i++)
	{
		cnt=i;
		pam=n-i;
		maxx=sb(cnt,pam);
		sum=max(maxx,sum);
	}
	printf("%d",sum);
}
