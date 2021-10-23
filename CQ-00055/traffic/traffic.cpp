#include<bits/stdc++.h>
using namespace std;
int st;
char rbuf[10000002];
int pt=-1;
inline int read(){
	int t=0;char v=rbuf[++pt];
	while(v<'0')v=rbuf[++pt];
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=rbuf[++pt];
	return t;
}
struct edge{int to,next,w;}e[2000002],e1[2000002];
int n,head[500002],pos[502][502],m,k,t,h1[500002],c1,S,T,cnt,q[500002],hd,tl,tot,num,a[502][502],b[502][502],X[52],P[52],TT[52],px[52],py[52],dis[500002],inf=1e9,gap[500002];
char v[500002];
inline void add(int x,int y,int z,bool o=0){e[++cnt]=(edge){y,head[x],z},head[x]=cnt,e[++cnt]=(edge){x,head[y],o?z:0},head[y]=cnt;}
inline int dfs(int x,int y){
	if(x==T)return y;
	int dlt=0;
	for(int i=head[x];i;i=e[i].next)
		if(e[i].w&&dis[x]==dis[e[i].to]+1){
			int tt=dfs(e[i].to,min(e[i].w,y));
			y-=tt,dlt+=tt,e[i].w-=tt,e[i^1].w+=tt;
			if(!y||dis[S]>tot)return dlt;
		}
	if(!(--gap[dis[x]]))dis[S]=tot+1;
	++gap[++dis[x]];
	return dlt;
}
inline int SAP(){
	hd=1,tl=0;
	for(int i=1;i<=tot;++i)v[i]=dis[i]=gap[i]=0;
	q[++tl]=T,v[T]=1;
	while(hd<=tl){
		int x=q[hd++];++gap[dis[x]];
		for(int i=head[x];i;i=e[i].next)
			if(!v[e[i].to]){
				dis[e[i].to]=dis[x]+1,v[e[i].to]=1;
				q[++tl]=e[i].to;
			}
	}
	int s=0;
	while(dis[S]<=tot)s+=dfs(S,inf);
	return s;
}
struct solve1{
	struct node{
		int dis,id;
		bool operator <(const node A)const{return dis>A.dis;}
	}h[500022];
	priority_queue<node>Q;
	edge E[2000022];
	int Cnt,Head[250022],pp[502][502],Num,ID[502][502],s,t;
	inline void Add(int x,int y,int z){E[++Cnt]=(edge){y,Head[x],z},Head[x]=Cnt,E[++Cnt]=(edge){x,Head[y],z},Head[y]=Cnt;}
	inline void work(){
		memset(Head,0,sizeof(Head)),Cnt=Num=0;
		for(int i=1;i<n;++i)
			for(int j=1;j<m;++j)
				pp[i][j]=++Num;
		for(int i=1;i<n;++i)
			for(int j=1;j<m;++j){
				if(j<m-1)Add(pp[i][j],pp[i][j+1],a[i][j+1]);
				if(i<n-1)Add(pp[i][j],pp[i+1][j],b[i+1][j]);
			}
		s=++Num,t=++Num;
		Add(s,t,min(X[1],X[2]));
		int ttt=0;
		for(int i=1;i<=m;++i)ID[1][i]=++ttt;
		for(int i=2;i<=n;++i)ID[i][m]=++ttt;
		for(int i=m-1;i;--i)ID[n][i]=++ttt;
		for(int i=n-1;i>2;--i)ID[i][1]=++ttt;
		int L=min(ID[px[1]][py[1]],ID[px[2]][py[2]]),R=max(ID[px[1]][py[1]],ID[px[2]][py[2]]);
		for(int i=1;i<L;++i){
			int ppp=0,dd=0;
			if(i<m)ppp=pp[1][i],dd=b[1][i];
			else if(i<n+m-1)ppp=pp[i-m+1][m-1],dd=a[i-m+1][m];
			else if(i<n+m+m-2)ppp=pp[n-1][m-(i-n-m+1)-1],dd=b[n][m-(i-n-m+1)-1];
			else ppp=pp[n-(i-m-m-n+2)-1][1],dd=a[n-(i-m-m-n+2)-1][1];
			Add(s,ppp,dd);
		}
		for(int i=L;i<R;++i){
			int ppp=0,dd=0;
			if(i<m)ppp=pp[1][i],dd=b[1][i];
			else if(i<n+m-1)ppp=pp[i-m+1][m-1],dd=a[i-m+1][m];
			else if(i<n+m+m-2)ppp=pp[n-1][m-(i-n-m+1)-1],dd=b[n][m-(i-n-m+1)-1];
			else ppp=pp[n-(i-m-m-n+2)-1][1],dd=a[n-(i-m-m-n+2)-1][1];
			Add(ppp,t,dd);
		}
		for(int i=R;i<=m+m+n+n-4;++i){
			int ppp=0,dd=0;
			if(i<m)ppp=pp[1][i],dd=b[1][i];
			else if(i<n+m-1)ppp=pp[i-m+1][m-1],dd=a[i-m+1][m];
			else if(i<n+m+m-2)ppp=pp[n-1][m-(i-n-m+1)-1],dd=b[n][m-(i-n-m+1)-1];
			else ppp=pp[n-(i-m-m-n+2)-1][1],dd=a[n-(i-m-m-n+2)-1][1];
			Add(s,ppp,dd);
		}
		for(int i=1;i<=Num;++i)h[i].id=i,h[i].dis=inf;
		h[s].dis=0;
		while(!Q.empty())Q.pop();
		Q.push(h[s]);
		while(!Q.empty()){
			node x=Q.top();Q.pop();
			if(x.dis!=h[x.id].dis)continue;
			for(int i=Head[x.id];i;i=E[i].next)
				if(x.dis+E[i].w<h[E[i].to].dis){
					h[E[i].to].dis=x.dis+E[i].w;
					Q.push(h[E[i].to]);
				}
		}
		printf("%d\n",h[t].dis);
	}
}S1;
int ed;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	fread(rbuf,1,10000000,stdin);
	n=read(),m=read(),t=read(),num=n*m;
	for(int i=1;i<=n;++i)for(int j=1;j<=m;++j)pos[i][j]=++tot;
	S=++tot,T=++tot,cnt=1;
	for(int i=1;i<n;++i)for(int j=1;j<=m;++j)a[i][j]=read();
	for(int i=1;i<=n;++i)for(int j=1;j<m;++j)b[i][j]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<=m;++j){
			if(i<n)add(pos[i][j],pos[i+1][j],a[i][j],1);
			if(j<m)add(pos[i][j],pos[i][j+1],b[i][j],1);
		}
	c1=cnt;
	for(int i=1;i<=tot;++i)h1[i]=head[i];
	for(int i=1;i<=cnt;++i)e1[i]=e[i];
	int ttt=tot;
	while(t--){
		k=read();
		for(int i=1;i<=k;++i){
			X[i]=read(),P[i]=read(),TT[i]=read();
			if(P[i]<=m)px[i]=1,py[i]=P[i];
			else if(P[i]<=n+m)px[i]=P[i]-m,py[i]=m;
			else if(P[i]<=n+m+m)px[i]=n,py[i]=m-(P[i]-n-m)+1;
			else px[i]=n-(P[i]-n-m-m)+1,py[i]=1;
		}
		bool ia=1;
		for(int i=1;i<=k;++i)ia&=(TT[i]==TT[1]);
		if(ia){puts("0");continue;}
		if(k==2){
			S1.work();
			continue;
		}
		cnt=c1,tot=ttt;
		for(int i=1;i<=tot;++i)head[i]=h1[i];
		for(int i=1;i<=cnt;++i)e[i]=e1[i];
		for(int i=1;i<=k;++i){
			++tot,head[tot]=0;
			if(TT[i])add(S,tot,inf);
			else add(tot,T,inf);
			add(tot,pos[px[i]][py[i]],X[i],1);
		}
		printf("%d\n",SAP());
	}
}

