#include<iostream>
#include<cstdio>
using namespace std;
#define N 512
#define mod 1000000007
inline int M(int x){return (x>=mod)?(x-mod):x;}
inline int M1(int x){return (x<0)?(x+mod):x;}
inline int ksm(int p,int k){int res=1;while(k){if(k&1)res=1ll*res*p%mod;k>>=1;p=1ll*p*p%mod;}return res;}
int n,m,f[N][N],g[N][N],h[N][N],w[N][N],ans;bool ca[N][N];char sc[N];
inline bool ju(int x,char v){return (sc[x]==v)||(sc[x]=='?');}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&m);int i,l,r,res;scanf("%s",sc+1);
	for(l=1;l<=n;l++)
	for(ca[l][l-1]=1,r=l;r<=min(n,l+m-1);r++)ca[l][r]=ca[l][r-1]&&ju(r,'*');
	for(l=1;l<=n+1;l++)f[l][l-1]=g[l][l-1]=h[l][l-1]=w[l][l-1]=1;
	for(l=n;l>=1;l--)
	for(r=l;r<=n;r++)
	{
		f[l][r]=(ju(l,'(')&&ju(r,')'))?M(ca[l+1][r-1]+M1(M(w[l+1][r-1]+h[l+1][r-1])-2*((l+1)==r))):0;
		res=0;for(i=r;i>=l;i--)if(ca[i][r])res=M(res+h[l][i-1]);else break;g[l][r]=res;
		res=0;for(i=r;i>=l;i--)res=(res+1ll*f[i][r]*M1(M(g[l][i-1]+h[l][i-1])-(i==l)))%mod;h[l][r]=res;
		res=0;for(i=l;i<r;i++)res=(res+1ll*f[l][i]*g[i+1][r])%mod;w[l][r]=res;
	}
	for(i=1;i<=n;i++)ans=(ans+1ll*f[1][i]*h[i+1][n])%mod;
	printf("%d",ans);return 0;
}
