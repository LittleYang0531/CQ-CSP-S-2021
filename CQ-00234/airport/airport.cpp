#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
struct node1
{
	int a1,b1;
	bool operator <(const node1 &n)const
	{
		return a1<n.a1;
	}
}arr1[1000005];
struct node2
{
	int a2,b2;
	bool operator <(const node2 &n)const
	{
		return a2<n.a2;
	}
}arr2[1000005];
int dp[1000005],f[1000005];	
priority_queue<int,vector<int>,greater<int> > p,q;
int ans;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)
	{
		scanf("%d%d",&arr1[i].a1,&arr1[i].b1);
	}
	for(int i=1;i<=m2;++i)
	{
		scanf("%d%d",&arr2[i].a2,&arr2[i].b2);
	}
	sort(arr1+1,arr1+m1+1);
	sort(arr2+1,arr2+m2+1);
	for(int i=1;i<=n;++i)
	{
		dp[i]=m1;
		f[i]=m2;
		for(int j=1;j<=m1;++j)
		{
			while(!p.empty())
			{
				int x=p.top();
				if(x<=arr1[j].a1)
				{
					p.pop();
				}
				else
				break;
			}
			if(p.size()<i)
			{
				p.push(arr1[j].b1);
			}
			else
			{
				dp[i]--;
			}
		}
		for(int j=1;j<=m2;++j)
		{
			while(!q.empty())
			{
				int x=q.top();
				if(x<=arr2[j].a2)
				{
					q.pop();
				}
				else
				break;
			}
			if(q.size()<i)
			{
				q.push(arr2[j].b2);
			}
			else
			{
				f[i]--;
			}
		}
		while(!p.empty())
		p.pop();
		while(!q.empty())
		q.pop();
	}
	for(int i=0;i<=n;++i)
	{
		ans=max(f[i]+dp[n-i],ans);
	}
	printf("%d\n",ans);
	return 0;
}
/*
   c        c    ffffffff     n      n           m             m            ss    l
  c        c     f            nn     n          m m           m m          s      l
 c        c      f            n n    n         m   m         m   m        s       l
c        c       ffffffff     n  n   n        m     m       m     m       s       l
c        c       f            n   n  n       m       m     m       m       s      l
 c        c      f            n    n n      m         m   m         m       s     l
  c        c     f            n     nn     m           m m           m    s  s    l
   c        c    f            n      n    m             m             m     s     lllllllllll
*/
