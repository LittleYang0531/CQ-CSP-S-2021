#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+10;
const int INF=1e9;
int n,m1,m2;
int sta[N],tot;
struct G{
	int st,ed;
}a[N],b[N];

bool cmp(G x,G y)
{
	return x.st<y.st;
}

signed main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%lld %lld",&a[i].st,&a[i].ed);
	for(int i=1;i<=m2;i++)
		scanf("%lld %lld",&b[i].st,&b[i].ed);
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		int ans1=0,ans2=0,gn=i,gw=n-i;
		for(int j=1;j<=m1;j++)
		{
			if(gn!=0)
			{
				sta[++tot]=j;
				gn--;
				ans1++;
			}
			else
			{
				int minn=INF;
				for(int k=1;k<=tot;k++)
				{
					if(a[sta[k]].ed<=a[j].st)
					{
						sta[k]=j;
						ans1++;
						break;
					}
				}
			}
		}
		memset(sta,0,sizeof(sta));
		tot=0;
		for(int j=1;j<=m2;j++)
		{
			if(gw!=0)
			{
				sta[++tot]=j;
				gw--;
				ans2++;
			}
			else
			{
				int minn=INF;
				for(int k=1;k<=tot;k++)
				{
					if(b[sta[k]].ed<=b[j].st)
					{
						sta[k]=j;
						ans2++;
						break;
					}
				}
			}
		}
		memset(sta,0,sizeof(sta));
		tot=0;
		ans=max(ans,(ans1+ans2));
		if(ans==(m1+m2)) break;
	}
	printf("%lld",ans);
	return 0;
 } 
