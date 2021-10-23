#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#include<queue>
#include<vector>
#define maxn 100002
#define inf (1<<30)
typedef long long ll;
using namespace std;
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-f,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	return x*f;
}
struct str{
	int l,r;
	bool operator <(const str &b)const
	{
		return r>b.r;
	}
}a[maxn],b[maxn];
int n,m1,m2;
bool cmp(str x,str y)
{
	return x.l<y.l;
}
priority_queue<int,vector<int>,greater<int> >q;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m1=read();
	m2=read();
	for(int i=1;i<=m1;i++)
	{
		a[i].l=read();
		a[i].r=read();
	}
	for(int i=1;i<=m2;i++)
	{
		b[i].l=read();
		b[i].r=read();
	}
	sort(a+1,a+m1+1,cmp);
	sort(b+1,b+m2+1,cmp);
	int ans=0;
	for(int k=0;k<=n;k++)
	{
		int k1=n-k;
		int sum=0,sum1=0;
		while(!q.empty() )q.pop();
		for(int i=1;i<=m1;i++)
		{
			while(!q.empty())
			{
				int w=q.top();
				if(w<a[i].l )
				{
					q.pop() ;
				}else
				{
					break;
				}
			}
			if(q.size()<k)
			{
				q.push(a[i].r);
				sum++;
			}
		}
		while(!q.empty()  )
		{
			q.pop() ;
		}
		for(int i=1;i<=m2;i++)
		{
			while(!q.empty() )
			{
				int w=q.top() ;
				if(w<b[i].l)
				{
					q.pop() ;
				}else break;
			}
			if(q.size()<k1)
			{
				q.push(b[i].r);
				sum1++;
			}
		}
		ans=max(ans,sum+sum1);
	}
	printf("%d\n",ans);
	return 0;
}


