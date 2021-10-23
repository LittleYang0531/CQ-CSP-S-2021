#include <cstdio>
#define print(x,y) write(x),putchar(y)

template <class T>
inline T read(const T sample) {
	T x=0; char s; bool f=0;
	while((s=getchar())>'9' or s<'0')
		f |= (s=='-');
	while(s>='0' and s<='9')
		x = (x<<1)+(x<<3)+(s^48),
		s = getchar();
	return f?-x:x;
}

template <class T>
inline void write(const T x) {
	if(x<0) {
		putchar('-');
		write(-x);
		return;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}

const int maxn = 505;
const int mod = 1e9+7;

char s[maxn];
int n,k,dp[maxn][maxn],pre[maxn];
int f[maxn][maxn];

inline int inc(int x,int y) {
	return x+y>=mod?x+y-mod:x+y;
}

bool isLeft(char c) {
	return c=='(' or c=='?';
}

bool isRight(char c) {
	return c==')' or c=='?';
}

int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(9),k=read(9);
	scanf("%s",s+1);
	for(int i=1;i<n;++i)
		if(isLeft(s[i]) and isRight(s[i+1]))
			dp[i][i+1]=1,f[i][i+1]=1;
	for(int i=1;i<=n;++i)
		pre[i] = pre[i-1]+(s[i]=='*' or s[i]=='?');
	for(int len=3;len<=n;++len) {
		for(int i=1;i+len-1<=n;++i) {
			int j=i+len-1;
			if(isLeft(s[i]) and isRight(s[j])) {
				if(j-1-i<=k and pre[j-1]-pre[i]==j-i-1) 
					dp[i][j] = inc(dp[i][j],1),
					f[i][j] = inc(f[i][j],1);
				for(int p=i+1;p<j-1 and p-i<=k;++p) {
					if(pre[p]-pre[i]==p-i)
						dp[i][j] = inc(dp[i][j],dp[p+1][j-1]),
						f[i][j] = inc(f[i][j],dp[p+1][j-1]);
				}
				for(int p=1;p<=k and j-p>i+1;++p) {
					if(pre[j-1]-pre[j-p-1]==j-p)
						dp[i][j] = inc(dp[i][j],dp[i+1][j-p-1]),
						f[i][j] = inc(f[i][j],dp[i+1][j-p-1]);
				}
				dp[i][j] = inc(dp[i][j],dp[i+1][j-1]);
				f[i][j] = inc(f[i][j],dp[i+1][j-1]);
			}
//			printf("FFF %d\n",dp[i][j]);
			for(int p=i+1;p<j;++p)
				for(int q=p;q<j and q-p+1<=k;++q) {
					if(pre[q]-pre[p-1]==q-p+1)
						dp[i][j] = inc(dp[i][j],1ll*dp[i][p-1]*dp[q+1][j]%mod),
						f[i][j] = inc(f[i][j],1ll*f[i][p-1]*f[q+1][j]%mod);
				}
			for(int p=i;p<j;++p)
				dp[i][j] = inc(dp[i][j],1ll*f[i][p]*dp[p+1][j]%mod);
		}
	}
	print(dp[1][n],'\n');
	return 0;
}

