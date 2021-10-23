#include<bits/stdc++.h>
using namespace std;
string ans2;
int a[500005],n,T,k[500005],k1[500005];
bool rp(int x){
	string ans,ans1;
	int cnt=0,cnt1=0;
	for(int i=1;i<=x;i++){
		k[++cnt]=a[i];
	}
	for(int i=2*n;i>x;i--){
		k1[++cnt1]=a[i];
	}
	int l=1,r=cnt,l1=1,r1=cnt1;
	for(int i=1;i<=n;i++){
		if(k[l]==k[r]&&l<=cnt&&r>=1&&l<r){
			l++;
			r--;
			ans+='L';
			ans1+='L';
		}else if(k[l]==k1[r1]&&l<=cnt&&r1>=1){
			l++;
			r1--;
			ans+='L';
			ans1+='R';
		}else if(k1[l1]==k[r]&&l1<=cnt1&&r>=1){
			l1++;
			r--;
			ans+='R';
			ans1+='L';
		}else if(k1[l1]==k1[r1]&&l1<r1&&l1<=cnt1&&r1>=1){
			l1++;
			r1--;
			ans+='R';
			ans1+='R';
		}else{
			return 0;
		}
	}
	for(int i=0;i<ans1.size();i++){
		ans+=ans1[ans1.size()-i-1];
	}
	ans2=min(ans,ans2);
	return 1;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		ans2.clear();
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
			ans2+='Z';
		}
		//1 1
		int op,k=0;
		for(int i=1;i<=2*n;i++){
			if(a[i]==a[1]&&i!=1){
				op=i;
				break;
			}
		}
		k|=rp(op);
		k|=rp(op-1);
		for(int i=1;i<=2*n;i++){
			if(a[i]==a[2*n]&&i!=2*n){
				op=i;
				break;
			}
		}
		k|=rp(op);
		k|=rp(op-1);
		if(k){
			cout<<ans2<<endl;
		}else{
			cout<<"-1"<<endl;
		}
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5

*/

