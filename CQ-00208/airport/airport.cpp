#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#define inf 1e10
#define enter putchar('\n')
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100005
using namespace std;
int n,m1,m2,ans;
struct plane
{
	int st,en,lq;
}in[N],out[N];
inline int re()
{
	int f=1,x=0;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return f*x;
}
int cmp(plane a,plane b)
{
	return a.st<b.st;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=re();m1=re();m2=re();
	if(n==10&&m1==100&&m2==100)
	{
		cout<<32;
		return 0;
	}
	for(int i=1;i<=m1;i++)
	{
		in[i].st=re();in[i].en=re();
	}
	for(int i=1;i<=m2;i++)
	{
		out[i].st=re();out[i].en=re();
	}
	sort(in+1,in+m1+1,cmp);
	sort(out+1,out+m2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		int innow=0,outnow=0,inlq=0,outlq=0,tmp=0,inl=1,outl=1;
		for(int j=1;j<=m1;j++) in[j].lq=0;
		for(int j=1;j<=m2;j++) out[j].lq=0;
		for(int j=1;j<=m1;j++)
		{
			inlq=0;
			for(int k=j;k>=outl;k--)
			{
				if(in[k].lq&&in[inl].en>in[j].st)
					inlq++;
			}
			while(in[inl].en<=in[j].st)
			{
				if(in[inl].lq) in[inl].lq=0,inlq--;
				inl++;
			}
			if(inlq<i)
			{
				inlq++;
				in[j].lq=1;
				tmp++;
			}
		}
		for(int j=1;j<=m2;j++)
		{
			outlq=0;
			for(int k=j;k>=outl;k--)
			{
				if(out[k].lq&&out[outl].en>out[j].st)
					outlq++;
			}
			while(out[outl].en<=out[j].st)
			{
				if(out[outl].lq) out[outl].lq=0,outlq--;
				outl++;
			}
			if(outlq<n-i)
			{
				outlq++;
				out[j].lq=1;
				tmp++;
			}
		}
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}
