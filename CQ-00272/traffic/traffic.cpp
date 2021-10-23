#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 505
#define MAXM 1000005
#define LL long long
#define DB double
#define ENDL putchar('\n')
#define lowbit(x) (-(x) & (x))
LL read() {
	LL f=1,x=0;int s = getchar();
	while(s < '0' || s > '9') {if(s<0)return -1;if(s=='-')f=-f;s=getchar();}
	while(s >= '0' && s <= '9') {x = (x<<3) + (x<<1) + (s^48);s = getchar();}
	return f * x;
}
void putpos(LL x) {if(!x)return ;putpos(x/10);putchar((x%10)^48);};
void putnum(LL x) {
	if(!x) {putchar('0');return ;}
	if(x<0) putchar('-'),x = -x;
	return putpos(x);
}
void AIput(LL x,int c) {putnum(x);putchar(c);}

int n,m,s,o,k;
int S,T,cnt;
int nr[MAXN<<2];
int p[MAXN][MAXN];
int d[MAXN*MAXN];
int hd2[MAXN*MAXN];
struct itm{
	int hd[MAXN*MAXN],v[MAXM<<1],nx[MAXM<<1],w[MAXM<<1],cne;
	int rev[MAXM<<1];
	itm(){memset(hd,0,sizeof(hd));cne = 0;}
	int ins(int x,int y,int z) {
		nx[++ cne] = hd[x]; v[cne] = y; w[cne] = z; hd[x] = cne;
		nx[++ cne] = hd[y]; v[cne] = x; w[cne] = 0; hd[y] = cne;
		rev[cne] = cne-1; rev[cne-1] = cne; return cne-1;
	}
	bool bfs() {
		for(int i = 1;i <= cnt;i ++) {
			d[i] = -1; hd2[i] = hd[i];
		}
		queue<int> b;
		b.push(S); d[S] = 0;
		while(!b.empty()) {
			int t = b.front();b.pop();
			if(t == T) return 1;
			for(int i = hd[t];i;i = nx[i]) {
				if(d[v[i]] < 0 && w[i] > 0) {
					d[v[i]] = d[t]+1;
					b.push(v[i]);
				}
			}
		}return 0;
	}
	LL dfs(int x,LL mxf) {
		if(x == T) return mxf;
		LL nm = 0;
		for(int i = hd2[x];i;i = nx[i]) {
			if(d[v[i]] == d[x] + 1 && w[i] > 0) {
				LL ad = dfs(v[i],min(mxf-nm,(LL)w[i]));
				nm += ad; w[i] -= ad; w[rev[i]] += ad;
				if(nm == mxf) break;
			}
			hd2[x] = nx[i];
		}
		return nm;
	}
	LL dinic() {
		LL ans = 0;
		while(bfs()) {
			ans += dfs(S,(LL)1e18);
//			printf("ans: %lld\n",ans);
		}
		return ans;
	}
};
itm A,B;
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n = read();m = read();int Q = read();
	S = 1; T = 2; cnt = 2;
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j <= m;j ++) {
			p[i][j] = ++ cnt;
		}
	}
	for(int i = 1;i < n;i ++) {
		for(int j = 1;j <= m;j ++) {
			s = read();
			B.ins(p[i][j],p[i+1][j],s);
			B.ins(p[i+1][j],p[i][j],s);
		}
	}
	for(int i = 1;i <= n;i ++) {
		for(int j = 1;j < m;j ++) {
			s = read();
			B.ins(p[i][j],p[i][j+1],s);
			B.ins(p[i][j+1],p[i][j],s);
		}
	}
	int cc = 0;
	for(int i = 1;i <= m;i ++) nr[++ cc] = p[1][i];
	for(int i = 1;i <= n;i ++) nr[++ cc] = p[i][m];
	for(int i = m;i > 0;i --) nr[++ cc] = p[n][i];
	for(int i = n;i > 0;i --) nr[++ cc] = p[i][1];
	while(Q --) {
		A = B;
		k = read();
		for(int i = 1;i <= k;i ++) {
			s = read();o = nr[read()];
			int op = read();
			if(op) {
				A.ins(S,o,s);
			}
			else A.ins(o,T,s);
		}
		AIput(A.dinic(),'\n');
	}
	return 0;
}
