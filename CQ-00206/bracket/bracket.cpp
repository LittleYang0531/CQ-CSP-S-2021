#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
long long fb[10000];
long long q=1000000010;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s;
	fb[2]=1;
	fb[3]=1;
	for(int i=4;i<=n;i++)
	   fb[i]=(fb[i-1]+fb[i-3]+fb[i-2])%q;
	cout<<fb[n]<<"\n";
	return 0;
}
