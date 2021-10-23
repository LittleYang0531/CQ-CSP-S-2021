#include<cstdio>//JZM yyds!!
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<ctime>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<random>
#define ll long long
#define uns unsigned
#define MOD 
#define MAXN 500005
#define INF 1e16
#define IF (it->first)
#define IS (it->second)
using namespace std;
inline ll read(){
	ll x=0;bool f=1;char s=getchar();
	while((s<'0'||s>'9')&&s>0){if(s=='-')f^=1;s=getchar();}
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?x:-x;
}
inline ll lowbit(ll x){return x&-x;}
int n,m,Q;

//dinic
struct edge{
	int v,to;ll f;edge(){}
	edge(int V,int T,ll F){
		v=V,to=T,f=F;
	}
}e[2100005],pe[2100005];
int EN=1,pn,G[MAXN],d[MAXN],cur[MAXN];
int PG[MAXN];
inline void addedge(int u,int v,ll f){
	e[++EN]=edge(v,G[u],f),G[u]=EN;
	e[++EN]=edge(u,G[v],0),G[v]=EN;
}
inline void addedge_(int u,int v,ll f){
	e[++EN]=edge(v,G[u],f),G[u]=EN;
	e[++EN]=edge(u,G[v],f),G[v]=EN;
}
queue<int>q;//bfs
inline bool bfs(int S,int T){
	for(int i=1;i<=pn;i++)d[i]=-1;
	while(!q.empty())q.pop();
	q.push(S),d[S]=0;
	while(!q.empty()){
		int u=q.front();q.pop();
		if(u==T)break;
		for(int i=G[u];i;i=e[i].to){
			int v=e[i].v,f=e[i].f;
			if(f>0&&d[v]<0)d[v]=d[u]+1,q.push(v);
		}
	}
	return d[T]>=0;
}
inline ll dfs(int x,int T,ll lim){
	if(x==T)return lim;
	ll res=lim;
	for(int i=cur[x];i&&res;i=e[i].to){
		cur[x]=i;
		int v=e[i].v;
		if(d[v]==d[x]+1&&e[i].f>0){
			ll ad=dfs(v,T,min(res,e[i].f));
			e[i].f-=ad,res-=ad,e[i^1].f+=ad;
		}
	}
	return lim-res;
}
inline ll dinic(int S,int T){
	ll res=0;
	while(bfs(S,T)){
		for(int i=1;i<=pn;i++)cur[i]=G[i];
		while(ll ad=dfs(S,T,INF))res+=ad;
//		printf(" %lld\n",res);
	}
	return res;
}
//dinic end

int id[505][505],td[5005],S,T;
const ll ef=5e6;
ll sum;
int PE,PP;
signed main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),Q=read();
	S=1,T=2,pn=2;
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++){
			id[i][j]=++pn,G[pn]=0;
			addedge(S,pn,ef);
			addedge(pn,T,ef);
		}
	int pid=0;
	for(int j=1;j<=m;j++)pid++,td[pid]=id[1][j];
	for(int i=1;i<=n;i++)pid++,td[pid]=id[i][m];
	for(int j=m;j>0;j--)pid++,td[pid]=id[n][j];
	for(int i=n;i>0;i--)pid++,td[pid]=id[i][1];
	
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			addedge_(id[i][j],id[i+1][j],read());
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			addedge_(id[i][j],id[i][j+1],read());
	sum=dinic(S,T);
	for(int i=2;i<=EN;i++)pe[i]=e[i];
	for(int i=1;i<=pn;i++)PG[i]=G[i];
	PE=EN,PP=pn;
	while(Q--){
		int k=read();
		for(int i=1;i<=k;i++){
			int f=read(),p=read(),t=read();
			pn++,G[pn]=0;
			addedge_(pn,td[p],f);
			if(t)addedge(pn,T,INF);
			else addedge(S,pn,INF);
		}
//		printf("%d %d\n",pn,EN);
		ll ad=dinic(S,T);
		printf("%lld\n",sum+ad-ef*n*m);
		
		EN=PE,pn=PP;
		for(int i=2;i<=EN;i++)e[i]=pe[i];
		for(int i=1;i<=pn;i++)G[i]=PG[i];
	}
	return 0;
}
