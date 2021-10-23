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
#define pb pop_back
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

const int maxn=5e5+5;
int T,n;
int a[maxn<<1],t[maxn],pos[maxn<<1];
vi g,h;

bool Work(int l,int r,int x,int y){
	if(r-l+1==n){
		int nowx=1,nowy=2*n;
		Rep(auto p:g){
			if(p==nowx) putchar('L'),++nowx;
			else putchar('R'),--nowy;
			h.eb(a[p]);
		}
		per(i,(int)h.size()-1,0){
			if(a[nowx]==h[i]) putchar('L'),++nowx;
			else putchar('R'),--nowy;
		}puts("");
		return 1;
	}
	if(l+1<=x-1 && pos[l]==x-1){
		g.eb(l);
		if(Work(l+1,r,x-1,y)) return 1; 
		g.pb();
	}if(l+1<=x && y+1<=r && pos[l]==y+1){
		g.eb(l);
		if(Work(l+1,r,x,y+1)) return 1;
		g.pb();
	}if(l<=x-1 && y<=r-1 && pos[r]==x-1){
		g.eb(r);
		if(Work(l,r-1,x-1,y)) return 1;
		g.pb();
	}if(y+1<=r-1 && pos[r]==y+1){
		g.eb(r);
		if(Work(l,r-1,x,y+1)) return 1;
		g.pb();
	}return 0;
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(T);
	while(T--){
		read(n),g.clear(),h.clear();
		rep(i,1,n) t[i]=0;
		rep(i,1,n<<1){
			read(a[i]);
			if(t[a[i]]) pos[i]=t[a[i]],pos[t[a[i]]]=i;
			else t[a[i]]=i;
		}g.eb(1);
		if(!Work(2,n<<1,pos[1],pos[1])){
			g.pb();
			g.eb(n<<1);
			if(!Work(1,(n<<1)-1,pos[n<<1],pos[n<<1])) puts("-1");
		} 
    }
	return 0;
}
