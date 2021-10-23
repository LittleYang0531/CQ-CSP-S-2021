//亲爱的CCF， 当你看到这句话时， 我知道你肯定已经被骂过上千次了
//但我还是要骂一句， 你TM第一题码量这么打是吃了什么东西吗？ 
#include <cstdio>
#include <algorithm>
using namespace std;

#define MAXN 200000
#define L(p) (p << 1)
#define R(p) ((p << 1) | 1)
#define make_mid(l,r) int mid = (l + r) >> 1

pair <pair <int, int>, int> s1[MAXN + 5], s2[MAXN + 5];
int sl1[MAXN + 5], sl2[MAXN + 5];
int sa[MAXN + 5], sb[MAXN + 5];
struct node {
	int v;
	int smax;
	int h, t;
}sum[3][(MAXN << 4) + 5];

void build (int p, int l, int r) {
	sum[0][p].h = l;
	sum[0][p].t = r;
	sum[1][p].h = l;
	sum[1][p].t = r;
	if (l == r) {
		return;
	}
	make_mid (l, r);
	build (L(p), l, mid);
	build (R(p), mid + 1, r);
}
void change (int x, int p, int l, int v) {
	if (sum[x][p].h == sum[x][p].t) {
		sum[x][p].v += v;
		sum[x][p].smax += v;
		
		return;
	}
	make_mid (sum[x][p].h, sum[x][p].t);
	if (l <= mid) {
		change (x, L(p), l, v);
	}
	else {
		change (x, R(p), l, v);
	}
	sum[x][p].v = sum[x][L(p)].v + sum[x][R(p)].v;
	sum[x][p].smax = max (sum[x][L(p)].smax, sum[x][L(p)].v + sum[x][R(p)].smax);
}
int ask (int x, int p, int num) {
	if (sum[x][p].h == sum[x][p].t) {
		return sum[x][p].h;
	}
	if (sum[x][L(p)].t > sum[x][L(p)].smax + num) {
		return ask (x, L(p), num);
	}
	else {
		return ask (x, R(p), num + sum[x][L(p)].v);
	}
}

int main () {
	freopen ("airport.in", "r", stdin);
	freopen ("airport.out", "w", stdout);
	
	int n, m1, m2;
	
	scanf ("%d %d %d", &n, &m1, &m2);
	for (int i = 1; i <= m1; i ++) {
		scanf ("%d %d", &s1[i * 2 - 1].first.first, &s1[i * 2].first.first);
		s1[i * 2 - 1].first.second = i;
		s1[i * 2 - 1].second = 1;
		s1[i * 2].first.second = i;
		s1[i * 2].second = -1;
	}
	sort (s1 + 1, s1 + 1 + m1 * 2);
	for (int i = 1; i <= m2; i ++) {
		scanf ("%d %d", &s2[i * 2 - 1].first.first, &s2[i * 2].first.first);
		s2[i * 2 - 1].first.second = i;
		s2[i * 2 - 1].second = 1;
		s2[i * 2].first.second = i;
		s2[i * 2].second = -1;
	}
	sort (s2 + 1, s2 + 1 + m2 * 2);
	build (1, 1, max (m1, m2));
	for (int i = 1; i <= m1 * 2; i ++) {
		if (s1[i].second == -1) {
			change (1, 1, sl1[s1[i].first.second], -1);
		}
		else {
			sl1[s1[i].first.second] = ask (1, 1, 0);
			sa[sl1[s1[i].first.second]] ++;
			change (1, 1, sl1[s1[i].first.second], 1);
		}
	}
	for (int i = 1; i <= m2 * 2; i ++) {
		if (s2[i].second == -1) {
			change (1, 1, sl2[s2[i].first.second], -1);
		}
		else {
			sl2[s2[i].first.second] = ask (1, 1, 0);
			sb[sl2[s2[i].first.second]] ++;
			change (1, 1, sl2[s2[i].first.second], 1);
		}
	}
	for (int i = 1; i <= n; i ++) {
		sa[i] += sa[i - 1];
	}
	for (int i = 1; i <= n; i ++) {
		sb[i] += sb[i - 1];
	}
	
	int smax = 0;
	
	for (int i = 0; i <= n; i ++) {
		smax = max (smax, sa[i] + sb[n - i]);
	}
	printf ("%d", smax);
	
	return 0;
}
