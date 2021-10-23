#include<bits/stdc++.h>
#define N 5005
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') 
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-48;
		ch=getchar();
	}
	return x*f;
}
int mmax,n,m1,m2,t1,t2,tree[N<<2],lazy[N<<2];
struct node
{
	int l,r,id;
}a[N*2]; 
struct G
{
	int id,val;
}t[N*2];
int ord(G x,G y)
{
	return x.val<y.val;
}
int cmp(node x,node y)
{
	return x.l<y.l;
}
map<int,int>m;
void pushdown(int l,int r,int node)
{
	if(lazy[node])
	{
		tree[node<<1]+=lazy[node];
		tree[node<<1|1]+=lazy[node];
		lazy[node<<1]+=lazy[node];
		lazy[node<<1|1]+=lazy[node];
		lazy[node]=0;
	}
}
void change(int l,int r,int node,int x,int y,int v)
{
	if(r<x||l>y) return;
	if(x<=l&&r<=y)
	{
		tree[node]+=v;
		lazy[node]+=v;
		return;
	}
	int mid=(l+r)>>1;
	pushdown(l,r,node);
	change(l,mid,node<<1,x,y,v);
	change(mid+1,r,node<<1|1,x,y,v);
	tree[node]=max(tree[node<<1],tree[node<<1|1]);
}
int ans,tot;
int query(int l,int r,int node,int x,int y)
{
	if(r<x||l>y) return 0;
	if(x<=l&&r<=y)
	{
		return tree[node];
	}
	int mid=(l+r)>>1;
	pushdown(l,r,node);
	return max(query(l,mid,node<<1,x,y),query(mid+1,r,node<<1|1,x,y));
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;i++)
	{
		int f=read();
		t[++tot].val=f;
		t[tot].id=f;
		a[i].l=f;
		f=read();
		t[++tot].val=f;
		t[tot].id=f;
		a[i].r=f;
	}
	for(int i=m1+1;i<=m1+m2;i++)
	{
		int f=read();
		t[++tot].val=f;
		t[tot].id=f;
		a[i].l=f;
		f=read();
		t[++tot].val=f;
		t[tot].id=f;
		a[i].r=f;
	}
	sort(t+1,t+tot+1,ord);
	for(int i=1;i<=tot;i++)
	{
		m[t[i].id]=i;
	}

	sort(a+1,a+m1+1,cmp);sort(a+m1+1,a+m1+m2+1,cmp);
	for(int p=0;p<=n;p++)
	{
		int tmp=m1+m2;
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
		mmax=0;
		for(int i=1;i<=m1;i++)
		{
			change(1,tot,1,m[a[i].l],m[a[i].r],1);
			mmax=max(mmax,a[i].r);
			int now=query(1,tot,1,1,mmax);
			if(now>p)
			{
				change(1,tot,1,m[a[i].l],m[a[i].r],-1);
				tmp--;
			}	
		}
		memset(tree,0,sizeof(tree));
		memset(lazy,0,sizeof(lazy));
		mmax=0;
		for(int i=m1+1;i<=m1+m2;i++)
		{
			change(1,tot,1,m[a[i].l],m[a[i].r],1);
			mmax=max(mmax,m[a[i].r]);
			int now=query(1,tot,1,1,mmax);
			if(now>n-p)
			{
				change(1,tot,1,m[a[i].l],m[a[i].r],-1);
				tmp--;
			}	
		}
		ans=max(ans,tmp);
	}
	cout<<ans;
	return 0;
}
