#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
long long ans;
struct node
{
	int r,l;
}a[100005],b[100005];
bool sta[100005],stb[100005];
bool cmp(node a,node b)
{
	return a.l<b.l;
}
queue<int>q1;
queue<int>q2;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].l,&b[i].r);
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int i=1;i<=m1;i++)
	{
		int t=1;
		if(sta[i]==1)continue;
		else sta[i]=1;
		int R=a[i].r;
		for(int j=i+1;j<=m1;j++)
		{
			if(sta[j]==0&&a[j].l>R)
			{
				sta[j]=1;
				R=a[j].r;
				t++;
			}
		}
		q1.push(t);
	}
	for(int i=1;i<=m2;i++)
	{
		int t=1;
		if(stb[i]==1)continue;
		else stb[i]=1;
		int R=b[i].r;
		for(int j=i+1;j<=m2;j++)
		{
			if(stb[j]==0&&b[j].l>R)
			{
				stb[j]=1;
				R=b[j].r;
				t++;
			}
		}
		q2.push(t);
	}
	while(n--)
	{
		int x=0,y=0;
		if(!q1.empty())x=q1.front();
		if(!q2.empty())y=q2.front();
		ans+=max(x,y);
		if(x>=y&&!q1.empty())q1.pop();
		else if(!q2.empty())q2.pop();
	}
	printf("%lld\n",ans);
	return 0;
}
