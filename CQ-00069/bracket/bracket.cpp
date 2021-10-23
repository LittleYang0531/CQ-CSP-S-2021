#include <cstdio>
#include <cstring>
#include <iostream>

using namespace std;

#define LL long long

inline LL Read () {
	LL x = 0, f = 0;
	char Ch = getchar ();

	while (Ch > '9' or Ch < '0' ) {
		f |= Ch == '-', Ch = getchar ();
	}

	while (Ch >= '0' and Ch <= '9' ) {
		x = (x << 1) + (x << 3) + (Ch ^ 48);
		Ch = getchar ();
	}

	return f ? -x : x;
}

inline void Write (const LL Num) {
	if (Num < 0 ) {
		putchar ('-');
		Write (-Num);
		return ;
	}

	if (Num > 9 ) {
		Write (Num / 10);
	}

	putchar ((Num % 10) ^ 48);
	return ;
}

const LL Mod = 1e9 + 7;
const int Maxn = 5e2 + 10;

int Stack[Maxn], Top;
int Next[Maxn], Temp[Maxn], t;

int n, m;
LL Answer;
char Str[Maxn], S[Maxn];
LL f[2][Maxn][Maxn];

inline void Clac (const int Now) {
	if (Str[Now] == '(' ) {
		for (int i = 0; i <= n; ++ i ) {
			for (int j = 0; j <= m; ++ j ) {
				f[Now & 1][i + 1][0] = (f[Now & 1][i + 1][0] + f[(Now - 1) & 1][i][j]) % Mod;
			}
		}
		
		return ;
	}
	
	if (Str[Now] == ')' ) {
		for (int i = 1; i <= n; ++ i ) {
			for (int j = 0; j <= m; ++ j ) {
				f[Now & 1][i - 1][0] = (f[Now & 1][i - 1][0] + f[(Now - 1) & 1][i][j]) % Mod;
			}
		}
		
		return ;
	}
	
	for (int i = 0; i <= n; ++ i ) {
		for (int j = 0; j <= m; ++ j ) {
			f[Now & 1][i][j + 1] = (f[Now & 1][i][j + 1] + f[(Now - 1) & 1][i][j]) % Mod;
		}
	}
	
	return ;
}

signed main () {
	freopen ("bracket.in", "r", stdin);
	freopen ("bracket.out", "w", stdout);
	
	scanf ("%d %d %s", &n, &m, Str + 1);
	
	if (Str[1] == '*' or Str[1] == ')' ) {
		printf ("0\n");
		return 0;
	}
	
	f[1][1][0] = 1;
	
	for (int i = 2; i <= n; ++ i ) {
		memset (f[i & 1], 0, sizeof f[i & 1]);
		
		if (Str[i] != '?' ) {
			Clac (i);
			continue ;
		}
		
		for (int j = 0; j <= n; ++ j ) {
			for (int k = 0; k <= m; ++ k ) {
				f[i & 1][j + 1][0] = (f[i & 1][j + 1][0] + f[(i - 1) & 1][j][k]) % Mod;
				
				if (k < m ) {
					f[i & 1][j][k + 1] = (f[i & 1][j][k + 1] + f[(i - 1) & 1][j][k]) % Mod;
				}
				
				if (j ) {
					f[i & 1][j - 1][0] = (f[i & 1][j - 1][0] + f[(i - 1) & 1][j][k]) % Mod;
				}
			}
		}
	}
	
	Write (f[n & 1][0][0]), putchar ('\n'); 
	return 0;
}

