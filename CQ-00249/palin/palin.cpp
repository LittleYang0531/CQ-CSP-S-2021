#include<bits/stdc++.h>
using namespace std;
int n;
const int MAXN=5e5+5;
int t;
int a[MAXN*2];
int vis[MAXN*2];
int f[MAXN*2];
char s[MAXN*2];
bool found=0;
int abl1,abl2,abr1,abr2;
void dfs(int x,int l,int r,int nl,int nr,int op)
{
	if(found)
	{
		return;
	}
//	printf("%d %d %d %d %d\n",x,l,r,nl,nr);
	if(x==n+1)
	{
		found=1;
		for(int i=1;i<=2*n;i++)
		{
			printf("%c",s[i]);
		}
		return;
	}
	if(op==0)
	{

		s[x]='L';
		s[2*n-x+1]='L';
		dfs(x+1,l+1,r,f[l]-1,f[l]+1,1);
		s[x]='R';
		s[2*n-x+1]='L';
		dfs(x+1,l,r-1,f[r]-1,f[r]+1,1);
		return;
	}
	if(l<nl&&a[l]==a[nl])
	{
		s[x]='L';
		s[2*n-x+1]='L';
		dfs(x+1,l+1,r,nl-1,nr,op);
	}
	if(l<nr&&a[l]==a[nr])
	{
		s[x]='L';
		s[2*n-x+1]='R';
		dfs(x+1,l+1,r,nl,nr+1,op);
	}
	if(r>nl&&a[r]==a[nl])
	{
		s[x]='R';
		s[2*n-x+1]='L';
		dfs(x+1,l,r-1,nl-1,nr,op);
	}
	if(r>nr&&a[r]==a[nr])
	{
		s[x]='R';
		s[2*n-x+1]='R';
		dfs(x+1,l,r-1,nl,nr+1,op);
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
			if(!vis[a[i]])
			{
				vis[a[i]]=i;
			}
			else
			{
				f[i]=vis[a[i]];
				f[vis[a[i]]]=i;
			}
			
		}
		found=0;
		dfs(1,1,n*2,0,0,0);
		if(!found)
		{
			printf("-1");
		}
		printf("\n");
	}
	return 0;
}

