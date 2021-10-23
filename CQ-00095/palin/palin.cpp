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

const int Maxn = 5 * 1e5;

int t, n;
int a[Maxn * 2 + 5], idx[Maxn * 2 + 5], each[Maxn * 2 + 5];

string ans;
bool flag;
int vis[Maxn * 2 + 5];
bool check (int Index, int step) {
	if (vis[each[Index]] == 0) return 1;
	if (vis[each[Index]] == 2 * n - step + 1) return 1;
	else return 0;
}
void dfs (int step, int l, int r, string Now) {
	if (flag) return;
	if (step > n * 2) {
		flag = 1;
		ans = Now;
		return;
	}
	if (check (l, step)) {
		vis[l] = step;
		dfs (step + 1, l + 1, r, Now + 'L');
		vis[l] = 0;
	}
	if (check (r, step)) {
		vis[r] = step;
		dfs (step + 1, l, r - 1, Now + 'R');
		vis[r] = 0;
	}
}

int main () {
	freopen ("palin.in", "r", stdin);
	freopen ("palin.out", "w", stdout);
	read (t);
	while (t--) {
		read (n);
		
		flag = 0;
		for (int i = 1; i <= n * 2; i++)
			idx[i] = each[i] = vis[i] = 0;
		
		for (int i = 1; i <= n * 2; i++) {
			read (a[i]);
			if (idx[a[i]]) {
				each[i] = idx[a[i]];
				each[idx[a[i]]] = i;
			}
			else
				idx[a[i]] = i;
		}
		
		string s;
		dfs (1, 1, n * 2, s);
		if (flag) cout << ans << endl; 
		else cout << "-1" << endl; 
	}
	return 0;
}

