#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
struct xxx{int l,r;}p[N];
operator<(const xxx&a,const xxx&b){return a.l<b.l;}
int k,n,m,ans,L,e,a[N<<1],C[N],f[N],g[N];
void add(int x,int k){
	for(;x<=L;x+=x&-x)C[x]+=k;	
}
int get(int x){
	int res=0;
	for(;x;x-=x&-x)res+=C[x];	
	return res;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&k,&n,&m);
	L=0;
	for(int i=1;i<=n;i++){
		scanf("%d%d",&p[i].l,&p[i].r);
		a[++L]=p[i].l;a[++L]=p[i].r;
	}
	sort(a+1,a+1+L);L=unique(a+1,a+1+L)-a-1;
	for(int i=1;i<=n;i++){
		p[i].l=lower_bound(a+1,a+1+L,p[i].l)-a;
		p[i].r=lower_bound(a+1,a+1+L,p[i].r)-a;
	}
	sort(p+1,p+1+n);
	for(int x=1;x<=n;x++){
		memset(C,0,sizeof C);
		for(int i=1;i<=n;i++){
			if(get(p[i].l)==x)continue;
			f[x]++;add(p[i].l,1);add(p[i].r+1,-1);
		}
	}
	L=0;
	for(int i=1;i<=m;i++){
		scanf("%d%d",&p[i].l,&p[i].r);
		a[++L]=p[i].l;a[++L]=p[i].r;
	}
	sort(a+1,a+1+L);L=unique(a+1,a+1+L)-a-1;
	for(int i=1;i<=m;i++){
		p[i].l=lower_bound(a+1,a+1+L,p[i].l)-a;
		p[i].r=lower_bound(a+1,a+1+L,p[i].r)-a;
	}
	sort(p+1,p+1+m);
	for(int x=1;x<=m;x++){
		memset(C,0,sizeof C);
		for(int i=1;i<=m;i++){
			if(get(p[i].l)==x)continue;
			g[x]++;add(p[i].l,1);add(p[i].r+1,-1);
		}
	}
	for(int i=0;i<=k;i++)
	ans=max(ans,f[i]+g[k-i]);
	printf("%d",ans);return 0;
}
