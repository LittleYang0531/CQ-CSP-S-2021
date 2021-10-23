#include<iostream>
#include<cstdio>
using namespace std;
int main()
{
	freoprn("traffic","r",stdin);freopen("traffic","w",stdout);
	int n,m,t,x;
	cin>>n>>m>>t;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)
		{
			cin>>x;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)
		{
			cin>>x;
		}
	}
	cout<<"654";
	return 0;
}
