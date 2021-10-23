#include<bits/stdc++.h>
using namespace std;
int n;
int m;
const int MAXN=1005;
int get(int i,int j)
{
	return (i-1)*(m+1)+j;
}
struct Edge{
	int v,val,u;
}edge[MAXN*MAXN];
int k,t;
int x;
int p,op;
int clor[MAXN*MAXN];
int dg[MAXN][MAXN];
int ds[MAXN][MAXN];
pair<int,int> Fd(int p)
{
	if(p<=m)
	{
		return make_pair(1,p);
	}
	else if(p<=n+m)
	{
		return make_pair(p-m+1,m+1);
	}
	else if(p<=2*m+n)
	{
		return make_pair(n+1,2*m+n-p+2);
	}
	else
	{
		return make_pair(2*m+2*n-p+2,1);
	}
}
pair<int,int> FD(int p)
{
	if(p<=m)
	{
		return make_pair(2,p);
	}
	else if(p<=n+m)
	{
		return make_pair(p-m+1,m);
	}
	else if(p<=2*m+n)
	{
		return make_pair(n,2*m+n-p+2);
	}
	else
	{
		return make_pair(2*m+2*n-p+2,2);
	}
}
int ans=0x3f3f3f3f;
int cnt=0;
int check()
{
	int tot=0;
	for(int i=1;i<=cnt;i++)
	{
		if(clor[edge[i].u]!=clor[edge[i].v])
		{
			tot+=edge[i].val;
		}
	}
	return tot;
}
void dfs(int x)
{
	if(x==((n+1)*(m+1))+1)
	{
		ans=min(ans,check());
		return;
	}
	if(clor[x]==0x3f3f3f3f)
	{
		clor[x]=1;
		dfs(x+1);
		clor[x]=0;
		dfs(x+1);
		clor[x]=0x3f3f3f3f;
	}
	else
	{
		dfs(x+1);
	}
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d %d %d",&n,&m,&t);
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&dg[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			scanf("%d",&ds[i][j]);
		}
	}
	while(t--)
	{
		cnt=0;
		ans=0x3f3f3f3f;
		memset(clor,0x3f,sizeof(clor));
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				x=dg[i][j];
				int u=get(i+1,j+1);
				int v=get(i+2,j+1);
				Edge nows;
				nows.v=v;
				nows.val=x;
				nows.u=u;
				edge[++cnt]=nows;
			}
		}
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<m;j++)
			{
				x=ds[i][j];
				int u=get(i+1,j+1);
				int v=get(i+1,j+2);
				
				Edge nows;
				nows.v=v;
				nows.val=x;
				nows.u=u;
				edge[++cnt]=nows;
			}
		}
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			scanf("%d %d %d",&x,&p,&op);
			pair<int,int>pi=Fd(p);
			int u=get(pi.first,pi.second);
			int v=get(FD(p).first,FD(p).second);
		//	printf("%d %d\n",pi.first,pi.second);
			Edge nows;
			nows.v=v;
			nows.val=x;
			nows.u=u;
			edge[++cnt]=nows;
			clor[u]=op;
		}
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}

