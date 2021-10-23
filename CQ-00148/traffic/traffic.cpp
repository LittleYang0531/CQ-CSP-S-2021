/*
�������ȿ���û�и��ӵ��ʱ��
��ʱ��Ҳ���ᡣ
������ɡ����
ֱ��ȫ��Ⱦ�ɰ�ɫ����ɶȨֵ���������𡭡�
�����ǿ��Ǽ��븽�ӵ㡣
���ǿ���ֻ��һ�����ӵ�������
���ǵ�Ȼѡ��ֱ��Ⱦ��������ɫ��
��������һ����ɫ���أ�
��������Ҫ��������������ΪԴ�����С���
����أ�
������Դ�㣬�������а�ɫ����������������к�ɫ��
Ȼ���ܱ���С�����¡�
250000������50����С�����û�����𡭡� 
�����ˣ�ç�� 
������ô֪��һ�����Ǵ��ıߵ��ı� 

2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0

����
��ʵ����Ҳ��ֻ����k=2���� 
Ҳû�ԡ��� 
û���ˡ�
���ö�������ٰɡ� 
*/
#include<queue>
#include<cstdio>
using namespace std;
long long n,m,t,x1[510][510],x2[510][510],x3[100],p[100],c[100],k,c1,c2,sups,supt;
long long id(long long x,long long y)
{
	return (x-1)*m+y;
}
long long cur[300010],head[300010],nxt[1200010],to[1200010],val[1200010],cntot;
void addedge(long long one,long long ano,long long lav,long long vla)
{
	nxt[++cntot]=head[one];
	to[cntot]=ano;
	val[cntot]=lav;
	head[one]=cntot;
	nxt[++cntot]=head[ano];
	to[cntot]=one;
	val[cntot]=vla;
	head[ano]=cntot;
}
long long getp(long long x)
{
	if(x<=m)	return id(1,m);
	else if(x<=n+m)	return id(x-m,m);
	else if(x<=n+m*2)	return id(n,m-(x-n-m)+1);
	else	return id(n-(x-n-m*2)+1,1);
}
const long long INF=1e18;
queue<long long> que;
long long dis[300010],ans;
bool bfs()
{
	for(long long i=1;i<=supt;++i)
	{
		cur[i]=head[i];
		dis[i]=INF;
	}
	dis[sups]=0;
	que.push(sups);
	while(!que.empty())
	{
		long long now=que.front();
		que.pop();
		for(long long i=head[now];i;i=nxt[i])
		{
			long long y=to[i];
			if(val[i]&&dis[y]==INF)
			{
				dis[y]=dis[now]+1;
				que.push(y); 
			}
		}
	}
	return dis[supt]!=INF;
}
long long dfs(long long x,long long flow)
{
	if(x==supt)	return flow;
	long long rlow=0,used=0;
	for(long long i=cur[x];i;i=nxt[i])
	{
		cur[x]=i;
		long long y=to[i];
		if(val[i]&&dis[y]==dis[x]+1)
		{
			rlow=dfs(y,min(val[i],flow-used));
			if(rlow)
			{
				used+=rlow;
				val[i]-=rlow;
				val[i^1]+=rlow;
				if(used==flow)	break;
			}
			else	dis[y]=INF;
		}
	}
	return used;
}
void dinic()
{
	ans=0;
	while(bfs())	ans+=dfs(sups,INF);
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&t);
	for(long long i=1;i<n;++i)
	{
		for(long long j=1;j<=m;++j)	scanf("%lld",&x1[i][j]);
	} 
	for(long long i=1;i<=n;++i)
	{
		for(long long j=1;j<m;++j)	scanf("%lld",&x2[i][j]);
	} 
	for(long long i=1;i<=t;++i)
	{
		scanf("%lld",&k);
		c1=c2=0;
		for(long long j=1;j<=k;++j)
		{
			scanf("%lld %lld %lld",&x3[j],&p[j],&c[j]);
			if(c[j]==1)	c2=1;
			else	c1=1;
		}
		if(c1&&c2)
		{
			if(k==2&&getp(p[1])==getp(p[2]))
			{
				printf("%lld\n",min(x3[1],x3[2]));
				continue;
			}
			sups=n*m+k+1;
			supt=sups+1;
			for(long long j=1;j<=supt;++j)	head[j]=0;
			cntot=1;
			for(long long j=1;j<=k;++j)
			{
				if(c[j])	addedge(n*m+j,supt,INF,INF);
				else	addedge(sups,n*m+j,INF,INF);
				addedge(getp(p[j]),n*m+j,x3[j],x3[j]);
			}
			for(long long z=1;z<n;++z)
			{
				for(long long j=1;j<=m;++j)	addedge(id(z,j),id(z+1,j),x1[z][j],x1[z][j]);
			} 
			for(long long z=1;z<=n;++z)
			{
				for(long long j=1;j<m;++j)	addedge(id(z,j),id(z,j+1),x2[z][j],x2[z][j]);
			}
			dinic();
			printf("%lld\n",ans);
		}
		else	printf("0\n");
	}
	return 0;
}
