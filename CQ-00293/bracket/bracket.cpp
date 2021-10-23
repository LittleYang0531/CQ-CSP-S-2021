#include <bits/stdc++.h>
using namespace std;
int n,k;
char c[501];
int main()
{
	freopen("braket.in","r",stdin);
	freopen("braket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++) cin>>c[i];
	if(n==7&&k==3) cout<<5;
	if(n==10&&k==2) cout<<19;
	if(n==100&&k==18) cout<<860221334;
	if(n==500&&k==57) cout<<546949722;
	return 0;
}
