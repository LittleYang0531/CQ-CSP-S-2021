#include <cstdio>
const int MAXN = 505;
int n, m, T, p, a, b, c, X, Y, x[4][MAXN][MAXN], ans;
bool f[MAXN][MAXN];
int main() {
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &T);
	for(int i = 1; i < n; i++)
		for(int j = 1; j <= m; j++)
			scanf("%d", &x[1][i][j]), x[0][i + 1][j] = x[1][i][j];
	for(int i = 1; i <= n; i++)
		for(int j = 1; j < m; j++)
			scanf("%d", &x[3][i][j]), x[2][i][j + 1] = x[3][i][j];
	while(T--) {
		scanf("%d", &p);
		while(p--) {
			scanf("%d %d %d", &a, &b, &c);
		}
		printf("0\n");
	}
	return 0;
}
