#include<bits/stdc++.h>
#define N 1000005
#define INF 0x3f3f3f3f3f3f3f3fll
using namespace std;
typedef long long ll;
int n,m,Case,tot,S,T,P,h[N];
struct Edge{int to,next,f;};
inline void A(int x,int y,int z){e[++cnt]={y,h[x],z},h[x]=cnt,e[++cnt]={x,h[y],0},h[y]=cnt;} 
inline int dfs(int x,int mxf){
	int i,y,res=0,dlt;
	for(i=h[x];i;i=e[i].next)if(e[i].f&&dis[y=e[i].to]==dis[x]+1){
		dlt=dfs(y,min(mxf,e[i].f));
		e[i].f-=dlt,e[i^1].f+=dlt,res+=dlt;
		if(!(mxf-=dlt))return dis[x]=INF,res;
	}if(!--gap[dis[x]])dis[S]=P;++gap[++dis[x]];
}
inline ll SAP(int x){
	ll ans=0;
	while(dis[S]^P)ans+=dfs(S,INF);
}
inline void Find(int a,int&x,int&y){
	if(a<=m)return x=0,y=a,void();
	if(a<=m+n)return x=a-n,y=m+1,void();
	if(a<=2*m+n)return x=n+1,y=m-(a-m-n)+1,void();
	return x=n-(a-2*m-n)+1,y=0,void();
}
int main(void){
	scanf("%d%d%d",&n,&m,&Case);
	for(i=1;i<n;++i)
		for(j=1;j<=m;++j)scanf("%d",&a[i][j]);
	for(i=1;i<=n;++i)
		for(j=1;j<m;++j)scanf("%d",&b[i][j]);
	for(i=0;i<=n+1;++i)
		for(j=0;j<=m+1;++j)pos[i][j]=++tot;
	S=0,T=pos[n+1][m+1]+1;P=T+1;
	while(Case--){
		scanf("%d",&k);
		for(i=1;i<=k;++i)scanf("%d%d%d",v+i,X+i,c+i);
		for(i=1;i<n;++i)
			for(j=1;j<=m;++j)A(pos[i][j],pos[i+1][j],a[i][j]),A(pos[i+1][j],pos[i][j],a[i][j]);
		for(i=1;i<=n;++i)
			for(j=1;j<m;++j)A(pos[i][j],pos[i][j+1],a[i][j]),A(pos[i][j+1],pos[i][j],a[i][j]);
		for(i=1;i<=k;++i){
			Find(X[i],x,y);
			if(!c[i])A(S,pos[x][y],INF);
			else A(pos[x][y],T,INF);
			if(!x)A(pos[x][y],pos[1][y],v[i]),A(pos[1][y],pos[x][y],v[i])
			if(x==n+1)A(pos[x][y],pos[n][y],v[i]),A(pos[n][y],pos[x][y],v[i])
			if(!y)A(pos[x][y],pos[x][1],v[i]),A(pos[x][1],pos[x][y],v[i])
			if(y==m+1)A(pos[x][y],pos[x][m],v[i]),A(pos[x][m],pos[x][y],v[i])
		}
		printf("%lld\n",SAP());
	}
	return 0;
}



