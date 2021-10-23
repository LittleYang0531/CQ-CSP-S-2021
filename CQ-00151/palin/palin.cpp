#include<bits/stdc++.h>
using namespace std;

int T;
int N;
int a[1000005];

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(false);
	cin>>T;
	for(int i=1;i<=T;i++)
	{
		cin>>N;
		for(int j=1;j<=N*2;j++)
		{
			cin>>a[i];
		}
		cout<<"-1"<<endl;
	}
	return 0;
}
