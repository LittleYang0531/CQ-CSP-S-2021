#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define mod 1000000007
#define ll long long
#define N 505
using namespace std;
template<class T>void read(T&x) {
	T f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
char _st;
int n,m,R[N];
ll f[N][N],g[N][N],sum[N];
char s[N];
bool check(int x,char c){return s[x]==c||s[x]=='?';}
bool pd(int l,int r) {
	if(r-l+1 > m)return 0;
	for(int i=l; i<=r; ++i)if(!check(i,'*'))return 0;
	return 1;
}
char _ed;
int main() {
	cerr << "Memory: " << ((&_st-&_ed)>>20) << '\n';
	file("bracket");
	read(n);read(m);R[n+1] = n;
	scanf("%s",s+1);
	for(int i=n; i>=1; --i)if(check(i,'*'))R[i] = R[i+1];else R[i] = i-1;
	for(int i=1; i<=n; ++i)R[i] = min(R[i],i+m-1);
	for(int i=1; i<n; ++i)f[i][i+1] = g[i][i+1] = check(i,'(')&&check(i+1,')');
	for(int l=3; l<=n; ++l)
		for(int i=1; i+l-1<=n; ++i) {
			int j = i+l-1;if(!check(i,'(') || !check(j,')'))continue;
			if(R[i+1] >= j-1)f[i][j]++,g[i][j]++;//(S)
			for(int k=i+1; k<=j-3; ++k)//(SA)
				if(R[i+1] >= k)f[i][j] += f[k+1][j-1],g[i][j] += f[k+1][j-1];
			for(int k=j-1; k>=i+3; --k)//(AS)
				if(R[k] >= j-1)f[i][j] += f[i+1][k-1],g[i][j] += f[i+1][k-1];
			f[i][j] += f[i+1][j-1],g[i][j] += f[i+1][j-1];//(A)
			sum[i-1] = 0;
			for(int k=i; k<=j; ++k)sum[k] = (sum[k-1]+f[k][j])%mod;
			for(int k=i+2; k<=j-1; ++k) {
				f[i][j] += g[i][k-1]*f[k][j]%mod;//AB
				f[i][j] += g[i][k-1]*(sum[min(R[k],j-2)+1]-sum[k])%mod;//ASB
			}
			f[i][j] %= mod;g[i][j] %= mod;
		}
	cout << f[1][n] << '\n';
}
