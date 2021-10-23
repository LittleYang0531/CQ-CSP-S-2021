#include<cstdio>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
#include<cctype>
#include<vector>
#include<map>

using namespace std;

template <class T>
void read(T &x){
	x=0;char c=getchar();bool f=false;
	while(!isdigit(c)) f=c=='-',c=getchar();
	while(isdigit(c)) x=x*10+c-'0',c=getchar();
	x=f? (-x):x;
}

const int MAXN=25;

bool c[MAXN][MAXN];

int n,m,T;

map <pair<int,int>,int> mp1;
map <int,pair<int,int> > mp2;
int cnt,ans=0x3f3f3f3f;

const int dx[]={1,0,-1,0};
const int dy[]={0,1,0,-1};
struct Edge{
	pair<int,int> u,v;
	int val;
}E[MAXN*MAXN*2];
struct Node{
	int x,p,t;
}a[MAXN];

int ecnt=0,k;
int calc(){
	int ret=0;
	for(int i=1;i<=ecnt;i++){
		pair<int,int> u=E[i].u,v=E[i].v;
		if (c[u.first][u.second]!=c[v.first][v.second])  ret+=E[i].val;
	}
	for (int i=1;i<=k;i++){
		pair <int,int> pos;
		if (1<=a[i].p&&a[i].p<=m) pos=make_pair(1,a[i].p);
		else if (m+1<=a[i].p&&a[i].p<=m+n) pos=make_pair(a[i].p-m,m);
		else if (m+n+1<=a[i].p&&a[i].p<=2*m+n) pos=make_pair(n,2*m+n+1-a[i].p);
		else pos=make_pair(2*m+2*n+1-a[i].p,1);
		if (a[i].t!=c[pos.first][pos.second]) ret+=a[i].x;
	}
	return ret;
}

void dfs(int now){
	if (now==cnt+1){
		ans=min(ans,calc());
		return;
	}
	pair <int,int> cur=mp2[now];
	c[cur.first][cur.second]=1;
	dfs(now+1);
	c[cur.first][cur.second]=0;
	dfs(now+1);
}

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	read(n);read(m);read(T);
	for (int i=1;i<=n;i++){
		for (int j=1;j<=m;j++){
			mp1[make_pair(i,j)]=++cnt;
			mp2[cnt]=make_pair(i,j);
		}
	}
	for (int i=1;i<n;i++){
		for (int j=1;j<=m;j++){
			++ecnt;
			read(E[ecnt].val);
			E[ecnt].u=make_pair(i,j);
			E[ecnt].v=make_pair(i+1,j);
		}
	}
	for (int i=1;i<=n;i++){
		for (int j=1;j<m;j++){
			++ecnt;
			read(E[ecnt].val);
			E[ecnt].u=make_pair(i,j);
			E[ecnt].v=make_pair(i,j+1);
		}
	}
	while(T--){
		read(k);
		for (int i=1;i<=k;i++){
			read(a[i].x);read(a[i].p);read(a[i].t);
		}
		ans=0x3f3f3f3f;
		dfs(1);
		printf("%d\n",ans);
	}
}
