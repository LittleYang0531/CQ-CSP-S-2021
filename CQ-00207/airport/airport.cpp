#include<iostream>
#include<cstdio>
#include<queue>
#include<vector>
#include<algorithm>
using namespace std;
struct Node
{
	int a;
	int b;
}a[100005]={},b[100005]={};
int e[100005]={};
int f[100005]={};
int s[100005]={};
int qq[100005]={};
int cnt;
int zhanyong;
priority_queue<int,vector<int>,greater<int> > q;
bool cmp(const Node &a,const Node &b)
{
	return a.a<b.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2,maxx,tmp;
	maxx=-999999999;
	tmp=0;
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i=i+1)
	{
		cin>>a[i].a>>a[i].b;
	}
	for(int i=1;i<=m2;i=i+1)
	{
		cin>>b[i].a>>b[i].b;
	}
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int i=0;i<=n;i=i+1)
	{
		tmp=0;
		zhanyong=0;
		while(!q.empty())
		{
			q.pop();
		}
		for(int j=1;j<=m1;j=j+1)
		{
			while(!q.empty())
			{
				if(a[j].a>q.top())
				{
					
				}else
				{
					break;
				}
				zhanyong=zhanyong-1;
				q.pop();
			}
			zhanyong=zhanyong+1;
//			cout<<zhanyong<<" ";
			
			if(zhanyong<=i)
			{
				tmp=tmp+1; 
				q.push(a[j].b);
			}else
			{
				zhanyong=zhanyong-1;
			}
			
		}
		zhanyong=0;
		while(!q.empty())
		{
			q.pop();
		}
		for(int j=1;j<=m2;j=j+1)
		{
			while(!q.empty())
			{
				if(b[j].a>q.top())
				{
					
				}else
				{
					break;
				}
				zhanyong=zhanyong-1;
				q.pop();
			}
			zhanyong=zhanyong+1;
			if(zhanyong<=n-i)
			{
				tmp=tmp+1;
				q.push(b[j].b);
			}else
			{
				zhanyong=zhanyong-1;
			}
			
		}
		if(tmp>maxx)
		{
			maxx=tmp;
		}
	}
	cout<<maxx;
//	for(int i=1;i<=m1;i=i+1)
//	{
//		while(!q.empty())
//		{
//			if(a[i].a>q.top())
//			{
////				cout<<a[i].a;
//			}else
//			{
//				break;
//			}
//			zhanyong=zhanyong-1;
//			q.pop();
//		}
//		 
//		zhanyong=zhanyong+1;
//		e[i]=zhanyong;
//		q.push(a[i].b);
//	}
//	for(int i=1;i<=m1;i=i+1)
//	{
////		cout<<e[i]<<" ";
//	}
//	zhanyong=0;
//	while(!q.empty())
//	{
//		q.pop();
//	}
//	for(int i=1;i<=m2;i=i+1)
//	{
//		while(!q.empty())
//		{
//			if(b[i].a>q.top())
//			{
//				
//			}else
//			{
//				break;
//			}
//			zhanyong=zhanyong-1;
//			q.pop();
//		}
//		zhanyong=zhanyong+1;
//		f[i]=zhanyong;
//		q.push(b[i].b);
//	}
//	for(int i=1;i<=m2;i=i+1)
//	{
//		cout<<f[i]<<" ";
//	}
//	for(int i=1;i<=m1;i=i+1)
//	{
//		s[e[i]]=s[e[i]]+1;
//	}
//	for(int i=1;i<=m2;i=i+1)
//	{
//		qq[f[i]]=qq[f[i]]+1;
//	}
//	for(int i=1;i<=n;i=i+1)
//	{
//		s[i]=s[i-1]+s[i];
//	}
//	for(int i=1;i<=n;i=i+1)
//	{
//		qq[i]=qq[i-1]+qq[i];
//	}
//	for(int i=0;i<=n;i=i+1)
//	{
//		if(s[i]+qq[n-i]>maxx)
//		{
//			maxx=s[i]+qq[n-i];
//		}
//	}
//	cout<<maxx;
	return 0;
}
