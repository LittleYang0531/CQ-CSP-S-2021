#include <cstdio>

int n, a[25], b[25], cnt;

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T;
	scanf("%d", &T);
	while (T --) {
		int n;
		bool penis = true;
		scanf("%d", &n);
		n *= 2;
		for (int i = 1; i <= n; ++ i) scanf("%d", a + i);
		for (int S = 0; S < 1 << n; ++ S) {
			for (int i = 0, p = 1, q = n; i < n; ++ i)
				if (S & 1 << n - i - 1) b[i + 1] = a[p], p ++;
				else b[i + 1] = a[q], q --;
			bool flag = true;
			for (int i = 1; i <= n >> 1; ++ i)
				if (b[i] != b[n + 1 - i]) {flag = false; break;}
			if (flag) {
				penis = false;
				for (int i = n - 1; i; -- i) putchar(S & 1 << i ? 'L' : 'R');
				putchar('\n');
				break;
			}
		}
		if (penis) puts("-1");
	}
	return 0;
}
