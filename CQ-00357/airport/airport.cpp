#include<bits/stdc++.h>
#define N 600005
using namespace std;
int n,m1,m2,t[N],ans,p[N],f[N],g[N],fir[N],c[N],sa[N],sb[N];
vector<int>v[N];
struct Node{
	int l,r;inline char operator<(Node a)const{return l<a.l;}
}a[N],b[N];
inline void A(int x,int v){
	++x;
	while(x<=*t+1)c[x]+=v,x+=x&-x;
}
inline int Q(int x){
	int res=0;++x;
	while(x)res+=c[x],x-=x&-x;
	return res;
}
int main(void){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int i,j,l,r,x,y,res,mid;scanf("%d%d%d",&n,&m1,&m2);
	for(i=1;i<=m1;++i)scanf("%d%d",&x,&y),a[i]=(Node){x,y},t[++*t]=x,t[++*t]=y;
	for(i=1;i<=m2;++i)scanf("%d%d",&x,&y),b[i]=(Node){x,y},t[++*t]=x,t[++*t]=y;
	sort(t+1,t+*t+1);
	sort(a+1,a+m1+1),sort(b+1,b+m2+1);
	for(i=1;i<=m1;++i)a[i].l=lower_bound(t+1,t+*t+1,a[i].l)-t,a[i].r=lower_bound(t+1,t+*t+1,a[i].r)-t;
	for(i=1;i<=m2;++i)b[i].l=lower_bound(t+1,t+*t+1,b[i].l)-t,b[i].r=lower_bound(t+1,t+*t+1,b[i].r)-t;
	for(i=j=1;i<=m1;++i){
		l=0,r=i,res=0;
		for(;j<a[i].l;++j)for(int x:v[j])A(f[x],-1);
		while(l<=r){
			mid=(l+r)>>1;
			if(Q(mid)<mid)r=(res=mid)-1;else l=mid+1;
		}A(f[i]=res,1);v[a[i].r].push_back(i);
	}
	for(i=1;i<=*t+1;++i)v[i].clear(),c[i]=0;
	for(i=j=1;i<=m2;++i){
		l=0,r=i,res=0;
		for(;j<b[i].l;++j)for(int x:v[j])A(g[x],-1);
		while(l<=r){
			mid=(l+r)>>1;
			if(Q(mid)<mid)r=(res=mid)-1;else l=mid+1;
		}A(g[i]=res,1);v[b[i].r].push_back(i);
	}
	for(i=1;i<=m1;++i)++sa[f[i]];
	for(i=1;i<=n;++i)sa[i]+=sa[i-1];
	for(i=1;i<=m2;++i)++sb[g[i]];
	for(i=1;i<=n;++i)sb[i]+=sb[i-1];
	for(i=0;i<=n;++i)ans=max(ans,sa[i]+sb[n-i]);
	//putchar('\n');
	printf("%d\n",ans);
	return 0;
}



