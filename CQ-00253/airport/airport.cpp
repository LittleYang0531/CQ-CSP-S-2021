#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int Maxn=1e5;
struct Node {
	int l,r;
}a[Maxn+5],b[Maxn+5];
int lsh[2*Maxn+5],n,m1,m2;
inline int mymax(int x,int y) {return x>y?x:y;}
struct SegTree {
	#define ls(p) (p<<1)
	#define rs(p) (p<<1|1)
	#define mid (((l)+(r))>>1)
	int v[Maxn<<2],lazy[Maxn<<2];
	void build(int p,int l,int r) {
		v[p]=lazy[p]=0;
		if(l==r)return ;
		build(ls(p),l,mid);
		build(rs(p),mid+1,r);
	}
	inline void update(int p) {
		v[p]=mymax(v[ls(p)],v[rs(p)]);
	}
	inline void spread(int p) {
		int x=lazy[p];lazy[p]=0;
		v[ls(p)]+=x,v[rs(p)]+=x;
		lazy[ls(p)]+=x,lazy[rs(p)]+=x;
	}
	void change(int p,int l,int r,int L,int R,int d) {
		if(L<=l&&r<=R) {
			v[p]+=d;lazy[p]+=d;
			return ;
		}
		if(lazy[p])spread(p);
		if(L<=mid)change(ls(p),l,mid,L,R,d);
		if(R>mid)change(rs(p),mid+1,r,L,R,d);
		update(p);
	}
	int query(int p,int l,int r,int L,int R) {
		if(L<=l&&r<=R)return v[p];
		if(lazy[p])spread(p);
		int ret=0;
		if(L<=mid)ret=max(ret,query(ls(p),l,mid,L,R));
		if(R>mid)ret=max(ret,query(rs(p),mid+1,r,L,R));
		return ret;
	}
}t[2];
bool cmp(Node a,Node b) {
	return a.l<b.l;
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(ri i=1;i<=m1;i++)scanf("%d%d",&a[i].l,&a[i].r);
	for(ri i=1;i<=m2;i++)scanf("%d%d",&b[i].l,&b[i].r);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for(ri i=1;i<=m1;i++)lsh[i*2-1]=a[i].l,lsh[i*2]=a[i].r;
	sort(lsh+1,lsh+2*m1+1);
	int cnta=unique(lsh+1,lsh+2*m1+1)-lsh-1;
	for(ri i=1;i<=m1;i++) {
		a[i].l=lower_bound(lsh+1,lsh+cnta+1,a[i].l)-lsh;
		a[i].r=lower_bound(lsh+1,lsh+cnta+1,a[i].r)-lsh;
	}
	for(ri i=1;i<=m2;i++)lsh[i*2-1]=b[i].l,lsh[i*2]=b[i].r;
	sort(lsh+1,lsh+2*m2+1);
	int cntb=unique(lsh+1,lsh+2*m2+1)-lsh-1;
	for(ri i=1;i<=m2;i++) {
		b[i].l=lower_bound(lsh+1,lsh+cntb+1,b[i].l)-lsh;
		b[i].r=lower_bound(lsh+1,lsh+cntb+1,b[i].r)-lsh;
	}
	int ans=0;
	for(ri i=0;i<=n;i++) {
		int cnt=0;
		t[0].build(1,1,cnta);
		t[1].build(1,1,cntb);
		for(ri j=1;j<=m1;j++) {
			if(t[0].query(1,1,cnta,a[j].l,a[j].r)<i) {
				++cnt;
				t[0].change(1,1,cnta,a[j].l,a[j].r,1);
			}
		}
		for(ri j=1;j<=m2;j++) {
			if(t[1].query(1,1,cntb,b[j].l,b[j].r)<n-i) {
				++cnt;
				t[1].change(1,1,cntb,b[j].l,b[j].r,1);
			}
		}
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}

