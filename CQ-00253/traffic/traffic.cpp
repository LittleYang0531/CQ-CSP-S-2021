#include <bits/stdc++.h>
#define ri register int
#define ll long long
using namespace std;
const int Maxn=5e2;
const int Inf=1e9;
int a[Maxn+5][Maxn+5],b[Maxn+5][Maxn+5],col[Maxn+5][Maxn+5];
int x[Maxn+5],c[Maxn+5],val[Maxn+5],n,m,T,k,ans;
void dfs(int dep) {
	if(dep>n*m) {
		int cnt=0;
		for(ri i=1;i<n;i++)
			for(ri j=1;j<=m;j++)
				if(col[i][j]!=col[i+1][j])cnt+=a[i][j];
		for(ri i=1;i<=n;i++)
			for(ri j=1;j<m;j++)
				if(col[i][j]!=col[i][j+1])cnt+=b[i][j];
		for(ri i=1;i<=k;i++) {
			if(x[i]<=m) {
				if(c[i]!=col[1][x[i]])cnt+=val[i];
			}
			else if(x[i]<=m+n) {
				if(c[i]!=col[x[i]-m][m])cnt+=val[i];
			}
			else if(x[i]<=2*m+n) {
				if(c[i]!=col[n][m-(x[i]-n-m)+1])cnt+=val[i];
			}
			else {
				if(c[i]!=col[n-(x[i]-2*m-n)+1][1])cnt+=val[i];
			}
		}
		ans=min(ans,cnt);
	}
	else {
		int x=(dep-1)/m+1,y=dep-(x-1)*m;
		col[x][y]=0;
		dfs(dep+1);
		col[x][y]=1;
		dfs(dep+1);
	}
}
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&T);
	for(ri i=1;i<n;i++)
		for(ri j=1;j<=m;j++)scanf("%d",&a[i][j]);
	for(ri i=1;i<=n;i++)
		for(ri j=1;j<m;j++)scanf("%d",&b[i][j]);
	while(T--) {
		scanf("%d",&k);
		for(ri i=1;i<=k;i++)scanf("%d%d%d",&val[i],&x[i],&c[i]);
		ans=Inf;
		dfs(1);
		printf("%d\n",ans);
	}
	return 0;
}

