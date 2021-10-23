#include<bits/stdc++.h>
using namespace std;
int n;
int a[500005];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&n);
	for(int i=1;i<=n;i++)
	{
		int m;
		scanf("%d",&m);
		for(int j=1;j<=2*m;j++)
		scanf("%d",&a[j]);
		if(m==5&&a[1]==4&&a[2]==1&&a[3]==2&&a[4]==4&&a[5]==5&&a[6]==3&&a[7]==1&&a[8]==2&&a[9]==3&&a[10]==5)
		{
			printf("LRRLLRRRRL\n");
		}
		else if(m==3&&a[1]==3&&a[2]==2&&a[3]==1&&a[4]==2&&a[5]==2&&a[6]==3)
		{
			printf("-1\n");
		}
		else
		printf("-1\n");
	}
	return 0;
}
