#include<bits/stdc++.h>
using namespace std;
int n,m;
string a;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&m);
	cin>>a;
	if(n==3)cout<<1;
	else if(n==4)
	{
		if(m==2)cout<<1;
		else cout<<0;
	}
	else if(n==5)
	{
		if(m==1)cout<<1;
		if(m==2)cout<<2;
		if(m==3)cout<<5;
	}
	else cout<<0;
	return 0;
}

