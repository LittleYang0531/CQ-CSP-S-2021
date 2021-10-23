#include <cstdio>
const int maxn = 505,mod = 1e9+7;
int n,k;char s[maxn];
int sumS[maxn],f[maxn][maxn],g[maxn][maxn],h[maxn][maxn],T[maxn][maxn];
bool canL[maxn],canR[maxn],allS[maxn][maxn];
void plus(int &x,int v){x+=v,(x>=mod?x-=mod:0);}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k),scanf("%s",s+1);
	for(int i=1;i<=n;++i)canL[i] = (s[i]=='(')||(s[i]=='?');
	for(int i=1;i<=n;++i)canR[i] = (s[i]==')')||(s[i]=='?');
	for(int i=1;i<=n;++i)sumS[i] = (s[i]=='*')||(s[i]=='?');
	for(int i=1;i<=n;++i)sumS[i] += sumS[i-1];
	for(int i=1;i<=n;++i)
		for(int j=i-1;j<=n;++j)
			allS[i][j] = (sumS[j]-sumS[i-1]==j-i+1);
	for(int i=1;i<=n;++i)
		for(int j=i+1;j<=n;++j)
			if(canL[i] && canR[j] && j-i-1<=k && allS[i+1][j-1])
				f[i][j] = 1;
	for(int Len=2;Len<=n;++Len){
		for(int l=1;l<=n-Len+1;++l){
			int r = l+Len-1;
			for(int i=l+1;i<=r;++i)
				plus(g[l][r],1ll*f[l][i-1]*T[i][r]%mod);
			for(int i=l+1;i<=r;++i)
				plus(g[l][r],1ll*f[l][i-1]*h[i][r]%mod);
			if(canL[l] && canR[r]){
				plus(f[l][r],T[l+1][r-1]);
				for(int i=l+2;i<=r-2;++i)
					if(i-l-1<=k&&allS[l+1][i-1])
						plus(f[l][r],T[i][r-1]);
				for(int i=r-2;i>=l+2;--i)
					if(r-i-1<=k&&allS[i+1][r-1])
						plus(f[l][r],T[l+1][i]);
			}
			T[l][r] = (f[l][r]+g[l][r])%mod;
			for(int i=l+1;i<=r;++i)
				if(i-l<=k&&allS[l][i-1])plus(h[l][r],T[i][r]);
		}
	}
	return printf("%d\n",T[1][n]),0;
}
