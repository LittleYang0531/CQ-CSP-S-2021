#include<cstdio>
#include<algorithm>
const int Q=505;
const int INF=(1<<30);
const int mod=1e9+7;
typedef long long ll;
#define rg register int
#define cint const register int
#define gc() getchar()
inline bool ig(char c){return c>='0'&&c<='9';}
inline void read(int&oi){char c;int res=0,f=1;while(c=gc(),c^'-'&&!ig(c));c^'-'?res=(c^48):f=-1;while(c=gc(),ig(c))res=res*10+(c^48);oi=f*res;}
inline void print(int oi){if(oi<0)putchar('-'),oi=~oi+1;if(oi>9)print(oi/10);putchar(oi%10+48);}
inline void write(int oi,char c){print(oi);putchar(c);}
inline int inc(cint x,cint y){return x+y<mod?x+y:x+y-mod;}
inline int mul(cint x,cint y){return 1ll*x*y%mod;}
int n,m,a[Q],go[Q];
int b[Q],ans;
//,f[Q][Q][Q];
int st[Q],top,is[Q],cnt[Q],num[Q],tt;
inline void dfs(cint dep){
//	write(dep,' ');write(tt,'\n');
	if(dep==n+1){
		if(b[1]==0||b[n]==0)return;
		for(rg i=0;i<=n;++i)cnt[i]=num[i]=0;
		for(rg i=1;i<=n;++i){
			rg pos=i;for(;pos<=n;++pos)if(!b[pos])break;
			i=pos;for(;pos<=n;++pos)if(b[pos])break;--pos;
			if(pos-i+1>m)return;i=pos;
		}
//		for(rg i=1;i<=n;++i)write(b[i],' ');putchar('\n');
		top=0;for(rg i=1;i<=n;++i){
			if(b[i]==-1)cnt[top+1]=num[top+1]=0,++cnt[top],--top;
			else if(b[i]==1)++top;else{
				rg pos=i;for(;pos<=n;++pos)if(b[pos])break;
				--pos;++num[top+1];if(b[i-1]==-1&&cnt[top+1]<num[top+1])return;i=pos;
			}if(top<0)return;
		}
		if(top!=0)return;
//		for(rg i=1;i<=n;++i)write(b[i],' ');putchar('\n');
		++ans;return;
	}
	if(a[dep]!=2)b[dep]=a[dep],dfs(dep+1);
	else b[dep]=1,++tt,dfs(dep+1),--tt,b[dep]=0,dfs(dep+1),b[dep]=-1,--tt,dfs(dep+1),++tt;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	go['(']=1;go[')']=-1;go['*']=0;go['?']=2;
	read(n);read(m);char c;
	while(c=gc(),c^'('&&c^')'&&c^'*'&&c^'?');a[1]=go[c];
	for(rg i=2;i<=n;++i)c=gc(),a[i]=go[c];
	if(a[1]==-1||a[1]==0){write(0,'\n');return 0;}
	dfs(1);write(ans,'\n');
	return 0;
}
/*
7 3
(*??*??
10 2
???(*??(?)
*/
