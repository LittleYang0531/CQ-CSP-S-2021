#include<bits/stdc++.h>
using namespace std;
int n,m,T,a[505][505],lst[250005],id[505][505],cntid;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
			scanf("%d",&a[i][j]);
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			scanf("%d",&a[i][j]);
	while(T--)
	{
		int k;
		scanf("%d",&k);
		bool flag=1;
		long long sum=0;
		int x,y,z,lst=-1;
		while(k--)
		{
			scanf("%d%d%d",&x,&y,&z);
			if(lst=-1) z=lst;
			else if(lst!=z) flag=0;
			sum+=y;
		}
		printf("%lld\n",sum);
	}
	return 0;
}
