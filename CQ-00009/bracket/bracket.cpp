#include<bits/stdc++.h>
#define N 505
using namespace std;
int n,k;
char a[N];
bool vis[2*N][2*N];
long long dp1[2*N][2*N],dp2[2*N][2*N],dp3[2*N][2*N],mod=1e9+7;
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	cin>>a+1;
	for (int i=1;i<=n;i++) {
		for (int j=i;j<=n;j++) {
			bool flag=1;
			for (int l=i;l<=j;l++) {
				if (a[l]=='('||a[l]==')') {
					flag=0;
					break;
				}
			}
			vis[i][j]=flag;
		}
	}
	for (int i=1;i<n;i++) {
		if (a[i]=='('&&a[i+1]!='('&&a[i+1]!='*'||a[i+1]==')'&&a[i]!=')'&&a[i]!='*'||a[i]==a[i+1]&&a[i+1]=='?') dp1[i][i+1]=1;
	}
	for (int len=3;len<=n;len++) {
		for (int l=1;l+len-1<=n;l++) {
			int r=l+len-1;
			if (a[l]=='*'||a[r]=='*') {
				continue;
			}
			if (a[l]==')'||a[r]=='(') {
				continue;
			}
			if (r-l-1<=k) {
				dp1[l][r]=vis[l+1][r-1];
			}
			dp1[l][r]+=dp1[l+1][r-1]+dp2[l+1][r-1]+dp3[l+1][r-1];
			for (int d=l+1;d<=r-2;d++) {
				dp2[l][r]+=(dp1[l][d]+dp3[l][d])%mod*((dp1[d+1][r]+dp2[d+1][r]+dp3[d+1][r]))%mod;
				dp2[l][r]%=mod;
			}
			for (int L=1;L<=k;L++) {
				if (vis[l+1][l+L]) dp1[l][r]+=dp1[l+L+1][r-1]+dp2[l+L+1][r-1]+dp3[l+L+1][r-1];
				if (vis[r-L][r-1]) dp1[l][r]+=dp1[l+1][r-L-1]+dp2[l+1][r-L-1]+dp3[l+1][r-L-1];
				dp1[l][r]%=mod;
				for (int s=l+2;s+L<=r-1;s++) {
					if (vis[s][s+L-1]) {
						dp3[l][r]+=dp1[l][s-1]*((dp1[s+L][r]+dp3[s+L][r])%mod);
						dp3[l][r]%=mod;
					}
				}
			}
		}
	}
//	for (int i=1;i<=n;i++) {
//		for (int j=i;j<=n;j++) {
//			printf("%d %d %lld %lld %lld\n",i,j,dp1[i][j],dp2[i][j],dp3[i][j]);
//		}
//	}
	printf("%lld",(dp1[1][n]+dp2[1][n]+dp3[1][n])%mod);
	return 0;
}
