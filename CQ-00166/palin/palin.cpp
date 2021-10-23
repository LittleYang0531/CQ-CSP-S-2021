#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define pr pair <int, int>
#define mr make_pair
using namespace std;
const int MAXN = 1e6 + 5;
int T, n, a[MAXN], tmp[MAXN], f;
char s[MAXN], ans[MAXN];
void dfs(int x, int l, int r) {
	if(f) return;
	if(x == 2 * n + 1) {
		for(int i = 1; i <= n; i ++) if(tmp[i] != tmp[2 * n - i + 1]) return;
		for(int i = 1; i <= 2 * n; i ++) ans[i] = s[i];
		f = 1; return;
	}
	tmp[x] = a[l]; s[x] = 'L'; dfs(x + 1, l + 1, r);
	tmp[x] = a[r]; s[x] = 'R'; dfs(x + 1, l, r - 1);
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while(T --) {
		scanf("%d", &n); f = 0;
		for(int i = 1; i <= 2 * n; i ++) scanf("%d", &a[i]);
		dfs(1, 1, 2 * n);
		if(f) {
			for(int i = 1; i <= 2 * n; i ++) printf("%c", ans[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}
