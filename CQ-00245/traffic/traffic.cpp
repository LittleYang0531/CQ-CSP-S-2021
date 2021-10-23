#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##END=b;i<=i##END;++i)
#define go(x) for(int i=a,i##END=b;i<=i##END;++i)
template<class T>
inline void in(T&x)
{
	T f=1;x=0;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9')x=(x<<1)+(x<<3)+(ch^48),ch=getchar();
	x*=f;
}
template void in<int>(int&);
template<class T>
void out(T x)
{
	if(x<0)putchar('-'),x=-x;
	if(x>9)out(x/10);
	putchar(x%10^48);
}
template void out<int>(int);

using namespace std;

const int N=7;

int n,m,k,ans;
int b[N][N],a[N][N][2];
int p[55],d[55],t[55];

int get(int x,int y)
{
	return (x-1)*m+y;
}

int find(int x)
{
	if(x<=m)return x;
	if(x<=n+m)return get(x-m,m);
	if(x<=n+2*m)return get(n,2*m+n+1-x);
	return get(2*m+2*n+1-x,1);
}

int Link()
{
	int res=0;
	For(i,1,n)
	{
		For(j,1,m)
		{
			if((b[i][j]^b[i][j+1])&&b[i][j+1]!=-1)res+=a[i][j][0];
			if((b[i][j]^b[i+1][j])&&b[i+1][j]!=-1)res+=a[i][j][1];
		}
	}
	For(i,1,k)
	{
		int now=find(p[i]);
		int x,y;
		y=(now-1)%m+1,x=(now-y)/m+1;
		if(b[x][y]^t[i])res+=d[i];
	}
	return res;
}

void dfs1(int x,int y)
{
	if(y>m)++x,y=1;
	if(x>n)
	{
		ans=min(ans,Link());
		return;
	}
	b[x][y]=0;
	dfs1(x,y+1);
	b[x][y]=1;
	dfs1(x,y+1);
}

signed main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int T;
	in(n),in(m),in(T);
	For(i,1,n-1)
	{
		For(j,1,m)
		{
			int x;
			in(x);
			a[i][j][1]=x;
		}
	}
	For(i,1,n)
	{
		For(j,1,m-1)
		{
			int x;
			in(x);
			a[i][j][0]=x;
		}
	}
	while(T--)
	{
		ans=1e18;
		memset(b,-1,sizeof b);
		in(k);
		For(i,1,k)
		{
			in(d[i]),in(p[i]),in(t[i]);
		}
		dfs1(1,1);
		out(ans),putchar('\n');
	}
	return 0;
}
