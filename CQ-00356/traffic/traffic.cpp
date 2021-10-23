#include <cstdio>
#include <iostream>
using namespace std;
const int M = 505;
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int T,n,m,k,a[M][M],b[M][M],c[M][M];
int ans,s1[M],s2[M],s3[M];
int cal()
{
	int res=0;
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			if(c[i][j]^c[i+1][j])
				res+=a[i][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			if(c[i][j]^c[i][j+1])
				res+=b[i][j];
	//nmsl
	for(int i=1;i<=k;i++)
	{
		int xd=0,yd=0;
		if(s2[i]<=m) xd=1,yd=s2[i];
		else if(s2[i]<=n+m) xd=s2[i]-m,yd=m;
		else if(s2[i]<=2*m+n)
			xd=n,yd=m-(s2[i]-n-m)+1;
		else xd=n-(s2[i]-n-2*m)+1,yd=1;
		if(c[xd][yd]^s3[i]) res+=s1[i];
	}
	return res;
}
void dfs(int x,int y,int ls)
{
	if(x==n+1)
	{
		ans=min(ans,cal());
		return ;
	}
	int tx=x,ty=y+1;
	if(ty==m+1) tx++,ty=1;
	c[x][y]=ls;
	dfs(tx,ty,ls);
	c[x][y]=ls^1;
	dfs(tx,ty,ls^1);
}
void work()
{
	ans=0x3f3f3f3f;
	k=read();
	for(int i=1;i<=k;i++)
	{
		s1[i]=read();
		s2[i]=read();
		s3[i]=read();
	}
	dfs(1,1,0);
	printf("%d\n",ans);
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read();m=read();T=read();
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			a[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			b[i][j]=read();
	while(T--) work();
}
