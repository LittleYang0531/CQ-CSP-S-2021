#include<bits/stdc++.h>
#define N 500005
using namespace std;
int T,n,a[2*N],b[2*N];
char ans[2*N];
bool flag;
bool check() {
	for (int i=1;i<=(n+1)/2;i++) {
		if (b[i]!=b[n-i+1]) return 0;
	}
	return 1;
}
void dfs(int k,int l,int r) {
	if (k==n+1) {
		if (check()) {
			for (int i=1;i<=n;i++) {
				printf("%c",ans[i]);
			}
			printf("\n");
			flag=true;
		}
		return;
	}
	b[k]=a[l];
	ans[k]='L';
	dfs(k+1,l+1,r);
	if (flag) return;
	b[k]=a[r];
	ans[k]='R';
	dfs(k+1,l,r-1);
	return;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while (T--) {
		flag=0;
		scanf("%d",&n);
		n*=2;
		for (int i=1;i<=n;i++) scanf("%d",&a[i]);
		dfs(1,1,n);
		if (!flag) {
			printf("-1\n");
		}
	}
	return 0;
}
