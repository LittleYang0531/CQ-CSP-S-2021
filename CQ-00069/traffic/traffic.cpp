#include <cstdio>
#include <cstdlib>
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

LL Answer, S;
int T, n, m, k, Cos, x, y, Col, num;
LL Graph1[Maxn][Maxn], Graph2[Maxn][Maxn], Color[Maxn][Maxn], Cost[Maxn][Maxn];

inline void Clac () {
	LL Sum = S;
	
	for (int i = 1; i <= n; ++ i ) {
		for (int j = 1; j <= m; ++ j ) {
			if (i > 1 and Color[i][j] ^ Color[i - 1][j] ) {
				Sum += Graph1[i - 1][j];
			}
			
			if (j > 1 and Color[i][j] ^ Color[i][j - 1] ) {
				Sum += Graph2[i][j - 1];
			}
			
			Sum += Cost[i][j] * Color[i][j];
//			printf ("%d ", Color[i][j]);
		}
		
//		putchar ('\n');
	}
	
//	printf ("%lld\n", Sum);
	Answer = min (Answer, Sum);
	return ;
}

inline void Search (const int i, const int j) {
	if (i == n + 1 ) {
		Clac ();
		return ;
	}
	
	Color[i][j] = 1, Search (i + (j == m), j % m + 1);
	Color[i][j] = 0, Search (i + (j == m), j % m + 1);
	return ;
}

inline void Getxy (const int Num) {
	if (Num <= m ) {
		x = 1, y = Num;
	}
	
	else if (Num <= n + m ) {
		x = Num - m, y = m;
	}
	
	else if (Num <= n + 2 * m ) {
		x = n, y = n + 2 * m - Num + 1;
	}
	
	else {
		x = 2 * n + 2 * m - Num + 1, y = 1;
	}
	
	return ;
}

signed main () {
	freopen ("traffic.in", "r", stdin);
	freopen ("traffic.out", "w", stdout);
	
	n = Read (), m = Read (), T = Read ();
	
	for (int i = 1; i < n; ++ i ) {
		for (int j = 1; j <= m; ++ j ) {
			Graph1[i][j] = Read ();
		}
	}
	
	for (int i = 1; i <= n; ++ i ) {
		for (int j = 1; j < m; ++ j ) {
			Graph2[i][j] = Read ();
		}
	}
	
	while (T -- ) {
		k = Read (), S = 0;
		Answer = 1ll << 60;
		
		while (k -- ) {
			Cos = Read (), num = Read (), Col = Read ();
			Getxy (num);
			
			if (Col ) {
				S += Cos, Cost[x][y] = -Cos;
			}
			
			else {
				Cost[x][y] = Cos;
			}
		}
		
		Search (1, 1), Write (Answer), putchar ('\n');
	}
	
	return 0;
}

