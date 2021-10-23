#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define LL long long
#define ULL unsigned long long
#define PII pair <int, int>
#define MP(x,y) make_pair (x, y)
#define rep(i,j,k) for (int i = (j); i <= (k); i++)
#define per(i,j,k) for (int i = (j); i >= (k); i--)
#define fi first
#define se second

template <typename T>
void read (T &x) {
	x = 0; T f = 1;
	char ch = getchar ();
	while (ch < '0' || ch > '9') {
		if (ch == '-') f = -1;
		ch = getchar ();
	}
	while (ch >= '0' && ch <= '9') {
		x = (x << 3) + (x << 1) + ch - '0';
		ch = getchar ();
	}
	x *= f;
}
template <typename T>
void write (T x) {
	if (x < 0) {
		x = -x;
		putchar ('-');
	}
	if (x < 10) {
		putchar (x + '0');
		return;
	}
	write (x / 10);
	putchar (x % 10 + '0');
}
template <typename T>
void print (T x, char ch) {
	write (x); putchar (ch);
}

const int Maxn = 500;
const LL Mod = 1e9 + 7;

int n, k;
char s[Maxn + 5];
LL dp[Maxn + 5][Maxn + 5];
LL ans[Maxn + 5][Maxn + 5];

bool check (int l, int r) {
	if (s[l] == '(' && s[r] == ')') return 1;
	if (s[l] == '(' && s[r] == '?') return 1;
	if (s[l] == '?' && s[r] == ')') return 1;
	if (s[l] == '?' && s[r] == '?') return 1;
	return 0;
}
void add (LL &x, LL y) {
	x = (x + y) % Mod;
}

int main () {
	freopen ("bracket.in", "r", stdin);
	freopen ("bracket.out", "w", stdout);
	read (n); read (k);
	scanf ("%s", s + 1);
	
	for (int l = 1; l <= n; l++)
		for (int r = l; r <= n; r++) {
			if (s[r] != '*' && s[r] != '?') break;
			if (r - l + 1 > k) break;
			ans[l][r] = 1;
		}
	for (int len = 2; len <= n; len++) {
		
//		if (len == n) {
//			printf ("FUCK CCF\n");
//		}
		
		for (int l = 1; l + len - 1 <= n; l++) {
			int r = l + len - 1;
			
//			if (l == 3 && r == 9) {
//				printf ("FUCK CCF\n");
//			}
			
			if (check (l, r)) {
				if (l + 1 > r - 1) add (dp[l][r], 1);
				if (l + 1 <= r - 1)
					add (dp[l][r], ans[l + 1][r - 1]);
				if (l + 1 <= r - 1)
					add (dp[l][r], dp[l + 1][r - 1]);
				for (int i = l + 1; i + 1 <= r - 1; i++) {
					//[l + 1, i], dp[i + 1, r - 1]
//					if (!(l + 1 <= i && i + 1 <= r - 1))
//						printf ("FUCK CCF");
					if (l + 1 <= i && i + 1 <= r - 1)
						add (dp[l][r], dp[l + 1][i] * ans[i + 1][r - 1]);
					if (l + 1 <= i && i + 1 <= r - 1)
						add (dp[l][r], ans[l + 1][i] * dp[i + 1][r - 1]);
				}
			}
			
			int poi = n + 1; LL res = 0;
			for (int i = l; i + 1 <= r; i++) {
				//[l, i], [i + 1, r];
				if (dp[l][i]) {
					poi = i + 1;
					while (poi <= r && !dp[i + 1][poi]) poi++;
					if (poi <= r && dp[i + 1][poi] && res == 0) 
						res = dp[l][i];
					if (poi <= r && dp[i + 1][poi])
						res = res * dp[i + 1][poi] % Mod;
				}
			}
			add (dp[l][r], res);
			
			for (int i = l; i <= r; i++) {
				for (int j = i + 2; j <= r; j++) {
					//[l, i], [i + 1, j - 1], [j, r]
//					if (!(l <= i && i + 1 <= j - 1 && j <= r))
//						printf ("FUCK CCF");
//					if (i + 1 > j - 1) 
//						printf ("FUCK CCF");
					if (l <= i && i + 1 <= j - 1 && j <= r)
						add (dp[l][r], dp[l][i] * ans[i + 1][j - 1] * dp[j][r]);
				}
			}
		}
	}
	
//	for (int i = 1; i <= n; i++) {
//		for (int j = i; j <= n; j++) {
//			printf ("ans[%d][%d] = %lld\n", i, j, ans[i][j]);
//		}
//	}
//	for (int i = 1; i <= n; i++) {
//		for (int j = i; j <= n; j++) {
//			printf ("dp[%d][%d] = %lld\n", i, j, dp[i][j]);
//		}
//	}
	
	write (dp[1][n]);
	return 0;
}

