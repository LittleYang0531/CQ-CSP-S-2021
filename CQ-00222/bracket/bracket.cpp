#include<bits/stdc++.h>
#define inl inline 
#define Rep for
#define re(i,x,y,z) for(int i=(x);i!=(y);i=(z))
#define rep(i,x,y) for(int i=(x);i<=(y);++i)
#define repp(i,x,y,d) for(int i=(x);i<=(y);i+=d)
#define reep(i,x,y) for(int i=(x);i<=(y);i<<=1)
#define per(i,x,y) for(int i=(x);i>=(y);--i)
#define perr(i,x,y,d) for(int i=(x);i>=(y);i-=d)
#define pii pair<int,int>
#define piL pair<int,LL>
#define pLi pair<LL,int>
#define pLL pair<LL,LL>
#define vi vector<int>
#define vL vector<LL>
#define vii vector<pii>
#define viL vector<piL>
#define vLi vector<pLi>
#define vLL vector<pLL>
#define fi first
#define se second
#define mp make_pair
#define eb emplace_back
#define lowbit(x) (x&(-(x)))
using namespace std;
#define getchar() (SB==TB&&(TB=(SB=BB)+fread(BB,1,1<<15,stdin),SB==TB)?EOF:*SB++)
char BB[1<<16],*SB=BB,*TB=BB;
template<typename T>inl void read(T &n){
	T w=1;n=0;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')w=-1;ch=getchar();}
	while(isdigit(ch)){n=(n<<3)+(n<<1)+(ch&15);ch=getchar();}
	n*=w;
}
typedef long long LL;
typedef double db;
template<typename T>inl void chkmx(T &a,T b){(a<b) && (a=b);}
template<typename T>inl void chkmn(T &a,T b){(a>b) && (a=b);}

const int MOD=1e9+7;
inl int inc(int a,int b){return a+b>=MOD ? a+b-MOD : a+b;}
inl int mul(int a,int b){return 1LL*a*b%MOD;}
inl void Inc(int &a,int b){((a+=b)>=MOD) && (a-=MOD);}

const int maxn=5e2+5;
int n,K;
bool ok[maxn][maxn];
int f[maxn][maxn],g[maxn][maxn],h[maxn][maxn];
char S[maxn];

inl bool Check(int pos,char ch){return S[pos]==ch || S[pos]=='?';}

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&K);
	scanf("%s",S+1);
	rep(l,1,n) rep(r,l,min(l+K-1,n)){
		if(Check(r,'*')) ok[l][r]=1;
		else break;
	}rep(i,1,n) ok[i][i-1]=1;
	rep(len,2,n){
		rep(i,1,n-len+1){
			int j=i+len-1;
			if(Check(i,'(') && Check(j,')')){
				if(ok[i+1][j-1]) f[i][j]=1;
				Inc(f[i][j],g[i+1][j-1]);
				rep(k,i+1,j-1) if(ok[i+1][k]) Inc(f[i][j],g[k+1][j-1]);
				per(k,j-1,i+1) if(ok[k][j-1]) Inc(f[i][j],g[i+1][k-1]);
			}
			g[i][j]=f[i][j];
			rep(o,i,j-1) Inc(g[i][j],mul(g[i][o],f[o+1][j]));
			rep(o,i,j-1) Inc(g[i][j],mul(g[i][o],h[o+1][j]));
			rep(o,i,j-1) if(ok[i][o]) Inc(h[i][j],f[o+1][j]);
		}
	}printf("%d\n",g[1][n]);
	return 0;
}
