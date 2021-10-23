#include<iostream>
#include<cstdio>
#include<cstring>
#include<queue>
using namespace std;
const int MAXN=505;
int a1[MAXN][MAXN],a2[MAXN][MAXN];
struct point {
	int to,next,v;
};
point a[MAXN*MAXN*8];
int cnt,h[MAXN*MAXN];
void add(int x,int y,int z) {
	a[++cnt].next=h[x];
	a[cnt].to=y;
	a[cnt].v=z;
	h[x]=cnt;
}
int v[55],id[55],col[55],ss[MAXN*MAXN];
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,t;
	cin>>n>>m>>t;
	for(int i=1; i<n; i++)for(int j=1; j<=m; j++)scanf("%d",&a1[i][j]);
	for(int i=1; i<=n; i++)for(int j=1; j<m; j++)scanf("%d",&a2[i][j]);
	for(int _t=1; _t<=t; _t++) {
		int nn,bj[2]= {0};
		scanf("%d",&nn);
		memset(h,0,sizeof(h));
		cnt=0;
		for(int i=1; i<=nn; i++) {
			scanf("%d%d%d",v+i,id+i,col+i);
			bj[col[i]]=1;
		}
		if(nn!=2||!bj[0]||!bj[1]) {
			printf("0\n");
			continue;
		}
		int ans=min(v[1],v[2]);
		for(int i=1; i<n; i++) {
			for(int j=1; j<m; j++) {
				int t=(i-1)*m+j;
				if(j+1!=m) {
					add(t,t+1,a1[i][j+1]);
					add(t+1,t,a1[i][j+1]);
				}
				if(i+1!=n) {
					add(t,t+m,a2[i+1][j]);
					add(t+m,t,a2[i+1][j]);
				}
			}
		}
		int s=n*m+1,t=n*m+2;
		for(int i=1; i<m; i++) {
			int p=id[1]<=i&&i<id[2]?s:t;
			add(p,i,a2[1][i]);
			add(i,p,a2[1][i]);
			p=id[1]<=m+n+m-i+1&&m+n+m-i+1<id[2]?s:t;
			add(p,i,a2[n][i]);
			add(i,p,a2[n][i]);
		}
		for(int i=1; i<n; i++) {
			int p=id[1]<=i+m&&i+m<id[2]?s:t;
			add(p,i*m-1,a1[i][m]);
			add(i*m-1,p,a1[i][m]);
			a1[i][m]=0;
			p=id[1]<=2*m+2*n-i+1&&2*m+2*n-i+1<id[2]?s:t;
			add(p,(i-1)*m+1,a1[i][1]);
			add((i-1)*m+1,p,a1[i][1]);
		}
		queue<int>q;
		memset(ss,0x3f,sizeof(ss));
		ss[s]=0;
		q.push(s);
		while(!q.empty()) {
			int u=q.front();
			q.pop();
			for(int i=h[u]; i; i=a[i].next) {
				int to=a[i].to;
				if(ss[to]>ss[u]+a[i].v) {
					ss[to]=ss[u]+a[i].v;
					q.push(to);
				}
			}
		}
		printf("%d\n",min(ans,ss[t]));
	}
	return 0;
}
