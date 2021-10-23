#include<cstdio>
#include<algorithm>
using namespace std;
int n,m1,m2,q1[100005],q2[100005];
struct aa {int x,y;} china[100005];
aa world[100005];
bool cmp(aa x,aa y)
{
	return x.x<y.x;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int ans=0;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&china[i].x,&china[i].y);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&world[i].x,&world[i].y);
	sort(china+1,china+n+1,cmp);
	sort(world+1,world+n+1,cmp);
	for(int i=0;i<=n;i++)
	{
		int sn=n-i,r1=0,r2=0,num1=0,num2=0;
		if(i)
			for(int j=1;j<=m1;j++)
			{
				if(r1<i)
				{
					q1[++r1]=j;
					num1++;
				}
				else
				{
					for(int k=1;k<=r1;k++)
						if(china[q1[k]].y<=china[j].x)
						{
							q1[k]=j;
							num1++;
							break;
						}
				}
			}
		if(sn)
			for(int j=1;j<=m2;j++)
			{
				if(r2<sn)
				{
					q2[++r2]=j;
					num2++;
				}
				else
				{
					for(int k=1;k<=r2;k++)
						if(world[q2[k]].y<=world[j].x)
						{
							q2[k]=j;
							num2++;
							break;
						}
				}
			}
		ans=max(ans,num1+num2);
	}
	printf("%d",ans);
	
	return 0;
}
