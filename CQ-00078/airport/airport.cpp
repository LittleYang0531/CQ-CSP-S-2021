#include<bits/stdc++.h>
using namespace std;
const int MAXN=1e5+5;
int n,m1,m2,ans,rr;
bool v1[MAXN],v2[MAXN];
int a1[MAXN],a2[MAXN];
struct node{
	int l,r;
}a[MAXN],b[MAXN];
bool cmp(node x,node y) {
	return x.l<y.l;
}
int bs1(int l,int r) {
	if(l>r) return -1;
	if(l==r) {
		if(a[l].l<=rr) return -1;
		return l;
	}
	int mid=(l+r)>>1;
	if(a[mid].l>rr) return bs1(l,mid);
	return bs1(mid+1,r);
}
int bs2(int l,int r) {
	if(l>r) return -1;
	if(l==r) {
		if(b[l].l<=rr) return -1;
		return l;
	}
	int mid=(l+r)>>1;
	if(b[mid].l>rr) return bs2(l,mid);
	return bs2(mid+1,r);
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i) scanf("%d %d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;++i) scanf("%d %d",&b[i].l,&b[i].r);
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int i=1;i<=m1;++i) {
		rr=0;
		for(int j=1;~j;j=bs1(j+1,m1)) {
			while(v1[j]) ++j;
			if(j>m1) break;
			v1[j]=1;
			rr=a[j].r;
			++a1[i];
		}
		a1[i]+=a1[i-1];
	}
	for(int i=1;i<=m2;++i) {
		rr=0;
		for(int j=1;~j;j=bs2(j+1,m2)) {
			while(v2[j]) ++j;
			if(j>m2) break;
			v2[j]=1;
			rr=b[j].r;
			++a2[i];
		}
		a2[i]+=a2[i-1];
	}
	for(int i=0;i<=n;++i) ans=max(ans,a1[i]+a2[n-i]);
	printf("%d",ans);
	return 0;
}
