#include <bits/stdc++.h>
using namespace std;

int n, _2n, a[45], b[45];
bool flag;
char ans[45];

bool check() {
	for(int i = 1; i <= n; i++) {
		if(b[i] != b[_2n + 1 - i]) return false;
	}
	return true;
}

void dfs(int t, int l, int r) {
	if(flag) return;
	if(t == _2n + 1) {
		if(check() && !flag) {
			printf("%s\n", ans + 1);
			flag = 1;
		}
		return;
	}
	if(l > _2n || r < 0 || r < l) return;
	//L
	ans[t] = 'L';
	b[t] = a[l];
	dfs(t + 1, l + 1, r);
	//R
	ans[t] = 'R';
	b[t] = a[r];
	dfs(t + 1, l, r - 1);
	//»ØËÝ 
	ans[t] = 0;
	b[t] = 0; 
	return;
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		ans[0] = 0;
		flag = 0;
		scanf("%d", &n);
		_2n = 2 * n;
		for(int i = 1; i <= _2n; i++) scanf("%d", &a[i]);
		dfs(1, 1, _2n);
		if(!flag) printf("-1\n");
	}
	return 0;
}

/*
2 
5
4 1 2 4 5 3 1 2 3 5
3 
3 2 1 2 1 3

1
5
4 1 2 4 5 3 1 2 3 5

1
20
5 20 6 12 13 18 9 17 2 7 7 18 1 11 10 15 4 6 17 19 14 10 14 13 1 16 8 3 12 8 19 20 4 16 5 3 9 2 15 11
*/
