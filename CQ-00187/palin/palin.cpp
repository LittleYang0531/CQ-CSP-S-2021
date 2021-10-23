#include<bits/stdc++.h>
using namespace std;
#define ll long long
bool bj, pos[500005];
int ans[500005];
int n, num[500005];
bool use[500005];
void print() {
	for(int i=1; i<=n*2; ++i) {
		if(pos[i]) putchar('R');
		else putchar('L');
	}
	putchar('\n');
}
bool cheak(int x, int y) {
//	for(int i=x; i<=y; ++i) cout << num[i] << " ";
//	cout << endl;
//	for(int i=n; i>=1; --i) cout << ans[i] << " ";
//	cout << endl;
	for(int i=n; i>=1; --i) {
		if(num[x]==ans[i]) {
			pos[2*n-i+1]=0;
			++x;
		} else if(num[y]==ans[i]) {
			pos[2*n-i+1]=1;
			--y;
		} else{
			return false;
		} 
	}
	print();
	return true;
}
void dfs(int d, int x, int y) {
	if(d>n) {
//		printf("%d %d\n", x, y);
//		print();
		if(cheak(x, y)) bj=1;
		return;
	}

	if(!use[num[x]]) {
		pos[d]=0;
		use[num[x]]=1;
		ans[d]=num[x];
		dfs(d+1, x+1, y);
		use[num[x]]=0;
	}
	if(bj) return;
	if(!use[num[y]]) {
		pos[d]=1;
		use[num[y]]=1;
		ans[d]=num[y];
		dfs(d+1, x, y-1);
		use[num[y]]=0;
	}
}

int main() {
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int t;
	scanf("%d", &t);
	while(t--) {
		scanf("%d", &n);
		for(int i=1; i<=2*n; ++i) {
			scanf("%d", &num[i]);
		}
		bj=0;
		dfs(1, 1, n*2);
		if(!bj) printf("-1\n");
	}
	return 0;
}

