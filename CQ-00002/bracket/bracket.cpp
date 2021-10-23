#include<bits/stdc++.h>
#define int long long
using namespace std;
const int N=1e5+101,mod=1e9+7;

inline int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') { s=s*10+ch-'0';ch=getchar();}
	return s*w;
}

char ch[N],p[N];

int n,k,ans,x,y;
void dfs(int pos,int w) {
	if(pos==n+1) {
		if(x==y) {
			++ans;
			//for(int i=1;i<=n;++i) cout<<p[i];
		}
		return ;
	}
	if(ch[pos]=='?') {
		if(pos!=n) {++x;p[pos]='(';dfs(pos+1,0);--x;}
		if(pos!=1) {++y;p[pos]=')';if(x>=y) dfs(pos+1,0);--y;}
		if(pos!=1&&pos!=n) {
			if(p[pos-1]==')'&&p[pos-2]=='('&&p[pos-3]=='*') return;
			++w;p[pos]='*';if(w<=k) dfs(pos+1,w);--w;
		}
	}
	if(ch[pos]=='(') {
		p[pos]='(';
		++x;
		dfs(pos+1,0);
		--x;
	}
	if(ch[pos]==')') {
		p[pos]=')';
		++y;
		if(x>=y) dfs(pos+1,0);
		--y;
	}
	if(ch[pos]=='*') {
		if(p[pos-1]==')'&&p[pos-2]=='('&&p[pos-3]=='*') return;
		p[pos]='*';
		++w;
		if(w<=k) dfs(pos+1,w);
		--w;
	}
}

int dp[N][10];
signed main() {
	
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	n=read(),k=read();
	scanf("%s",ch+1);
	
	dfs(1,0);
	printf("%lld",ans%mod);
//	int num=0;
//	dp[1][1]=1,dp[1][2]=0,dp[1][3]=0;	//(,*,)
//	for(int i=2;i<=n;++i) {
//		dp[i][1]=dp[i-1][2]+dp[i-1][3];
//		if(num+1<=k) dp[i][2]=dp[i][1]+dp[i][3],num++;
//		dp[i][3]=dp[i][1]+dp[i][2];
//	}
	return 0;
}
