#include<cstdio>
#include<cmath>
#include<cstring>
long long dp[505][505],n,m;
bool a[505][505];
char k[505];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld%lld%s",&n,&m,k+1);
	if (k[1]=='*' || k[1]==')' || k[n]=='*' || k[n]=='('){
		printf("0");
		return 0;
	}
	for (int i=1;i<=n-1;i++){
		if ((k[i]=='(' || k[i]=='?') && (k[i+1]==')' || k[i+1]=='?')) dp[i][i+1]=1;
	}
	for (int i=1;i<=n;i++){
		for (int l=i;l<=n;l++){
			if ((k[l]=='*' || k[l]=='?') && (l-i+1)<=m) a[i][l]=true;
			else break;
		}
	}
	
	for (int i=0;i<=n-1;i++){
		for (int l=1;l<=n-i;l++){
			int r=l+i;
			for (int j=l;j<=r-1;j++){
				dp[l][r]+=dp[l][j]*dp[j+1][r];
				
				for (int s=j+1;s<=r-2;s++){
					if (a[j][s]){
						dp[l][r]+=dp[l][j]*dp[s+1][r];
					}
					else break;
				}
			}
			if ((k[l]=='(' || k[l]=='?') && (k[r]==')' || k[r]=='?') && (l!=r)){
				dp[l][r]+=dp[l+1][r-1]+a[l+1][r-1];
				for (int j=l+1;j<=r-2;j++){
					if (a[l+1][j]){
						dp[l][r]+=dp[j+1][r-1];
					}
					else break;
					if ((j-l-1)>m) break;
				}
				for (int j=r-1;j>=l+2;j--){
					if (a[j][r-1]){
						dp[l][r]+=dp[l+1][j-1];
					}
					else break;
					if ((r-j)>m) break;
				}
				
			}
			dp[l][r]%=(1000000007);
		}
	}
	printf("%d",dp[1][n]);
}
