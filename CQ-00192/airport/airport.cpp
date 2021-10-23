#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,ans1,ans2,ans;
int t1[100000000],t2[100000000];
struct solve{
	int x,y;
}a[100002],b[100002];
//bool aa[5002],bb[5002];
bool cmp(solve a,solve b)
{
	return a.x<b.x||a.x==b.x&&a.y<b.y;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].x,&a[i].y);
	for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].x,&b[i].y);
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int k=0;k<=n;k++)
	{
		ans1=0;ans2=0;
		for(int i=1;i<=100000000;i++)
		{
			t1[i]=0;
			t2[i]=0;
		}
		for(int i=1;i<=m1;i++)
		{
			if(t1[a[i].x]<k)
			{
				for(int j=a[i].x;j<=a[i].y;j++)t1[j]++;
				ans1++;
			}
		}
		for(int i=1;i<=m2;i++)
		{
			if(t2[b[i].x]<n-k)
			{
				for(int j=b[i].x;j<=b[i].y;j++)t2[j]++;
				ans2++;
			}
		}
//		printf("%d\n",ans1+ans2);
		ans=max(ans,ans1+ans2);

	}
	printf("%d\n",ans);
	return 0;
//	int r;
//	for(int k=1;k<=min(n,m1);k++)
//	{
//		for(int i=1;i<=n;i++)
//		{
//			aa[i]=false;
//			bb[i]=false;
//		}
//		for(int i=1;i<=k;i++)
//		{
//			if(i==1)
//			{
//				d++;
//				ans1++;
//				aa[i]=true;
//			}
//			else
//			{
//				for(int j=i-k-1;j>=1;j--)
//				{
//					if
//				}
//			}
//		}
//	}
////	for(int i=1;i<=n;i++)
////	{
////		int t=i;
////		for(int j=1;j<=m1;j++)
////		{
////			
////		}
////	}
}
