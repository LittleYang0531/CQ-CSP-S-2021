#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=510,inf=0x7f7f7f7f;
int n,m,T,k;
int c[N][N],r[N][N];
int num[N][N];
ll ans=inf;
int cnt=1;
int dx[]={-1,1,0,0};
int dy[]={0,0,-1,1};
ll get()
{
	ll res=0;
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			if(num[i][j]!=num[i+1][j])
				res+=c[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			if(num[i][j]!=num[i][j+1])
				res+=r[i][j];
	for(int i=0;i<=n+1;i++)
	{
		if(num[i][0]!=-1)
			if(num[i][0]!=num[i][1])
				res+=r[i][0];
		if(num[i][m+1]!=-1)
			if(num[i][m+1]!=num[i][m])
				res+=r[i][m];
	}
	for(int i=0;i<=m+1;i++)
	{
		if(num[0][i]!=-1)
			if(num[0][i]!=num[1][i])
				res+=c[0][i];
		if(num[n+1][i]!=-1)
			if(num[n+1][i]!=num[n][i])
				res+=c[n][i];
	}
	return res;
}
void dfs(int x,int y)
{
	if(cnt==n*m)
	{
		ans=min(ans,get());
		return;
	}
	for(int i=0;i<4;i++)
	{
		int nx=x+dx[i];
		int ny=y+dy[i];
		if(nx<=0||nx>=n+1 || ny<=0||ny>=m+1)
			continue;
		if(num[nx][ny]!=-1)
			continue;
		cnt++;
		num[nx][ny]=0;
		dfs(nx,ny);
		num[nx][ny]=1;
		dfs(nx,ny);
		num[nx][ny]=-1;
		cnt--;
	}
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	memset(num,-1,sizeof num);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&c[i][j]);
	for(int i=1;i<m;i++)
		for(int j=1;j<=n;j++)
			scanf("%d",&r[i][j]);
	while(T--)
	{
		int x1[N],p1[N],t1[N];
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			scanf("%d%d%d",&x1[i],&p1[i],&t1[i]);
			int x=x1[i],p=p1[i],t=t1[i];
			if(p<=m)
			{
				c[0][p]=x;
				num[0][p]=t;
			}
			else if(p<=m+n)
			{
				r[p-m][m]=x;
				num[p-m][m+1]=t;
			}
			else if(p<=2*m+n)
			{
				c[n][m-(p-m-n)+1]=x;
				num[n+1][m-(p-m-n)+1]=t;
			}
			else
			{
				r[n-(p-2*m-n)+1][0]=x;
				num[n-(p-2*m-n)+1][0]=t;
			}
		}
		num[1][1]=0;
		dfs(1,1);
		num[1][1]=1;
		dfs(1,1);
		printf("%lld\n",ans);
		for(int i=1;i<=k;i++)
		{
			int x=x1[i],p=p1[i],t=t1[i];
			if(p<=m)
			{
				c[0][p]=0;
				num[0][p]=-1;
			}
			else if(p<=m+n)
			{
				c[p-m][m]=0;
				num[p-m][m+1]=-1;
			}
			else if(p<=2*m+n)
			{
				c[n][m-(p-m-n)+1]=0;
				num[n+1][m-(p-m-n)+1]=-1;
			}
			else
			{
				c[n-(p-2*m-n)+1][0]=0;
				num[n-(p-2*m-n)+1][0]=-1;
			}
		}
	}
	return 0;
}
