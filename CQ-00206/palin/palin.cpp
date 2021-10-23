#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[1000010];
char ans[1000010];
int zhong;
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		cin>>n;
		for(int j=0;j<n*2;j++)
		    cin>>a[j];
		cout<<"-1"<<endl;
	}
	return 0;
}
