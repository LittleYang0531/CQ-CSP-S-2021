#include<bits/stdc++.h>
using namespace std;
inline int Rd() {
	int s=0; char fl=0,c=getchar();
	while(c<'0'||c>'9') fl|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return fl?-s:s;
}

const int N=2.5e5+5,M=4e6+5;

int cnt=0,ima,to[M],nxt[M],vedge[M],h[N];

inline void AddEdge(int x,int y,int z) {
	to[++cnt]=y,nxt[cnt]=h[x],vedge[cnt]=z,h[x]=cnt;
}
inline void Add2(int x,int y,int z) {
	AddEdge(x,y,z),AddEdge(y,x,z);
}

int n,m,Q,tot=0,id[505][505];
int row[505][505],col[505][505];
int val[55],pos[55],color[55];

int S,T;

int dir;
inline int Find(int ps) {
	if(ps<=m) return dir=1,id[1][ps]; ps-=m;
	if(ps<=n) return dir=0,id[ps][m]; ps-=n;
	if(ps<=m) return dir=1,id[n][m-ps+1]; ps-=m;
	return dir=0,id[n-ps+1][1];
}


int main() {
//	system("fc traffic.out traffic.out");
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=Rd(),m=Rd(),Q=Rd();
	for(int i=1; i<n; ++i) 
		for(int j=1; j<m; ++j) id[i][j]=++tot;
		
	for(int i=1; i<n; ++i) for(int j=1; j<=m; ++j) row[i][j]=Rd();
	for(int i=1; i<=n; ++i) for(int j=1; j<m; ++j) col[i][j]=Rd();
		
	for(int i=1; i<n; ++i) for(int j=2; j<m; ++j) 
		Add2(id[i][j-1],id[i][j],row[i][j]);
	
	for(int i=2; i<n; ++i) for(int j=1; j<m; ++j) 
		Add2(id[i-1][j],id[i][j],col[i][j]);
	
	S=++tot,T=++tot,ima=cnt;
	while(T--) {
		int K=Rd();
		for(int i=1; i<=K; ++i) val[i]=Rd(),pos[i]=Rd(),color[i]=Rd();
		
		if(color[1]==color[2]) {puts("0"); continue; }
		
//		Link(1,pos[1],T,1);
//		Link(pos[1],pos[2],S,0);
//		Link(pos[2],T,1);
//		
//		
//		for(int i=pos[1]; i<=pos[2]; ++i) {
//			Find
//		}
//		
//		int po1=Find(pos[1]),d1=dir;
//		int po2=Find(pos[2]),d2=dir;
		
	}
	return 0;
}

