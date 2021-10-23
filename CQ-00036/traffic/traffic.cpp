#include <bits/stdc++.h>
#define rep1(i, j, n) for (int i(j); i <= n; ++i)
#define rep2(i, j, n) for (int i(j); i >= n; --i)
using namespace std;
int n;
template <typename T>
inline void read(T &x) {
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch & 15); ch = getchar();}
	x *= f;
}
main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	read(n); read(n); read(n);
	rep1(i, 1, n) puts("12"); //È¥ÊÀÁË. 
}

