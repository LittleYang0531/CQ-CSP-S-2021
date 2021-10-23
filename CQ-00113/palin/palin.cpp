#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
int n,t,a[1000005],b[1000005];
char end[1000005];
bool finish=0;
inline bool test(){
	for(int i=1;i<=n;i++){
		if(b[i]!=b[2*n-i+1]) return 0;
	}
	return 1;
}
inline void dfs(int l,int r,int num){
	if(num>2*n){
		printf("-------------\n");
		if(test()) finish=1;
		return ;
	}
	b[num]=a[l];
	dfs(l+1,r,num+1);
	if(finish){
		end[2*n-num+1]='L';
		return ;
	}
	b[num]=a[r];
	dfs(l,r-1,num+1);
	if(finish){
		end[2*n-num+1]='R';
		return ;
	}
	return ;
}
int main(){
//	freopen("palin.in","r",stdin);
//	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		finish=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		dfs(1,2*n,1);
		if(!finish) printf("-1\n");
		else for(int i=2*n;i>=1;i--) printf("%c",end[i]);
	}
	
	return 0;
}
//1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 1 
