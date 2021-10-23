#include <cstdio>
#include <iostream>
#include <algorithm>
using namespace std;
const int M = 200005;
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int n,m1,m2,ans,use[M];
struct node
{
	int x,id,f;
	bool operator < (const node &b) const
	{
		return x<b.x;
	}
}a[M],b[M];
int check(node *a,int m,int x)
{
	int nw=0,res=0;
	for(int i=1;i<=m;i++) use[i]=0;
	for(int i=1;i<=m;i++)
	{
		if(a[i].f==0)//left
		{
			if(nw<x)//get in
				use[a[i].id]=1,nw++,res++;
		}
		else//right
		{
			if(use[a[i].id])//delete now
				use[a[i].id]=0,nw--;
		}
	}
	return res;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++)
	{
		int l=read(),r=read();
		a[2*i-1]=node{l,i,0};
		a[2*i]=node{r,i,1};
	}
	for(int i=1;i<=m2;i++)
	{
		int l=read(),r=read();
		b[2*i-1]=node{l,i,0};
		b[2*i]=node{r,i,1};
	}
	m1<<=1;m2<<=1;
	sort(a+1,a+1+m1);
	sort(b+1,b+1+m2);
	for(int i=0;i<=n;i++)
		ans=max(ans,check(a,m1,i)+
		check(b,m2,n-i));
	printf("%d\n",ans);
}
