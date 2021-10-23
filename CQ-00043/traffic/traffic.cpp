#include<bits/stdc++.h>
#define ll long long
using namespace std;
char gc(){static char buf[1<<16],*s,*t;if(s==t){t=(s=buf)+fread(buf,1,1<<16,stdin);if(s==t)return EOF;}return *s++;}
#define getchar gc
int read()
{
	char c;
	int w=1;
	while((c=getchar())>'9'||c<'0')if(c=='-')w=-1;
	int ans=c-'0';
	while((c=getchar())>='0'&&c<='9')ans=(ans<<1)+(ans<<3)+c-'0';
	return ans*w;
}
const int xx=2e6+5;//100*100*4应该是够了 
struct node{int next,to,v;}e[xx];
int cnt=1,h[xx];
void add(int x,int y,int z)
{
	cnt++;
	e[cnt].next=h[x];
	h[x]=cnt;
	e[cnt].to=y;
	e[cnt].v=z;
}
int S,T,d[xx],cur[xx],num;
void clear()
{
	memset(e,0,sizeof(e[0])*(cnt+1));
	memset(h,0,sizeof(h[0])*(num+1));
	cnt=1;num=0;
}
bool bfs()
{
	memset(d,-1,sizeof(d));
	memcpy(cur,h,sizeof(h[0])*(num+1));
	queue<int>q;
	q.push(S);
	d[S]=0;
	while(!q.empty())
	{
		int x=q.front();
		q.pop();
		for(int i=h[x];i;i=e[i].next)
		{
			if(e[i].v&&d[e[i].to]==-1)
			{
				d[e[i].to]=d[x]+1;
				q.push(e[i].to);
				if(e[i].to==T)return 1;
			}
		}
	}
	return 0;
}
int n,m,q;
int id[505][505];
int get(int x,int y)
{
	if(!id[x][y])id[x][y]=++num;
	return id[x][y];
}
int D[505][505],R[505][505];
void build()
{
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
			id[i][j]=0;
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			add(get(i,j),get(i+1,j),D[i][j]);
			add(get(i+1,j),get(i,j),D[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			add(get(i,j),get(i,j+1),R[i][j]);
			add(get(i,j+1),get(i,j),R[i][j]);
		}
	}
//	for(int i=1;i<=n;i++)
//		for(int j=1;j<=m;j++)
//		{
//			cout<<i<<" "<<j<<" ss "<<get(i,j)<<"\n";
//		}
//	cout<<num<<"!!!\n";
	S=++num,T=++num;
}
int dinic(int x,int mx)
{
	if(x==T)return mx;
	int rem=mx;
	for(int i=cur[x];i;i=e[i].next)
	{
		cur[x]=i;
//		cout<<x<<" "<<e[i].to<<" "<<e[i].v<<" "<<mx<<" "<<S<<" "<<T<<"\n"<<"\n"; 
		if(e[i].v&&d[e[i].to]==d[x]+1)
		{
			int a=dinic(e[i].to,min(e[i].v,rem));
			if(!a)d[e[i].to]=-1;
			rem-=a;
			e[i].v-=a;
			e[i^1].v+=a;
			if(!rem)break;
		}
	}
	return mx-rem;
}
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),q=read();
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			D[i][j]=read();
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			R[i][j]=read();
	//甚至不会爆int 
	while(q--)
	{
		clear();
		build();//0连接源点 
		int k=read();
		for(int i=1;i<=k;i++)
		{
			int v=read(),a=read(),col=read();
			int x=0,y=0;
			if(a<=m)x=1,y=a;
			else if(a<=n+m)x=a-m,y=m;
			else if(a<=n+m+m)x=n,y=m+m+n+1-a;
			else if(a<=n+n+m+m)x=n+n+m+m+1-a,y=1;
			num++;
//			cout<<x<<" ss "<<y<<"\n";
			add(get(x,y),num,v);
			add(num,get(x,y),v);
			if(col==0)add(S,num,5e8),add(num,S,5e8);//1e9可能在增广的时候爆吗？？？5e8不会爆的 
			else add(num,T,5e8),add(T,num,5e8);
		}
//		cerr<<cnt<<" "<<num<<"\n";
		ll ans=0;
		while(bfs())ans+=dinic(S,5e8);
		cout<<ans<<"\n";
	}
	return 0;
}

