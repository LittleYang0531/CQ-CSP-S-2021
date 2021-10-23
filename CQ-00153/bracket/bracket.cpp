#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N = 1e5+10;
const ll mo = 1e9+7;
int n,m;
ll dp[505][505];
char A[505],a[5];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&m,A+1);
	for(int l=2;l<=n;l++)
	for(int i=1;i<=n-l+1;i++){
		int j=i+l-1;
		for(int k=i+1;k<j-1;k++){
			dp[i][j]=(dp[i][j]+dp[i][k]*dp[k+1][j]%mo)%mo;
			for(int p=k+1;p<j-1&&p-k<=m;p++){
				if(A[p]!='?'&&A[p]!='*')break;
				dp[i][j]=(dp[i][j]+dp[i][k]*dp[p+1][j]%mo)%mo;
			}
		}
		if((A[i]=='('||A[i]=='?')&&(A[j]==')'||A[j]=='?')){
			if(l==2)dp[i][j]=1;
			else{
				dp[i][j]=(dp[i][j]+dp[i+1][j-1])%mo;
				for(int p=i+1;p<j&&p-i<=m;p++){
					if(A[p]!='*'&&A[p]!='?')break;
					if(p==j-1)dp[i][j]++;
					else dp[i][j]=(dp[i][j]+dp[p+1][j-1])%mo;
				}
				for(int p=j-1;p>i-2&&j-p<=m;p--){
					if(A[p]!='*'&&A[p]!='?')break;
					dp[i][j]=(dp[i][j]+dp[i+1][p-1])%mo;
				}
			}
		}
//		printf("%lld %d %d\n",dp[i][j],i,j);
	}
	printf("%lld\n",dp[1][n]);
	return 0;
}
/*
6 2
(*()?)
*/

