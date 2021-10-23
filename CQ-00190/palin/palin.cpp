#include <bits/stdc++.h>
using namespace std;
int qr(){
	int x=0,f=0;
	char c=getchar();
	while(!isdigit(c)) f|=(c=='-'),c=getchar();
	while(isdigit(c)) x=(x<<3)+(x<<1)+(c^48),c=getchar();
	return f?~(x-1):x;
}
int n,a[200005],b[100005][2],ans[100005];
bool dfs(int l1,int r1,int l2,int r2,int x){//[l2,r2]\in[l1,r1]
	if(x==n+1) return 1;
	if(l2==-1){
		ans[x]=a[l1];
		if(dfs(l1+1,r1,b[a[l1]][1],b[a[l1]][1],x+1)) return 1;
		ans[x]=a[r1];
		if(dfs(l1,r1-1,b[a[r1]][0],b[a[r1]][0],x+1)) return 1;
		return 0;
	}
	if(l1<l2){
		if(b[a[l1]][1]==l2-1){
			ans[x]=a[l1];
			if(dfs(l1+1,r1,l2-1,r2,x+1)) return 1;
		}else if(b[a[l1]][1]==r2+1){
			ans[x]=a[l1];
			if(dfs(l1+1,r1,l2,r2+1,x+1)) return 1;
		}
	}
	if(r1>r2){
		if(b[a[r1]][0]==r2+1){
			ans[x]=a[r1];
			if(dfs(l1,r1-1,l2,r2+1,x+1)) return 1;
		}else if(b[a[r1]][0]==l2-1){
			ans[x]=a[r1];
			if(dfs(l1,r1-1,l2-1,r2,x+1)) return 1;
		}
	}
	return 0;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int zqw=qr();
	while(zqw--){
		memset(b,0,sizeof(b));
		n=qr();
		for(int i=1;i<=n*2;++i){
			a[i]=qr();
			if(!b[a[i]][0]) b[a[i]][0]=i;
			else b[a[i]][1]=i;
		}
		if(!dfs(1,n*2,-1,-1,1)){
			printf("-1\n");
		}else{
			int l=1,r=2*n,tmp=1;
			while(r-l+1>n){
				if(a[l]==ans[tmp]) putchar('L'),tmp++,l++;
				else putchar('R'),tmp++,r--;
			}
			--tmp;
			while(r-l+1){
				if(a[l]==ans[tmp]) putchar('L'),tmp--,l++;
				else putchar('R'),tmp--,r--;
			}
			putchar('\n');
		}
		
	}
	return 0;
}
