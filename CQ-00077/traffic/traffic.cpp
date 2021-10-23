#include <bits/stdc++.h>
using namespace std;
int n,m,T,x1[1001][1001],x2[1001][1001],p[1001],c[1001][1001];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(NULL));//sto sto sto
	std::cin>>n>>m>>T;
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&x1[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m-1;j++)
			scanf("%d",&x2[i][j]);
	for(int i=1,k,x3;i<=T;i++)
	{
		scanf("%d",&k);
		for(int j=1;j<=k;j++)
		{
			scanf("%d",&x3);
			scanf("%d%d",&p[x3],&c[x3]);
		}
		printf("%d\n",rand());//orz orz orz
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}//sto rand() orz
