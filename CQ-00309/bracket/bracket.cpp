#include <cstdio>
#include <cstring>
#include <algorithm>

using namespace std;

#define Maxn 505
#define LL long long
const int Mod = 1e9 + 7;

int n, k, len, ret;
char s[Maxn], str[Maxn];
LL dp[Maxn][Maxn][2][2], C[Maxn][Maxn];
//0 (  1 )

bool Check () {
	int cnt = 0, maxn = 0, res = 0;
	for (int i = 1; i <= n; i ++) {
		if (s[i] == '*') {
			cnt ++;
		} else {
			maxn = max (maxn, cnt);
			cnt = 0;
		}
	}
	maxn = max (maxn, cnt);
	return maxn < k;
}

void DFS (int u, int cntl) {
	if (u == n + 1) {
//		printf ("%s\n", s + 1);
		if (cntl == 0 && Check ()) {
//			printf ("%s\n", s + 1);
			ret ++;
		}
		return ;
	}
	if (s[u] != '*') {
		if (s[u] == '(') {
			DFS (u + 1, cntl + 1);
		} else if (s[u] == ')') {
			if (cntl == 0) return ;
			DFS (u + 1, cntl - 1);
		} else {
			if (cntl) {
				s[u] = ')';
				DFS (u + 1, cntl - 1);
				s[u] = '?';
			}
			s[u] = '(';
			DFS (u + 1, cntl + 1);
			s[u] = '*';
			DFS (u + 1, cntl);
			s[u] = '?';
		}	
	} else {
		DFS (u + 1, cntl);
	}
}

void Init () {
	for (int i = 0; i <= 500; i ++) {
		C[i][0] = 1;
		for (int j = 1; j <= i; j ++) {
			C[i][j] = (C[i - 1][j] + C[i - 1][j - 1]) % Mod;
		}
	}
}

int main () {
	freopen ("bracket.in", "r", stdin);
	freopen ("bracket.out", "w", stdout);
	
	scanf ("%d %d %s", &n, &k, s + 1);
	
	DFS (1, 0);
	
//	Init ();
//	
//	LL ans = 0;
//	for (int c = ct; c <= min (ct + unk, k); c ++) {
//		if ((n - c) % 2) continue;
//		int cnttt = 0;
//		len = 0;
//		for (int i = 1; i <= n; i ++) {
//			if (s[i] == '*') continue;
//			if (s[i] == '?') {
//				cnttt ++;
//				if (cnttt > c - ct) str[++ len] = s[i];
//			} else {
//				str[++ len] = s[i];
//			}
//		}
////		printf ("%s", str + 1);	
//		ret = 0;
//		DFS (1, 0);
//		printf ("%d\n", ret);
//		ans = (ans + ret * C[cnttt][c - ct] % Mod) % Mod;
//		memset (str, 0, sizeof str);
//	}
	
	printf ("%lld", ret);
	return 0;
}

