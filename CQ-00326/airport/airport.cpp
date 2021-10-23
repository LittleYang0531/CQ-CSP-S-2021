#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,a1[100001],a2[100001],b1[100001],b2[100001];
struct node
{
	int a,b;
};
node na[100001],inn[100001];
bool cmp(node x,node y)
{
	return x.a<y.a;
}
int vis1[100001],vis2[100001];
bool check(int x)
{
	
	for(int i=0;i<=n;i++)
	{
		int k1=i,k2=n-i;
		int sum=0;
		for(int j=1;j<=m1;j++)
		{
			if(k1>0)
			{
				k1--;
				sum++;
				if(sum>=x)
				return 1;
				vis1[j]=1;
			}
			else
			{
				for(int k=1;k<=j;k++)
				{
					if(vis1[k])
					{
						if(na[j].a>na[k].b)
						{
							vis1[k]=0;
							k1++;
						}
					}
				}
				if(k1>0)
				{
					sum++;
					k1--;
					vis1[j]=1;
					if(sum>=x)
					return 1;
				}
			}
			
		}
		for(int j=1;j<=m2;j++)
		{
			if(k2>0)
			{
				k2--;
				sum++;
				if(sum>=x)
				return 1;
				vis2[j]=1;
			}
			else
			{
				for(int k=1;k<=j;k++)
				{
					if(vis2[k])
					{
						if(inn[j].a>inn[k].b)
						{
							vis2[k]=0;
							k2++;
						}
					}
				}
				if(k2>0)
				{
					sum++;
					k2--;
					vis2[j]=1;
					if(sum>=x)
					return 1;
				}
			}
		}
	}
	return 0;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int c=clock();
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	scanf("%d%d",&na[i].a,&na[i].b);
	for(int i=1;i<=m2;i++)
	scanf("%d%d",&inn[i].a,&inn[i].b);
	sort(na+1,na+m1+1,cmp);
	sort(inn+1,inn+m2+1,cmp);
	int l=0,r=m1+m2+1;
	while(l<=r)
	{
		int mid=(l+r)/2;
		if(check(mid))
		l=mid+1;
		else
		r=mid-1;
	}
	printf("%d",r);
	return 0;
}
