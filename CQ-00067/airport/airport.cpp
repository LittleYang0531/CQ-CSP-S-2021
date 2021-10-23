#include <bits/stdc++.h>
using namespace std;
int n,m1,m2;
struct node
{
	int in;
	int out;
} a[100001];
struct note
{
	int in;
	int out;
} b[100001];
int ans=-1;
int mark[100001];
int bio1(int x)
{
	int res=0;
	memset(mark,0,sizeof (mark));
	for (int i=1;i<=m1;i++)
	{
		for (int j=1;j<=x;j++)
		{
			if (mark[j] < a[i].in)
			{
				mark[j]=a[i].out;
				res++;
				break;
			}
		}
	}
	return res;
}
int bio2(int x)
{
	int res=0;
	memset(mark,0,sizeof (mark));
	for (int i=1;i<=m2;i++)
	{
		for (int j=1;j<=x;j++)
		{
			if (mark[j]<b[i].in)
			{
				mark[j]=b[i].out;
				res++;
				break;
			}
		}
	}
	return res;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for (int i=1; i<=m1; i++)
	{
		scanf("%d %d",&a[i].in,&a[i].out);
	}
	for (int i=1; i<=m2; i++)
	{
		scanf("%d %d",&b[i].in,&b[i].out);
	}
	int a1[100001];
	for (int i=0;i<=n;i++)
	{
		a1[i]=bio1(i);
	}
	int a2[100001];
	for (int i=0;i<=n;i++)
	{
		a2[i]=bio2(i);
	}
	for (int i=0;i<=n;i++)
	{
		int j=n-i;
		ans=max(ans,a1[i]+a2[j]);
	}
	printf("%d",ans);
	return 0;
}
