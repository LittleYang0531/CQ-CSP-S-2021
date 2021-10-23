#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],b[1000010],ok;
bool d[1000010],vis[1000010];
bool check(int l,int r){
	int now=n;
	for(int i=n;i>=1;i--){
		if(b[i]==a[l]){
			l++;
			d[++now]=0;
		}
		else if(b[i]==a[r]){
			r--;
			d[++now]=1;
		}
		else{
//			printf("lost:%d %d %d\n",b[i],a[l],a[r]);
			return 0;
		}
	}
	for(int i=1;i<=2*n;i++){
		if(d[i])putchar('R');
		else putchar('L');
	}
	putchar('\n');
	return 1;
}
void dfs(int l,int r,int len){
	if(ok)return ;
	if(len==n){
//		for(int i=1;i<=len;i++)printf("%d ",b[i]);
//		printf("\n");
		if(check(l,r))ok=1;
		return ;
	}
	if(!vis[a[l]]){
		vis[a[l]]=1,b[len+1]=a[l],d[len+1]=0;
		dfs(l+1,r,len+1);
		vis[a[l]]=0;	
	}
	if(!vis[a[r]]){
		vis[a[r]]=1,b[len+1]=a[r],d[len+1]=1;
		dfs(l,r-1,len+1);
		vis[a[r]]=0;
	}
	
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		ok=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]),vis[a[i]]=0;
		dfs(1,2*n,0);
		if(!ok){
			puts("-1");
			continue;
		}
	}
	return 0;
}

