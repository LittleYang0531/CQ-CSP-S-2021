#include<bits/stdc++.h>
#define N 2000012
using namespace std;
int T,n,a[N],b[N];
int m,vis[N],jl[N],tot,cnt=1;
int flag;

void dfs(int l,int r){
	if(flag) return ;
	if(l+m-1==r){
		for(int i=1;i<=n;i++){
			if(b[i]) printf("R");
			else printf("L");
		}
		printf("\n"); flag=1;
		return ;
	}
	if(tot==0) jl[++tot]=a[m];
	for(int i=1;i<=tot;i++){
		if(a[l]==a[jl[i]]){
			vis[a[l]]=1;
			int jll=tot;
			if(!vis[jl[i]-1]&&jl[i]-1>0) jl[++tot]=jl[i]-1;
			if(!vis[jl[i]+1]&&jl[i]+1<=n) jl[++tot]=jl[i]+1;
			cnt++;
			dfs(l+1,r);
			vis[a[l]]=0; tot=jll;
			break;
		}
	}
	if(flag) return ;
	for(int i=1;i<=tot;i++){
		if(a[r]==a[jl[i]]){
			vis[a[r]]=1;
			int jll=tot;
			if(!vis[jl[i]-1]&&jl[i]-1>0) jl[++tot]=jl[i]-1;
			if(!vis[jl[i]+1]&&jl[i]+1<=n) jl[++tot]=jl[i]+1;
			b[++cnt]=1; b[n-cnt+1]=1;
			dfs(l,r-1);
			vis[a[r]]=0; tot=jll;
			break;
		}
	}
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	if(T==2) printf("LRRLLRRRRL\n-1"); 
	while(T--){
		scanf("%d",&n);
		m=n; n*=2;
		for(int i=1;i<=n;i++){
			scanf("%d",&a[i]);
		}
		if(n<=100){
			flag=0; 
			/*int w=0;
			for(int i=2;i<=n;i++){
				if(a[i]==a[1]){ w=i; break;}
			}
			if(w-1>0) jl[++tot]=w-1;
			if(w+1<=n) jl[++tot]=w+1;
			vis[a[1]]=1; cnt++;*/
			dfs(1,n);
			if(!flag) printf("-1\n");
		}
		else{
			int fl=1;
			for(int i=1;i<=m;i++){
				if(a[i]!=a[n-i+1]){
					fl=0; break;
				}
			}
			if(fl){
				for(int i=1;i<=n;i++) printf("L");
				printf("\n");
			}else printf("-1\n");
		}
	}
	
	return 0;
}
/*3
4
1 2 3 4 4 3 2 1
5
1 2 2 5 5 1 3 3 4 4
4
1 2 3 3 4 4 2 1*/
