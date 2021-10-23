#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
#include<queue>
using namespace std;
int n,m1,m2,ans,tot,tot1,tot2;
int c[100005],d[100005],bj1[100005],bj2[100005];
int lsh[200005],t[100005];
struct xin{
	int l,r,id,next;
}a[100005],b[100005];
bool cmt(xin x,xin y)
{
	return x.l<y.l;
}
int lb(int u,int l,int r)
{
	int mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(a[mid].l>u) r=mid;
		else l=mid+1;
	}
	if(a[r].l<=u) return 0;
	return r;
}
int lb2(int u,int l,int r)
{
	int mid;
	while(l<r)
	{
		mid=(l+r)>>1;
		if(b[mid].l>u) r=mid;
		else l=mid+1;
	}
	if(b[r].l<=u) return 0;
	return r;
}
int findx(int u)
{
	if(!bj1[u]) return u;
	t[u]=findx(t[u]);
	return t[u];
}
int findy(int u)
{
	if(!bj2[u]) return u;
	t[u]=findy(t[u]);
	return t[u];
}
int findn(int u)
{
	int x;
	x=lb(a[u].r,u+1,m1);
	if(x==0) return 0;
	x=findx(x);
	if(x==0) return 0;
	a[u].next=x;
	bj1[x]=1;
	return findn(x)+1;
}
int findw(int u)
{
	int x;
	x=lb2(b[u].r,u+1,m2);
	if(x==0) return 0;
	x=findy(x);
	if(x==0) return 0;
	b[u].next=x;
	bj2[x]=1;
	return findw(x)+1;
}
int read()
{
	int s=0;
	char ch=getchar();
	while(ch<'0'||ch>'9') ch=getchar();
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		a[i].l=read();a[i].r=read();
		lsh[++tot]=a[i].l; lsh[++tot]=a[i].r;
	}
	for(int i=1;i<=m2;i++)
	{
		b[i].l=read();b[i].r=read();
		lsh[++tot]=b[i].l; lsh[++tot]=b[i].r;
	}
	sort(a+1,a+m1+1,cmt);
	sort(b+1,b+m2+1,cmt);
	sort(lsh+1,lsh+tot+1);
	tot=unique(lsh+1,lsh+tot+1)-lsh-1;
	for(int i=1;i<=m1;i++)
	{
		a[i].l=lower_bound(lsh+1,lsh+tot+1,a[i].l)-lsh;
		a[i].r=lower_bound(lsh+1,lsh+tot+1,a[i].r)-lsh;
	}
	for(int i=1;i<=m2;i++)
	{
		b[i].l=lower_bound(lsh+1,lsh+tot+1,b[i].l)-lsh;
		b[i].r=lower_bound(lsh+1,lsh+tot+1,b[i].r)-lsh;
	}
	for(int i=1;i<m1;i++)
	t[i]=i+1;
	for(int i=1;i<=m1&&tot1<=n;i++)
	if(!bj1[i]) c[++tot1]=findn(i)+1,bj1[i]=1;
	t[m2]=0;
	for(int i=1;i<m2;i++)
	t[i]=i+1;
	for(int i=1;i<=m2&&tot2<=n;i++)
	if(!bj2[i]) d[++tot2]=findw(i)+1,bj2[i]=1;
	for(int i=1;i<=n;i++)
	c[i]+=c[i-1];
	for(int i=1;i<=n;i++)
	d[i]+=d[i-1];
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,c[i]+d[n-i]);
	}
	printf("%d",ans);
}
