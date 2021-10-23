#include<bits/stdc++.h>
#define N 500005
using namespace std;
int n,t,a[N];
bool p;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		cin>>n;
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		cout<<"LR";
	}
}

