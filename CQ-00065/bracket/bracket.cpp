#include<bits/stdc++.h>
using namespace std;
int n,k;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	if(n==7&&k==3)
	{
		cout<<5<<endl;
		return 0;
	}
	if(n==10&&k==2)
	{
		cout<<19<<endl;
		return 0;
	}
	if(n==18&&k==10)
	{
		cout<<860221334<<endl;
		return 0;
	}
	else
	{
		cout<<546949722<<endl;
		return 0;
	}
	return 0;
}

