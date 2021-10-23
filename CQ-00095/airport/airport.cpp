#include <queue>
#include <cmath>
#include <vector>
#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define PII pair <int, int>
#define MP(x,y) make_pair (x, y)
#define rep(i,j,k) for (int i = (j); i <= (k); i++)
#define per(i,j,k) for (int i = (j); i >= (k); i--)
#define fi first
#define se second

template <typename T> T Max (T x, T y) { return x > y ? x : y; }
template <typename T> T Min (T x, T y) { return x < y ? x : y; }
template <typename T> T Abs (T x) { return x > 0 ? x : -x; }
template <typename T>
void read (T &x) {
	x = 0; T f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar ();
	}
	x *= f;
}
template <typename T>
void write (T x) {
	if (x < 0) {
		x = -x;
		putchar ('-');
	}
	if (x < 10) {
		putchar (x + '0');
		return;
	}
	write (x / 10);
	putchar (x % 10 + '0');
}
template <typename T>
void print (T x, char ch) {
	write (x); putchar (ch);
}

const int Maxn = 2 * 1e5;

int n, m1, m2;
int numa[Maxn + 5], numb[Maxn + 5];
int baka[Maxn + 5], bakb[Maxn + 5];
int prea[Maxn + 5], preb[Maxn + 5];
PII a[Maxn + 5], b[Maxn + 5];

int BIT[Maxn + 5];
int lowbit (int x) { return x & -x; }
void Clear () {
	for (int i = 1; i <= Maxn; i++)
		BIT[i] = 0;
}
void Update (int Index, int x) {
	for (int i = Index; i <= Maxn; i += lowbit (i))
		BIT[i] += x;
}
int Query (int Index) {
	int res = 0;
	for (int i = Index; i >= 1; i -= lowbit (i))
		res += BIT[i];
	return res;
}

int main () {
	freopen ("airport.in", "r", stdin);
	freopen ("airport.out", "w", stdout);
	
	read (n); read (m1); read (m2);
	for (int i = 1; i <= m1; i++) {
		read (a[i].fi); read (a[i].se);
	}
	for (int i = 1; i <= m2; i++) {
		read (b[i].fi); read (b[i].se);
	}
	sort (a + 1, a + 1 + m1);
	sort (b + 1, b + 1 + m2);
	
	priority_queue <PII, vector <PII>, greater <PII> > p;
	Clear (); while (p.size ()) p.pop ();
	for (int i = 1; i <= m1; i++) {
		while (p.size () && p.top ().fi < a[i].fi) {
			PII tmp = p.top (); p.pop ();
			Update (numa[tmp.se], -1);
		}
		
		int l = 0, r = n + 1;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if (Query (mid) < mid) r = mid;
			else l = mid;
		}
		numa[i] = r;
		Update (numa[i], 1);
		p.push (MP (a[i].se, i));
		baka[numa[i]]++;
	}
	
	Clear (); while (p.size ()) p.pop ();
	for (int i = 1; i <= m2; i++) {
		while (p.size () && p.top ().fi < b[i].fi) {
			PII tmp = p.top (); p.pop ();
			Update (numb[tmp.se], -1);
		}
		
		int l = 0, r = n + 1;
		while (l + 1 < r) {
			int mid = (l + r) >> 1;
			if (Query (mid) < mid) r = mid;
			else l = mid;
		}
		numb[i] = r;
		Update (numb[i], 1);
		p.push (MP (b[i].se, i));
		bakb[numb[i]]++;
	}
	
	for (int i = 1; i <= n; i++)
		prea[i] = prea[i - 1] + baka[i];
	for (int i = 1; i <= n; i++)
		preb[i] = preb[i - 1] + bakb[i];
	
	int res = 0;
	for (int i = 0; i <= n; i++) {
		res = Max (res, prea[i] + preb[n - i]);
	}
	write (res);
	return 0;
}
