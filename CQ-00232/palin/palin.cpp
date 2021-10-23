#include <cstdio>
#include <algorithm>
#include <iostream>
using namespace std;

const int N = 110;

int a[N], b[N], opt[N], n;

bool dfs(int Now, int l, int r) {
	if(Now == n + 1) {
		for(int i = 1, j = n; i <= j; ++i, --j) {
			if(b[i] != b[j]) {
				return false;
			}
		}
		for(int i = 1; i <= n; ++i) {
			if(opt[i] == 0) {
				putchar('L');
			} else {
				putchar('R');
			}
		}
		puts("");
		return true;
	}
	opt[Now] = 0;
	b[Now] = a[l];
	if(dfs(Now + 1, l + 1, r)) {
		return true;
	}
	opt[Now] = 1;
	b[Now] = a[r];
	if(dfs(Now + 1, l, r - 1)) {
		return true;
	}
	return false;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int Case;
	scanf("%d", &Case);
	while(Case -- ) {
		scanf("%d", &n);
		n <<= 1;
		for(int i = 1; i <= n; ++i) {
			scanf("%d", &a[i]);
		}
		if(!dfs(1, 1, n)) {
			puts("-1");
		}	
	}
	return 0;
}
