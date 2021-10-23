#include<bits/stdc++.h>
#define _I inline
#define _R register
#define mod 1000000007
#define INF 0x3f3f3f3f
#define eps 1e-4
#define memset(x,y) memset(x,y,sizeof(x))
#define memcpy(x,y) memcpy(x,y,sizeof(x))
#define ll long long
#define ull unsigned long long
#define int ll
using namespace std;
//char buf[1<<19],*p1=buf,*p2=buf;
//#define getchar() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<19,stdin)),p1==p2)?EOF:*p1++;
int read(){
	int x=0,f=0;char ch=getchar();
	while(ch<'0'||ch>'9')f|=(ch=='-'),ch=getchar();
	while('0'<=ch&&ch<='9')x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	if(f)x=-x;return x;
}
const int N=505;
int f[N][N][2],g[N][N],n,k,s[N][N],a[N];char b[N];
int qmod(int x){return x>=mod?x-mod:x;}
int dp2(int l,int r);
int dp(int l,int r,int op=0){
	if(f[l][r][op]!=-1)return f[l][r][op];
	if(l+1==r)return f[l][r][op]=((a[l]&1)&&(a[r]&2));
	if(l>=r)return f[l][r][op]=0;
	int ret=0;if((a[l]&1)&&(a[r]&2)&&s[l+1][r-1])ret=1;
	if(op!=1)for(_R int i=l;i<r;++i)ret=(ret+dp(l,i,1)*dp(i+1,r))%mod;
	if(op!=1)for(_R int j=l+1;j<r;++j)ret=(ret+dp(l,j-1,1)*dp2(j,r))%mod;
	if((a[l]&1)&&(a[r]&2)){
		ret+=dp(l+1,r-1);
		for(_R int i=l+1;i<=r-1;++i)if(s[l+1][i])ret=qmod(ret+dp(i+1,r-1));
		for(_R int i=l+1;i<=r-1;++i)if(s[i][r-1])ret=qmod(ret+dp(l+1,i-1));
	}
	return f[l][r][op]=ret;
}
int dp2(int l,int r){
	if(g[l][r]!=-1)return g[l][r];
	int ret=0;
	for(_R int i=l;i<r;++i)if(s[l][i])ret=qmod(ret+dp(i+1,r));
	return g[l][r]=ret;
}
signed main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();k=read();scanf("%s",b+1);memset(f,-1);memset(g,-1);
	for(_R int i=1;i<=n;++i){
		if(b[i]=='(')a[i]=1;
		if(b[i]==')')a[i]=2;
		if(b[i]=='?')a[i]=3;
	}
	for(_R int i=1;i<=n;++i)
		for(_R int j=i;j<=n;++j){
			if(a[j]==1||a[j]==2)break;
			s[i][j]=(j-i+1<=k);
		}
	cout<<dp(1,n);
	return 0;
}
/*
6 2
???(*?


()*()()(*)

*/
