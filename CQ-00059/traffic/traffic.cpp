#include<bits/stdc++.h>
using namespace std;
const int NN=1e6+7;

int n,m,T;
int a[4500][4500];

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>m>>T;
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++)
		{
			int w;
			cin>>w;
			a[i*10+j][(i+1)*10+j]=a[(i+1)*10+j][i*10+j]=w;
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
		{
			int w;
			cin>>w;
			a[i*10+j][i*10+j+1]=a[i*10+j+1][i*10+j]=w;
		}
	for(int i=1;i<=n*10;i++)
		for(int j=1;j<=m;j++)
			if(a[i][j]==0)
				a[i][j]==1e9;
	while(T--)
	{
		int k;
		cin>>k;
		while(k--)
		{
			int x,p,t;
			cin>>x>>p>>t;
			if(p<=m)
				a[1][m]=x;
			else if(p<=m+n)
					a[p-m][m]=x;
				else if(p<=2*m+n)
						a[n][p-m-n]=x;
					else a[p-n-2*m][1]=x;
		}
		
//		for(int i=1;i<=n;i++)
//		{
//			for(int j=1;j<=m;j++)
//				cout<<a[i][j]<<" ";
//			cout<<endl;
//		}
		cout<<0<<endl;
	}
	return 0;
}
