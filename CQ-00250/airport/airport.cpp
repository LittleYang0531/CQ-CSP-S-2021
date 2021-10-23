//ta±£””Œ“≈∂ 
#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m1,m2,h,t,ca[N],cb[N],c[N];
int lowbit(int x) {return x&(-x);}
void Update(int x,int w) {for(;x<=n;x+=lowbit(x))c[x]+=w;}
void Clear(int x) {for(;x<=n;x+=lowbit(x))c[x]=0;}
int Ask(int x) {int res=0;for(;x;x-=lowbit(x))res+=c[x];return res;}
struct node {
	int l,r;
}a[N],b[N];
struct nd {
	int bb,w;
	bool operator<(const nd &u) const{return w>u.w;}
};
bool cmp(node u,node v) {return u.l<v.l;}
priority_queue<nd> Q;
bool check(int up) {
	return Ask(up)<up;
}
void solve_a() {
	sort(a+1,a+1+m1,cmp);
	for(int i=1;i<=m1;i++) {
		while(!Q.empty()&&Q.top().w<a[i].l) {
			Update(Q.top().bb,-1);
			Q.pop();
		}
		int l=1,r=n,best=-1;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1,best=mid;
			else l=mid+1;
		}
		if(best==-1) {continue;}
		ca[best]++;
		Update(best,1);
		nd tmp; tmp.bb=best,tmp.w=a[i].r;
		Q.push(tmp);
	}
	for(int i=1;i<=n;i++) ca[i]+=ca[i-1];
}
void solve_b() {
	while(!Q.empty()) Q.pop();
	for(int i=1;i<=n;i++) Clear(i);
	sort(b+1,b+1+m2,cmp);
	for(int i=1;i<=m2;i++) {
		while(!Q.empty()&&Q.top().w<b[i].l) {
			Update(Q.top().bb,-1);
			Q.pop();
		}
		int l=1,r=n,best=-1;
		while(l<=r) {
			int mid=(l+r)>>1;
			if(check(mid))r=mid-1,best=mid;
			else l=mid+1;
		}
		if(best==-1) {continue;}
		cb[best]++;
		Update(best,1);
		nd tmp; tmp.bb=best,tmp.w=b[i].r;
		Q.push(tmp);
	}
	for(int i=1;i<=n;i++) cb[i]+=cb[i-1];
}
void solve() {
	int ans=0;
	for(int i=0;i<=n;i++) ans=max(ans,ca[i]+cb[n-i]);
	printf("%d",ans);
}
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;i++) scanf("%d%d",&b[i].l,&b[i].r);
	solve_a();
	solve_b();
	solve();
	return 0;
}

//3 5 4
//1 5
//3 8
//6 10
//9 14
//13 18
//2 11
//4 15
//7 17
//12 16
