#include<bits/stdc++.h>
using namespace std;
const int N=2e6+10;
int n,m,t;
int h[N],w[N],e[N],ne[N],idx;
int col[N];
bool st[N],st2[N];
void add(int a,int b,int c)
{
	e[idx]=b;
	w[idx]=c;
	ne[idx]=h[a];
	h[a]=idx++;
}
long long dfs(int u,int f,int c)
{
//	cout<<c;
	long long cnt=0;
	for(int i=h[u];i!=-1;i=ne[i])
	{
		int j=e[i];
		if(j==f||st[i]==1)continue;
		st[i]=1;
		if(st2[j]==1)
		{
			cnt+=w[i];
			continue;
		}
		st2[j]=1;
		if(j<=m*n)
		cnt+=min(dfs(j,u,c),dfs(j,u,!c)+w[i]);
		else if(c!=col[j]) cnt+=w[i];
		st[i]=0;
		st2[j]=0;
	}
//	cout<<cnt;
	return cnt;
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	memset(h,-1,sizeof h);
	cin>>n>>m>>t;
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
		{
			int a;
			cin>>a;
			add((i-1)*m+j,i*m+j,a);
			add(i*m+j,(i-1)*m+j,a);
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
		{
			int a;
			cin>>a;
			add((i-1)*m+j,(i-1)*m+j+1,a);
			add((i-1)*m+j+1,(i-1)*m+j,a);
		}
	int k;
	while(t--)
	{
		int idx2=idx;
		cin>>k;
		for(int i=1;i<=k;i++)
		{
			int x,p,t;
			cin>>p>>x>>t;
			col[n*m+x]=t;
//			cout<<(x-m)*m<<" ";
//			cout<<(n-1)*m+2*m+n+1-x<<" ";
			if(x<=m)
			add(n*m+x,x,p),add(x,n*m+x,p);
			else if(x>m&&x<=m+n)
			add(n*m+x,(x-m)*m,p),add((x-m)*m,n*m+x,p);
			else if(x>m+n&&x<=2*m+n)
			add(n*m+x,(n-1)*m+2*m+n+1-x,p),add((n-1)*m+2*m+n+1-x,n*m+x,p);
			else
			add(n*m+x,(2*m+2*n-x)*m+1,p),add((2*m+2*n-x)*m+1,n*m+x,p);
		}
		cout<<min(dfs(1,-1,1),dfs(1,-1,0))<<endl;
		idx=idx2;
	}
	return 0;
}
/*
2 3 1
9 4 7
3 8
10 5
2
19 3 1
17 9 0
*/
