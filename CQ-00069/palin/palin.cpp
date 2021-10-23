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
const int Maxn = 5e5 + 10;

int T, n;
char Str[Maxn];
int Arr[Maxn], Num[Maxn], Used[Maxn];

inline bool Check (int l, int r) {
	for (int i = n; i; -- i ) {
		if (Arr[l] == Num[i] ) {
			++ l, Str[n * 2 - i + 1] = 'L';
		}
		
		else if (Arr[r] == Num[i] ) {
			-- r, Str[n * 2 - i + 1] = 'R';
		}
		
		else {
			return false;
		}
	}
	
	return true;
}

inline bool Search (const int Now, const int Left, const int Right) {
	if (Now > n ) {
		if (Check (Left, Right) ) {
			return true;
		}
		
		return false;
	}
	
	if (!Used[Arr[Left]] ) {
		Num[Now] = Arr[Left], Str[Now] = 'L';
		
		if (Search (Now + 1, Left + 1, Right) ) {
			return true;
		}
	}
	
	if (!Used[Arr[Right]] ) {
		Num[Now] = Arr[Right], Str[Now] = 'R';
		
		if (Search (Now + 1, Left, Right - 1) ) {
			return true;
		}
	}
	
	return false;
}

signed main () {
	freopen ("palin.in", "r", stdin);
	freopen ("palin.out", "w", stdout);
	T = Read ();
	
	while (T -- ) {
		n = Read ();
		
		for (int i = 1; i <= n * 2; ++ i ) {
			Arr[i] = Read ();
		}
		
		if (Search (1, 1, n * 2) ) {
			for (int i = 1; i <= n * 2; ++ i ) {
				putchar (Str[i]);
			}
			
			putchar ('\n');
		}
		
		else {
			Write (-1), putchar ('\n');
		}
	}
	return 0;
}

