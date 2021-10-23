#include<bits/stdc++.h>
#define int long long
#define mes(x, i) memset(x, i, sizeof x)
#define max(i, j) (i > j ? i : j)
#define min(i, j) (i < j ? i : j)
using namespace std;
int a[2005];
char ans[1005];
int T, n;
signed main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &T);
	while(T--){
		scanf("%d", &n);
		for(int i = 1; i <= 2 * n; i++) scanf("%d", &a[i]);
		printf("-1");
	}
//	system("Pause");//Ìá½»Ç°×¢ÊÍ£¡£¡£¡
	return 0;
}
