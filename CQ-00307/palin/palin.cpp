#include<bits/stdc++.h>
using namespace std;
const int M=2e5+5;
int T,n,m,flag,op[M],b[M],a[M],vis[M];
char ans[M];
bool check(int x,int y){
	if(abs(x-y)<=1) return 1;
	return 0;
}
void dfs(int x,int l,int r,int lst){
	if(flag) return;
	//printf("%")
	if(l>r){
		flag=1;
		for(int i=1;i<x;i++){
			printf("%c",ans[i]);
		}
		return;
	}
	for(int i=0;i<=1;i++){
		if(x==1){
			if(i==0){
				vis[l]=x;
				ans[x]='L';
				dfs(x+1,l+1,r,l);
				vis[l]=0;
			}
			else{
				vis[r]=x;
				ans[x]='R';
				dfs(x+1,l,r-1,r);
				vis[r]=0;
			}
		}
		else{
			if(i==0){
				if(op[lst]==l&&r-l>1) continue;
				if((check(op[l],op[lst])==1&&x<=n)||(x>n&&x-n==n-vis[op[l]]+1)){
					ans[x]='L';
					vis[l]=x;
					dfs(x+1,l+1,r,l);
					vis[l]=0;
				}
			}
			else{
				if(op[lst]==l&&r-l>1) continue;
				if((check(op[r],op[lst])==1&&x<=n)||(x>n&&x-n==n-vis[op[r]]+1)){
					ans[x]='R';
					vis[r]=x;
					dfs(x+1,l,r-1,r);
					vis[r]=0;
				}
			}
		}
	}
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	for(int i=1;i<=T;i++){
		flag=0;
		
		scanf("%d",&n);
		m=n*2;
		for(int i=1;i<=m;i++){
			b[i]=0;
			op[i]=0;
		}
		for(int i=1;i<=m;i++){
			scanf("%d",&a[i]);
			if(b[a[i]]){
				op[i]=b[a[i]];
				op[b[a[i]]]=i;
			}
			else
			b[a[i]]=i;
			
		}
		dfs(1,1,m,0);
		if(!flag){
			printf("-1");
		}
		printf("\n");
	}
}
