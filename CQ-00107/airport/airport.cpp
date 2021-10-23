#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,a1[100000],a2[100000],b1[100000],b2[100000],a[100000],b[100000];
int q[100000];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	int t=0;
	for(int i=0;i<m1;i++) cin>>a1[i]>>b1[i];
	for(int i=0;i<m2;i++) cin>>a2[i]>>b2[i];
	for(int k=0;k<=n;k++)
	{
		int maxx=0;
		int x=0,ts=0;
		for(int i=0;i<m1;i++)
		{
			if(ts<k)
			{
				ts++;
				q[i]=b1[i];
				maxx=i;
				x++;
			}
			for(int j=0;j<=maxx;j++)
				if(q[j]!=0 && q[j]<=a1[i])
					q[j]=0,ts--;
		}
		for(int i=0;i<=maxx;i++) q[i]=0;
		maxx=0;
		for(int i=0;i<m2;i++)
		{
			if(ts<n-k)
			{
				ts++;
				q[i]=b2[i];
				maxx=i;
				x++;
			}
			for(int j=0;j<=maxx;j++)
				if(q[j]!=0 && q[j]<=a2[i])
					q[j]=0,ts--;
		}
		for(int i=0;i<=maxx;i++) q[i]=0;
		t=max(t,x);
	}
	cout<<t;
	
	return 0;
}
