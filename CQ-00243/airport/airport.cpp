#include<bits/stdc++.h>
using namespace std;
long long pp[100001],jj[100001];
long long n,m1,m2,ans=0,js=0;
struct thy{
	int l,r;
}a[100001],b[100001];
int cmp(thy a,thy b){
	return a.l<b.l;
}
void dfs(int x,int m1){
	for(int i=x;i<=m1;i++){
		if(a[x].r<a[i].l){
			ans++;
			dfs(i,m1);
			break;
		}
	}
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%lld%lld",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;i++) scanf("%lld%lld",&b[i].l,&b[i].r);
	sort(1+a,1+a+m1,cmp);sort(1+b,1+b+m2,cmp);
	if(n<=100){
		for(int i=0;i<=n;i++){
			long long x=i,y=n-i;
			ans=0;
			for(int j=1;j<=m1;j++){
				for(int k=1;k<=x;k++){
					if(a[j].l>=pp[k]){
						pp[k]=a[j].r;
						ans++;
						break;
					} 
				}
			}
			for(int j=1;j<=m2;j++){
				for(int k=1;k<=y;k++){
					if(b[j].l>=jj[k]){
						jj[k]=b[j].r;
						ans++;
						break;
					}
				}
			}	
			memset(pp,0,sizeof(pp));
			memset(jj,0,sizeof(jj));
			if(ans>js) js=ans;
		}
		printf("%lld",js);
	}
	else{
		for(int i=1;i<=n;i++){
			ans=0;
			for(int j=1;j<=i;j++) dfs(j,m1);
			for(int j=1;j<=n-i;j++) dfs(j,m2);
			if(ans>js) js=ans;
		}
		printf("%lld",js+n);
	}
}
