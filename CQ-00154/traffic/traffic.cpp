#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef long long ll;

int x1[507][507], x2[507][507], x3[57], p[57], t[57], val[507][507], vis[2007];

inline ll min(ll a, ll b){
	return a < b ? a : b;
}

int main(){
	int n, m, T;
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &T);
	srand(time(NULL));
	for (int i = 1; i < n; i++){
		for (int j = 1; j <= m; j++){
			scanf("%d", &x1[i][j]);
		}
	}
	for (int i = 1; i <= n; i++){
		for (int j = 1; j < m; j++){
			scanf("%d", &x2[i][j]);
		}
	}
	for (int i = 1; i <= T; i++){
		int k;
		ll ans = 1e18;
		scanf("%d", &k);
		for (int j = 1; j <= (n + m) * 2; j++){
			vis[j] = 0;
		}
		for (int j = 1; j <= k; j++){
			scanf("%d %d %d", &x3[j], &p[j], &t[j]);
			vis[p[j]] = j;
		}
		ll limit = 1ll << (n * m);
		for (int j = 0; j <= 2.5e4; j++){
			ll cur;
			if (j == 0){
				cur = 0;
			} else if (j == 1){
				cur = limit - 1;
			} else {
#if RAND_MAX == 0X7fff
				cur = (ll)rand() * rand() * rand() * rand() % limit;
#else
				cur = (ll)rand() * rand() % limit;
#endif
			}
			for (int k = 1; k <= n; k++){
				for (int l = 1; l <= m; l++){
					val[k][l] = cur >> (m * (k - 1) + l - 1) & 1;
				}
			}
			ll cur_ans = 0;
			for (int k = 1; k <= n; k++){
				for (int l = 1; l <= m; l++){
					if (k > 1){
						if (val[k][l] != val[k - 1][l]) cur_ans += x1[k - 1][l];
					}
					if (l > 1){
						if (val[k][l] != val[k][l - 1]) cur_ans += x2[k][l - 1];
					}
					if (k == 1){
						int pos = vis[l];
						if (pos && val[k][l] != t[pos]) cur_ans += x3[pos];
					}
					if (k == n){
						int pos = vis[l + n + m];
						if (pos && val[k][l] != t[pos]) cur_ans += x3[pos];
					}
					if (l == 1){
						int pos = vis[k + n + m * 2];
						if (pos && val[k][l] != t[pos]) cur_ans += x3[pos];
					}
					if (l == m){
						int pos = vis[k + m];
						if (pos && val[k][l] != t[pos]) cur_ans += x3[pos];
					}
					if (ans < cur_ans) goto NEXT;
				}
			}
			ans = min(ans, cur_ans);
NEXT:		;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
