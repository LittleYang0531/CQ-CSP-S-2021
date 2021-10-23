#include<cstdio>//JZM yyds!!
#include<cstring>
#include<iostream>
#include<algorithm>
#include<cmath>
#include<vector>
#include<ctime>
#include<queue>
#include<stack>
#include<map>
#include<set>
#include<random>
#define ll long long
#define uns unsigned
#define MOD 1000000007ll
#define MAXN 505
#define INF 1e17
#define IF (it->first)
#define IS (it->second)
using namespace std;
inline ll read(){
	ll x=0;bool f=1;char s=getchar();
	while((s<'0'||s>'9')&&s>0){if(s=='-')f^=1;s=getchar();}
	while(s>='0'&&s<='9')x=(x<<1)+(x<<3)+(s^48),s=getchar();
	return f?x:-x;
}
inline ll lowbit(ll x){return x&-x;}
int n,m;
bool f[MAXN][MAXN];
ll dp[MAXN][MAXN][3];
char s[MAXN];
inline ll AD(ll a,ll b){
	a+=b;return a>=MOD?a-MOD:a;
}
inline void add(ll&a,ll b){
	a+=b;if(a>=MOD)a-=MOD;
}
inline bool c1(char c){
	return c=='('||c=='?';
}
inline bool c2(char c){
	return c==')'||c=='?';
}
inline bool c3(char c){
	return c=='*'||c=='?';
}
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),m=read();
	scanf("%s",s+1);
	for(int i=n;i>0;i--){
		f[i][i]=c3(s[i]);
		for(int j=i+1;j<=n&&j<i+m;j++)
			f[i][j]=f[i][j-1]&c3(s[j]);
	}
	for(int i=1;i<=n+1;i++)dp[i][i-1][0]=1;
	for(int i=n-1;i>0;i--)
		for(int j=i+1;j<=n;j++){
			if(c1(s[i])&&c2(s[j]))
				add(dp[i][j][0],dp[i+1][j-1][0]),
				add(dp[i][j][0],dp[i+1][j-1][1]),
				add(dp[i][j][0],dp[i+1][j-1][2]),
				add(dp[i][j][0],f[i+1][j-1]);
			for(int k=i+1;k<j-1;k++)if(c1(s[i])&&c2(s[k]))
				add(dp[i][j][0],AD(dp[i+1][k-1][0],AD(dp[i+1][k-1][1],AD(dp[i+1][k-1][2],f[i+1][k-1])))*
				AD(dp[k+1][j][0],dp[k+1][j][1])%MOD);
			for(int k=i;k<j-1&&k<i+m;k++)
				add(dp[i][j][1],f[i][k]*dp[k+1][j][0]);
			for(int k=j;k>i+1&&k>j-m;k--)
				add(dp[i][j][2],f[k][j]*dp[i][k-1][0]);
		}
	printf("%lld\n",dp[1][n][0]);
	return 0;
}
