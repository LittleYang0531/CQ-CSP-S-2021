#include <set>
#include <cstdio>
inline char gc(){
	static char buf[1<<16],*S,*T;
	if(S==T){
		T = (S=buf)+fread(buf,1,1<<16,stdin);
		if(S==T)return EOF;
	}return *S++;
}
#define getchar gc
inline int re(){//without '-'
	char c;
	while((c=getchar())<'0'||c>'9');
	int res = c-'0';
	while((c=getchar())>='0'&&c<='9')res = res*10+c-'0';
	return res;
}
inline int max(int a,int b){return a>b?a:b;}
const int maxn = 1e5+5;
int n,m1,m2,ans1[maxn],ans2[maxn];
struct Itv{
	int l,r;Itv(int L=0,int R=0):l(L),r(R){};
	bool operator <(Itv b)const{return l<b.l;}
};
std :: set<Itv> na,in;
typedef std :: set<Itv> :: iterator Iter;
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n = re(),m1 = re(),m2 = re();
	for(int i=1,l,r;i<=m1;++i)l = re(),r = re(),na.insert(Itv(l,r));
	for(int i=1,l,r;i<=m2;++i)l = re(),r = re(),in.insert(Itv(l,r));
	for(int i=1;i<=n;++i){
		ans1[i] = ans1[i-1];if(!na.size())continue;
		int nowt = 0;
		while(1){
			Iter it = na.lower_bound(Itv(nowt,0));
			if(it != na.end())++ans1[i],nowt = it->r,na.erase(it);
			else break;
		}
	}
	for(int i=1;i<=n;++i){
		ans2[i] = ans2[i-1];if(!in.size())continue;
		int nowt = 0;
		while(1){
			Iter it = in.lower_bound(Itv(nowt,0));
			if(it != in.end())++ans2[i],nowt = it->r,in.erase(it);
			else break;
		}
	}
	int ans = 0;
	for(int i=0;i<=n;++i)ans = max(ans,ans1[i]+ans2[n-i]);
	return printf("%d\n",ans),0;
}
