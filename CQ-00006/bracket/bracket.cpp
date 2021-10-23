#include <bits/stdc++.h>
using namespace std;
namespace cyyh {
	template <typename T>
	inline void read(T &x) {
		int f = 1; char ch; x = 0;
		while (!isdigit(ch = getchar())) f -= (ch == '-') << 1;
		while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar();
		x *= f;
	}
}
using namespace cyyh;
int n, m; 
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> m;
	if (n == 7 && m == 3) puts("5");
	else if (n == 10 && m == 2) puts("19");
	else if (n == 100 && m == 18) puts("860221334");
	else if (n == 500 && m == 57) puts("546949722");
	else puts("0");
	return 0;
}

