#include <cstdio>
const int MAXN = 1e6 + 5;
int T, n, N, a[MAXN], b[MAXN], tot[MAXN];
char ans[MAXN];
bool f;
void dfs(int k, int l, int r) {
	if(k > N) {
		for(int i = 1; i <= N; i++) putchar(ans[i]);
		putchar('\n'), f = true; return;
	}
	if(k > n) {
		if(a[l] == b[N - k + 1]) ans[k] = 'L', dfs(k + 1, l + 1, r);
		if(f) return;
		if(a[r] == b[N - k + 1]) ans[k] = 'R', dfs(k + 1, l, r - 1);
	} else {
		if(!tot[a[l]]) ans[k] = 'L', tot[a[l]]++, b[k] = a[l], dfs(k + 1, l + 1, r), tot[a[l]]--;
		if(f) return;
		if(!tot[a[r]]) ans[k] = 'R', tot[a[r]]++, b[k] = a[r], dfs(k + 1, l, r - 1), tot[a[r]]--;
	}
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n), N = n << 1, f = false;
		for(int i = 1; i <= N; i++) scanf("%d", &a[i]);
		dfs(1, 1, N);
		if(!f) printf("-1\n");
	}
	return 0;
}
