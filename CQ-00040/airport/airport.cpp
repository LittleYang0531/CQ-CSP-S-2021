#include<bits/stdc++.h>
using namespace std;
int read()
{
	int x=0;
	char c;
	do
		c=getchar();
	while(c<'0'||'9'<c);
	while('0'<=c&&c<='9')
	{
		x=(x<<3)+(x<<1)+(c^48);
		c=getchar();
	}
	return x;
}
const int N=1e5;
int m[2],w[2][N+5],v[N];
priority_queue<pair<int,int> >q,d;
struct fj{
	int a,b;
}f[N];
bool cmp(fj x,fj y)
{
	return x.a<y.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n=read(),a=0,c;
	m[0]=read(),m[1]=read();
	for(int i=0;i<2;i++)
	{
		c=0;
		while(!q.empty())
			q.pop();
		while(!d.empty())
			d.pop();
		for(int j=0;j<m[i];j++)
			f[j].a=read(),f[j].b=read();
		sort(f,f+m[i],cmp);
		for(int j=0;j<m[i];j++)
		{
			while(!q.empty()&&f[j].a+q.top().first>0)
			{
				d.push(pair<int,int>(-v[q.top().second],q.top().second));
				q.pop();
			}
			if(!d.empty())
			{
				v[j]=v[d.top().second];
				d.pop();
			}
			else
				v[j]=++c;
			w[i][v[j]]++;
			q.push(pair<int,int>(-f[j].b,j));
		}
		for(int j=0;j<n;j++)
			w[i][j+1]+=w[i][j];
	}
	for(int i=0;i<=n;i++)
		a=max(w[0][i]+w[1][n-i],a);
	printf("%d",a);
}
