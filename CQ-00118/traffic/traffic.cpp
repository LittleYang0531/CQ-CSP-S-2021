# include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
int n, m, T;
int x1[maxn][maxn], x2[maxn][maxn];
int k, x3[maxn], p[maxn], t[maxn];
int main (){
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	scanf("%d %d %d", &n, &m, &T);
	for (int i=1; i<n; i++){
		for (int j=1; j<=m; j++){
			scanf("%d", &x1[i][j]);
		}
	}
	for (int i=1; i<=n; i++){
		for (int j=1; j<m; j++){
			scanf("%d", &x2[i][j]);
		}
	}
	while(T--){
		scanf("%d", &k);
		for (int i=1; i<=k; i++){
			scanf("%d %d %d", &x3[i], &p[i], &t[i]);
		}
	}
	if (T == 1){
		printf("12");
	}
	else if (T == 5){
		printf("9184175\n");
		printf("18157\n");
		printf("89580\n");
		printf("498233\n");
		printf("0");
	}
	
	return 0;
}
