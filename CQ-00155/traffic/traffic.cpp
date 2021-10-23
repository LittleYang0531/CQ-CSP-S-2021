#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
struct E{int to;ll val;};
struct Thing{int val,bel,col;}a[55];
bool operator <(const E x,const E y){return x.val>y.val;}
bool operator <(const Thing x,const Thing y){return x.bel<y.bel;}
int n,m,Q,K,A[505][505],B[505][505],b[55],S,N,cl[260005];
ll dis[260005],d[55][55],f[105][105];
vector<E> g[260005];
int pos(int x,int y){
	return (x-1)*(m-1)+y;
}
void Add(int x,int y,int z,bool icl=0){
	g[x].push_back((E){y,z}),g[y].push_back((E){x,z});
	if(icl)cl[++cl[0]]=x,cl[++cl[0]]=y;
}
int Pre(int x){
	if(x==1)return K;
	return x-1;
}
void Dijkstra(){
	priority_queue<E> q;
	memset(dis,0x3f,sizeof(dis)),dis[S]=0,q.push((E){S,dis[S]});
	while(!q.empty()){
		int x=q.top().to;
		ll v=q.top().val;
		q.pop();
		if(dis[x]!=v)continue;
		for(E i:g[x]){
			int y=i.to;
			if(dis[y]>dis[x]+i.val)dis[y]=dis[x]+i.val,q.push((E){y,dis[y]});
		}
	}
}
void Solve(){
	scanf("%d",&K);
	int is[2]={0};
	for(int i=1;i<=K;i++)scanf("%d%d%d",&a[i].val,&a[i].bel,&a[i].col),is[a[i].col]=1;
	if(!is[0]||!is[1])return puts("0"),void();
	sort(a+1,a+K+1),b[0]=0;
	for(int i=1;i<=K;i++)if(a[i].col!=a[Pre(i)].col)b[++b[0]]=i;
	for(int i=1;i<=K;i++){//pre(i)~iµÄÇøÓò 
		Add(N+i,N+Pre(i),a[Pre(i)].val,1);
		for(int j=a[Pre(i)].bel;j!=a[i].bel;j=j%(2*n+2*m)+1){
			if(1<=j&&j<m)Add(N+i,pos(1,j),B[1][j],1);
			if(m+1<=j&&j<m+n)Add(N+i,pos(j-m,m-1),A[j-m][m],1);
			if(m+n+1<=j&&j<m+m+n)Add(N+i,pos(n-1,2*m+n-j),B[n][2*m+n-j],1);
			if(2*m+n+1<=j&&j<2*m+2*n)Add(N+i,pos(2*m+2*n-j,1),A[2*m+2*n-j][1],1);
		}
	}
	ll ans=1e18;
	for(int i=1;i<=b[0];i++){
		S=N+b[i],Dijkstra();
		for(int j=1;j<=b[0];j++)d[i][j]=dis[N+b[j]];
	}
	memset(f,0x3f,sizeof(f));
	for(int i=1;i<=2*b[0];i++)f[i][i-1]=0;
	for(int len=2;len<=b[0];len+=2){
		for(int i=1;i+len-1<=2*b[0];i++){
			int j=i+len-1;
			for(int k=i+1;k<=j;k++){
				f[i][j]=min(f[i][j],f[i+1][k-1]+f[k+1][j]+d[(i-1)%b[0]+1][(k-1)%b[0]+1]);
			}
			if(len==b[0])ans=min(ans,f[i][j]);
		}
	}
	cout<<ans<<'\n';
	while(cl[0])g[cl[cl[0]]].pop_back(),cl[0]--;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&Q),N=(n-1)*(m-1);
	for(int i=1;i<n;i++)for(int j=1;j<=m;j++)scanf("%d",&A[i][j]);
	for(int i=1;i<=n;i++)for(int j=1;j<m;j++)scanf("%d",&B[i][j]);
	for(int i=1;i<n-1;i++)for(int j=1;j<m;j++)Add(pos(i,j),pos(i+1,j),B[i+1][j]);
	for(int i=1;i<n;i++)for(int j=1;j<m-1;j++)Add(pos(i,j),pos(i,j+1),A[i][j+1]);
	while(Q--)Solve();
	return 0;
}
