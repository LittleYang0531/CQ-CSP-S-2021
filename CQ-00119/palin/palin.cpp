#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define re register

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

int T;
int n;
int num[500005],b[500005];
static char c[500005];
char z[500005];

inline bool cheak(int x[],int y)
{
	for(re int i = 1,j = y;i <= j;++i,--j)
	{
		if(x[i] != x[j])
			return false;
	}
	return true;
}

inline void dfs(int x,int y,int cnt)
{
	if(cnt > n*2+1)
		return;
	if(cnt == n*2+1)
	{
		if(cheak(b,n*2))
		for(re int i = 1;i <= n*2;++i)
		{
			if(z[i] == c[i])
				continue;
			if(z[i] < c[i])
			{
				for(re int i = 1;i < cnt;++i)
					c[i] = z[i];
				return;
			}
			else{
				return;
			}
		}
		else
			return;
	}
	z[cnt] = 'L';
	b[cnt] = num[x];
	dfs(x+1,y,cnt+1);
	z[cnt] = 'R';
	b[cnt] = num[y];
	dfs(x,y-1,cnt+1);
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T = read();
	while(T--)
	{
		n = read();
		fill(c+1,c+1+n,'z');
		for(re int i = 1;i <= n*2;++i)
			num[i] = read();
		dfs(1,2*n,1);
		if(c[1] == 'z')
			printf("-1\n");
		else
		{
			for(re int i = 1;i <= 2*n;++i)
				printf("%c",c[i]);
			printf("\n");
		}	
	}
	return 0;
}
