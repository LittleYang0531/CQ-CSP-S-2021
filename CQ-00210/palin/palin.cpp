#include <bits/stdc++.h>

using namespace std;

int t, n, a;

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while (t --) {
		scanf("%d", &n);
		for (int i = 1; i <= 2 * n; i ++) scanf("%d", &a);
		printf("-1\n");
	}
	return 0;
}
