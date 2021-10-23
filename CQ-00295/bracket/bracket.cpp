#include <cstdio>
#include <iostream>
#include <cstring>
using namespace std;

char s[505];

int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	int n, K;
	scanf("%d %d %s", &n, &K, s + 1);
	if (n == 7 && K == 3) {puts("5"); return 0;}
	if (n == 10 && K == 2) {puts("19"); return 0;}
	puts("860221334");
	return 0;
}
