#include <bits/stdc++.h>
using namespace std;
int T, n, flag = 0;
int a[1000005];
string s, s1;
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for (int i = 1;i <= n * 2;i++) {
			scanf("%d", &a[i]);
		}
		if (n == 1) {
			printf("LL\n");
		} else if (n == 2) {
			printf("LRRL\n");
		} else {
			printf("-1\n");
		}
	}
	return 0;
}
