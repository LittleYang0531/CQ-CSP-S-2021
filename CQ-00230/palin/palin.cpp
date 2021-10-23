#include<cstdio>
#include<algorithm>
const int Q=500005;
const int INF=(1<<30);
typedef long long ll;
#define rg register int
#define cint const register int
#define gc() getchar()
inline bool ig(char c){return c>='0'&&c<='9';}
inline void read(int&oi){char c;int res=0,f=1;while(c=gc(),c^'-'&&!ig(c));c^'-'?res=(c^48):f=-1;while(c=gc(),ig(c))res=res*10+(c^48);oi=f*res;}
inline void print(int oi){if(oi<0)putchar('-'),oi=~oi+1;if(oi>9)print(oi/10);putchar(oi%10+48);}
inline void write(int oi,char c){print(oi);putchar(c);}
inline void swap(rg&x,rg&y){cint t=x;x=y;y=t;}
int T,n,a[Q],p[Q],cnt[Q],b[Q],ans,p1[Q],p2[Q];
inline void solve(cint st,cint k){
	rg L=1,R=2*n,pos=0;
	for(rg i=0,j=n-1;i<n;++i,--j)if((st>>j)&1)p[i]=1;else p[i]=0;
	for(rg i=0;i<n;++i)b[pos++]=a[p[i]?(L++):(R--)];
	for(rg i=1;i<=n;++i)cnt[i]=0;
	for(rg i=0;i<n;++i)++cnt[b[i]];
	for(rg i=1;i<=n;++i)if(cnt[i]!=1)return;
	if(k)for(rg i=0;i<n;++i)putchar(p[i]?'L':'R');
	for(rg i=n-1;i>=0;--i){
		cint x=b[i];
		if(a[L]==x){L++;if(k)putchar('L');}
		else if(a[R]==x){R--;if(k)putchar('R');}
		else return;
	}
	if(k)putchar('\n');ans=st;
}
inline void dfs(cint dep,cint st){
	if(dep==n)return solve(st,0);
	dfs(dep+1,st*2+1);if(~ans)return;dfs(dep+1,st*2);
}
int main(){
	freopen("palin.in","r",stdin);
//	freopen("palin2.in","r",stdin);
	freopen("palin.out","w",stdout);
	read(T);for(;T--;){
		read(n);for(rg i=1;i<=2*n;++i)read(a[i]),p1[i]=p2[i]=0;
		for(rg i=1;i<=2*n;++i)if(!p1[a[i]])p1[a[i]]=i;else p2[a[i]]=i;rg fg=0;
		for(rg i=1;i<=n;++i){
			if(p1[i]>p2[i])swap(p1[i],p2[i]);
			cint cnt=p1[i]+2*n-p2[i];if(cnt==n){fg=1;break;}
			if(p1[i]+1==p2[i]){fg=1;break;}
		}
		if(!fg){write(-1,'\n');continue;}
		ans=-1;dfs(0,0);if(~ans)solve(ans,1);else write(-1,'\n');
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
