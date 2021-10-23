#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,at,bt,al,bl,a1[100002][2],b1[100002][2],k,ma;
struct node{int l,r;}a[100002],b[100002];
bool cmp(node x,node y){return x.l<y.l;}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=0;i<m1;i++)scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=0;i<m2;i++)scanf("%d%d",&b[i].l,&b[i].r);
	sort(a,a+m1,cmp);
	sort(b,b+m2,cmp);
	for(int i=0;i<=n&&i<=m1;i++)
	{
		at=0;bt=0;al=i;bl=n-i;k=0;
		for(int j=0;j<m1;j++)
		{
			if(al<=0)
			{
				for(int l=0;l<at;l++)
				if(!a1[l][1]&&a1[l][0]<=a[j].l)a1[l][1]=1,al++;
			}
			if(al)
			{
				al--;k++;
				a1[at][1]=0;
				a1[at++][0]=a[j].r;
			}
		}
		for(int j=0;j<m2;j++)
		{
			if(bl<=0)
			{
				for(int l=0;l<bt;l++)
				if(!b1[l][1]&&b1[l][0]<=b[j].l)b1[l][1]=1,bl++;
			}
			if(bl)
			{
				bl--;k++;
				b1[bt][1]=0;
				b1[bt++][0]=b[j].r;
			}
		}
		ma=max(ma,k);
	}
	printf("%d",ma);
	return 0;
}
