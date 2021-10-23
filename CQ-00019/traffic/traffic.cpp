#include<bits/stdc++.h>
#define _I inline
#define _R register
#define mod 998244353
#define INF 0x3f3f3f3f3f3f3f3f
#define eps 1e-4
#define memset(x,y) memset(x,y,sizeof(x))
#define memcpy(x,y) memcpy(x,y,sizeof(x))
#define ll long long
#define ull unsigned long long
#define int ll
using namespace std;
char buf[1<<19],*p1=buf,*p2=buf;
#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<19,stdin)),p1==p2)?EOF:*p1++;
int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	if(f)x=-x;return x;
}
const int N=700005,M=505;
int n,m,k,num,s,t,T,edge,id[M][M],c[N],xx[N],yy[N],zz[N],head[N],nx[N*8],to[N*8],l[N*8],cnt=1,gap[N],dis[N];
ll ans;
void add(int x,int y,int z,int bj=0){
	nx[++cnt]=head[x];to[cnt]=y;l[cnt]=z;head[x]=cnt;
	if(bj)nx[++cnt]=head[y],to[cnt]=x,l[cnt]=z,head[y]=cnt;
	else nx[++cnt]=head[y],to[cnt]=x,l[cnt]=0,head[y]=cnt;
}
int dfs(int x,int maxf){
	if(x==t||!maxf)return maxf;int ret=0,dlt;
	for(_R int i=head[x];i;i=nx[i])if(dis[x]==dis[to[i]]+1&&l[i]){
		dlt=dfs(to[i],min(l[i],maxf));
		l[i]-=dlt;l[i^1]+=dlt;
		ret+=dlt;maxf-=dlt;
		if(!maxf||dis[s]==num)return ret;
	}
	if(!(--gap[dis[x]]))dis[s]=num;
	++gap[++dis[x]];return ret;
}
signed main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();m=read();T=read();s=1;t=2;num=2;
	for(_R int i=1;i<=n;++i)for(_R int j=1;j<=m;++j)id[i][j]=++num;
	for(_R int i=1;i<=m;++i)c[i]=id[1][i];
	for(_R int i=1;i<=n;++i)c[i+m]=id[i][m];
	for(_R int i=1;i<=m;++i)c[i+m+n]=id[n][m+1-i];
	for(_R int i=1;i<=n;++i)c[i+m+n+m]=id[n+1-i][1];
	for(_R int i=1;i<n;++i)for(_R int j=1;j<=m;++j)xx[++edge]=id[i][j],yy[edge]=id[i+1][j],zz[edge]=read();
	for(_R int i=1;i<=n;++i)for(_R int j=1;j<m;++j)xx[++edge]=id[i][j],yy[edge]=id[i][j+1],zz[edge]=read();
	while(T--){
		cnt=1;memset(head,0);k=read();int x,y,z;memset(dis,0);memset(gap,0);gap[0]=num;ans=0;
		while(k--){
			x=read(),y=read(),z=read();
			if(z)add(s,c[y],x);else add(c[y],t,x);
		}
		for(_R int i=1;i<=edge;++i)add(xx[i],yy[i],zz[i],1);
		while(dis[s]<num)ans+=dfs(s,INF);cout<<ans<<"\n";
	}
	return 0;
}
