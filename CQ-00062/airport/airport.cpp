#include<bits/stdc++.h>
using namespace std;
inline int read()
{
	int x;
	char ch=getchar();
	while(ch<'0'||ch>'9')
	{
		ch=getchar();
	}
	x=ch-'0';
	ch=getchar();
	while(ch>='0'&&ch<='9')
	{
		x=x*10+(ch^48);
		ch=getchar();
	}
	return x;
}
int n;
int m[2];
struct plant{
	int x,y;
}a[100001];
/*
int c[100001];
inline int lowbit(int n)
{
	return n&(-n);
}
inline void add(int x,int t)
{
	for(;x<=n;x+=lowbit(x))
	{
		c[x]+=t;
	}
	return ;
}
inline int find(int x)
{
	int ans=0;
	for(;x;x-=lowbit(x))
	{
		ans+=c[x];
	}
	return ans;
}
*/
int f[2][100001];
priority_queue<pair<int,int>,vector<pair<int,int> >,greater<pair<int,int> > >q;
priority_queue<int,vector<int>,greater<int> >q_;
int ans=0;
inline bool cmp(plant a,plant b)
{
	return a.x<b.x;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();
	m[0]=read();
	m[1]=read();
	for(int i=1;i<=m[0];i++)
	{
		a[i].x=read();
		a[i].y=read();
		q_.push(i);
	}
	sort(a+1,a+m[0]+1,cmp);
	for(int i=1;i<=m[0];i++)
	{
		while((!q.empty())&&a[i].x>=q.top().first)
		{
			q_.push(q.top().second);			
			q.pop();
		}
		q.push(make_pair(a[i].y,q_.top()));
		//cout<<q_.top()<<endl;
		f[0][q_.top()]++;
		q_.pop();
	}
	while(!q.empty())
	{
		q.pop();
	}
	while(!q_.empty())
	{
		q_.pop();
	}
	for(int i=1;i<=m[1];i++)
	{
		a[i].x=read();
		a[i].y=read();
		q_.push(i);
	}
	sort(a+1,a+m[1]+1,cmp);
	for(int i=1;i<=m[1];i++)
	{
		while((!q.empty())&&a[i].x>=q.top().first)
		{
			q_.push(q.top().second);			
			q.pop();
		}
		q.push(make_pair(a[i].y,q_.top()));
		//cout<<q_.top()<<endl;
		f[1][q_.top()]++;
		q_.pop();
	}
	for(int i=1;i<=n;i++)
	{
		f[0][i]+=f[0][i-1];
		f[1][i]+=f[1][i-1];
		//cout<<f[0][i]<<" ";
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,f[0][i]+f[1][n-i]);
	}
	cout<<ans<<endl;
	//getchar();
	return 0;
}
