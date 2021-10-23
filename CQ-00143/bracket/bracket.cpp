#include<bits/stdc++.h>
#define lc (k<<1)
#define rc ((k<<1)|1)
using namespace std;
template<typename T>inline void read(T &n){
	T w=1;n=0;
	char ch=getchar();
	while(!isdigit(ch)&&ch!=EOF){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)&&ch!=EOF){n=(n<<1)+(n<<3)+(ch&15);ch=getchar();}
	n*=w;
}
typedef long long ll;
const int N=505,mo=1000000007;
int n,K,d[N];ll dp[N][N];
char s[N];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	read(n);read(K);
	scanf("%s",s+1);
	for(int i=1;i<=n;++i)
		d[i]=d[i-1]+(s[i]=='*'||s[i]=='?');
	for(int i=1;i<n;++i)
	if((s[i]=='('||s[i]=='?')&&(s[i+1]==')'||s[i+1]=='?'))
		dp[i][i+1]=1;
	for(int len=3;len<=n;++len)
	for(int i=1,j=i+len-1;j<=n;++i,++j)
	if((s[i]=='('||s[i]=='?')&&(s[j]==')'||s[j]=='?')){
		for(int k=i+1;k<j-1;++k){
			dp[i][j]=(dp[i][j]+dp[i][k]*dp[k+1][j])%mo;
			for(int l=k+2;l<j&&d[l-1]-d[k]==l-k-1&&l-k-1<=K;++l)
				dp[i][j]=(dp[i][j]+dp[i][k]*dp[l][j])%mo;
		}
		dp[i][j]=(dp[i][j]+dp[i+1][j-1]);
		if(d[j-1]-d[i]==j-i-1&&j-i-1<=K)dp[i][j]=(dp[i][j]+1)%mo;
		for(int k=i+1;k<j-1;k++)
		if(d[k]-d[i]==k-i&&k-i<=K)dp[i][j]=(dp[i][j]+dp[k+1][j-1])%mo;
		for(int k=i+2;k<j;k++)
		if(d[j-1]-d[k-1]==j-k&&j-k<=K)dp[i][j]=(dp[i][j]+dp[i+1][k-1])%mo;
	}
	printf("%lld\n",dp[1][n]);
	return 0;
}
