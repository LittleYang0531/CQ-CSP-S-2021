#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<map>
using namespace std;
int n,m[2],b[100005],tot,root,now,an[100005][2],ans;
int maxx(int x,int y){return x<y?y:x;}
struct ll
{
	int x;
	int y;
}a[2][100005]; 
bool cmp(ll x,ll y){return x.x<y.x;}
map<int,int>mp;
struct pt
{
	int f;
	int ch[2];
	int size;
	int id;
}t[100005];
void up(int x){t[x].size=t[t[x].ch[0]].size+t[t[x].ch[1]].size+1;}
void rtt(int x)
{
	int p=t[x].f,qwq=!(t[p].ch[1]^x);
	t[x].f=t[p].f;
	if(t[p].f)t[t[p].f].ch[!(t[t[p].f].ch[1]^p)]=x;
	t[p].ch[qwq]=t[x].ch[qwq^1];
	if(t[x].ch[qwq^1])t[t[x].ch[qwq^1]].f=p;
	t[x].ch[qwq^1]=p;t[p].f=x;
	up(p);up(x);
}
void splay(int x,int y)
{
	int p=t[x].f;
	while(p^y)
	{
		if(t[p].f^y&&!((!(t[p].ch[1]^x))^(!(t[t[p].f].ch[1]^p))))rtt(p);
		rtt(x);p=t[x].f;
	}
	if(!y)root=x;
}
void cr(int x)
{
	if(!root){root=++tot;t[tot].size=1;t[tot].id=x;return ;}
	int p=root;
	t[p].ch[1]=++tot;
	t[tot].f=p;t[tot].size=1;
	t[tot].id=x;splay(tot,0);
}
int hj(int d)
{
	int p=root;
	while(t[p].ch[a[now][t[p].id].x<d])p=t[p].ch[a[now][t[p].id].x<d];
	splay(p,0);if(!(p^m[now]+2))return 0;
	if(a[now][t[p].id].x>d)return p;
	p=t[p].ch[1];while(t[p].ch[0])p=t[p].ch[0];
	if(!(p^m[now]+2))return 0;
	return p;
}
void sc(int x)
{
	int l,r;
	splay(x,0);
	l=t[x].ch[0];r=t[x].ch[1];
	while(t[l].ch[1])l=t[l].ch[1];
	while(t[r].ch[0])r=t[r].ch[0];
	splay(l,0);splay(r,l);
	t[r].ch[0]=0;splay(r,0);
}
void js()
{
	int i,la,qwq;
	tot=root=0;mp.clear();
	memset(t,0,sizeof(t));
	memset(b,0,sizeof(b));
	for(i=1;i<=m[now];++i)
	{
		scanf("%d%d",&a[now][i].x,&a[now][i].y);
		b[++tot]=a[now][i].x;b[++tot]=a[now][i].y;
	}
	sort(a[now]+1,a[now]+m[now]+1,cmp);
	sort(b+1,b+(m[now]<<1)+1);tot=0;
	for(i=1;i<=(m[now]<<1);++i)mp[b[i]]=++tot;
	for(i=1;i<=m[now];++i)
	{
		a[now][i].x=mp[a[now][i].x];
		a[now][i].y=mp[a[now][i].y];
	}
	tot=0;
	cr(0);for(i=1;i<=m[now];++i)cr(i);cr(m[now]+1);
	
	for(i=1;i<=n;++i)
	{
		an[i][now]=an[i-1][now];la=0;
		while(qwq=hj(la)){sc(qwq);la=a[now][t[qwq].id].y;++an[i][now];}
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int i,j;
	scanf("%d%d%d",&n,&m[0],&m[1]);
	a[0][0].x=a[1][0].x=-1;a[0][m[0]+1].x=a[1][m[1]+1].x=100000001;
	now=0;js();now=1;js();
	for(i=1;i<=n;++i)ans=maxx(ans,an[i][0]+an[n-i][1]);
	printf("%d\n",ans);
	return 0;
}
/*
3 5 4
1 3
2 5
4 7
6 9
8 10

1 4
2 6
3 8
5 7


2 4 6
20 30
40 50
21 22
41 42

1 19
2 18
3 4
5 6
7 8
9 10


*/
