//傻逼ccf， 闲着没事考什么KM
//GM， 我对不起你， 我把KM给忘了
//哦， 好像网络流也可以做来着，可是我TM不会 
//哇，我会40分呀！！！（但真的好难打） 
//qwq, qaq, qvq 
//QwQ, QaQ, QvQ
//先把纯暴力打完吧。 
//我*， 这个题目是神马玩意， 程序名复制不了i？？？ 
#include <cstdio>
#include <algorithm>
#include <cmath>
#include <ctime>
using namespace std;

#define MAXN 3500
#define INF 0x3f3f3f3f3f3f3f3f

struct node {
	int ed;
	long long v;
	node *next;
}*s1[MAXN + 5], *s2[MAXN + 5];
bool color[MAXN + 5];
int n, m;

void push1 (int x, int y, long long z) {
	node *p = new node;
	
	p->next = s1[x];
	p->v = z;
	p->ed = y;
	s1[x] = p;
} 
void push2 (int x, int y, long long z) {
	node *p = new node;
	
	p->next = s2[x];
	p->v = z;
	p->ed = y;
	s2[x] = p;
} 

int f (int x, int n, int m) {
	if (x <= m) {
		return x + 2 * n + 2 * m;
	}
	else if (x <= m + n) {
		return (x - m) * m + 2 * n + 2 * m;
	}
	else if (x <= 2 * m + n) {
		return 2 * m + n - x + 1 + (n - 1) * m + 2 * n + 2 * m;
	}
	else {
		return (2 * m + 2 * n - x) * m + 1 + 2 * n + 2 * m;
	}
}

long long dfs (int l) {
	if (2 * n + 2 * m >= l) {
		return 0;
	}
	else {
		if (n * m > 25) {
			long long sum = 0;
			long long smin = INF;
			
			color[l] = rand () & 1;
			for (node *i = s1[l]; i; i = i->next) {
				if (color[i->ed] != color[l]) {
					sum += i->v;
				}
			}
			for (node *i = s2[l]; i; i = i->next) {
				if (color[i->ed] != color[l]) {
					sum += i->v;
				}
			}
			
			return sum + dfs (l - 1);
		}
		else {
			long long sum = 0;
			long long smin = INF;
			
			color[l] = 0;
			for (node *i = s1[l]; i; i = i->next) {
				if (color[i->ed] != color[l]) {
					sum += i->v;
				}
			}
			for (node *i = s2[l]; i; i = i->next) {
				if (color[i->ed] != color[l]) {
					sum += i->v;
				}
			}
			smin = min (smin, sum + dfs (l - 1));
			color[l] = 1;
			sum = 0;
			for (node *i = s1[l]; i; i = i->next) {
				if (color[i->ed] != color[l]) {
					sum += i->v;
				}
			}
			for (node *i = s2[l]; i; i = i->next) {
				if (color[i->ed] != color[l]) {
					sum += i->v;
				}
			}
			smin = min (smin, sum + dfs (l - 1));
			
			return smin;
		}
	}
}

int main () {
	freopen ("traffic.in", "r", stdin);
	freopen ("traffic.out", "w", stdout);
	
	int t;
	
	srand (time (0));
	scanf ("%d %d %d", &n, &m, &t);
	for (int i = 1; i < n; i ++) {
		for (int j = 1; j <= m; j ++) {
			long long v;
			int x = 2 * n + 2 * m + (i - 1) * m + j, y = 2 * n + 2 * m + i * m + j;
			
			scanf ("%lld", &v);
			push1 (x, y, v);
		}
	}
	for (int i = 1; i <= n; i ++) {
		for (int j = 1; j < m; j ++) {
			long long v;
			int x = 2 * n + 2 * m + (i - 1) * m + j, y = 2 * n + 2 * m + (i - 1) * m + j + 1;
			
			scanf ("%lld", &v);
			push1 (x, y, v);
		}
	}
	while (t --) {
		for (int i = 2 * n + 2 * m + 1; i <= 2 * n + 2 * m + n * m; i ++) {
			s2[i] = 0;
		}
		
		int k;
		
		scanf ("%d", &k);
		for (int i = 1; i <= k; i ++) {
			int x, y;
			long long v;
			int col;
			
			scanf ("%lld %d %d", &v, &x, &col);
			color[x] = col;
			y = f (x, n, m);
			push2 (y, x, v);
		}
		if (n * m > 25) {
			long long smin = INF;
			
			for (int i = 1; i <= 200; i ++) {
				smin = min (smin, dfs (2 * n + 2 * m + n * m));
			}
			printf ("%lld\n", smin);
		}
		else {
			printf ("%lld\n", dfs (2 * n + 2 * m + n * m));
		}
	}
	
	return 0;
}
