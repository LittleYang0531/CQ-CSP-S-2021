#include <bits/stdc++.h>
using namespace std;
const int maxn = 500+5;
const int mo = 1e9+7;
int readint(){
	int x=0,f=1;char s=getchar();
	#define sc (s=getchar())
	while(s<'0'||s>'9'){
		if(s=='-')
			f=-1;
		sc;
	}
	while(s>='0'&&s<='9'){
		x=(x<<3)+(x<<1)+(s^48);
		sc;
	}
	#undef sc
	return x*f;
}
int dp[maxn][maxn][maxn][3];//第i位，有多少个未被匹配左括号，与上个括号有多少个*,当前的字符的方案数 (:0 ):1 *:2
char s[maxn];
int main (){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n=readint(),k=readint();
	scanf("%s",s+1);
	if(s[1]==')'||s[1]=='*'||s[n]=='('||s[n]=='*'){
		puts("0");
		return 0;
	}
	dp[1][1][0][0]=1;
	for(int i=2;i<=n;i++){
		if(s[i]=='('){
			for(int j=1;j<=n;j++){
				for(int k=0;k<=n;k++){
					dp[i][j][0][0]=(0ll+dp[i][j][0][0]+dp[i-1][j-1][k][1]+dp[i-1][j-1][k][0])%mo;
				}
				for(int k=1;k<=n;k++){
					dp[i][j][k][0]=(0ll+dp[i][j][k][0]+dp[i-1][j-1][k][2])%mo;
				}
			}
		}
		if(s[i]==')'){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					dp[i][j][0][1]=(0ll+dp[i][j][0][1]+dp[i-1][j+1][k][0]+dp[i-1][j+1][k][1])%mo;
				}
				for(int k=1;k<=n;k++){
					dp[i][j][k][1]=(0ll+dp[i][j][k][1]+dp[i-1][j+1][k][2])%mo;
				}
			}
		}
		if(s[i]=='*'){
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					dp[i][j][1][2]=(0ll+dp[i][j][1][2]+dp[i-1][j][k][0]+dp[i-1][j][k][1])%mo;
				}
				for(int k=2;k<=n;k++)
					dp[i][j][k][2]=(0ll+dp[i][j][k][2]+dp[i-1][j][k-1][2])%mo;
			}
		}
		if(s[i]=='?'){
			for(int j=1;j<=n;j++){
				for(int k=0;k<=n;k++){
					dp[i][j][0][0]=(0ll+dp[i][j][0][0]+dp[i-1][j-1][k][1]+dp[i-1][j-1][k][0])%mo;
				}
				for(int k=1;k<=n;k++){
					dp[i][j][k][0]=(0ll+dp[i][j][k][0]+dp[i-1][j-1][k][2])%mo;
				}
			}
			
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					dp[i][j][0][1]=(0ll+dp[i][j][0][1]+dp[i-1][j+1][k][0]+dp[i-1][j+1][k][1])%mo;
				}
				for(int k=1;k<=n;k++){
					dp[i][j][k][1]=(0ll+dp[i][j][k][1]+dp[i-1][j+1][k][2])%mo;
				}
			}
			
			for(int j=0;j<=n;j++){
				for(int k=0;k<=n;k++){
					dp[i][j][1][2]=(0ll+dp[i][j][1][2]+dp[i-1][j][k][0]+dp[i-1][j][k][1])%mo;
				}
				for(int k=2;k<=n;k++)
					dp[i][j][k][2]=(0ll+dp[i][j][k][2]+dp[i-1][j][k-1][2])%mo;
			}
		}
	}
	int ans=0;
	for(int i=0;i<=k;i++){
		ans=(0ll+ans+dp[n][0][i][1])%mo;
	}
	printf("%d\n",ans);
	return 0;
}
