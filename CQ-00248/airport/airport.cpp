#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,get1[100007],get2[100007],ans=0,k=10;
bool vis1[100007],vis2[100007];
const double down=0.996;
struct node
{
	int come,leave;
}a1[100007],a2[100007];
bool cmp(node b1,node b2)
{
	if(b1.come!=b2.come) return b1.come<b2.come;
	return b1.leave<b2.leave;
}
inline int cost(node *a,int ma,bool *vis)
{
	int tmp=0,sum=0;
	for(int i=1;i<=ma;i++)
	{
		if(vis[i]==0&&a[i].come>=tmp)
		{
			sum++;
			tmp=a[i].leave;
			vis[i]=1;
		}
	}
	return sum;
}
int check(int a,int b)
{
	int tmp1[a+1],tmp2[b+1];
	int sum=0;
//	memset(vis1,0,sizeof(vis1));
//	memset(vis2,0,sizeof(vis2));
	for(int i=1;i<=m1;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(tmp1[j]<=a1[i].come)
			{
				sum++;
				tmp1[j]=a1[i].leave;
				break;
			}
		}
	}
	for(int i=1;i<=m2;i++)
	{
		for(int j=1;j<=a;j++)
		{
			if(tmp2[j]<=a2[i].come)
			{
				sum++;
				tmp2[j]=a2[i].leave;
				break;
			}
		}
	}
	return sum;
}
void fire()
{
	double t=3007;
	int nowans,a=1,b=n-1;
	while(t>=1e-12)
	{
		int tmpa=a,tmpb=b;
		a+=rand()%n+1;
		a=a%n+1,b=n-a;
		nowans=check(a,b);
		if(nowans>ans) ans=nowans;
		else if(exp(nowans-ans)/t<(double)rand()/RAND_MAX) a=tmpa,b=tmpb;
		t*=down;
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d %d",&a1[i].come,&a1[i].leave);
	}
	for(int i=1;i<=m2;i++)
	{
		scanf("%d %d",&a2[i].come,&a2[i].leave);
	}
	sort(a1+1,a1+1+m1,cmp);
	sort(a2+1,a2+1+m2,cmp);
	if(m1*n<1e9&&m2*n<1e9)
	{
		for(int i=1;i<=n;i++)
		{
			get1[i]=get1[i-1]+cost(a1,m1,vis1);
			get2[i]=get2[i-1]+cost(a2,m2,vis2);
		}
		for(int i=0;i<=n;i++)
		{
			ans=max(get1[i]+get2[n-i],ans);
		}
		printf("%d",ans);
		return 0;
	}
	while(k--)
	{
		fire();
	}
	printf("%d",ans);
	return 0;
}
