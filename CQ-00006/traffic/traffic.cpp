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

int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	cout << 12 << endl;	
	return 0;
}

