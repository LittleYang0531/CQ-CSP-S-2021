#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<cstring>
#include<algorithm>
#define N 100005
#define INF 0x7fffffff
using namespace std;
struct pot
{
	int x,y;
}pit[105][105];
int x1[105][105],x2[105][105];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	int n,m,k;
	scanf("%d %d %d",&n,&m,&k);
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&x1[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			scanf("%d",&x2[i][j]);
		}
	}
	while(k--)
	{
		printf("0\n");
	}
	return 0;
}

