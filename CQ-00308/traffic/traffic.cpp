#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,mod=1e9+7;
int n,m,k,t;
int a[N][N],b[N][N],v[N][N],p[N][N],s[N][N];
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	int maa=0;
	for(int i=1;i<=n-1;i++)	
	{
		for(int j=1;j<=m;j++)
		{
			cin>>a[i][j];
			maa=max(maa,a[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			cin>>b[i][j];
			maa=max(maa,b[i][j]);
		}
	}
	for(int i=1;i<=t;i++)
	{
		cin>>k;
		int maxe=0;
		for(int j=1;j<=k;j++)
			cin>>v[i][j]>>p[i][j]>>s[i][j];
		for(int j=1;j<=k-1;j++)
		maxe=max(maxe,(v[i][j]-v[i][j+1]));
		maxe+=maa;
		cout<<maxe<<endl;
	}
	return 0;
}
