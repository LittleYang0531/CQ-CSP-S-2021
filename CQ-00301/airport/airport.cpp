#include<algorithm>
#include<iostream>
#include<cstdio>
const int N=1e5+5;
using namespace std;
//#define getchar gc
inline int read()
{
	char h=getchar();
	int y=0,q=1;
	while(h<'0'||h>'9'){if(h=='-')q=-1;h=getchar();}
	while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();
	return y*q;
}
struct node{
	int a,b;
	bool operator<(const node x)const
	{
		return a<x.a;
	}
}q1[N],q2[N];
int l1[N],l2[N],r1[N],r2[N],ne1[N],ne2[N],ans1[N],ans2[N];
int head1,head2,tail1,tail2,m1,m2;
bool v1[N],v2[N];
int fi1(int x)
{
	if(x>m1)return -1;
	return !v1[x]?x:r1[x]=fi1(r1[x]);
}
int fi2(int x)
{
	if(x>m2)return -1;
	return !v2[x]?x:r2[x]=fi2(r2[x]);
}
int main()
{
//	cout<<((&me1-&me2)>>20)<<"!!!\n";
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=read();m1=read(),m2=read();
	for(int i=1;i<=m1;i++)q1[i].a=read(),q1[i].b=read();
	for(int i=1;i<=m2;i++)q2[i].a=read(),q2[i].b=read();
	sort(q1+1,q1+1+m1);sort(q2+1,q2+1+m2);
	for(int i=1;i<=m1;i++)
	{
		int l=i+1,r=m1,da=m1+1;
		while(l<=r)
		{
			int m=(l+r)>>1;
			if(q1[m].a>=q1[i].b)da=m,r=m-1;
			else l=m+1;
		}
		ne1[i]=da;
	}
	for(int i=1;i<=m2;i++)
	{
		int l=i+1,r=m2,da=m2+1;
		while(l<=r)
		{
			int m=(l+r)>>1;
			if(q2[m].a>=q2[i].b)da=m,r=m-1;
			else l=m+1;
		}
		ne2[i]=da;
	}
//	cout<<"!!!\n";
//	for(int i=1;i<=m1;i++)cout<<i<<":"<<ne1[i]<<"!!!\n";
//	for(int i=1;i<=m2;i++)cout<<i<<":"<<ne2[i]<<"!!!\n";
	for(int i=1;i<=m1;i++)l1[i]=i-1,r1[i]=i+1;
	for(int i=1;i<=m2;i++)l2[i]=i-1,r2[i]=i+1;
	head1=1,tail1=m1;head2=1,tail2=m2;
	for(int i=1;i<=n;i++)
	{
		ans1[i]=ans1[i-1];
		if(ans1[i]!=m1)
		{
			int x=head1;
			while(x!=-1)
			{
				ans1[i]++;
				if(x==head1)head1=r1[x];
				else if(x==tail1)tail1=l1[x];
				else l1[r1[x]]=l1[x],r1[l1[x]]=r1[x];
				v1[x]=1;
				x=fi1(ne1[x]);
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans2[i]=ans2[i-1];
		if(ans2[i]!=m2)
		{
			int x=head2;
			while(x!=-1)
			{
				ans2[i]++;
				if(x==head2)head2=r2[x];
				else if(x==tail2)tail2=l2[x];
				else l2[r2[x]]=l2[x],r2[l2[x]]=r2[x];
				v2[x]=1;
				x=fi2(ne2[x]);
			}
		}
	}
//	for(int i=0;i<=n;i++)cout<<i<<":"<<ans1[i]<<" "<<ans2[i]<<"!!!\n"; 
	int ma=0;
	for(int i=0;i<=n;i++)ma=max(ma,ans1[i]+ans2[n-i]);
	cout<<ma<<"\n";
	return 0;
}
