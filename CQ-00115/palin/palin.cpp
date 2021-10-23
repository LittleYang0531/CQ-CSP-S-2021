#include <cstdio>
#define abs(x) ((x) >= 0 ? (x) : (-(x)))
int t, n, a[1000005], b[1000005];
char s[1000005];
bool flag;
bool check() {
	int l = 1, r = 2 * n;
	for(int i = 1; i <= 2 * n; ++i)
		if(s[i] == 'L') b[i] = a[l++];
		else b[i] = a[r--];
	for(int i = 1; i <= n; ++i) if(b[i] != b[2 * n - i + 1]) return false;
	return true;
}
void dfs(int p) {
	if(flag) return;
	if(p == 2 * n + 1) {
		if(check()) {
			puts(s + 1);
			flag = true;
		}
		return;
	}
	s[p] = 'L';
	dfs(p + 1);
	s[p] = 'R';
	dfs(p + 1);
}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n; ++i) scanf("%d", &a[i]);
		s[2 * n + 1] = '\0';
		flag = false;
		dfs(1);
		if(!flag) puts("-1");
	}
	return 0;
}
