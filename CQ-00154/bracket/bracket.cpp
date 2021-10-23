#include <stdio.h>

const int mod = 1e9 + 7;
char s[507], my[507];

int dfs(int cur, int n, int cnt, int k){
	if (cnt > k) return 0;
	if (cur > n){
		if (my[1] == '*' || my[n] == '*') return 0;
		int lcnt = 0, rcnt = 0;
		for (int i = 1; i <= n; i++){
			if (my[i] == '('){
				lcnt++;
			} else if (my[i] == ')'){
				rcnt++;
			}
			if (lcnt < rcnt) return 0;
		}
		return lcnt == rcnt;
	}
	if (s[cur] != '?') return dfs(cur + 1, n, s[cur] == '*' ? cnt + 1 : 0, k);
	int ans;
	my[cur] = '(';
	ans = dfs(cur + 1, n, 0, k);
	my[cur] = ')';
	ans = (ans + dfs(cur + 1, n, 0, k)) % mod;
	my[cur] = '*';
	ans = (ans + dfs(cur + 1, n, cnt + 1, k)) % mod;
	return ans;
}

int main(){
	int n, k;
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d %d", &n, &k);
	scanf("%s", &s[1]);
	for (int i = 1; i <= n; i++){
		my[i] = s[i];
	}
	printf("%d", dfs(1, n, 0, k));
	return 0;
}
