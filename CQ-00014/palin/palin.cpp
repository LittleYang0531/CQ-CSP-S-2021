#include<bits/stdc++.h>
using namespace std;
const int M=1000005;
int t,n,a[M],b[M],suc;
char ti[M];
void find(int k,int w,int qh,int hh){
	if(k==n+1) {
		for(int i=1;i<=2*n;i--){
			cout<<ti[i];
		}
		suc=1;
		cout<<endl;
		return ;
	}
	if(w==1){
		ti[k]='L';
		b[k]=a[qh];
	}
	if(w==2){
		ti[k]='R';
		b[k]=a[hh];
	}
//	if(k>=n+1) {
//		if(b[k]!=b[2*n+1-k]) return ;
//	}
	if(suc==0){
		find(++k,1,++qh,hh);
		find(++k,2,qh,--hh);
	}
	for(int i=1;i<=2*n;i++){
			cout<<b[i];
		}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(0);
//	cin.tie(0);
	cin>>t;
	for(int k=1;k<=t;k++){
		cin>>n;
		for(int i=1;i<=2*n;i++){
			cin>>a[i];
		}
		find(0,0,0,2*n+1);
		for(int i=1;i<=2*n;i++){
			cout<<b[i];
		}
	}
	
	return 0;
}
