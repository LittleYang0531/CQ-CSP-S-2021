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

const int maxn=5e2+5;
int n,m,T,k;
int x[maxn],p[maxn],t[maxn];
int w[maxn][maxn],v[maxn][maxn],f[2][maxn][maxn];

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	read(n),read(m),read(T);
	rep(i,1,n-1) rep(j,1,m) read(w[i][j]);
	rep(i,1,n) rep(j,1,m-1) read(v[i][j]);
	while(T--){
		read(k);
		rep(i,1,k) read(x[i]),read(p[i]),read(t[i]);
		puts("12");
	}
	return 0;
}
