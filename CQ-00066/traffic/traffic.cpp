#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
const int Maxx=1000005,Maxn=2005,INF=0x3f3f3f3f,Mod=1e9+7;
inline int read()
{
	int res=0;char bj=0,ch=getchar();
	while(ch<'0'||ch>'9')bj|=ch=='-',ch=getchar();
	while(ch>='0'&&ch<='9')res=(res<<1)+(res<<3)+(ch^48),ch=getchar();
	return bj?-res:res;
}
void print(int x){
	if(x>9)print(x/10);
	putchar(x%10^48);
}
inline void printnum(int x,char ch)
{
	if(x<0)putchar('-'),x=-x;
	print(x),putchar(ch);
}
int ft,cnt=1,h[20005],fh[20005];
struct edge {int to,nx,vl;}e[80005],fe[80005];
inline void Add(int x,int y,int v){
//	cout<<x<<"-->"<<y<<" "<<v<<"\n";
	e[++cnt].nx=h[x],e[cnt].to=y,e[cnt].vl=v,h[x]=cnt;
	e[++cnt].nx=h[y],e[cnt].to=x,e[cnt].vl=v,h[y]=cnt;
}
int d[20005];
inline bool Bfs(int S,int T){
	static int Q[20005];int l=0,r=0,x;
	memset(d,-1,sizeof(int)*(T+1)),d[Q[++r]=S]=0;
	while(l<r){
		for(int i=h[x=Q[++l]],y;i;i=e[i].nx)
		if(e[i].vl&&d[y=e[i].to]==-1){
			d[Q[++r]=y]=d[x]+1;
			if(y==T)return 1; 
		}
	}
	return 0;
}
int Dfs(int x,int Mx,int T){
	if(x==T)return Mx;
	int ret=0,dlt;
	for(int i=h[x],y;i;i=e[i].nx)
	if(e[i].vl&&d[y=e[i].to]==d[x]+1){
		if((dlt=Dfs(y,min(Mx,e[i].vl),T)))
			e[i].vl-=dlt,e[i^1].vl+=dlt,Mx-=dlt,ret+=dlt; 
		else d[y]=-1;
	}return ret; 
}
int N[505][505],fd[2333];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n=read(),m=read(),Q=read()+1,id=0;
	for(int i=1;i<=n;++i)
	for(int j=1;j<=m;++j)
	N[i][j]=++id;
	for(int i=1;i<n;++i)
	for(int j=1;j<=m;++j)
	Add(N[i][j],N[i+1][j],read());
	for(int i=1;i<=n;++i)
	for(int j=1;j<m;++j)Add(N[i][j],N[i][j+1],read());
	memcpy(fh,h,sizeof(h)),memcpy(fe,e,sizeof(e)),ft=cnt,cnt=0;
	for(int i=1;i<=m;++i)fd[++cnt]=N[1][i];
	for(int i=1;i<=n;++i)fd[++cnt]=N[i][m];
	for(int i=m;i;--i)fd[++cnt]=N[n][i];
	for(int i=n;i;--i)fd[++cnt]=N[i][1];
	while(--Q){
		int K=read(),nd=id,S=id+K+1,T=S+1;
		memcpy(h,fh,sizeof(fh)),memcpy(e,fe,sizeof(fe)),cnt=ft;
		for(int i=1;i<=K;++i){
			int v=read(),x=read();
			Add(++nd,fd[x],v);
			if(read())Add(S,nd,INF);
			else Add(nd,T,INF);
		}
		int Ans=0;
		while(Bfs(S,T))Ans+=Dfs(S,INF,T);
		cout<<Ans<<"\n"; 
	}
	return 0;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0
*/
