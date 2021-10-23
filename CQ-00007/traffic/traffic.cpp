#include<iostream>
#include<cstring>
#include<cstdio>
#include<queue>
using namespace std;
#define N 500012
#define INF 0x3f3f3f3f
int tot=0,h[N],cnt=1;
struct Edge{int to,next,s;}e[N<<1];
inline void AddEdge(int x,int y,int v){e[++cnt]=(Edge){y,h[x],v};h[x]=cnt;e[++cnt]=(Edge){x,h[y],v};h[y]=cnt;}
int cur[N],de[N],h1[N],cnt1;queue<int>q;
bool bfs(int S,int T)
{
	int i,x,y;memset(de+1,0x3f,sizeof(int)*tot);memcpy(cur+1,h+1,sizeof(int)*tot);de[S]=0;q.push(S);
	while(!q.empty())
	{
		x=q.front();q.pop();
		for(i=h[x];i;i=e[i].next)if(e[i].s&&(de[y=e[i].to]==INF))de[y]=de[x]+1,q.push(y);
	}return (de[T]!=INF);
}
int dfs(int x,int fw,int T)
{
	if(x==T)return fw;
	int y,res=0,dlt;
	for(int &i=cur[x];i&&fw;i=e[i].next)
	if(e[i].s&&(de[y=e[i].to]==(de[x]+1)))
	{
		dlt=dfs(y,min(fw,e[i].s),T);if(!dlt){de[y]=INF;continue;}
		fw-=dlt;e[i].s-=dlt;res+=dlt;e[i^1].s+=dlt;if(!fw)return res;
	}return res;
}
inline int dinic(int S,int T){int maxflow=0;while(bfs(S,T))maxflow+=dfs(S,INF,T);return maxflow;}
int n,m,Q,K,a[512][512];
inline void ret(){memcpy(h+1,h1+1,sizeof(int)*tot);cnt=cnt1;for(int i=2;i<=cnt;i+=2)e[i].s=e[i+1].s=((e[i].s+e[i+1].s)>>1);}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q);int i,j,S,T,v,x,y,o,p;
	for(i=1;i<=n;i++)
	for(j=1;j<=m;j++)a[i][j]=++tot;
	S=++tot;T=++tot;
	for(i=1;i<n;i++)
	for(j=1;j<=m;j++)scanf("%d",&v),AddEdge(a[i][j],a[i+1][j],v);
	for(i=1;i<=n;i++)
	for(j=1;j<m;j++)scanf("%d",&v),AddEdge(a[i][j],a[i][j+1],v);
	memcpy(h1,h,sizeof(h));cnt1=cnt;
	while(Q--)
	{
		scanf("%d",&K);ret();
		while(K--)
		{
			scanf("%d%d%d",&v,&o,&p);
			if(o<=m)x=1,y=o;else if(o<=n+m)x=o-m,y=m;else if(o<=2*m+n)x=n,y=m-(o-m-n)+1;else x=n-(o-2*m-n)+1,y=1;
			if(p)AddEdge(S,a[x][y],v);else AddEdge(T,a[x][y],v);
		}
		printf("%d\n",dinic(S,T));
//		for(i=1;i<=n;i++)
//		{
//			for(j=1;j<=m;j++)cout<<((de[a[i][j]]==INF)?0:1)<<" ";cout<<endl;
//		}
	}
	return 0;
}
