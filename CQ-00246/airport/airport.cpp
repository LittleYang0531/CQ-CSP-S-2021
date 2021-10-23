#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
#define mid ((l+r)>>1)
const int N=1e5+5;
int mi[4*N],ma[4*N],la[4*N],ans[4*N],an[2][N],m[2],n,a1[N];
struct aa{
	int a,b; 
}a[2*N];
void down(int g){
	ans[2*g]+=ans[g];
	ans[2*g+1]+=ans[g];
	ans[g]=0;
	mi[2*g]+=la[g];
	mi[2*g+1]+=la[g];
	ma[2*g]+=la[g];
	ma[2*g+1]+=la[g];
	la[2*g]+=la[g];
	la[2*g+1]+=la[g];
	la[g]=0;
}
int ef(int g,int l,int r){
	if(l==r){
		if(mi[g]<l){
			mi[g]++;
			ma[g]++;
			return l;
		}
		else{
			ans[g]++;
			return l+1;
		}
	}
	int an;
	down(g);
	if(ma[2*g]>=mid){
		ans[2*g]++;
		an=ef(2*g+1,mid+1,r);
	}
	else{
		mi[2*g+1]++;
		ma[2*g+1]++;
		la[2*g+1]++;
		an=ef(2*g,l,mid);
	}
	mi[g]=mi[2*g];
	ma[g]=ma[2*g+1];
	return an;
}
void add(int g,int l,int r,int l1,int r1){
	if(l1<=l && r<=r1){
		mi[g]--;
		ma[g]--;
		la[g]--;
		return;
	}
	down(g);
	if(l1<=mid) add(2*g,l,mid,l1,r1);
	if(r1>mid) add(2*g+1,mid+1,r,l1,r1);
	mi[g]=mi[2*g];
	ma[g]=ma[2*g+1];
}
void dfs(int g,int l,int r,int v){
	if(l==r){
		an[v][l]=ans[g];
		ans[g]=la[g]=mi[g]=ma[g]=0;
		return;
	}
	down(g);
	dfs(2*g,l,mid,v);
	dfs(2*g+1,mid+1,r,v);
	ans[g]=la[g]=mi[g]=ma[g]=0;
}
bool cmp(aa a,aa b){
	return a.a<b.a;
}
void cl(int v,int n){
	for(int i=1;i<=n;i++){
		scanf("%d %d",&a[2*i-1].a,&a[2*i].a);
		a[2*i-1].b=i;
		a[2*i].b=-i; 
	}
	sort(a+1,a+1+2*n,cmp);
	for(int i=1;i<=2*n;i++){
		if(a[i].b<0){
			a[i].b*=-1;
			if(a1[a[i].b]>n) continue;
			add(1,1,n,a1[a[i].b],n);
			continue;
		}
		else a1[a[i].b]=ef(1,1,n);
	}
	dfs(1,1,n,v);
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m[0],&m[1]);
	cl(0,m[0]);
	cl(1,m[1]);
	int ans=min(m[0]+an[1][n],m[1]+an[0][n]);
	for(int i=1;i<n;i++){
		ans=min(ans,an[0][i]+an[1][n-i]);
	}
	printf("%d",m[0]+m[1]-ans);
	return 0;
}
