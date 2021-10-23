#include <cstdio>
#include <iostream>
using namespace std;
const int MAXN = 2e5 + 5;

int n, m1, m2, ans;
int a1[MAXN], b1[MAXN];
int a2[MAXN], b2[MAXN];
int aip[MAXN], tot, last;

int get_res(int k1, int k2) {
	int res = 0, t = 0;
	tot = 0;
	for (int i = 1; i <= m1; i++) {
		int k = 0;
		for (int j = 1; j <= tot; j++)
			if (a1[i] > aip[j]) {
				k = j;
				break; // jianzhi
			}
		if (k) aip[k] = b1[i], res++;
		else if (tot < k1) aip[++tot] = b1[i], res++;
	}
	t = res;
	if (k1 && res + last <= ans) return 0; // jianzhi
	tot = 0;
	for (int i = 1; i <= m2; i++) {
		int k = 0;
		for (int j = 1; j <= tot; j++)
			if (a2[i] > aip[j]) {
				k = j;
				break; // jianzhi
			}
		if (k) aip[k] = b2[i], res++;
		else if (tot < k2) aip[++tot] = b2[i], res++;
	}
	last = res - t; // use "last" to get higher score
	return res;
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for (int i = 1; i <= m1; i++)
		scanf("%d %d", &a1[i], &b1[i]);
	for (int i = 1; i <= m2; i++)
		scanf("%d %d", &a2[i], &b2[i]);
	for (int i = 0; i <= n; i++) {
		int x = get_res(i, n - i);
		cout << x << endl;
		#define max(a, b) a > b ? a : b
		ans = max(ans, x);
	}
	printf("%d\n", ans);
	return 0;
}
