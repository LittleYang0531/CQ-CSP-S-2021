#include <cstdio>
const int M = 100005;
int read()
{
	int x=0,f=1;char c;
	while((c=getchar())<'0' || c>'9') {if(c=='-') f=-1;}
	while(c>='0' && c<='9') {x=(x<<3)+(x<<1)+(c^48);c=getchar();}
	return x*f;
}
int T,n,m,f,a[M],b[M],p[M];
void dfs(int x,int l,int r)
{
	if(f==1) return ;int y=x-1;
	if(y>n && p[y]!=p[m-y+1]) return ;
	if(l>r)//find the answer
	{
		for(int i=1;i<=m;i++)
		{
			if(b[i]==0) putchar('L');
			if(b[i]==1) putchar('R');
		}
		f=1;
		return ;
	}
	b[x]=0;p[x]=a[l];
	dfs(x+1,l+1,r);
	b[x]=1;p[x]=a[r];
	dfs(x+1,l,r-1);
}
void work()
{
	n=read();m=2*n;f=0;
	for(int i=1;i<=m;i++)
		a[i]=read();
	dfs(1,1,m);
	if(!f) printf("-1");
	puts("");
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--) work();
}
