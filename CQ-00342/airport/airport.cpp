#include<bits/stdc++.h>
using namespace std;

const int N=1e5+5;
int la[N],num[N],sinsd[N],sousd[N];
priority_queue < pair < int,int > > q;
struct Node
{
	int a,b;
}insd[N],ousd[N];
struct LTree
{
	struct Tree
	{
		int l,r,val;
	}tree[N<<2];
	inline void build(int id,int l,int r)
	{
		tree[id].l=l; tree[id].r=r;
		if( l==r ) { tree[id].val=1e8+5; return; }
		int mid=l+r>>1;
		build(id<<1,l,mid);
		build(id<<1|1,mid+1,r);
		tree[id].val=min(tree[id<<1].val,tree[id<<1|1].val);
	}
	inline void updata(int id,int k,int val)
	{
		if( tree[id].l==tree[id].r ) {tree[id].val=val; return; }
		int mid=tree[id].l+tree[id].r>>1;
		if( k <= mid ) updata(id<<1,k,val);
		else updata(id<<1|1,k,val);
		tree[id].val=min(tree[id<<1].val,tree[id<<1|1].val);
	}
	inline int query(int id,int val)
	{
		if( tree[id].l==tree[id].r ) return tree[id].l;
		if( tree[id<<1].val < val ) return query(id<<1,val);
		else if( tree[id<<1|1].val < val ) return query(id<<1|1,val);
		else return -1;
	}
}t1,t2;

inline int read()
{
	int x=0,f=1; char ch=getchar();
	while( ch < '0' or ch > '9' ) f *= ch=='-' ? -1 : 1, ch=getchar();
	while( ch >= '0' and ch <= '9' ) x =x*10+ch-'0', ch=getchar();
	return x*f;
}

inline bool cmp(Node x,Node y) { return x.a < y.a; }

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	
	int n=read(),m1=read(),m2=read();
	for(int i=1;i<=m1;i++) insd[i].a=read(),insd[i].b=read(); sort(insd+1,insd+m1+1,cmp);
	for(int i=1;i<=m2;i++) ousd[i].a=read(),ousd[i].b=read(); sort(ousd+1,ousd+m2+1,cmp);
	int cnt1=0; 
	t1.build(1,1,m1);
	for(int i=1;i<=m1;i++)
	{
		if( t1.query(1,insd[i].a)==-1 ) { t1.updata(1,++cnt1,insd[i].b); num[cnt1]++; }
		else { int x=t1.query(1,insd[i].a); t1.updata(1,x,insd[i].b); num[x]++; }
	}
	for(int i=1;i<=n;i++) sinsd[i]=sinsd[i-1]+num[i];

	memset(num,0,sizeof(num));
	int cnt2=0; 
	t2.build(1,1,m2);
	for(int i=1;i<=m2;i++)
	{
		if( t2.query(1,ousd[i].a)==-1 ) { t2.updata(1,++cnt2,ousd[i].b); num[cnt2]++; }
		else { int x=t2.query(1,ousd[i].a); t2.updata(1,x,ousd[i].b); num[x]++; }
	}
	for(int i=1;i<=n;i++) sousd[i]=sousd[i-1]+num[i];
	
	int ans=0;
	for(int i=0;i<=n;i++) ans=max(ans,sinsd[i]+sousd[n-i]);
	printf("%d",ans);
	return 0;
}
