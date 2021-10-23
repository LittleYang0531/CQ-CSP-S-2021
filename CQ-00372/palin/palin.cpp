#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int ans[N],vis[N],n,a[N];
char s[N];
bool dfs(int x,int l,int r){
	if(x==2*n+1){
		printf("%s\n",s+1);
		return true;
	}
	if(x<=n){
		if(!vis[a[l]]){
			vis[a[l]]=1;
			s[x]='L';
			ans[x]=a[l];
			if(dfs(x+1,l+1,r)) return true;
			vis[a[l]]=0;
		}
		if(!vis[a[r]]){
			vis[a[r]]=1;
			s[x]='R';
			ans[x]=a[r];
			if(dfs(x+1,l,r-1)) return true;
			vis[a[r]]=0;
		}
	}
	else{
		if(a[l]==ans[n*2+1-x]){
			s[x]='L';
			if(dfs(x+1,l+1,r)) return true;
		}
		if(a[r]==ans[n*2+1-x]){
			s[x]='R';
			if(dfs(x+1,l,r-1)) return true;
		}
	}
	return false;
}
int T;
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		memset(vis,0,sizeof(vis));
		scanf("%d",&n);
		for(int i=1;i<=n*2;i++){
			scanf("%d",&a[i]);
		}
		if(!dfs(1,1,n*2)) printf("-1\n");
	}
	return 0;
}
/*
2 
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

*/

