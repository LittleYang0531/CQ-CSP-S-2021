#include <stdio.h>

int a[1000007], b[1000007];
char ans[1000007], cur[1000007];
bool vis[1000007];

int main(){
	int t;
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	for (int i = 1; i <= t; i++){
		int n;
		bool FLAG = false;
		scanf("%d", &n);
		for (int j = 1; j <= n * 2; j++){
			scanf("%d", &a[j]);
		}
		if (n > 10){
			bool qwq = true;
			for (int j = 1; j <= n; j++){
				vis[j] = false;
			}
			int l = 1, r = n * 2;
			for (int j = 1; j <= n; j++){
				if (!vis[a[l]]){
					vis[a[l]] = true;
					b[j] = a[l];
					ans[j - 1] = 'L';
					l++;
				} else if (!vis[a[r]]){
					vis[a[r]] = true;
					b[j] = a[r];
					ans[j - 1] = 'R';
					r--;
				} else {
					qwq = false;
					break;
				}
			}
			if (!qwq){
				printf("-1\n");
				continue;
			}
			for (int j = 1; j <= n; j++){
				if (a[l] == b[n - j + 1]){
					vis[a[l]] = true;
					ans[j + n - 1] = 'L';
					l++;
				} else if (a[r] == b[n - j + 1]){
					vis[a[r]] = true;
					ans[j + n - 1] = 'R';
					r--;
				} else {
					qwq = false;
					break;
				}
			}
			if (!qwq){
				printf("-1\n");
				continue;
			}
			for (int j = 0; j < n * 2; j++){
				printf("%c", ans[j]);
			}
			printf("\n");
			continue;
		}
		int m = 1 << (n * 2);
		for (int j = 0; j < m; j++){
			int l = 1, r = n * 2, k = 0, cnt = 0;
			bool flag = true;
			while (r >= l){
				if (j >> k & 1){
					b[++cnt] = a[r--];
				} else {
					b[++cnt] = a[l++];
				}
				if (cnt > n && b[cnt] != b[n * 2 - cnt + 1]){
					flag = false;
					break;
				}
				k++;
			}
			if (flag){
				for (int k = 0; k < n * 2; k++){
					cur[k] = (j >> k & 1) ? 'R' : 'L';
				}
				if (!FLAG){
					FLAG = true;
					for (int k = 0; k < n * 2; k++){
						ans[k] = cur[k];
					}
				} else {
					bool fl = false;
					for (int k = 0; k < n * 2; k++){
						if (ans[k] > cur[k]){
							fl = true;
							break;
						} else if (ans[k] < cur[k]){
							break;
						}
					}
					if (fl){
						for (int k = 0; k < n * 2; k++){
							ans[k] = cur[k];
						}
					}
				}
			}
		}
		if (!FLAG){
			printf("-1\n");
		} else {
			for (int j = 0; j < n * 2; j++){
				printf("%c", ans[j]);
			}
			printf("\n");
		}
	}
	return 0;
}
