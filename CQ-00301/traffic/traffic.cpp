#include<iostream>
#include<cstdio>
#include<queue>
const int N=5e5+5,inf=1e9;
using namespace std;
//char me1;
struct edge{
	int x,y,z;
}g[N*6];
int k[N],ck[N],d[N],c[N],cz[N*6];
int n,m,T,su=1,csu,s,t,ans=0;
queue<int>dl;
//#define getchar gc
inline int read()
{
	char h=getchar();
	int y=0,q=1;
	while(h<'0'||h>'9'){if(h=='-')q=-1;h=getchar();}
	while(h>='0'&&h<='9')y=y*10+h-'0',h=getchar();
	return y*q;
}
inline void add(int a,int b,int c)
{
	g[++su]=(edge){k[a],b,c};
	k[a]=su;
	g[++su]=(edge){k[b],a,c};
	k[b]=su;
}
inline int zh(int a,int b)
{
	return (a-1)*m+b;
}
inline bool bfs()
{
	for(int i=1;i<=t;i++)d[i]=0;
	while(!dl.empty())dl.pop();
//	memset(d,0,sizeof d);
	d[s]=1;
	c[s]=k[s];
	dl.push(s);
	while(!dl.empty())
	{
		int x=dl.front();dl.pop();
//		cout<<x<<"!!!\n";
		for(int i=k[x];i;i=g[i].x)
		{
			int y=g[i].y,z=g[i].z;
			if(z&&!d[y])
			{
				d[y]=d[x]+1;
				c[y]=k[y];
				if(y==t)return 1;
				dl.push(y);
			}
		}
	}
	return 0;
}
#define minn(x,y) ((x)<(y)?(x):(y))
int dfs(int x,int nl)
{
	if(x==t||!nl)return nl;
	int sl=0;
	for(int i=c[x];i;i=g[i].x)
	{
		c[x]=i;
		int y=g[i].y,z=g[i].z,l;
		if(d[y]==d[x]+1&&(l=dfs(y,minn(z,nl))))
		{
			nl-=l;
			sl+=l;
			g[i].z-=l;g[i^1].z+=l;
			if(!nl)break;
		}
		
	}
	if(!sl)d[x]=0;
	return sl;
}
inline void dinic()
{
//	for(int i=1;i<=t;i++)c[i]=k[i];
	ans=0;
	while(bfs())
	{
//		cout<<"!!!\n";
		ans+=dfs(s,inf);
//		cout<<ans<<"!!!\n";
	}
}
//char me2;
int main()
{
//	cout<<((&me1-&me2)>>20)<<"!!!\n";
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),T=read();
	for(int i=1;i<=n-1;i++)
	for(int j=1;j<=m;j++)add(zh(i,j),zh(i+1,j),read());
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m-1;j++)add(zh(i,j),zh(i,j+1),read());
	n=n*m;
	for(int i=1;i<=n;i++)ck[i]=k[i];
	for(int i=1;i<=su;i++)cz[i]=g[i].z;
	csu=su;
	while(T--)
	{
		int nu=read();s=n+1,t=s+1;
		for(int i=1;i<=t;i++)k[i]=ck[i];
		su=csu;
		for(int i=1;i<=su;i++)g[i].z=cz[i];
		for(int i=1;i<=nu;i++)
		{
			int x=read(),y=read(),z=read();
			if(y<=m)add((z?t:s),(zh(1,y)),x);
			else if(y<=(n/m)+m)add((z?t:s),(zh(y-m,m)),x);
			else if(y<=(n/m)+(m<<1))add((z?t:s),zh(n/m,m-(y-(n/m)-m)+1),x);
			else add((z?t:s),zh((n/m)-(y-(n/m)-(m<<1))+1,1),x);
		}
//		cout<<"!!!\n";
		dinic();
		cout<<ans<<"\n";
	}
	return 0;
}
/*
2 3 2
9 4 7
3 8
10 5
2
19 3 1
17 9 0
2
19 3 1
17 9 0
*/
