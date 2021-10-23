#include<bits/stdc++.h>
#define N 105
using namespace std;
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') 
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-48;
		ch=getchar();
	}
	return x*f;
}
int flag,tot,q[N],T,n,a[N],vis[N];
void dfs(int k)
{
	if(flag) return;
	if(k==2*n+1)
	{
		int l=1,r=n*2;
		tot=0;
		for(int i=1;i<=n*2;i++)
		{
			if(vis[i]==1) 
			{
				q[++tot]=a[l];
				l++;
			}
			else
			{
				q[++tot]=a[r];
				r--;
			}
		}
		int pd=1;
		for(int i=1;i<=n;i++)
		{
			if(q[i]!=q[2*n-i+1])
			{
				pd=0;
				break;
			}
		}
		if(pd)
		{
			for(int i=1;i<=n*2;i++)
			{
				if(vis[i]==1) printf("L");
				else printf("R");
			}
			flag=1;
			printf("\n");
		}
		return;
	}
	else
	{
		vis[k]=1;
		dfs(k+1);
		if(flag) return;
		vis[k]=0;
		dfs(k+1);
		if(flag) return;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=n*2;i++)
		{
			a[i]=read();
		}
		memset(vis,0,sizeof(vis));
		flag=0;
		dfs(1);
		if(!flag)printf("-1\n");
	}
	return 0;
}
