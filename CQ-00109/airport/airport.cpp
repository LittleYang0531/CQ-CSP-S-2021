#include<bits/stdc++.h>
using namespace std;
int a1[100005],b1[100005];
int a2[100001],b2[100005];
int c[100001];
int n,m1,m2,did1,bj=0,ans=0,sum=0;
int maxn=0,minn=0x7fffffff;
int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1; i<=m1; i++) {
		cin>>a1[i]>>b1[i];
		maxn=max(maxn,b1[i]);
		minn=min(minn,a1[i]);
	}
	for(int i=1;i<=m1;i++){
		for(int j=1;j<=i;j++){
			if(a1[i]<a1[j]){
				swap(a1[i],a1[j]);
				swap(b1[i],b1[j]);
			}
		}
	}
	for(int i=1; i<=m2; i++) {
		cin>>a2[i]>>b2[i];
		maxn=max(maxn,b2[i]);
		minn=min(minn,a2[i]);
	}
	for(int i=1;i<=m2;i++){
		for(int j=1;j<=i;j++){
			if(a2[i]<a2[j]){
				swap(a2[i],a2[j]);
				swap(b2[i],b2[j]);
			}
		}
	}
	for(int did=0; did<=n; did++) {
		ans=0;
		did1=n-did;
		for(int i=minn; i<=maxn; i++) {
			c[i]=0;
		}
		for(int i=1; i<=m1; i++) {
			bj=0;
			for(int j=a1[i]; j<=b1[i]; j++) {
				if(c[j]>=did) {
					bj=1;
					break;
				}
			}
			if(bj==0) {
				ans++;
				for(int j=a1[i]; j<=b1[i]; j++) {
					c[j]++;
				}
			}
		}
		for(int i=minn; i<=maxn; i++) {
			c[i]=0;
		}
		for(int i=1; i<=m2; i++) {
			bj=0;
			for(int j=a2[i]; j<=b2[i]; j++) {
				if(c[j]>=did1) {
					bj=1;
					break;
				}
			}
			if(bj==0) {
				ans++;
				for(int j=a2[i]; j<=b2[i]; j++) {
					c[j]++;
				}
			}
		}
		sum=max(sum,ans);
	}
	cout<<sum<<endl;
	return 0;
}
