#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N = 555;

void file(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
}
int read(){
	int s=0,w=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')s=s*10+ch-'0',ch=getchar();
	return s*w;
}

int edge[2][N][N],col[N][N];
int n,m,T,k,x,p,t,ans;

int get(int p){
	if(p<=m)return p;
	if(p<=n+m)return p-m;
	if(p<=2*m+n)return m-p+n+m+1;
	else return n-p+n+2*m+1;
}
int calc(){
	int res=0;
	for(int i=0;i<=n;++i)
		for(int j=0;j<=m;++j)
			if(~col[i][j]){
				if(col[i+1][j]!=-1&&col[i][j]!=col[i+1][j])res+=edge[0][i][j];
				if(col[i][j+1]!=-1&&col[i][j]!=col[i][j+1])res+=edge[1][i][j];
			}
	return res;
}
void dfs(int x,int y){
	if(x==n+1)return ans=min(ans,calc()),void();
	if(y==m){
		col[x][y]=1,dfs(x+1,1);
		col[x][y]=0,dfs(x+1,1);
	}else{
		col[x][y]=1,dfs(x,y+1);
		col[x][y]=0,dfs(x,y+1);
	}
}

signed main(){
	file();
	n=read(),m=read(),T=read();
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)
			edge[0][i][j]=read();
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j)
			edge[1][i][j]=read();
	while(T--){
		k=read();
		for(int i=0;i<=n+1;++i)
			for(int j=0;j<=m+1;++j)
				col[i][j]=-1;
		for(int i=1;i<=k;++i){
			x=read(),p=read(),t=read();
			if(p<=m)edge[0][0][p]=x,col[0][p]=t;
			else if(p<=n+m)edge[1][p-m][m]=x,col[p-m][m+1]=t;
			else if(p<=2*m+n)edge[0][n][m-p+n+m+1]=x,col[n+1][m-p+n+m+1]=t;
			else edge[1][n-p+n+2*m+1][0]=x,col[n-p+n+2*m+1][0]=t;
		} 
		ans=1e18,dfs(1,1);
		printf("%lld\n",ans);
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
