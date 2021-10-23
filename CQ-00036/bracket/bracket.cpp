#include <bits/stdc++.h>
#define rep1(i, j, n) for (int i(j); i <= n; ++i)
#define rep2(i, j, n) for (int i(j); i >= n; --i)
#define int long long
using namespace std;
template <typename T>
inline void read(T &x) {
	x = 0; int f = 1; char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = -1; ch = getchar();}
	while (isdigit(ch)) {x = (x << 1) + (x << 3) + (ch & 15); ch = getchar();}
	x *= f;
}
const int N = 505;
string s; int n, k, sum = 0;
inline void dfs(int step, int nk) {
	if (step >= n && nk <= k) {
		int f = 0;
		if (s[0] == '*') return ;
		rep1(i, 0, (int)(s.length() - 1)) {
			if (s[i] == '(') ++f;
			else if (s[i] == ')') --f;
			if (f < 0) return ;
		}
		if (f != 0) return ;
		(++sum) %= (long long)(1e9 + 7);
		return ;
	} else if (step >= n) return ;
	if (s[step] ^ '?') {if ((s[step] == '*' && nk < k) || (s[step] ^ '*')) dfs(step + 1, (s[step] ^ '*' ? 0 : nk + 1)); else return ;}
	else {
		if (nk < k) {
			s[step] = '*';
			dfs(step + 1, nk + 1);
		}
		s[step] = '(';
		dfs(step + 1, 0);
		s[step] = ')';
		dfs(step + 1, 0);
		s[step] = '?';
	}
}
main() {
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	read(n); read(k); cin >> s;
	dfs(0, 0);
	printf("%lld\n", sum % (long long)(1e9 + 7));
}
