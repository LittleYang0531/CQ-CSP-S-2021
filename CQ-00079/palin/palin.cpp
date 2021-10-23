#include<cstdio>
#include<iostream>
#include<string.h>
using namespace std;
char s[100005];int cnt=0;
int st[100005];
int n;
int a[100005];
int check(int idx)
{
	//if(idx1!=idx2) return 0;
	for(int  i=1;i<=n;i++)
	{
		if(st[i]!=st[idx-i])
		{
			return 0;
		}
	}
	return 1;
}
int f=0;
void dfs(int lidx,int ridx,int idx,int cnt)
{
	if(lidx>2*n+1||ridx<0) return;
	if(lidx-ridx==1&&idx==n*2+1)
	{
		if(check(idx)==1)
		{
			for(int i=1;i<=cnt;i++)
			{
				printf("%c",s[i]);
			}
			printf("\n");
			f=1;
			return;
		}
	}
	//if(idx1>n||idx2>n) return;
	st[idx]=a[lidx];
	s[cnt]='l';
	dfs(lidx+1,ridx,idx+1,cnt+1);
	if(f==1) return;
	st[idx]=a[ridx];
	s[cnt]='r';
	dfs(lidx,ridx-1,idx+1,cnt+1);
	if(f==1) return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;cin>>t;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1,2*n,1,1);
		if(f==0) printf("-1\n");		
	}
	return 0;
}
