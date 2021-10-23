#include<bits/stdc++.h>
#define R register int
#define I inline
#define ll long long
#define P pair<int,int>
using namespace std;
const int N=1e6+3;
map<P,int>w;
int a[N];
int dfs(int l,int r,int x,int y)
{
//	printf("! %d %d %d %d\n",l,r,x,y);
	if(w.count(P(l,r)))return w[P(l,r)];
	if(l==x&&r==y)return w[P(l,r)]=1;
	if(a[l]==a[x-1]&&l<x-1&&dfs(l+1,r,x-1,y)!=-1)w[P(l,r)]=1;
	else if(a[l]==a[y+1]&&dfs(l+1,r,x,y+1)!=-1)w[P(l,r)]=1;
	else if(a[r]==a[x-1]&&dfs(l,r-1,x-1,y)!=-1)w[P(l,r)]=2;
	else if(a[r]==a[y+1]&&r>y+1&&dfs(l,r-1,x,y+1)!=-1)w[P(l,r)]=2;
	else w[P(l,r)]=-1;
	return w[P(l,r)];
}
char u[N],v[N];
int tu,tv;
void cons(int l,int r,int x,int y)
{
//	printf("? %d %d %d %d %d %d\n",l,r,x,y,tu,tv);
	if(l==x&&r==y)return;
	if(w[P(l,r)]==1)
	{
		u[++tu]='L';
		if(a[l]==a[x-1]&&l<x-1)v[++tv]='L',cons(l+1,r,x-1,y);
		else v[++tv]='R',cons(l+1,r,x,y+1);
	}
	else
	{
		u[++tu]='R';
		if(a[r]==a[x-1])v[++tv]='L',cons(l,r-1,x-1,y);
		else v[++tv]='R',cons(l,r-1,x,y+1);
	}
}
void solve()
{
	int n,m;
	scanf("%d",&n);m=n<<1;
	w.clear();
	for(R i=1;i<=m;i++)scanf("%d",a+i);a[m+1]=0;
	int x=-1,y=-1;
	for(R i=2;i<=m;i++)if(a[i]==a[1]){x=i;break;}
	for(R i=1;i<m;i++)if(a[i]==a[m]){y=i;break;}
//	printf("X %d Y %d\n",x,y);
	tu=tv=0;
	if(dfs(2,m,x,x)!=-1)
	{
		u[++tu]='L';
		v[++tv]='L';
		cons(2,m,x,x);
	}
	else if(dfs(1,m-1,y,y)!=-1)
	{
		u[++tu]='R';
		v[++tv]='L';
		cons(1,m-1,y,y);
	}
	if(tu)
	{
		for(R i=1;i<=tu;i++)putchar(u[i]);
		for(R i=tv;i;i--)putchar(v[i]);
		puts("");
	}
	else puts("-1");
}
int main()
{
//	freopen("palin2.in","r",stdin);
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;scanf("%d",&t);
	while(t--)solve();
}
