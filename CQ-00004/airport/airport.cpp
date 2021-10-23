#include<bits/stdc++.h>
using namespace std;
int n,ma,mb,num;
int a[100005];
struct gl
{
	int a,b;
}ga[100005];
struct gw
{
	int a,b;
}gb[100005];
bool cmpa(gl x,gl y)
{
	return x.a<y.a;
}
bool cmpb(gw x,gw y)
{
	return x.a<y.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&ma,&mb);
	for(int i=1;i<=ma;i++)
	{
		cin>>ga[i].a>>ga[i].b;
	}
	sort(ga,ga+ma+1,cmpa);
	for(int i=1;i<=mb;i++)
	{
		cin>>gb[i].a>>gb[i].b;
	}
	sort(gb,gb+mb+1,cmpb);
	for(int i=0;i<=n;i++)
	{
		memset(a,0,sizeof(a));
		int ans=0;
		int flaga=i;
		int flagb=n-i;
		int tot=1;
		for(int j=1;j<=ma;j++)
		{
			if(j==1&&flaga==0) break;		
			if(tot==1&&j==1)
			{
				a[tot]=ga[j].b;
				flaga--;
				ans++;
				continue;
			}
			for(int k=1;k<=tot;k++)
			{

				if(ga[j].a>a[k])
				{
					a[k]=ga[j].b;
					ans++;
					break;
				}
				if(ga[j].a<a[k])
				{
					if(flaga!=0)
					{
						tot++;
						a[tot]=ga[j].b;
						flaga--;
						ans++;
						break;
					}
				}				
			}
		}
		memset(a,0,sizeof(a));
		tot=1;
		for(int j=1;j<=mb;j++)
		{
			if(j==1&&flagb==0) break;
			if(tot==1&&j==1)
			{
				a[tot]=gb[j].b;
				ans++;
				flagb--;
				continue;
			}
			for(int k=1;k<=tot;k++)
			{
				if(gb[j].a<a[k])
				{
					if(flagb!=0)
					{
						tot++;
						a[tot]=gb[j].b;
						flagb--;
						ans++;
						break;
					}
				}
				else
				{
					a[k]=gb[j].b;
					ans++;
					break;
				}
			}
		}
		num=max(ans,num);		
	}
	cout<<num;		
	return 0;
}
