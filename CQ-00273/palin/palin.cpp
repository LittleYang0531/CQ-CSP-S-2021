#include <bits/stdc++.h>
using namespace std;
int T, n, a[400007], vis[400007], ss[400007];
//void dfs(int l, int r, int step) {
//	if(step == n) {
//		for(int i = 0; i < n; i++) {
//			cout << ss[i] << " ";
//		}
//		cout << endl;
//		return;
//	}
////	if(step < n) {
//		if(!vis[a[l]]) {
//			cout << "L" << endl;
//			vis[a[l]] = 1;
//			ss[step] = a[l];
//			dfs(l + 1, r, step + 1);
//			vis[a[l]] = 0;
//		}
//		else if(!vis[a[r]]) {
//			cout << "R" << endl;
//			vis[a[r]] = 1;
//			ss[step] = a[r];
//			dfs(l, r - 1, step + 1);
//			vis[a[r]] = 0;	
//		}
//		else {
//			return;
//		}
////	}
//}
int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while(T--) {
		scanf("%d", &n);
		for(int i = 1; i <= n * 2; i++) {
			scanf("%d", &a[i]);
		}
//		dfs(1, n * 2, 0);
bool flag = 1;
		for(int i = 1; i <= n; i++) {
			if(a[i] != a[n * 2 - i + 1]) {
				flag = 0;
				break;
			}
		}
		if(flag) {
			for(int i = 1; i <= n * 2; i++) {
				printf("L");
			}
			printf("\n");
		}
		else {
			printf("-1\n");
		}
	}
	return 0;
}
