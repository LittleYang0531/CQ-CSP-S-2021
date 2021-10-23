#include <stdio.h>
#include <cstring>
using namespace std;
const int N = 500005;

int T, n;
bool flag;
int a[N], b[N];
char temp[N], ans[N];

void dfs(int x, int l, int r) {
	if (l > r) {
		flag = true;
		return;
	}
	if (flag) return;
	int pos = n - x + 1;
	if (pos < x) {
		if (b[pos] == a[l]) {
			temp[x] = 'L', b[x] = a[l];
			dfs(x + 1, l + 1, r);
			if (flag) return;
		} 
		if (b[pos] == a[r]) {
			temp[x] = 'R', b[x] = a[r];
			dfs(x + 1, l, r - 1);
			if (flag) return;
		}
	} else {
		temp[x] = 'L', b[x] = a[l];
		dfs(x + 1, l + 1, r);
		if (flag) return;
		temp[x] = 'R', b[x] = a[r];
		dfs(x + 1, l, r - 1);
		if (flag) return;
	}
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while (T--) {
		flag = false;
		scanf("%d", &n);
		n <<= 1;
		for (int i = 1; i <= n; i++) scanf("%d", &a[i]);
		dfs(1, 1, n);
		if (!flag) puts("-1");
		else {
			for (int i = 1; i <= n; i++) printf("%c", temp[i]);
			puts("");
		}
	}
	return 0;
}

