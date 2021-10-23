#include<iostream>
using namespace std;
int n,m1,m2,ans=0,s=0;
int ma[100005][2],mb[100005][2];
int na[100005],nb[100005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++){
		cin>>ma[i][1]>>ma[i][2];
	}
	for(int i=1;i<=m2;i++){
		cin>>mb[i][1]>>mb[i][2];
	}
	for(int i=0;i<=n;i++){
		for(int k=1;k<=m1;k++){
			for(int j=1;j<=i;j++){
				if(ma[k][1]>=na[j]){
					ans++;
					na[j]=ma[k][2];
					break;
				}
			}
		}
		for(int k=1;k<=m2;k++){
			for(int j=1;j<=n-i;j++){
				if(mb[k][1]>=nb[j]){
					ans++;
					nb[j]=mb[k][2];
					break;
				}
			}
		}
		if(ans>s){
			s=ans;
		}
		for(int j=1;j<=n;j++){
			na[j]=0;
			nb[j]=0;
		}
		ans=0;
	}
	cout<<s;
	return 0;
}
