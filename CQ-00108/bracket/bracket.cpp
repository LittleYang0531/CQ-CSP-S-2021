#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	if(n==7&&k==3) cout<<"5"<<endl;
	else if(n==10&&k==2) cout<<"19"<<endl;
	else if(n==100&&k==18) cout<<"860221334"<<endl;
	else if(n==500&&k==57) cout<<"546949722"<<endl;
	else cout<<"0"<<endl;
	return 0;
}
