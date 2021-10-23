#include<bits/stdc++.h>
using namespace std;
int n,k,cnt;
const int mod=1e9+7;
char a[505],vis[505];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++){
		cin>>a[i];
		if(a[i]=='?')++cnt;
	}
	cout<<(cnt%mod)*((cnt+1)%mod);
	return 0;
}
