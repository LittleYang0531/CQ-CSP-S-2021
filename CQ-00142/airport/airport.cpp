#include <cstdio>
#define print(x,y) write(x),putchar(y)

template <class T>
inline T read(const T sample) {
	T x=0; char s; bool f=0;
	while((s=getchar())>'9' or s<'0')
		f |= (s=='-');
	while(s>='0' and s<='9')
		x = (x<<1)+(x<<3)+(s^48),
		s = getchar();
	return f?-x:x;
}

template <class T>
inline void write(const T x) {
	if(x<0) {
		putchar('-');
		write(-x);
		return;
	}
	if(x>9) write(x/10);
	putchar(x%10^48);
}

#include <algorithm>
using namespace std;

const int maxn = 1e5+5;

int s,n,m,tot;
int val[maxn],cnt[2][maxn<<1];
int t[maxn<<3],la[maxn<<3];
struct node {
	int a,b;
	
	bool operator < (const node &t) const {
		return a<t.a;
	}
} p[maxn],q[maxn];

void pushDown(int o) {
	if(!la[o]) return;
	la[o<<1] += la[o];
	la[o<<1|1] += la[o];
	t[o<<1] += la[o];
	t[o<<1|1] += la[o];
	la[o]=0;
}

void ins(int o,int l,int r,int L,int R) {
	if(l>=L and r<=R) 
		return ++t[o],++la[o],void();
	int mid=l+r>>1;
	pushDown(o);
	if(L<=mid) ins(o<<1,l,mid,L,R);
	if(R>mid) ins(o<<1|1,mid+1,r,L,R);
	t[o] = max(t[o<<1],t[o<<1|1]);
}

void build(int o,int l,int r) {
	t[o]=la[o]=0;
	if(l==r) return;
	int mid=l+r>>1;
	build(o<<1,l,mid);
	build(o<<1|1,mid+1,r);
}

int ask(int o,int l,int r,int L,int R) {
	if(l>=L and r<=R) return t[o];
	int mid=l+r>>1,ret=0;
	pushDown(o);
	if(L<=mid) ret=ask(o<<1,l,mid,L,R);
	if(R>mid) ret=max(ret,ask(o<<1|1,mid+1,r,L,R));
	return ret;
}

namespace bruteForce {
	int dis[maxn<<1];
	
	void work() {
		for(int i=1;i<=n;++i) {
			p[i].a=lower_bound(val+1,val+tot+1,p[i].a)-val;
			p[i].b=lower_bound(val+1,val+tot+1,p[i].b)-val;
		}
		for(int i=1;i<=m;++i) {
			q[i].a=lower_bound(val+1,val+tot+1,q[i].a)-val;
			q[i].b=lower_bound(val+1,val+tot+1,q[i].b)-val;
		}
		int cur,pos,ans=0,aa,bb;
		for(int t=0;t<=s;++t) {
			cur=pos=aa=bb=0;
			for(int i=1;i<=tot;++i)
				dis[i]=0;
			for(int i=1;i<=n;++i) {
				while(pos+1<=p[i].a)
					cur-=dis[pos+1],++pos;
				if(cur==t) continue;
				++cur; ++aa;
				++dis[p[i].b];
			}
			cur=pos=0;
			for(int i=1;i<=tot;++i)
				dis[i]=0;
			for(int i=1;i<=m;++i) {
				while(pos+1<=q[i].a)
					cur-=dis[pos+1],++pos;
				if(cur==s-t) continue;
				++cur; ++bb;
				++dis[q[i].b];
			}
			ans = max(ans,aa+bb);
		}
		print(ans,'\n');
	}
}

int main() {
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	s=read(9),n=read(9),m=read(9);
	for(int i=1;i<=n;++i)
		p[i].a=read(9),p[i].b=read(9),
		val[++tot]=p[i].a,val[++tot]=p[i].b;
	for(int i=1;i<=m;++i)
		q[i].a=read(9),q[i].b=read(9),
		val[++tot]=q[i].a,val[++tot]=q[i].b;
	sort(p+1,p+n+1); sort(q+1,q+m+1);
	sort(val+1,val+tot+1);
	tot=unique(val+1,val+tot+1)-val-1;
	if(n<=5000)
		return bruteForce::work(),0;
	for(int i=1;i<=n;++i) {
		p[i].a=lower_bound(val+1,val+tot+1,p[i].a)-val;
		p[i].b=lower_bound(val+1,val+tot+1,p[i].b)-val;
		ins(1,1,tot,p[i].a,p[i].b);
		++cnt[0][ask(1,1,tot,p[i].a,p[i].b)];
	}
	for(int i=1;i<=n;++i) 
		cnt[0][i] += cnt[0][i-1];
	build(1,1,tot);
	for(int i=1;i<=m;++i) {
		q[i].a=lower_bound(val+1,val+tot+1,q[i].a)-val;
		q[i].b=lower_bound(val+1,val+tot+1,q[i].b)-val;
		ins(1,1,tot,q[i].a,q[i].b);
		++cnt[1][ask(1,1,tot,q[i].a,q[i].b)];
	}
	for(int i=1;i<=m;++i) 
		cnt[1][i] += cnt[1][i-1];
	int ans = 0;
	for(int i=0;i<=s;++i)
		ans = max(ans,cnt[0][i]+cnt[1][s-i]);
	print(ans,'\n');
	return 0;
}

