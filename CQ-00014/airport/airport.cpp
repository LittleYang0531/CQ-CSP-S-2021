#include<bits/stdc++.h>
using namespace std;
const int M=1e5+5;
struct air{
	int l,r;
}a[100005],b[100005];
//void cmp(int a.x,int a.y){
//	return a.x<a.y;
//}
int n,ma,mb,iu,ju;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>ma>>mb;
	for(int i=1;i<=ma;i++){
		cin>>a[i].l>>a[i].r;
	}
	for(int i=1;i<=mb;i++){
		cin>>b[i].l>>b[i].r;
	}
//	sort(a+1,a+1+n,cmp);
//	sort(b+1,b+1+n,cmp);
	for(int i=0;i<=n;i++){
		int j=n-i;
		iu=i;ju=j;
		
	}
	cout<<n;
	return 0;
}
