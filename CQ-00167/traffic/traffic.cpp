#include <bits/stdc++.h>
using namespace std;
int t,n,m,k,tot,ans,g_po,n_to,a[505][505],h[260000],color[260000];
struct Doge {
	int x,y,z;
} ma[550000];
int Dw(int x) {
	if (x <= m) {
		n_to = a[1][x];
		return a[0][x];
	} else if (x <= n + m) {
		n_to = a[x - m][m];
		return a[x - m][m + 1];
	} else if (x <= 2 * m + n) {
		n_to = a[n][2 * m + n + 1 - x];
		return a[n + 1][2 * m + n + 1 - x];
	} else {
		n_to = a[2 * m + 2 * n + 1 - x][1];
		return a[2 * m + 2 * n + 1 - x][0];
	}
}
void add(int x,int y,int z) {
	ma[++ tot].x = h[x];
	h[x] = tot;
	ma[tot].y = y;
	ma[tot].z = z;
}
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for (int i = 0; i <= n + 1; i ++)
		for (int j = 0 ; j <= m + 1; j ++)
			a[i][j] = ++ tot;
	for (int i = 0; i <= n + 1; cout << endl,i ++)
		for (int j = 0 ; j <= m + 1; j ++)
			cout << a[i][j] << " ";
	tot = 0;
	for (int i = 1; i < n; i ++)
		for (int j = 1; j <= m; j ++) {
			int x;
			scanf("%d",&x);
			add(a[i][j],a[i + 1][j],x);
			add(a[i + 1][j],a[i][j],x);
		}
	for (int i = 1; i <= n; i ++)
		for (int j = 1; j < m; j ++) {
			int x;
			scanf("%d",&x);
			add(a[i][j],a[i][j + 1],x);
			add(a[i][j + 1],a[i][j],x);
		}
	while (t --) {
		memset(ma,0,sizeof(ma));
		memset(h,0,sizeof(h));
		memset(color,0x3f,sizeof(color));
		ans = 0;
		scanf("%d",&k);
		for (int i = 1; i <= k; i ++) {
			int x,y,z;
			scanf("%d%d%d",&x,&y,&z);
			y = Dw(y);
			color[y] = z;
			add(y,n_to,x);
			add(n_to,y,x);
		}
		while (g_po < n * m)
			for (int i = 1; i <= n; i ++)
				for (int j = 1; j <= m; j++) {
					int x = a[i][j];
					if (color[x] >= 0x3f3f3f3f) {
						int w_sum = 0,b_sum = 0;
						for (int i1 = h[x]; i1; i1 = ma[x].x) {
							int to = ma[i1].y;
							if (color[to] >= 0x3f3f3f3f) continue;
							if (0 ^ color[to]) w_sum += ma[i1].z;
							if (1 ^ color[to]) b_sum += ma[i1].z;
						}
						if (w_sum > b_sum) {
							color[x] = 1;
							ans += w_sum;
						} else {
							color[x] = 0;
							ans += b_sum;
						}
						g_po ++;
					}
				}
		printf("%d\n",ans);
	}
	return 0;
}
