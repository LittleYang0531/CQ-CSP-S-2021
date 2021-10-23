#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define LL long long
using namespace std;
const int Mod = 1e9 + 7, MAXN = 505;
int n, K, brl[MAXN], brr[MAXN]; // brouden
LL prel[MAXN][MAXN][2], prer[MAXN][MAXN][2], dp[MAXN][MAXN][2];
char s[MAXN];
// dp[l][r][1] <-> must, dp[l][r][0] <-> must not
// 搞心态 
// 离线谢谢出题人 
// 麻了 
int main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d%s", &n, &K, s + 1);
	for(int i = 0; i <= n + 1; i ++) {
		for(int j = i - 1; j >= 0; j --) dp[i][j][0] = 1;
	}
	for(int i = 1; i <= n; i ++) {
		if(s[i] == '(' || s[i] == ')') { brl[i] = -1; continue; } 
		brl[i] = i;
		for(int j = i + 1; j <= n; j ++) {
			if(s[j] == '(' || s[j] == ')') break;
			else brl[i] = j;
		}
	}
	for(int i = n; i >= 1; i --) {
		if(s[i] == '(' || s[i] == ')') { brr[i] = -1; continue; } 
		brr[i] = i;
		for(int j = i - 1; j >= 1; j --) {
			if(s[j] == '(' || s[j] == ')') break;
			else brr[i] = j;
		}
	}
	for(int i = 1; i <= n; i ++) {
		if(s[i] == '*') dp[i][i][1] = 1;
		if(s[i] == '?') dp[i][i][1] = 1;
	}
	for(int len = 2; len <= n; len ++) {
	//	memset(prel, 0, sizeof(prel)); memset(prer, 0, sizeof(prer)); 
		for(int r = n; r >= 1; r --) {
			for(int l = r; l >= 1; l --) {
				prer[l][r][0] = (prer[l + 1][r][0] + dp[l][r][0]) % Mod;
				prer[l][r][1] = (prer[l + 1][r][1] + dp[l][r][1]) % Mod;
			}
		}
		for(int l = 1; l <= n - len + 1; l ++) {
			int r = l + len - 1;
			if(s[l] == '(' || s[l] == '?') {
				for(int k = l + 1; k <= r; k ++) {
					if(s[k] == ')' || s[k] == '?') {
						dp[l][r][0] = (dp[l][r][0] + (dp[l + 1][k - 1][1] + dp[l + 1][k - 1][0]) * dp[k + 1][r][0]) % Mod;
					}
				}
			}
			// cool down！
			// All fall down. 
			for(int k = l + 1; k < r; k ++) {
				if(brl[k + 1] != -1 && k + 2 <= r) {
					dp[l][r][0] = (dp[l][r][0] + dp[l][k][0] * (prer[k + 2][r][0] - prer[min(r, min(brl[k + 1] + 1, k + K + 1)) + 1][r][0])) % Mod;
				}
			}
			// pro 1
			if(r - l + 1 <= K && brl[l] >= r) dp[l][r][1] = (dp[l][r][1] + 1) % Mod; // special:all
			for(int k = l; k < r; k ++) {
				if(r - k <= K && brl[k + 1] >= r) dp[l][r][1] = (dp[l][r][1] + dp[l][k][0]) % Mod;
			}
			for(int k = l + 1; k <= r; k ++) {
				if(k - l <= K && brl[l] >= k - 1) dp[l][r][1] = (dp[l][r][1] + dp[k][r][0]) % Mod;
			}
		}
	}
	printf("%lld", (dp[1][n][0] + Mod) % Mod);
	return 0;
}
