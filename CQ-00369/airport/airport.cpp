#include<bits/stdc++.h>
using namespace std;
struct Edge{int a,b,v;};
Edge a[100005],b[100005];
int n,m1,m2,min1,min2,ans,v2[100005],st[10005],ey[10005],v1[10005];
bool cmp(Edge a,Edge b){return a.b<b.b;}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	min1=min2=1e8;
	memset(v1,-1,sizeof(v1));
	memset(v2,-1,sizeof(v2));
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&a[i].a,&a[i].b);
		a[i].v=a[i].b-a[i].a;
		v1[a[i].a]=i;
		min1=min(min1,a[i].a);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&b[i].a,&b[i].b);
		b[i].v=b[i].b-b[i].a;
		v2[b[i].a]=i;
		min2=min(min2,b[i].a);
	}
	ans=-1;
	for(int i=0;i<=n;i++)
	{
		int x=n-i,ti=i,sum1,sum2;
		sum1=sum2=0;
		memset(st,0,sizeof(st));
		memset(ey,0,sizeof(ey));
		for(int j=min1;j<=a[m1].b;j++)
		{
			for(int k=1;k<=i;k++)
			{
				if(st[k]>0)
				{
					st[k]--;
					if(st[k]==0){ey[k]=0;ti++;}
				}
			}
			if(ti>0&&v1[j]!=-1)
			{
				sum1++;ti--;
				for(int k=1;k<=i;k++)
				{
					if(ey[k]==0&&v1[j]!=-1){
						ey[k]=1;
						st[k]=a[v1[j]].v;
						break;
					}
				}
			}
		}
		memset(st,0,sizeof(st));
		memset(ey,0,sizeof(ey));
		for(int j=min2;j<=b[m2].b;j++)
		{
			for(int k=1;k<=m2;k++)
			{
				if(st[k]>0)
				{
					st[k]--;
					if(st[k]==0){ey[k]=0;x++;}
				}
			}
			if(x>0&&v2[j]!=-1)
			{
				sum2++;x--;
				for(int k=1;k<=n-i;k++)
					if(ey[k]==0){
						ey[k]=1;
						st[k]=b[v2[j]].v;
						break;
					}
			}
		}
		ans=max(ans,sum1+sum2);
	}
	printf("%d\n",ans);
	return 0;
}
