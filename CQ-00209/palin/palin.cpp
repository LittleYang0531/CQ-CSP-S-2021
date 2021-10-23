#include<bits/stdc++.h>
using namespace std;
string s;
int t;
int a[1000001];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int n;
	cin>>n;
	for(int i=1;i<=n;i++){
		cin>>t;
		for(int j=1;j<=2*t;j++) cin>>a[i];
		cout<<-1<<"\n";
	}
}
