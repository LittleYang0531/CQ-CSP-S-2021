#include<bits/stdc++.h>
using namespace std;
long long n,m1,m2,maxn;
struct nodgd
{
	long long time1,time2;
};
nodgd a[100005],b[100005];
int temp[100005];
bool p;
bool cmp(nodgd x,nodgd y)
{
	return x.time1<y.time1;
}
long long check(long long x,int y)
{
	long long lft=x;
	int ans=0,num=0,cha=2006032400,chs=0,val=0;
	bool w=0;
	//memset(temp,0,sizeof(temp));
	if (x==0) return 0;
	else
	{
		if (y==1)
		{
			lft--;
			num++;
			ans++;
			temp[1]=b[1].time2;
			for (int i=2;i<=m2;i++)
			{
				w=0;
				cha=2006032400;
				for (int j=1;j<=num;j++)
				{
					if (b[i].time1>temp[j]) 
					{
						if (abs(b[i].time1-temp[j])<cha)
						{
							chs=j;
							val=b[i].time2;
							cha=abs(b[i].time1-temp[j]);
							//cout<<cha<<" ";
						}
						w=1;
					} 
				}
				if (w==1)
				{
					ans++;
					temp[chs]=val;
				}
				if (lft>0 && w==0)
				{
					lft--;
					num++;
					ans++;
					//cout<<b[i].time2<<endl;
					temp[num]=b[i].time2;
				}
			}
		}
		if (y==0)
		{
			lft--;
			num++;
			ans++;
			temp[1]=a[1].time2;
			for (int i=2;i<=m1;i++)
			{
				//cout<<temp[1]<<" "<<temp[2]<<endl;
				w=0;
				cha=2006032400;
				for (int j=1;j<=num;j++)
				{
					if (a[i].time1>temp[j]) 
					{
						if (abs(a[i].time1-temp[j])<cha)
						{
							chs=j;
							val=a[i].time2;
							cha=abs(a[i].time1-temp[j]);
						}
						w=1;
					} 
				}
				if (w==1)
				{
					ans++;
					temp[chs]=val;
				}
				if (lft>0 && w==0)
				{
					lft--;
					num++;
					ans++;
					temp[num]=a[i].time2;
				}
			}
		}
		return ans;
	}
}
long long ans;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for (int i=1;i<=m1;i++)
	{
		scanf("%lld%lld",&a[i].time1,&a[i].time2);
	}
	for (int i=1;i<=m2;i++)
	{
		scanf("%lld%lld",&b[i].time1,&b[i].time2);
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	for (int i=0;i<=n;i++)
	{
		maxn=max(maxn,check(i,1)+check(n-i,0));
	}
	printf("%lld",maxn);
	//I love TLE so much!!! 70pts
	//20060324
	return 0;
}
