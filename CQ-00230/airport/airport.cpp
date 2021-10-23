#include<cstdio>
#include<algorithm>
#include<set>
#include<queue>
#include<vector>
const int Q=100005;
const int INF=(1<<30);
typedef long long ll;
#define rg register int
#define cint const register int
#define gc() getchar()
inline bool ig(char c){return c>='0'&&c<='9';}
inline void read(int&oi){char c;int res=0,f=1;while(c=gc(),c^'-'&&!ig(c));c^'-'?res=(c^48):f=-1;while(c=gc(),ig(c))res=res*10+(c^48);oi=f*res;}
inline void print(int oi){if(oi<0)putchar('-'),oi=~oi+1;if(oi>9)print(oi/10);putchar(oi%10+48);}
inline void write(int oi,char c){print(oi);putchar(c);}
inline int max(cint x,cint y){return x>y?x:y;}
int n,ans;
struct node{
	int l,r,pos;node(cint L=0,cint R=0,cint X=0):l(L),r(R),pos(X){}
	inline bool operator<(const node&rhs)const{
		return l^rhs.l?l<rhs.l:r<rhs.r;
	}
};
std::set<node>s;
#define siter std::set<node>::iterator
struct air{
	int m;node a[Q];
	int f[Q],nxt[Q],fr[Q],sum[Q];
	inline void getA(){for(rg i=1;i<=m;++i)read(a[i].l),read(a[i].r);}
	inline void dfs(cint x){if(!x)return;f[x]=1;dfs(nxt[x]);f[x]+=f[nxt[x]];}
	inline void pre(){
		std::sort(a+1,a+1+m);s.clear();
		for(rg i=1;i<=m;++i)a[i].pos=i,s.insert(a[i]);
		for(rg i=1;i<=m;++i){
			if(nxt[i])continue;
			for(rg x=i;;x=nxt[x]){
				siter pos=s.upper_bound(node(a[x].r,0,0));
				if(pos==s.end())break;
				nxt[x]=pos->pos;fr[pos->pos]=x;s.erase(pos);
			}
		}
		for(rg i=1;i<=m;++i)if(!f[i])dfs(i);rg pos=0;
		for(rg i=1;i<=m;++i)if(!fr[i])++pos,sum[pos]=sum[pos-1]+f[i];
		for(rg i=pos+1;i<=n;++i)sum[i]=m;
	}
	inline void debug(){
		puts("DEBUG");
		for(rg i=1;i<=m;++i)write(i,' '),write(a[i].l,' '),write(a[i].r,'\n');
		for(rg i=1;i<=m;++i)write(nxt[i],' ');putchar('\n');
		for(rg i=1;i<=m;++i)write(fr[i],' ');putchar('\n');
		for(rg i=1;i<=m;++i)write(f[i],' ');putchar('\n');
		for(rg i=1;i<=n;++i)write(sum[i],' ');putchar('\n');
	}
	inline int calc(cint x){
		if(x>=m)return m;if(!x)return 0;
		std::priority_queue<int,std::vector<int>,std::greater<int> >pq;
		while(!pq.empty())pq.pop();
		for(rg i=1;i<=x;++i)pq.push(a[i].r);rg res=x;
		for(rg i=x+1;i<=m;++i){
			if(pq.top()>=a[i].l)continue;
			++res;pq.pop();pq.push(a[i].r);
		}
		return res;
	}
}A,B;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	read(n);read(A.m);read(B.m);
	A.getA();B.getA();A.pre();B.pre();
	if(n<=1000){
		for(rg i=0;i<=n;++i)ans=max(ans,A.calc(i)+B.calc(n-i));
		write(ans,'\n');return 0;
	}
//	A.debug();B.debug();
	for(rg i=0;i<=n;++i){
		ans=max(ans,A.sum[i]+B.sum[n-i]);
//		printf("%d %d\n",A.sum[i],B.sum[n-i]);
	}
	write(ans,'\n');
	return 0;
}
