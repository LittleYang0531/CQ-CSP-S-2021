#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const ll mod = 1e9 + 7, maxn = 505;
ll n, k, dp[maxn][maxn];
bool can[maxn][maxn];
char s[maxn];
bool isok(int i, int j) {
	if((j - i + 1) >= 1 && (j - i + 1) <= k && can[i][j]) return 1;
	return 0;
}
/*
7 3
(*??*??

10 2
???(*??(?)
7 3
(**)*()

(**(*))
(*(**))
(*)**()
(*)(**)
*/
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	scanf("%s", s + 1);
	for(int i = 1; i <= n; i++) if(s[i] == '?' || s[i] == '*') can[i][i] = 1;
	for(int len = 2; len <= n; len++)
	for(int i = 1; i <= n + 1 - len; i++) {
		int j = i + len - 1;
		if(s[i] == '?' || s[i] == '*') can[i][j] |= can[i + 1][j];
		if(s[j] == '?' || s[j] == '*') can[i][j] |= can[i][j - 1];
	}
	for(int i = 1; i < n; i++) if((s[i] == '(' || s[i] == '?') && (s[i + 1] == ')' || s[i + 1] == '?')) dp[i][i + 1] = 1;
	for(int len = 3; len <= n; len++)
	for(int i = 1; i + len - 1 <= n; i++) {
		int j = i + len - 1;
		if((s[i] != '(' && s[i] != '?') || (s[j] != ')' && s[j] != '?')) continue;
		if(isok(i + 1, j - 1)) dp[i][j] = (dp[i][j] + 1) % mod;
		for(int m = i + 1; m < j; m++)
			if(isok(i + 1, m)) dp[i][j] = (dp[i][j] + dp[m + 1][j - 1]) % mod;
		for(int m = j - 1; m > i; m--)
			if(isok(m, j - 1)) dp[i][j] = (dp[i][j] + dp[i + 1][m - 1]) % mod;
		dp[i][j] = (dp[i][j] + dp[i + 1][j - 1]) % mod;
		
		for(int m1 = i + 1; m1 < j; m1++)
		for(int m2 = m1 + 2; m2 < j; m2++)
			if(isok(m1 + 1, m2 - 1)) dp[i][j] = (dp[i][j] + dp[i][m1] * dp[m2][j] % mod) % mod;
		for(int m = i + 1; m < j; m++)
			dp[i][j] = (dp[i][j] + dp[i][m] * dp[m + 1][j] % mod) % mod;
	}
	printf("%lld\n", dp[1][n]);
	return 0;
}
