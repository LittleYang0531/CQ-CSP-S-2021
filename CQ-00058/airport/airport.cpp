#include<iostream>
#include<cstring>
#include<cstdio>

#define maxn 100005
#define rc() getchar()

using namespace std;

struct node{int l,r;}a[maxn],b[maxn];
int f1[maxn],f2[maxn],lst[maxn],nxt[maxn];

inline int read()
{
	int x=0,b=1;char c=rc();
	while(c<'0'||c>'9') (c=='-')&&(b=-1),c=rc();
	while(c>='0'&&c<='9') x=x*10+(c^48),c=rc();
	return x*b;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	int n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;++i)
		a[i].l=read(),a[i].r=read(),lst[i]=i-1,nxt[i]=i+1;
	for(int i=1;i<=m2;++i)
		b[i].l=read(),b[i].r=read();
	int st=1;
	for(int i=1;i<=n;++i)
	{
		int en=0;
		for(int j=st;j<=m1;j=nxt[j])
		{
			if(en<a[j].l)
			{
				if(j==st) st=nxt[j];
				++f1[i];en=max(en,a[j].r);
				int l=lst[j],r=nxt[j];
				nxt[l]=r;lst[r]=l;
			}
		}
	}
	for(int i=1;i<=m2;++i)	
		lst[i]=i-1,nxt[i]=i+1;
	st=1;
	for(int i=1;i<=n;++i)
	{
		int en=0;
		for(int j=st;j<=m2;j=nxt[j])
		{
			if(en<b[j].l)
			{
				if(j==st) st=nxt[j];
				++f2[i];en=max(en,b[j].r);
				int l=lst[j],r=nxt[j];
				nxt[l]=r;lst[r]=l;
			}
		}
	}
	for(int i=1;i<=n;++i) f1[i]+=f1[i-1];
	for(int i=1;i<=n;++i) f2[i]+=f2[i-1];
	int ans=0;
	for(int i=1;i<=n;++i)
	{
		ans=max(ans,f1[i]+f2[n-i]);
	}
	cout<<ans;
	return 0;
}
