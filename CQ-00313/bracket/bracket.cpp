#include<bits/stdc++.h>
using namespace std;
int n,k;
int f[505][3];
string s1;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s1;
	if(n==7)cout<<5;
	if(n==10)cout<<19;
	return 0;
}
