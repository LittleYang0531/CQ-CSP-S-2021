#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
using namespace std;
int asw,n,m1,m2,g[100001],f1[100001],f2[100001];
struct node {
	int l,r;
} g1[100001],g2[100001];
struct tree {
	int l,r,mi;
} t[400001];
bool cmp(node a,node b) {
	return a.l<b.l;
}
void build(int k,int l,int r) {
	t[k].l=l,t[k].r=r,t[k].mi=0;
	if(l==r) return;
	int mid=(l+r)/2;
	if(l<=mid) build(k*2,l,mid);
	if(r>mid) build(k*2+1,mid+1,r);
}
void gai1(int k,int x,int y) {
	;
	if(t[k].l==t[k].r) {
		if(t[k].mi>x) return;
		t[k].mi=y;
		f1[t[k].l]++;
		return;
	}
	if(t[k*2].mi<=x) gai1(k*2,x,y);
	else gai1(k*2+1,x,y);
	t[k].mi=min(t[k*2].mi,t[k*2+1].mi);
}
void gai2(int k,int x,int y) {
	if(t[k].l==t[k].r) {
		if(t[k].mi>x) return;
		t[k].mi=y;
		f2[t[k].l]++;
		return;
	}
	if(t[k*2].mi<=x) gai2(k*2,x,y);
	else gai2(k*2+1,x,y);
	t[k].mi=min(t[k*2].mi,t[k*2+1].mi);
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1; i<=m1; i++) scanf("%d%d",&g1[i].l,&g1[i].r);
	for(int i=1; i<=m2; i++) scanf("%d%d",&g2[i].l,&g2[i].r);
	sort(g1+1,g1+1+m1,cmp),sort(g2+1,g2+1+m2,cmp);
	build(1,1,n);
	for(int i=1; i<=m1; i++) gai1(1,g1[i].l,g1[i].r);
	build(1,1,n);
	for(int i=1; i<=m2; i++) gai2(1,g2[i].l,g2[i].r);
	for(int i=2; i<=n; i++) f1[i]+=f1[i-1];
	for(int i=2; i<=n; i++) f2[i]+=f2[i-1];
	for(int i=0; i<=n; i++) asw=max(asw,f1[i]+f2[n-i]);
	printf("%d",asw);
}
