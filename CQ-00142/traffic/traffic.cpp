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

#include <vector>
#include <iostream>
using namespace std;
typedef long long ll;
typedef pair <int,int> pii;

const ll inf = 1e15;
const int maxn = 505;

int n,m,T;
int w[2][maxn][maxn];

namespace my {
	vector <pii> p[maxn*maxn];
	ll dp[1<<18][20];
	
	int ID(int x,int y) {
		return (x-1)*m+y;
	}
	
	int adj(int x) {
		if(x<=m) return ID(1,x);
		if(x<=m+n) return ID(x-m,m);
		if(x<=m*2+n)
			return ID(n,m*2+n-x+1);
		return ID(m*2+n*2+1-x,1);
	}
	
	pii dec(int x) {
		return make_pair((x-1)/m+1,(x-1)%m+1);
	}
	
	void work() {
		while(T--) {
			int x,y,z,tot=read(9);
			for(int i=1;i<=n*m;++i)
				p[i].clear();
			while(tot--) {
				x=read(9),y=read(9),z=read(9);
				int d=adj(y);
				p[d].push_back(make_pair(x,z));
			}
			int lim = (1<<(n*m)),id,aa; 
			ll ans = inf, tmp; bool co;
			for(int s=0;s<lim;++s) {
				tmp=0;
				for(int i=1;i<=n;++i)
					for(int j=1;j<=m;++j) {
						id=ID(i,j); co=(s>>id-1&1);
						if(i>1)	{
							aa=ID(i-1,j);
							if((s>>aa-1&1)!=co)
								tmp += w[0][i-1][j];
						}
						if(j>1) {
							aa=ID(i,j-1);
							if((s>>aa-1&1)!=co)
								tmp += w[1][i][j-1];
						}	
						for(int k=0;k<p[id].size();++k)
							if(p[id][k].second^co)
								tmp += p[id][k].first;
					}
				ans = min(ans,tmp);
			}
			print(ans,'\n');
		}
	}
}

int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(9),m=read(9),T=read(9);
	for(int i=1;i<n;++i)
		for(int j=1;j<=m;++j)
			w[0][i][j]=read(9);
	for(int i=1;i<=n;++i)
		for(int j=1;j<m;++j)
			w[1][i][j]=read(9);
	my::work();
	return 0;
}

