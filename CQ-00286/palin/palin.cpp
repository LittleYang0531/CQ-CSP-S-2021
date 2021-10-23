#include<bits/stdc++.h>
using namespace std;
long long t,n,a[105],b[105],ans[105],tot1=0,tot2=n*2+1;
bool q;
void dfs(long long k){
	if(k==n*2+1){
		bool flag=1;
		for(long long i=1;i<=n;i++) if(b[i]!=b[2*n+1-i]) flag=0;
		if(flag){
			q=1;
			for(long long i=1;i<=n*2;i++){
				if(ans[i]==1) printf("L");
				else printf("R");
			}
		}
		return;
	}
	ans[k]=1;b[k]=a[++tot1];
	dfs(k+1);
	if(q) return;
	tot1--;
	ans[k]=2;b[k]=a[--tot2];
	dfs(k+1);
	if(q) return;
	tot2++;
	return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%lld",&t);
	for(long long i=1;i<=t;i++){
		scanf("%lld",&n);
		tot1=0;tot2=n*2+1;q=0;
		memset(ans,0,sizeof(ans));
		for(long long j=1;j<=n*2;j++) scanf("%lld",&a[j]);
		dfs(1);
		if(!q) printf("-1");
		printf("\n");
	}
	return 0;
}
