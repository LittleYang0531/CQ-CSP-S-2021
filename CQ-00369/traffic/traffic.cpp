#include<bits/stdc++.h>
#define int long long
using namespace std;
int dx[4]={1,0,-1,0},dy[4]={0,-1,0,1};
int n,m,t,a[505][505][5],p[505][505],col[505][505],vst[505][505],dis[5];
void dfs(int x,int y,int nx,int ny,int f,int color)
{
	int sum=0;
	if(vst[x][y])return;
	vst[x][y]=color;
	if(x>0&&y>0&&x<=n&&y<=m)return;
	if(vst[x+1][y]!=color)sum+=a[x][y][1];
	if(vst[x][y+1]!=color)sum+=a[x][y][2];
	if(vst[x-1][y]!=color)sum+=a[x-1][y][1];
	if(vst[x][y-1]!=color)sum+=a[x][y-1][2];
	if(sum>dis[color])return;
	dis[color]+=sum;
	if((x+1!=nx||y!=ny)&&vst[x+1][y]!=-1)dfs(x+1,y,x,y,1,color);
	if((x!=nx||y+1!=ny)&&vst[x+1][y]!=-1)dfs(x,y+1,x,y,2,color);
	if((x-1!=nx||y!=ny)&&vst[x+1][y]!=-1)dfs(x-1,y,x,y,1,color);
	if((x!=nx||y-1!=ny)&&vst[x+1][y]!=-1)dfs(x,y-1,x,y,2,color);
}
signed main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)scanf("%d",&a[i][j][1]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)scanf("%d",&a[i][j][2]);
	for(int i=1;i<=t;i++)
	{
		int k;
		scanf("%d",&k);
		memset(dis,127,sizeof(dis)); 
		memset(vst,-1,sizeof(vst));
		for(int j=1;j<=k;j++)
		{
			int x,y;
			scanf("%d%d%d",&a[i][j][3],&p[i][j],&col[i][j]);
			vst[i][j]=col[i][j];
			if(p[i][j]<=m){
				x=0;y=p[i][j];
				a[x][y][1]=a[i][j][3];
				dfs(x+1,y,x,y,1,col[i][j]);
			}
			if(p[i][j]>m&&p[i][j]<=m+n){
				x=p[i][j]-m;y=m+1;
				a[x][y-1][2]=a[i][j][3];
				dfs(x,y-1,x,y,2,col[i][j]);
			}
			if(p[i][j]>m+n&&p[i][j]<=2*m+n){
				x=n+1;y=m-(p[i][j]-m-n)+1;
				a[x-1][y][1]=a[i][j][3];
				dfs(x-1,y,x,y,1,col[i][j]);
			}
			if(p[i][j]>2*m+n&&p[i][j]<=2*(m+n)){
				x=n-(p[i][j]-m-m-n)+1;y=0;
				a[x][y][2]=a[i][j][3];
				dfs(x,y+1,x,y,2,col[i][j]);
			}
		}
		printf("%d\n",min(dis[1],dis[0]));
	}
	return 0;
}
