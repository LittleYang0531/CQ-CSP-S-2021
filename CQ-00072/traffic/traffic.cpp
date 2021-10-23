#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long s,ans=0x7fffffff;
int n,m,k,k1,k2,t,p,cnt,tot;
int a[55][55][55][55],c[55][55],c2[505][505],f[500005];
int bj[500005],d1[500005],d2[500005];
void dfs(int x,int y)
{
	if(y>m)
	{
		dfs(x+1,1);
		return ;
	}
	if(x>n)
	{
		for(int i=1;i<=m;i++)
		if(a[1][i][0][i]&&c[1][i]!=c[0][i]) s+=a[1][i][0][i];
		else if(a[n][i][n+1][i]&&c[n][i]!=c[n+1][i]) s+=a[n][i][n+1][i];
		for(int i=1;i<=n;i++)
		if(a[i][1][i][0]&&c[i][1]!=c[i][0]) s+=a[i][1][i][0];
		else if(a[i][m][i][m+1]&&c[i][m]!=c[i][m+1]) s+=a[i][m][i][m+1];
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			if(c[i][j]!=c[i+1][j]&&i<n) s+=a[i][j][i+1][j];
			if(c[i][j]!=c[i][j+1]&&i<m) s+=a[i][j][i][j+1];
		}
		for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
		{
			cout<<c[i][j]<<" ";
			if(j==m) cout<<endl;
		}
		ans=min(ans,s);
		s=0;
		return ;
	}
	c[x][y]=0;
	dfs(x,y+1);
	c[x][y]=1;
	dfs(x,y+1);
	c[x][y]=0;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<n;i++)
	for(int j=1;j<=m;j++)
	scanf("%d",&a[i][j][i+1][j]),a[i+1][j][i][j]=a[i][j][i+1][j];
	for(int i=1;i<=n;i++)
	for(int j=1;j<m;j++)
	scanf("%d",&a[i][j][i][j+1]),a[i][j+1][i][j]=a[i][j][i][j+1];
	for(int zz=1,x;zz<=t;zz++)
	{
		scanf("%d",&x);
		for(int i=1,s1,s2,s3;i<=x;i++)
		{
			scanf("%d%d%d",&s1,&s2,&s3);
			if(s2<=m) a[0][s2][1][s2]=a[1][s2][0][s2]=s1,c[0][s2]=s3;
			else if(s2<=n+m) a[s2-m][m+1][s2-m][m]=a[s2-m][m][s2-m][m+1]=s1,c[s2-m][m+1]=s3;
			else if(s2<=n+2*m) a[n+1][n+2*m-s2+1][n][n+2*m-s2+1]=a[n][n+2*m-s2+1][n+1][n+2*m-s2+1]=s1,c[n+1][n+2*m-s2+1]=s3;
			else a[2*n+2*m-s2+1][0][2*n+2*m-s2+1][1]=a[2*n+2*m-s2+1][1][2*n+2*m-s2+1][0]=s1,c[2*n+2*m-s2+1][0]=s3;
		}
		dfs(1,1);
		for(int i=1;i<=m;i++)
		a[1][i][0][i]=a[0][i][1][i]=a[n][i][n+1][i]=a[n+1][i][n][i]=0;
		for(int i=1;i<=n;i++)
		a[i][1][i][0]=a[i][0][i][1]=a[i][m][i][m+1]=a[i][m+1][i][m]=0;
	}
	printf("%lld",ans);
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
