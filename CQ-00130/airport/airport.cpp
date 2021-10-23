#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,mn=INT_MIN;
struct node
{
	int x,y;
}a[10005],b[10005];
int f[100005];
inline bool cmp(register node a,register node b)
{
	return a.x<b.x;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	if(n>=m1+m2)
	{
		cout<<n;
		return 0;
	}
	for(int i=1;i<=m1;++i)
		scanf("%d %d",&a[i].x,&a[i].y);
	for(int i=1;i<=m2;++i)
		scanf("%d %d",&b[i].x,&b[i].y);
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+n,cmp);
	for(int i=0;i<=n;++i)
	{
		int x=i,y=n-i,s=0;
		if(x!=0)
			if(x>m1)s=m1;
			else
			{
				int l=0;
				for(int j=1;j<=m1;++j)
				{
					if(l==x)
					{
						while(1)
						{
							if(f[l]<a[j].x)f[l--]=0;
							else break;
						}
						if(l<x)
						{
							++s;
							f[l++]=a[j].y;
						}
					}
					else 
					{
						if(x-l>=1)
						{
							++s;
							f[++l]=a[j].y;
						}
					}
				}
		}
		if(y!=0)
			if(y>m2)s=m2;
			else
			{
				int l=0;
				for(int j=1;j<=m2;++j)
				{
					if(l==y)
					{
						while(1)
						{
							if(f[l]<a[j].x)f[l--]=0;
							else break;
						}
						if(l<y)
						{
							++s;
							f[l++]=a[j].y;
						}
					}
					else 
					{
						if(y-l>=1)
						{
							++s;
							f[++l]=a[j].y;
						}
					}
				}
		}
		mn=max(mn,s);
	}
	cout<<mn;
	return 0;
}
