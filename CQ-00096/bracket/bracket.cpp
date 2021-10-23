#include<bits/stdc++.h>
using namespace std;
const int N = 5e2 + 10, mod = 1e9 + 7;
int n, k, dp[N][N]; string s;
int rit(int sub, int r) {
	int num = 0;
	for(int i = sub + 1; i < r; ++i) if((s[i] == '*' || s[i] == '?') && num < k) ++num; else break;
	return sub + num;
}
int lft(int sub, int l) {
	int num = 0;
	for(int i = sub - 1; i > l; --i) if((s[i] == '*' || s[i] == '?') && num < k) ++num; else break;
	return sub - num;
}
int sp(int sub, int l) {
	for(int i = sub - 1; i > l; --i) if(s[i] == '(' || s[i] == '?') return i;
	return -1;
}
void rit1(int sub, int r1, int l, int r) {
	int num = 0;
	for(int i = sub; i < r1; ++i) {
		if(num == k) break;
		if(s[i] == '?' || s[i] == '*') ++num, (dp[l][r] += dp[l][sub] * dp[i + 1][r]) %= mod;
		else break;
	}
}
int main() {
	freopen("braket.in", "r", stdin);
	freopen("braket.out", "w", stdout);
	scanf("%d%d", &n, &k); cin >> s;
	for(int i = 0; i < int(s.length()) - 1; ++i) dp[i][i + 1] = (s[i] == '(' || s[i] == '?') & (s[i + 1] == ')' || s[i + 1] == '?');
	for(int i = 3; i <= n; ++i) {
		int l = 0, r = l + i - 1;
		while(r < n) {
			int p, t;
			if(s[l] == ')' || s[r] == '(') {dp[l][r] = 0; ++l, ++r; continue;}
			if(s[l] == '*' || s[r] == '*') {dp[l][r] = 0; ++l, ++r; continue;}
			if((s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?')) dp[l][r] += dp[l + 1][r - 1];
			p = rit(l, r); if(p != l && p != -1) {
				for(int k1 = l + 1; k1 <= p; ++k1) dp[l][r] += dp[k1 + 1][r - 1];
			}
			p = lft(r, l); if(p != r && p != -1) {
				for(int k1 = r - 1; k1 >= p; --k1) dp[l][r] += dp[l + 1][k1 - 1];
			}
			if(p && p == l + 1) dp[l][r]++; t = sp(r, l);
			if(t == -1) {++l, ++r; continue;}
			for(int k1 = l + 1; k1 < r; ++k1) {
				if(s[k1] == ')' || s[k1] == '?') rit1(k1, t, l ,r);
				else continue;
			} ++l, ++r;
		}
	}
	printf("%d\n", dp[0][n - 1]);
	return 0;
}
