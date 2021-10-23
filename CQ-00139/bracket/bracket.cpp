#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int mod=1e9+7;
const int N=505;
inline int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int n,m;
ll dp[N][N][2][2],sum[N][N];
void Mod(ll &x,ll y) {
	x=(x+y)%mod;
}
char s[N];
bool chk1(int l) {
	return s[l]=='?'||s[l]=='*';
}
bool chk2(int l) {
	return s[l]=='('||s[l]=='?';
}
bool chk3(int l) {
	return s[l]==')'||s[l]=='?';
} 
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=1;i<=n+1;i++) {
		sum[i][i-1]=1;
	}
	for(int i=1;i<=n;i++) {
		for(int j=i;j<=min(i+m-1,n);j++) {
			if(!chk1(j)) break;
			Mod(dp[i][j][0][0],1);
			Mod(sum[i][j],1);
		}
	}
	for(int i=1;i<n;i++) {
		dp[i][i+1][1][1]=chk2(i)&&chk3(i+1);
		Mod(sum[i][i+1],dp[i][i+1][1][1]);
	}
	for(int len=3;len<=n;len++) {
		for(int i=1;i<=n-len+1;i++) {
			int j=i+len-1;
			if(chk2(i)&&chk3(j)) {
				for(int k=i+1;k<=j;k++) {
					if(chk3(k)) {
						if(k!=j) {
							for(int l=0;l<2;l++) {
								Mod(dp[i][j][1][1],sum[i+1][k-1]*dp[k+1][j][l][1]);
							}
						}
						else {
							Mod(dp[i][j][1][1],sum[i+1][k-1]);
						}
					}
				}
			}
			if(chk2(i)) {
				for(int k=j;k>=max(i+2,j-m+1);k--) {
					if(!chk1(k)) break;
					Mod(dp[i][j][1][0],dp[i][k-1][1][1]);
				}
			}
			if(chk3(j)) {
				for(int k=i;k<=min(j-2,i+m-1);k++) {
					if(!chk1(k)) break;
					Mod(dp[i][j][0][1],dp[k+1][j][1][1]);
				}
			}
			for(int k=0;k<2;k++) {
				for(int l=0;l<2;l++) {
					Mod(sum[i][j],dp[i][j][k][l]);
				}
			}
		}
	}
	ll ans=(dp[1][n][0][0]+dp[1][n][1][1])%mod;
	printf("%lld",ans);
}
