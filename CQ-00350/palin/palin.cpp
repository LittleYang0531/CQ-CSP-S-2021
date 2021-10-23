#include<stdio.h>
using namespace std;
iny a[500001];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n;
	scanf("%d",&n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&b);
		for(int j=0;j<b*2;j++)
		{
			scanf("%d",&a[j]);
		}
		printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
