#include<bits/stdc++.h>
using namespace std;
const int MAX = 5e5+10;
int t,n,d;
int a[2*MAX],b[2*MAX];
bool vis[MAX];
inline int read()
{
	int x=0,f=1;
	char ch = getchar();
	while(ch<'0' or ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0' and ch<='9') x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
bool pd(int x,int y)
{
	for(int i = n;i>=1;i--)
	{
		if(a[x]==a[b[i]]) b[n+n-i+1] = x,x++;
		else if(a[y]==a[b[i]]) b[n+n-i+1] = y,y--;
		else return false;
	}
	x = 1,y = 2*n;
	for(int i = 1;i<=2*n;i++)
	{
		if(x==b[i])
		{
			printf("L");
			x++;
		} 
		else if(y==b[i])
		{
			printf("R");
			y--;
		}
	}
	printf("\n");
	return true;
}
void dfs(int now,int x,int y)
{
	if(d==1) return;
	if(now == n+1)
	{
		if(pd(x,y)) d = 1;
		return;
	}
	if(!vis[a[x]]) 
	{
		vis[a[x]] = 1,b[now] = x;
		dfs(now+1,x+1,y);
		vis[a[x]] = 0;
	}
	if(!vis[a[y]])
	{
		vis[a[y]] = 1,b[now] = y;
		dfs(now+1,x,y-1);
		vis[a[y]] = 0;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t = read();
	while(t--)
	{
		n = read(),d = 0;
		for(int i = 1;i<=2*n;i++) a[i] = read();
		dfs(1,1,2*n);
		if(d==0)printf("-1\n");
	}
	return 0;
}
