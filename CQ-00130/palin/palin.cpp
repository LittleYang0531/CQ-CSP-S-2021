#include<bits/stdc++.h>
using namespace std;
int T,n;
int a[10005];
int f[15];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		bool flag=true;
		scanf("%d",&n);
		memset(f,0,sizeof(f));
		for(int i=1;i<=n*2;++i)
		{
			scanf("%d",&a[i]);
			++f[a[i]];
		}
		for(int i=1,j=n*2;i<=n,j>=n;++i,--j)
		{
			if(a[i]!=a[j])
				flag=false;
		}
		if(flag)
		{
			for(int i=1;i<=n;++i)
				cout<<"LL";
			continue;
		}
		cout<<-1;
	}
	return 0;
}
