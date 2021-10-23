#include<bits/stdc++.h>
using namespace std;
int x1[505][505],x2[505][505];
	int n,m,T;
int flag[505][505];
int dfs(int x,int y){
	if(x==n+1&&y==1)return 0;
//	cout<<x<<" "<<y<<endl;
	int val=0;
	flag[x][y]=0;
	if(flag[x-1][y]!=-1)val+=(flag[x-1][y])*x1[x-1][y];
	if(flag[n+1][y]!=-1)if(x==n)val+=(flag[n+1][y])*x1[n][y];
	if(flag[x][y-1]!=-1)val+=(flag[x][y-1])*x2[x][y-1];
	if(flag[x][m+1]!=-1)if(y==m)val+=(flag[x][m+1])*x2[x][m];
	val+=dfs(x+(y==m),y-(y==m)*y+1);
	
	int vl=0;
	flag[x][y]=1;
	if(flag[x-1][y]!=-1)vl+=(!flag[x-1][y])*x1[x-1][y];
	if(flag[n+1][y]!=-1)if(x==n)vl+=(!flag[n+1][y])*x1[n][y];
	if(flag[x][y-1]!=-1)vl+=(!flag[x][y-1])*x2[x][y-1];
	if(flag[x][m+1]!=-1)if(y==m)vl+=(!flag[x][m+1])*x2[x][m];
	vl+=dfs(x+(y==m),y-(y==m)*y+1);
	return min(val,vl);
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d %d %d",&n,&m,&T);
	for(int i=1;i<=n-1;++i){
		for(int j=1;j<=m;++j){
			scanf("%d",&x1[i][j]);
		}
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<=m-1;++j){
			scanf("%d",&x2[i][j]);
		}
	}
	while(T--){
		int k;
		scanf("%d",&k);
		memset(flag,-1,sizeof flag);
		for(int i=1;i<=m;++i)x1[0][i]=x1[n][i]=0;
		for(int i=1;i<=n;++i)x2[i][0]=x2[i][m]=0;
		for(int i=1;i<=k;++i){
			int x3,p,t;
			scanf("%d %d %d",&x3,&p,&t);
			if(p<=m)x1[0][p]=x3,flag[0][p]=t;
			else if(p<=m+n)x2[p-m][m]=x3,flag[p-m][m+1]=t;
			else if(p<=2*m+n)x1[n][n*2+m-p+1]=x3,flag[n+1][n*2+m-p+1]=t;
			else x2[2*m+2*n-p+1][0]=x3,flag[2*m+2*n-p+1][0]=t;
		}
		cout<<dfs(1,1)<<endl;
	}
	return 0;
}
