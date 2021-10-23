#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define pii pair <int , int>
#define mp make_pair
#define fs first
#define sc second
using namespace std;
typedef long long LL;

template <typename T>
void read(T &x) {
	T f=1;x=0;char s=getchar();
	while(s<'0'||s>'9') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s-'0');s=getchar();}
	x *= f;
}

template <typename T>
void write(T x , char s='\n') {
	if(!x) {putchar('0');putchar(s);return;}
	if(x<0) {putchar('-');x=-x;}
	T tmp[25]={},t=0;
	while(x) tmp[t++]=x%10,x/=10;
	while(t-->0) putchar(tmp[t]+'0');
	putchar(s); 
}

const int MAXN = 1e6 + 5;
const LL inf = 1e18;

LL head[MAXN] , to[MAXN << 1] , nxt[MAXN << 1] , edge[MAXN << 1] , cnt;
void add(int u , int v , LL w) {
	nxt[++cnt] = head[u];head[u] = cnt;to[cnt] = v;edge[cnt] = w;
	nxt[++cnt] = head[v];head[v] = cnt;to[cnt] = u;edge[cnt] = 0;
}

int cur[MAXN] , d[MAXN] , s , t , num;
bool bfs() {
	for (int i = 1; i <= num; ++i) d[i] = 0 , cur[i] = head[i];
	d[s] = 1;
	queue <int> q;
	q.push(s);
	while(!q.empty()) {
		int x = q.front();
		q.pop();
		for (int i = head[x]; i; i = nxt[i]) {
			int v = to[i];
			if(d[v] || !edge[i]) continue;
			d[v] = d[x] + 1;
			if(v == t) return true;
			q.push(v);
		}
	}
	return false;
}

LL Dinic(int x , LL flow) {
	if(x == t) return flow;
	LL rest = flow;
	for (int i = cur[x]; i && rest; i = nxt[i]) {
		cur[x] = i;
		int v = to[i];
		if(d[v] != d[x] + 1 || !edge[i]) continue;
		LL k = Dinic(v , min(edge[i] , rest));
		if(!k) d[v] = 0;
		edge[i] -= k;
		edge[i ^ 1] += k;
		rest -= k;
	}
	return flow - rest;
}

int id[505][505] , D[505][505] , R[505][505];

int main() {
	freopen("traffic.in" , "r" , stdin);
	freopen("traffic.out" , "w" , stdout);
	cnt = 1;
	int n , m , T;
	read(n),read(m),read(T);
	for (int i = 1; i <= n; ++i) for (int j = 1; j <= m; ++j) id[i][j] = ++num;
	for (int i = 1; i < n; ++i) {
		for (int j = 1; j <= m; ++j) {
			read(D[i][j]);
		}
	}
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j < m; ++j) {
			read(R[i][j]);
		}
	}
	s = ++num;
	t = ++num;
	while(T -- > 0) {
		for (int i = 1; i < n; ++i) {
			for (int j = 1; j <= m; ++j) {
				add(id[i][j] , id[i + 1][j] , D[i][j]);
				add(id[i + 1][j] , id[i][j] , D[i][j]);
			}
		}
		for (int i = 1; i <= n; ++i) {
			for (int j = 1; j < m; ++j) {
				add(id[i][j] , id[i][j + 1] , R[i][j]);
				add(id[i][j + 1] , id[i][j] , R[i][j]);
			}
		}
		int k;read(k);
		for (int i = 1; i <= k; ++i) {
			int val , p , T;
			read(val),read(p),read(T);
			pii pos;
			if(p <= m) pos = mp(1 , p);
			else if(p <= m + n) pos = mp(p - m , m);
			else if(p <= 2 * m + n) pos = mp(n , 2 * m + n - p + 1);
			else pos = mp(2 * m + 2 * n - p + 1  , 1);
			if(T & 1) add(s , id[pos.fs][pos.sc] , val);
			else add(id[pos.fs][pos.sc] , t , val);
		}
		LL ans = 0;
		while(bfs()) 
			ans += Dinic(s , inf);
		write(ans);
		cnt = 1;
		for (int i = 1; i <= num; ++i) head[i] = 0;
	}
	
	return 0;
}
