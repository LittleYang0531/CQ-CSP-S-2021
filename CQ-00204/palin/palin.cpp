#include<bits/stdc++.h>
using namespace std;
int o,n,a[1000002],b[1000002],l,r;
bool c[1000002],T;
void dfs(int x)
{
	if(T)return;
	if(x==2*n)
	{
		for(int i=0;i<x;i++)
		if(!c[i])printf("L");
		else printf("R");
		printf("\n");
		T=1;
		return;
	}
	if(b[2*n-x-1]==a[l]||x<n)
	{
		c[x]=0;
		b[x]=a[l++];
		dfs(x+1);
		l--;
	}
	if(b[2*n-x-1]==a[r]||x<n)
	{
		c[x]=1;
		b[x]=a[r--];
		dfs(x+1);
		r++;
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&o);
	while(o--)
	{
		scanf("%d",&n);
		l=0;r=2*n-1;T=0;
		for(int i=0;i<2*n;i++)scanf("%d",&a[i]);
		dfs(0);
		if(!T)printf("-1\n");
	}
	return 0;
}
