#include<bits/stdc++.h>
using namespace std;
#define ll long long
const ll Mod=1e9+7;

ll dp[505][5];
int n,k;
char s[505];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s+1;
	for(int i=1;i<=n;i++) dp[i][i]=1;
	for(int i=1;i<=n;i++){
		if(s[i]=='*'||s[i]==')') continue;
		if(s[i+1]=='*'||s[i+1]=='(') continue;
		dp[i][i+1]=1;
	}
	for(int len=3;len<=n;len++){
		for(int l=1;l<=n-len+1;l++){
			int r=l+len-1;
			if(s[l]=='*'||s[l]==')') continue;
			if(s[r]=='*'||s[r]=='(') continue;
			bool f=0;
			for(int k1=l+1;k1<=r-1;k1++){
				if(s[k1]==')'){
					f=1;int k2;
					for(k2=k1+1;k2<=r-1&&k2-k1+1<=k;k2++){
						if(s[k2]=='('){
							dp[l][r]+=dp[l][k1]*dp[k2][r];dp[l][r]%=Mod;break;
						}
						if(s[k2]=='?'){
							dp[l][r]+=dp[l][k1]*dp[k2][r];dp[l][r]%=Mod;
						}
					}
				}
				if(s[k1]=='('){
					f=1;int k2;
					for(k2=k1+1;k2<=r-1&&k2-k1+1<=k;k2++){
						if(s[k2]==')'){
							dp[l][r]+=dp[k1][k2];dp[l][r]%=Mod;break;
						}
						if(s[k2]=='?'){
							dp[l][r]+=dp[k1][k2];dp[l][r]%=Mod;
						}
					}
				}
				if(s[k1]=='?'){
					int k2;
					for(k2=k1+1;k2<=r-1&&k2-k1+1<=k;k2++){
						if(s[k2]==')'){f=1;
							dp[l][r]+=dp[k1][k2];dp[l][r]%=Mod;break;
						}
						if(s[k2]=='('){f=1;
							dp[l][r]+=dp[l][k1]*dp[k2][r];dp[l][r]%=Mod;break;
						}
						if(s[k2]=='?'){
							dp[l][r]+=dp[l][k1]*dp[k2][r]+dp[k1][k2];dp[l][r]%=Mod;
						}
					}
				}
			}
			if(r-l<=k&&!f) dp[l][r]++;
		}
	}
//	for(int i=1;i<=n;i++)
//		for(int j=i+1;j<=n;j++) printf("%d %d:%lld\n",i,j,dp[i][j]);
	printf("%lld\n",dp[1][n]);
	return 0;
}
