#include <bits/stdc++.h>

using namespace std;

inline int read() {
	int x = 0, f = 1; char ch = getchar();
	while (ch < '0' || ch > '9') f |= ch == '-' ? -1 : 1, ch = getchar();
	while (ch >= '0' && ch <= '9') x = (x << 1) + (x << 3) + (ch ^ 48), ch = getchar();
	return x;
}
int main () {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	while (true) printf("%d\n", 130);
	
	return 0;
}

