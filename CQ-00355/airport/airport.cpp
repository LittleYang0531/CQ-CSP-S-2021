#include<cstdio>
#include<iostream>
#include<algorithm>
using namespace std;
int n,m1,m2;
int a[100010];
int b[100010];
int c[100010];
int x[100010];
int y[100010];
int z[100010];
long long ans;
int f(int l,int r)
{
	return a[l]<a[r];
}
int s(int l,int r)
{
	return x[l]<x[r];
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a[i],&b[i]);
		c[i]=i;
	}
	sort(c+1,c+m1+1,f);
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&x[i],&y[i]);
		z[i]=i;
	}
	sort(z+1,z+m2+1,s);
	for(int i=0;i<=n;i++)
	{
		int gn=i;
		long long ans1=0;
		int gj=n-i;
		long long ans2=0;
		int ss[100000];
		int idx1=0;
		int aa[100000];
		int idx2=0;
		for(int j=1;j<=m1;j++)
		{
			for(int k=1;k<=idx1;k++)
			{
				if(ss[k]!=0&&ss[k]<=a[c[j]]&&gn<i)
				{
					ss[k]==0;
					gn++;
				}
			}
			if(gn>0)
			{
				gn--;
				idx1++;
				ss[idx1]=b[c[j]];
				ans1++;
			}
		}
		for(int j=1;j<=m2;j++)
		{
			for(int k=1;k<=idx2;k++)
			{
				if(aa[k]!=0&&aa[k]<=x[z[j]]&&gj<n-i)
				{
					aa[k]==0;
					gj++;
				}
			}
			if(gj>0)
			{
				gj--;
				idx2++;
				aa[idx2]=y[z[j]];
				ans2++;
			}
		}
		ans=max(ans,ans1+ans2);
	}
	printf("%lld",ans);
	return 0;
}
