#include<bits/stdc++.h>
using namespace std;
int read() {
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') {if(ch=='-') w=-1;ch=getchar();}
	while(ch>='0'&&ch<='9') s=(s<<3)+(s<<1)+(ch^48),ch=getchar();
	return s*w;
}
const int maxn = 510, mod = 1e9+7;
int n,K,f[maxn][maxn],g[maxn][maxn];char S[maxn];
int MOD(int x) {return x>=mod?x-mod:x;}
int ton(int L,int R) {
	if(L>R) return 0;
	if(R-L+1>K) return 0;
	for(int i=L;i<=R;i++) if(S[i]=='('||S[i]==')') return 0;
	return 1;
}
char eqa(char x,char B) {return x=='?'||x==B;}
int ksm(int x,int y) {
	int r=1;
	while(y) y&1?r=1ll*r*x%mod:0,x=1ll*x*x%mod,y>>=1;
	return r;
}
signed main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),K=read(),scanf("%s",S+1);
	for(int i=1;i<=n;i++) f[i][i-1]=g[i][i-1]=1;
	for(int l=2;l<=n;l++)
		for(int i=1;i<=n;i++) {
			int j=i+l-1;
			if(j>n) break;
			// case 1: () (pro)
			if(eqa(S[i],'(')&&eqa(S[j],')')) f[i][j]=MOD(f[i][j]+f[i+1][j-1]);
			// case 2: (S)
			if(eqa(S[i],'(')&&eqa(S[j],')')) f[i][j]=MOD(f[i][j]+ton(i+1,j-1));
			// case 3: (S pro)
			if(eqa(S[i],'(')&&eqa(S[j],')'))
				for(int k=i+1;k<j-1;k++) {
					//i+1~k S
					//k+1~j-1 pro
					if(S[k]=='('||S[k]==')') break;
					if(k-i>K) break;
					f[i][j]=MOD(f[i][j]+f[k+1][j-1]);
				}
			// case 4: (pro S)
			if(eqa(S[i],'(')&&eqa(S[j],')'))
				for(int k=j-1;k>i+1;k--) {
					//k~j-1 S
					//i+1~k-1 pro
					if(S[k]=='('||S[k]==')') break;
					if(j-k>K) break;
					f[i][j]=MOD(f[i][j]+f[i+1][k-1]);
				}
			g[i][j]=f[i][j];
			// 以下两种都需要钦定左边的为第一次合并（即g） 
			// case 5: pro pro
			for(int k=i;k<j;k++) {
				//i~k pro
				// k+1 j pro
				f[i][j]=(f[i][j]+1ll*g[i][k]*f[k+1][j])%mod;
			}
			// case 6: pro S pro
			int lst=i;
			for(int k=i+1,r=0;k<j;k++) {
				if(S[k]=='('||S[k]==')') r=0,lst=k;
				if(lst<k-K) r=MOD(r+mod-g[i][k-K-1]);
				if(S[k]!='('&&S[k]!=')') r=MOD(r+g[i][k-1]);
				f[i][j]=(f[i][j]+1ll*r*f[k+1][j])%mod;
			}
//			if(f[i][j]) cerr<<i<<' '<<j<<' '<<g[i][j]<<' '<<f[i][j]<<'\n';
		}
	cout<<f[1][n]<<'\n';
	return 0;
}
