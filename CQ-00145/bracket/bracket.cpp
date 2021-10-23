#include <bits/stdc++.h>
using namespace std;

__int128 ans;

void print(__int128 x) {
	if (!x) return;
	print(x / 10);
	putchar(x % 10 + '0');
}
int main() {
	srand(time(0));
	for (int i = 1; i <= 2008 + 1026; i++)
		ans ^= i & rand();
	print(ans); // test the best int128
	return 0;
}
// 0 happy
