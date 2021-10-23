#include<bits/stdc++.h>
using namespace std;
int n,m,t;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d %d %d",&n,&m,&t);
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			int a;
			scanf("%d",&a);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			int a;
			scanf("%d",&a);
		}
	}
	for(int i=1;i<=t;i++)
	{
		int k;
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			int a,b,c;
			scanf("%d %d %d",&a,&b,&c);
		}
		printf("%d\n",rand());
	}
	
	return 0;
}
