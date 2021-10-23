#include <bits/stdc++.h>

const int N = 500000;

char ans[N + 5];

int a[2*N + 5], n;
bool check(int Lp, int Lq, int Rp, int Rq) {
	int k = 2;
	while (Lp <= Lq && Rp <= Rq) {
		if (a[Lp] == a[Rp]) {
			ans[k] = 'L', ans[n - k + 1] = 'R', k++, Lp++, Rp++;
		} else if (Lp != Lq && a[Lp] == a[Lq]) {
			ans[k] = ans[n - k + 1] = 'L', k++, Lp++, Lq--;
		} else if (a[Rq] == a[Lq]) {
			ans[k] = 'R', ans[n - k + 1] = 'L', k++, Lq--, Rq--;
		} else if (Rp != Rq && a[Rq] == a[Rp]) {
			ans[k] = ans[n - k + 1] = 'R', k++, Rp++, Rq--;
		} else return false;
	}
	while (Lp <= Lq) {
		if (a[Lp] != a[Lq]) return false;
		ans[k] = ans[n - k + 1] = 'L', k++, Lp++, Lq--;
	}
	while (Rp <= Rq) {
		if (a[Rq] != a[Rp]) return false;
		ans[k] = ans[n - k + 1] = 'R', k++, Rp++, Rq--;
	}
	assert (k == (n >> 1) + 1);
	return true;
}
bool checkL() {
	ans[1] = 'L';
	for (int i = n; i > 1; i--) if (a[1] == a[i])
		return check(1 + 1, i - 1, i + 1, n);
	assert (false); return false;
}
bool checkR() {
	ans[1] = 'R';
	for (int i = 1; i < n; i++) if (a[n] == a[i])
		return check(1, i - 1, i + 1, n - 1);
	assert (false); return false;
}
void solve() {
	scanf("%d", &n), n <<= 1;
	for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
	
	ans[n] = 'L', ans[n + 1] = 0;
	if (checkL() || checkR()) puts(ans + 1);
	else puts("-1");
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	
	int T; scanf("%d", &T);
	while (T--) solve();
}
