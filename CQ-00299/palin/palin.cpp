#include<cstdio>
#include<cmath>
#include<cstring>
int a[500005],n,b[500005];
char ans[500005]="ZZZ";
void maxx(char a[],char b[]){
	for (int i=1;i<=2*n;i++){
		if (b[i]<a[i]){
			for (;i<=2*n;i++){
				ans[i]=b[i];
			}
			return;
		}
		if (a[i]<b[i]){
			return;
		}
	}
	return;
}
void dfs(int l,int r,int b[],int tot,char k[]){
	if (tot>n+1 && b[tot-1]!=b[n*2+2-tot]) return;
	if (tot>2*n){
		maxx(ans,k);
		return;
	}
	b[tot]=a[l],k[tot]='L';
	dfs(l+1,r,b,tot+1,k);
	b[tot]=a[r],k[tot]='R';
	dfs(l,r-1,b,tot+1,k);
	return;
}
int main(){
	freopen("pailn.in","r",stdin);
	freopen("pailn.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--){
		ans[1]='Z';
		scanf("%d",&n);
		for (int i=1;i<=n*2;i++){
			scanf("%d",&a[i]);
		}
		char k[500005];
		dfs(1,n*2,b,1,k);
		if (ans[1]=='Z') printf("-1\n");
		else printf("%s\n",ans+1);
	}
	return 0;
}
