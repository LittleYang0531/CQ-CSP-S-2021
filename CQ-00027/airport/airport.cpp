#include<bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m1,m2;
struct plane{
	int st,ed;
};
plane a[N],b[N];
priority_queue<int> q;
bool cmp(plane x,plane y)
{
	return x.st<y.st;
}
bool check(int num)
{
	int x,y,ans=0;
	for(int i=0;i<=n;i++)
	{
		x=i;//国内分配i个廊桥
		ans=0;
		while(!q.empty()) q.pop();
		for(int j=1;j<=m1;j++)
		{
			while(!q.empty()&&a[j].st>-q.top())
			{
				q.pop();x++;
			}
			if(x)
			{
				q.push(-a[j].ed);x--;
				ans++;
				if(ans>=num) return true;
			}
		}
		y=n-i;
		while(!q.empty()) q.pop();
		for(int j=1;j<=m2;j++)
		{
			while(!q.empty()&&b[j].st>-q.top()) 
			{
				q.pop();y++;
			}
			if(y)
			{
				q.push(-b[j].ed);y--;
				ans++;
				if(ans>=num) {
				return true;
				}
			}
		}
	}
	return false;
} 
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)	scanf("%d%d",&a[i].st,&a[i].ed);
	for(int i=1;i<=m2;i++)	scanf("%d%d",&b[i].st,&b[i].ed);
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	int l=0,r=100000;
	while(l<r)
	{
		int mid=(l+r)/2;
		if(check(mid)) l=mid+1;else r=mid-1;  
	}
	printf("%d",r);
	return 0;
}
