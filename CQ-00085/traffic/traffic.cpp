#include<bits/stdc++.h>
using namespace std;
int n,t,a[605][605],b[605][605],flag,m,dp[605][605][2];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","r",stdout);
	cin>>n>>m>>t;
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			int x;scanf("%d",&x);
			a[i][j]=x;
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			int x;scanf("%d",&x);
			b[i][j]=x;
		}
	}
	while(t--){
		memset(dp,0,sizeof(dp));
		int k;
		scanf("%d",&k);
		for(int i=1;i<=k;i++){
			int bh,qz,bj,ii,jj;
			scanf("%d%d%d",&qz,&bh,&bj);
			if(bh<=m){ii=0;jj=bh;dp[ii+1][jj][bj]=qz;
			}else if(bh<=m+n){ii=bh-m;jj=m;dp[ii][jj][bj]=qz;
			}else if(bh<=2*m+n){ii=n;jj=2*m+n-bh+1;dp[ii][jj][bj]=qz;
			}else{ii=2*m+2*n-bh+1;dp[ii][1][bj]=qz;}
		}
		for(int i=2;i<=n;i++){
			dp[i][1][0]+=min(dp[i-1][1][0],dp[i-1][1][1]+a[i-1][1]);
			dp[i][1][1]+=min(dp[i-1][1][0]+a[i-1][1],dp[i-1][1][1]);
		}
		for(int i=2;i<=m;i++){
			dp[1][i][0]+=min(dp[1][i-1][0],dp[1][i-1][1]+b[1][i-1]);
			dp[1][i][1]+=min(dp[1][i-1][0]+b[1][i-1],dp[1][i-1][1]);
		}
		for(int i=2;i<=n;i++){
			for(int j=2;j<=m;j++){
				dp[i][j][0]+=min(dp[i-1][j][0],dp[i-1][j][1]+a[i-1][j])+min(dp[i][j-1][0],dp[i][j-1][1]+b[i][j-1]);
				dp[i][j][1]+=min(dp[i-1][j][0]+a[i-1][j],dp[i-1][j][1])+min(dp[i][j-1][0]+b[i][j-1],dp[i][j-1][1]);
			}
		}
		/*for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<dp[i][j][1]<<" "; 
			}
			puts("");
		}
		puts("");
		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				cout<<dp[i][j][0]<<" "; 
			}
			puts("");
		}*/
		printf("%d\n",max(dp[n][m][1],dp[n][m][0]));
	}
	return 0;
}
