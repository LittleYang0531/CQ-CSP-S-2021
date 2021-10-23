#include<bits/stdc++.h>
using namespace std;

int N;
int M;
int T;
int cnt;
int k[100000];

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>N>>M>>T;
	for(int i=1;i<=N-1;i++)
	{
		for(int j=1;j<=M;j++)
		{
			cin>>k[++cnt];
		}
	}
	for(int i=1;i<=N;i++)
	{
		for(int j=1;j<=M-1;j++)
		{
			cin>>k[++cnt];
		}
	}
	for(int i=1;i<=T;i++)
	{
		int op;
		cin>>op;
		for(int j=1;j<=op;j++)
		{
			int x,p,t;
			cin>>x>>p>>t;
		}
	}
	sort(k+1,k+cnt+1);
	cout<<k[1]+k[2]+k[3]<<endl;
	return 0;
}
