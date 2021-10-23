#include<bits/stdc++.h>
using namespace std;
#define MAXN 300005
typedef long long LL;
const LL INF=0x3f3f3f3f3f3f3f3f;
template<typename _T>
void read(_T &x){
	_T f=1;x=0;char s=getchar();
	while('0'>s||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x*=f;
}
int n,m,T,a[505][505],b[505][505],head[MAXN],tot,col[2005],val[2005];
LL dis[MAXN],dp[2][(1<<18)+5];
struct tann{
	LL t;int id;tann(){t=id=0;}
	tann(LL T,int I){t=T;id=I;}
	bool operator < (const tann &rhs)const{return t>rhs.t;}
};
struct edge{int to,nxt,paid;}e[MAXN<<2];
void addEdge(int u,int v,int w){e[++tot]=(edge){v,head[u],w};head[u]=tot;}
int Id(int x,int y){return x*(m+1)+y+1;}
priority_queue<tann>q;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	read(n);read(m);read(T);
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++)read(a[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<m;j++)read(b[i][j]);
	for(int i=1;i<=T;i++){
		int K;read(K);
		if(K<=2&&m>10){
			if(K==0){puts("0");continue;}
			int xid,wx,cx;read(wx);read(xid);read(cx);
			if(K==1){puts("0");continue;}
			int yid,wy,cy;read(wy);read(yid);read(cy);
			if(xid>yid)swap(wx,wy),swap(xid,yid),swap(cx,cy);
			if(cx==cy){puts("0");continue;}
			for(int j=1;j<n;j++)
				for(int k=1;k<=m;k++)
					addEdge(Id(j,k-1),Id(j,k),a[j][k]),
					addEdge(Id(j,k),Id(j,k-1),a[j][k]);
			for(int j=1;j<=n;j++)
				for(int k=1;k<m;k++)
					addEdge(Id(j-1,k),Id(j,k),b[j][k]),
					addEdge(Id(j,k),Id(j-1,k),b[j][k]);
			for(int j=1;j<=Id(n,m);j++)dis[j]=INF;
			while(!q.empty())q.pop();LL res=min(1ll*wx,1ll*wy);
			for(int j=1;j<m;j++)if(j<xid||j>=yid)dis[Id(0,j)]=0,q.push((tann){0LL,Id(0,j)});
			for(int j=1;j<n;j++)if(j+m<xid||j+m>=yid)dis[Id(j,m)]=0,q.push((tann){0LL,Id(j,m)});
			for(int j=1;j<m;j++)if(j+m+n<xid||j+m+n>=yid)dis[Id(n,m-j)]=0,q.push((tann){0LL,Id(n,m-j)});
			for(int j=1;j<n;j++)if(j+m+m+n<xid||j+m+m+n>=yid)dis[Id(n-j,0)],q.push((tann){0LL,Id(n-j,0)});
			while(!q.empty()){
				tann t=q.top();q.pop();if(dis[t.id]!=t.t)continue;int u=t.id;
				//if(u%100==0)printf("dis[%d]:%lld\n",u,dis[u]);
				for(int j=head[u];j;j=e[j].nxt){
					int v=e[j].to,w=e[j].paid;//printf("%d-->%d %d\n",u,v,w);
					if(dis[u]+1ll*w<dis[v])dis[v]=dis[u]+1ll*w,q.push((tann){dis[v],v});
				}
			}
			for(int j=1;j<m;j++)if(j>=xid&&j<yid)res=min(res,dis[Id(0,j)]);
			for(int j=1;j<n;j++)if(j+m>=xid&&j+m<yid)res=min(res,dis[Id(j,m)]);
			for(int j=1;j<m;j++)if(j+m+n>=xid&&j+m+n<yid)res=min(res,dis[Id(n,m-j)]);
			for(int j=1;j<n;j++)if(j+m+m+n>=xid&&j+m+m+n<yid)res=min(res,dis[Id(n-j,0)]);
			printf("%lld\n",res);
			for(int j=1;j<=Id(n,m);j++)head[j]=0;tot=0;continue;
		}
		LL res=INF;
		for(int j=1;j<=n+n+m+m;j++)val[j]=col[j]=0;
		for(int j=1;j<=K;j++){
			int w,id,c;read(w);read(id);read(c);
			val[id]=w;col[id]=c;
		}
		for(int j=0;j<(1<<m);j++)dp[0][j]=INF;dp[0][0]=0;int now=0,las=1;
		for(int j=1;j<=n;j++)
			for(int k=1;k<=m;k++){
				swap(now,las);int tmp0=0,tmp1=0;
				for(int l=0;l<(1<<m);l++)dp[now][l]=INF;
				if(j==1){if(col[k])tmp0+=val[k];else tmp1+=val[k];}
				if(k==m){if(col[j+m])tmp0+=val[j+m];else tmp1+=val[j+m];}
				if(j==n){if(col[m-k+1+m+n])tmp0+=val[m-k+1+m+n];else tmp1+=val[m-k+1+m+n];}
				if(k==1){if(col[n-j+1+m+n+m])tmp0+=val[n-j+1+m+n+m];else tmp1+=val[n-j+1+m+n+m];}
				//printf("point %d %d:%d %d\n",j,k,tmp0,tmp1);
				for(int l=0;l<(1<<m);l++){
					int tp0=tmp0,tp1=tmp1;
					if(l&(1<<k-1))tp0+=a[j-1][k];else tp1+=a[j-1][k];
					if(k>1){if(l&(1<<k-2))tp0+=b[j][k-1];else tp1+=b[j][k-1];}
					int S1=l|(1<<k-1),S2=l&((1<<m)-1-(1<<k-1));
					dp[now][S1]=min(dp[now][S1],dp[las][l]+1ll*tp1);
					dp[now][S2]=min(dp[now][S2],dp[las][l]+1ll*tp0);
				}
				//printf("dp[%d][%d]:%d\n",j,k,dp[now][(1<<m)-1]);
				//for(int l=0;l<(1<<m);l++)printf("dp[%d][%d][%d]:%d\n",j,k,l,dp[now][l]);
			}
		for(int j=0;j<(1<<m);j++)res=min(res,dp[n+m+1&1][j]);
		printf("%lld\n",res);
	}
	return 0;
}
