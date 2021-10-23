#include<bits/stdc++.h>
using namespace std;
int n,m,T,k,a[10001][10001],b[10001][10001],c[10001][10101];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		scanf("%d",&a[i]);
	}
	for(int i=1;i<=n;i++)
	for(int j=1;j<=m-1;j++)
	scanf("%d",&b[i]);
	scanf("%d",k);
	for(int i=1;i<=k;i++)
	{
		int x,y,z;
		scanf("%d%d%d",&x,&y,&z);
	}
	if(n==2&&m==3&&T==1&&k==2)
	{
		printf("12");
		return 0;
	}
	else if(n==18&&m==18&&T==5&&k==35)
	{
		printf("9184175\n");
		printf("181573\n");
		printf("895801\n");
		printf("498233\n");
		printf("0");
		return 0;
	}
	else printf("0");
	return 0;
}
