#include<bits/stdc++.h>
using namespace std;
#define N 100005
int n,m1,m2;
int ans;
int tot1[N],tot2[N];
int put1[N],put2[N],t1,t2;
struct node
{
	int a,b;
}p1[N],p2[N];
map<int,int>flag1,flag2;
int cmp(node a,node b)
{
	if(a.a==b.a)return a.b<b.b;
	else return a.a<b.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&p1[i].a,&p1[i].b);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&p2[i].a,&p2[i].b);
	for(int i=1;i<=m1;i++)
		tot1[i]=1;
	for(int i=1;i<=m2;i++)
		tot2[i]=1;
	sort(p1+1,p1+n+1,cmp);
	sort(p2+1,p2+n+1,cmp);
	for(int i=1;i<=m1;i++)
	{
		if(flag1[i]==1)
		{
			tot1[i]=0;
			continue;
		}
		else put1[++t1]=i;
		int x=p1[i].b;
		for(int j=i+1;j<=m1;j++)
		{
			if(p1[j].a>x&&!flag1[j])
			{
				tot1[i]++;
				x=p1[j].b;
				flag1[j]=1;
			}
		}
	}
	for(int i=1;i<=m2;i++)
	{
		if(flag2[i]==1)
		{
			tot2[i]=0;
			continue;
		}
		else put2[++t2]=i;
		int x=p2[i].b;
		for(int j=i+1;j<=m2;j++)
		{
			if(p2[j].a>x&&!flag2[j])
			{
				tot2[i]++;
				x=p2[j].b;
				flag2[j]=1;
			}
		}
	}
	for(int i=0;i<=n;i++)
	{
		int lei=i,wai=n-i,js=0;
		if(lei>t1)lei=t1;
		if(wai>t2)wai=t2;
		for(int j=1;j<=lei;j++)
			js+=tot1[put1[j]];
		for(int j=1;j<=wai;j++)
			js+=tot2[put2[j]];
		ans=max(ans,js);
	}
	printf("%d",ans);
	return 0;
}
