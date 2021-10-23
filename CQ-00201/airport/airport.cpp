#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define mod 1000000007
#define ll long long
#define N 200005
using namespace std;
template<class T>void read(T&x) {
	T f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
char _st;
int n,m1,m2,tot,ans1[N],ans2[N],lsh[N],R[N];
struct seg{int l,r;}a[N];
bool operator < (const seg &a,const seg &b){return a.l < b.l;}
int tag[N<<2];
struct node {
	int mx,pos;
	node operator + (const node &b)const {
		if(mx > b.mx)return *this;
		if(mx < b.mx)return b;
		return {mx,min(pos,b.pos)};
	}
}tr[N<<2];
void build(int v,int l,int r) {
	tr[v] = {0,l};tag[v] = 0;
	if(l == r)return;int mid = l+r>>1;
	build(v<<1,l,mid);build(v<<1|1,mid+1,r);
}
void pushtag(int v,int d){tag[v] += d;tr[v].mx += d;}
void pushdown(int v){if(tag[v])pushtag(v<<1,tag[v]),pushtag(v<<1|1,tag[v]),tag[v] = 0;}
void modify(int v,int l,int r,int L,int R,int d) {
	if(r < L || R < l)return;
	if(L <= l && r <= R)return pushtag(v,d);
	int mid = l+r>>1;pushdown(v);
	modify(v<<1,l,mid,L,R,d);modify(v<<1|1,mid+1,r,L,R,d);
	tr[v] = tr[v<<1]+tr[v<<1|1];
}
char _ed;
int main() {
	cerr << "Memory: " << ((&_st-&_ed)>>20) << '\n';
	file("airport");
	read(n);read(m1);read(m2);
	for(int i=1,l,r; i<=m1; ++i)read(l),read(r),a[i] = {l,r-1},lsh[++tot] = l,lsh[++tot] = r-1;
	sort(lsh+1,lsh+tot+1);tot = unique(lsh+1,lsh+tot+1)-lsh-1;
	build(1,1,tot);
	for(int i=1; i<=m1; ++i)a[i].l = lower_bound(lsh+1,lsh+tot+1,a[i].l)-lsh,a[i].r = lower_bound(lsh+1,lsh+tot+1,a[i].r)-lsh,modify(1,1,tot,a[i].l,a[i].r,1),R[a[i].l] = a[i].r;
	for(int i=max(n,m1),cur=m1; i>=1; --i) {
		while(tr[1].mx > i) {
			int p = tr[1].pos;
			modify(1,1,tot,p,R[p],-1);
			cur--;
		}
		ans1[i] = cur;
	}
	tot = 0;
	for(int i=1,l,r; i<=m2; ++i)read(l),read(r),a[i] = {l,r-1},lsh[++tot] = l,lsh[++tot] = r-1;
	sort(lsh+1,lsh+tot+1);tot = unique(lsh+1,lsh+tot+1)-lsh-1;
	build(1,1,tot);
	for(int i=1; i<=m2; ++i)a[i].l = lower_bound(lsh+1,lsh+tot+1,a[i].l)-lsh,a[i].r = lower_bound(lsh+1,lsh+tot+1,a[i].r)-lsh,modify(1,1,tot,a[i].l,a[i].r,1),R[a[i].l] = a[i].r;
	for(int i=max(n,m2),cur=m2; i>=1; --i) {
		while(tr[1].mx > i) {
			int p = tr[1].pos;
			modify(1,1,tot,p,R[p],-1);
			cur--;
		}
		ans2[i] = cur;
	}
	int maxx = 0;
	for(int i=0; i<=n; ++i)maxx = max(maxx,ans1[i]+ans2[n-i]);
	cout << maxx << '\n';
}
