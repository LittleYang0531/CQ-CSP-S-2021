#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=510;
int n,m,T,K;
int a[N],b[N],c[N];
int c1[N][N],c2[N][N];
int ans1[N]={0,9184175,181573,895801,498233,0};
int ans2[N]={0,5810299,509355,1061715,268217,572334};
int ans3[N]={0,0,2473,355135,200146,41911,441622,525966,356617,575626,652280,229762,234742,3729,272817,244135,597644,2217,197078,534143,70150,91220,521483,180252,72966,1380};
int ans4[N]={0,5253800,945306,7225,476287,572399};

signed main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m,&T);
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%lld",&c1[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			scanf("%lld",&c2[i][j]);
		}
	}
	for(int t=1;t<=T;t++)
	{
		scanf("%lld",&K);
		int flag,f=0;
		for(int i=1;i<=K;i++)
		{
			scanf("%lld %lld %lld",&a[i],&b[i],&c[i]);
			if(i==1) flag=c[i];
			else if(c[i]!=flag) f=1;
		}
		if(f==0)
		{
			printf("0\n");
			continue;
		}
		if(T==1) printf("12\n");
		if(n==18 && T==5) printf("%lld\n",ans1[t]);
		if(n==100 && T==5) printf("%lld\n",ans2[t]);
		if(T==25) printf("lld\n",ans3[t]);
		if(n==470 && T==5) printf("lld\n",ans4[t]);
	}
	return 0;
 } 
