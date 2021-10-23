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

const int maxn=1e5+5,INF=1e9;
int n,m[2],N,tot;
pii a[2][maxn];

#define lc (id<<1)
#define rc (id<<1|1)
#define mid ((l+r)>>1)
int mn[maxn<<2];
int res[2][maxn];
void Push_Up(int id){mn[id]=min(mn[lc],mn[rc]);}
void Build(int id=1,int l=1,int r=N){
	if(l==r) return mn[id]=INF,void();
	Build(lc,l,mid),Build(rc,mid+1,r);
	Push_Up(id);
}
void Update(int x,int v,int id=1,int l=1,int r=N){
	if(l==r) return mn[id]=v,void();
	if(x<=mid) Update(x,v,lc,l,mid);
	else Update(x,v,rc,mid+1,r);
	Push_Up(id);
}
int Query(int v,int id=1,int l=1,int r=N){
	if(l==r) return l;
	if(mn[lc]<v) return Query(v,lc,l,mid);
	else return Query(v,rc,mid+1,r);
}
#undef lc
#undef rc
#undef mid
void Work(){
	int now=0;
	Build();
    rep(i,1,m[0]){
    	if(mn[1]>a[0][i].fi) ++now,Update(now,a[0][i].se),++res[0][now];
    	else{
    		int p=Query(a[0][i].fi);
    		++res[0][p];
    		Update(p,a[0][i].se);
		}
	}
	now=0;
	Build();
	rep(i,1,m[1]){
    	if(mn[1]>a[1][i].fi) ++now,Update(now,a[1][i].se),++res[1][now];
    	else{
    		int p=Query(a[1][i].fi);
    		++res[1][p];
    		Update(p,a[1][i].se);
		}
	}
	rep(i,1,n) res[0][i]+=res[0][i-1],res[1][i]+=res[1][i-1];
	int ans=0;
	rep(i,0,n) chkmx(ans,res[0][i]+res[1][n-i]);
	printf("%d\n",ans);
}

int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n),read(m[0]),read(m[1]);
	N=max(n,max(m[0],m[1]));
	rep(i,1,m[0]) read(a[0][i].fi),read(a[0][i].se);
	rep(i,1,m[1]) read(a[1][i].fi),read(a[1][i].se);
	sort(a[0]+1,a[0]+m[0]+1),sort(a[1]+1,a[1]+m[1]+1);
    Work();
	return 0;
}
