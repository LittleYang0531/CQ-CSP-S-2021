#include <iostream>
#include <cstdio>
#include <cstring>
#include <queue>
#define inf 0x7fffffff/2
using namespace std;
template <typename T> void read(T &x) {
	x=0;
	char c=getchar();
	for (; !isdigit(c); c=getchar());
	for (; isdigit(c); c=getchar()) x=x*10+c-'0';
}
int n,m,T;
struct node {
	int next,to,w;
} a[50005];
int h[50005],cnt=0;
void addedge(int x,int y,int z) {
	a[++cnt].to=y;
	a[cnt].w=z;
	a[cnt].next=h[x];
	h[x]=cnt;
}
int X1[505][505],X2[505][505],g[505][505];
int X3[505],p[505],t[505],minn=inf;
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	read(n),read(m),read(T);
	int js=1;
	for (int i=1; i<=n; i++) {
		for (int j=1; j<=m; j++) {
			g[i][j]=js;
			js++;
		}
	}
	for (int i=1; i<n; i++) {
		for (int j=1; j<=m; j++) {
			read(X1[i][j]);
			addedge(g[i][j],g[i+1][j],X1[i][j]);
			addedge(g[i+1][j],g[i][j],X1[i][j]);
			minn=min(minn,X1[i][j]);
		}
	}
	for (int i=1; i<=n; i++) {
		for (int j=1; j<m; j++) {
			read(X2[i][j]);
			addedge(g[i][j],g[i][j+1],X2[i][j]);
			addedge(g[i][j+1],g[i][j],X2[i][j]);
			minn=min(minn,X2[i][j]);
		}
	}
	for (; T; --T) {
		int k;
		read(k);
		for (int i=1; i<=k; i++) {
			read(X3[i]),read(p[i]),read(t[i]);
			minn=min(minn,X3[i]);
		}
		printf("%d\n",minn);
	}
	return 0;
}

