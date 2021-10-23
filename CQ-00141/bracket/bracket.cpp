#include<bits/stdc++.h>
using namespace std;
long long n,k=0;
char a;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		cin>>a;
		if(a=='?') k++;
	}
	cout<<k;
	return 0;
}
