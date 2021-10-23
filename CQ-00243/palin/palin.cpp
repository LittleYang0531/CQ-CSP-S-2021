#include<bits/stdc++.h>
using namespace std;
long long a[1000001];
long long p,h;
struct thy{
	int l,r;
}js[1000001];
void dfs(int x,int y,int kk,int n){
	if(kk==0){
		p=kk;
		return;
	}
	else{
		if(js[a[x]].l==0){
			js[a[x]].l=x;
			js[a[x]].r=2*n+1-x;
		}
		else{
			if(js[a[x]].r==0){
				js[a[x]].r=x;
				js[a[x]].l=2*n+1-x;
			}
		}
		if(js[a[y]].l==0){
			js[a[y]].l=y;
			js[a[y]].r=2*n+1-y;
		}
		else{
			if(js[a[y]].r==0){
				js[a[y]].r=y;
				js[a[y]].l=2*n+1-y;
			}
		}
		if(js[a[x]].l!=0&&js[a[x]].r!=0&&2*n+js[a[x]].l!=js[a[x]].r){
			p=-1;
			return;
		}
		if(js[a[y]].l!=0&&js[a[y]].r!=0&&2*n+js[a[y]].l!=js[a[y]].r){
			p=-1;
			return;
		}
		dfs(x+1,y,kk-1,n);
		dfs(x,y-1,kk-1,n);
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	long long t,n,ans=-2;
	scanf("%lld",&t);
	for(int i=1;i<=t;i++){
		scanf("%lld",&n);
		ans=-2;
		for(int j=1;j<=2*n;j++) scanf("%lld",&a[j]);
		js[a[1]].l=1;
		js[a[1]].r=2*n;
		dfs(2,10,2*n,n);
		if(p>ans) ans=p;
		memset(js,0,sizeof(js));
		js[a[n*2]].l=2*n;
		js[a[n*2]].r=1;
		dfs(2,10,2*n,n);
		if(p>ans) ans=p;
		printf("%lld\n",ans);
	}
}
