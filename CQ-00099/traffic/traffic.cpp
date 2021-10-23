#include<bits/stdc++.h>
using namespace std;
int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
const int maxn = 510;
int v1[maxn][maxn],v2[maxn][maxn],d[maxn*maxn],v[maxn*maxn],S,T,n,m,cas;
#define dot(x,y) ((x-1)*(m-1)+y)
vector<pair<int,int> >g[maxn*maxn];
void add(int x,int y,int z) {
	g[x].push_back(make_pair(y,z)),g[y].push_back(make_pair(x,z));
}
void ins(int x,int y,int z) {
//	cerr<<"????????"<<x<<'?'<<y<<' '<<z<<'\n';
	g[x].push_back(make_pair(y,z));
}
void rem(int x) {g[x].pop_back();}
void dij() {
	for(int i=1;i<=T;i++) d[i]=0x3f3f3f3f,v[i]=0;
	priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
	while(!q.empty()) q.pop();
	q.push(make_pair(d[S]=0,S));
	while(!q.empty()) {
		int x=q.top().second;q.pop();
//		cerr<<x<<'\n';
		if(v[x]) continue;v[x]=1;
		for(auto z:g[x]) if(d[z.first]>d[x]+z.second) q.push(make_pair(d[z.first]=d[x]+z.second,z.first));
	}
}
signed main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),cas=read();
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++) v1[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++) v2[i][j]=read();
	for(int i=1;i<n;i++)
		for(int j=1;j<m-1;j++)
			add(dot(i,j),dot(i,j+1),v1[i][j+1]);
	for(int i=1;i<n-1;i++)
		for(int j=1;j<m;j++)
			add(dot(i,j),dot(i+1,j),v2[i+1][j]);
	S=(n-1)*(m-1)+1,T=(n-1)*(m-1)+2;
	while(cas--) {
		int ass=read();
		if(ass>2) assert(0);
		else {
			int vx=read(),x=read(),cx=read();
			int vy=read(),y=read(),cy=read();
			if(x>y) swap(x,y);
			if(cx==cy) cout<<0<<'\n';
			else {
				g[S].clear();
				for(int i=1;i<m;i++) {
					if(x<=i&&i+1<=y) ins(dot(1,i),T,v2[1][i]);
					else ins(S,dot(1,i),v2[1][i]);
					if(x<=m+n+i&&m+n+i+1<=y) ins(dot(n-1,m-i),T,v2[n][m-i]);
					else ins(S,dot(n-1,m-i),v2[n][m-i]);
				}
				for(int i=1;i<n;i++) {
					if(x<=m+i&&m+i+1<=y) ins(dot(i,m-1),T,v1[i][m]);
					else ins(S,dot(i,m-1),v1[i][m]);
					if(x<=m+n+m+i&&m+n+m+i+1<=y) ins(dot(n-i,1),T,v1[n-i][1]);
					else ins(S,dot(n-i,1),v1[n-i][1]);
				}
				dij();
				for(int i=1;i<m;i++) {
					if(x<=i&&i+1<=y) rem(dot(1,i));
					if(x<=m+n+i&&m+n+i+1<=y) rem(dot(n-1,m-i));
				}
				for(int i=1;i<n;i++) {
					if(x<=m+i&&m+i+1<=y) rem(dot(i,m-1));
					if(x<=m+n+m+i&&m+n+m+i+1<=y) rem(dot(n-i,1));
				}
				cout<<min(d[T],min(vx,vy))<<'\n';
			}
		}
	}
	return 0;
}
