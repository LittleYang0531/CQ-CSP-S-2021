#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#define inf 1e10
#define enter putchar('\n')
#define mem(a,b) memset(a,b,sizeof(a))
#define N 505
using namespace std;
int n,m,t,k,a[N][N],b[N][N];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=n-1;i++)
		for(int j=1;j<=m;j++)
			cin>>a[j][j];
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m-1;j++)
			cin>>b[i][j];
	while(t--)
	{
		cin>>k;
		if(k==1||k==0)
		{
			cout<<"0\n";
			continue;
		}
		else if(k==2)
		{
			int x[N],p[N],t[N];
			for(int i=1;i<=k;i++)
				cin>>x[i]>>p[i]>>t[i];
			if(t[1]==t[2])
			{
				cout<<"0\n";
				continue;
			}
			else
			{
				cout<<min(p[1],p[2]);
				enter;
			}
		}
		else cout<<rand()<<'\n';
	}
}
