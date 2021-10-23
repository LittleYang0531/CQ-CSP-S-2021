#include<bits/stdc++.h>
using namespace std;
const int inf=1e9+7;
const int MAX=2000+5;
int t,n;
int ans;
int a[MAX],b[MAX][2];
int vis[MAX];
bool fa=0;
void dfs(int l,int r,int w){
	if(2*n-r+l-1>n){
		for(int i=n,j=n+1;i>=l&&j<=r;i--,j++)
			if(b[j][0]==0) break;
			else if(b[i][0]!=b[j][0]) return;
	}
	if(l>r){
		for(int i=1;i<=n;i++){
			if(b[i][0]!=b[2*n+1-i][0]) return;
		}
		for(int i=1;i<=2*n;i++){
			if(b[i][1]==1) printf("L");
			else printf("R");
		}
		printf("\n");
		fa=1;
		return;
	}
	else{
		if(fa==1) return;
		b[2*n-r+l][0]=a[l];b[2*n-r+l][1]=1;
		dfs(l+1,r,1);
		if(fa==1) return;
		b[2*n-r+l][0]=a[r];b[2*n-r+l][1]=2;
		dfs(l,r-1,2);
		if(fa==1) return;
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		memset(vis,0,sizeof(vis));fa=0;
		scanf("%d",&n);
		int maxn=-1;
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
			vis[a[i]]^=1;
			maxn=max(maxn,a[i]);
		}
		for(int i=1;i<=maxn;i++){if(vis[i]==1){printf("-1\n");continue;}}
		dfs(1,2*n,1);
		dfs(1,2*n,2);
		if(fa==0) printf("-1\n");
	}
	return 0;
}
