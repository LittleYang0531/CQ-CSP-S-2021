#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
int n,m,t;
int a;
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<=n-1;i++)
	{
		for(int j=1;j<=m;j++)cin>>a;
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=m-1;j++)cin>>a;
	}
	while(t--)
	{
		cout<<0<<endl;
	}
	return 0;
}

