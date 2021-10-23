#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>

using namespace std;

#define LL long long
#define Lson(x) (x << 1)
#define Rson(x) (x << 1 | 1)

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

int Num[Maxn], Count;
int n, m1, m2, Pos, Rest, Answer;
int f[2][Maxn], Begin[Maxn], End[Maxn], Value[Maxn], Next[Maxn];

int Sum[Maxn << 2], Lazy[Maxn << 2];

inline void Pushup (const int Index) {
	Sum[Index] = max (Sum[Lson (Index)], Sum[Rson (Index)]);
	return ;
}

inline void Pushdown (const int Index) {
	Sum[Lson (Index)] += Lazy[Index], Lazy[Lson (Index)] += Lazy[Index];
	Sum[Rson (Index)] += Lazy[Index], Lazy[Rson (Index)] += Lazy[Index];
	Lazy[Index] = 0;
	return ;
}

inline void Build (const int Index, const int Left, const int Right) {
	Lazy[Index] = 0;
	
	if (Left == Right ) {
		Sum[Index] = Value[Left];
		return ;
	}
	
	int Mid = (Left + Right) >> 1;
	Build (Lson (Index), Left, Mid);
	Build (Rson (Index), Mid + 1, Right);
	Pushup (Index);
	return ;
}

inline void Modify (const int Index, const int Left, const int Right, const int Ql, const int Qr, const int Val) {
	if (Ql <= Left and Right <= Qr ) {
		Sum[Index] += Val, Lazy[Index] += Val;
		return ;
	}
	
	Pushdown (Index);
	int Mid = (Left + Right) >> 1;
//	printf ("%d %d\n", Left, Right);
	
	if (Ql <= Mid ) {
		Modify (Lson (Index), Left, Mid, Ql, Qr, Val);
	}
	
	if (Qr > Mid ) {
		Modify (Rson (Index), Mid + 1, Right, Ql, Qr, Val);
	}
	
	Pushup (Index);
	return ;
}

inline int Find (const int Index, const int Left, const int Right, const int Val) {
	if (Left == Right ) {
		return Left;
	}
	
	Pushdown (Index);
	int Mid = (Left + Right) >> 1;
	
	if (Sum[Lson (Index)] > Val ) {
		return Find (Lson (Index), Left, Mid, Val);
	}
	
	return Find (Rson (Index), Mid + 1, Right, Val);
}

inline void Solve (const int m, const int Type) {
	Count = 0;
	
	for (int i = 1; i <= m; ++ i ) {
		Begin[i] = Num[++ Count] = Read ();
		End[i] = Num[++ Count] = Read ();
	}
	
	sort (Num + 1, Num + Count + 1);
	Count = unique (Num + 1, Num + Count + 1) - Num - 1;
	
	for (int i = 1; i <= Count; ++ i ) {
		Value[i] = Next[i] = 0;
	}
	
	for (int i = 1; i <= m; ++ i ) {
		Begin[i] = lower_bound (Num + 1, Num + Count + 1, Begin[i]) - Num;
		End[i] = lower_bound (Num + 1, Num + Count + 1, End[i]) - Num;
		++ Value[Begin[i]], -- Value[End[i] + 1];
//		printf ("%d %d\n", Begin[i], End[i]);
		Next[Begin[i]] = End[i];
	}
	
	for (int i = 1; i <= Count; ++ i ) {
		Value[i] += Value[i - 1];
//		printf ("%d ", Value[i]);
	}
	
//	putchar ('\n');
	
	Build (1, 1, Count), Rest = m;
	
	for (int i = n; ~i; -- i ) {
		if (Sum[1] <= i ) {
			f[Type][i] = Rest;
			continue ;
		}
		
		while (Sum[1] > i ) {
			Pos = Find (1, 1, Count, i), -- Rest;
			Modify (1, 1, Count, Pos, Next[Pos], -1);
//			printf ("%d %d %d %d %d\n", Num[Pos], Num[Next[Pos]], Sum[Pos], Sum[1], i);
		}
		
		f[Type][i] = Rest;
	}
	
//	for (int i = 1; i <= n; ++ i ) {
//		printf ("%d\n", f[Type][i]);
//	}
	
	return ;
}

signed main () {
	freopen ("airport.in", "r", stdin);
	freopen ("airport.out", "w", stdout);
	
	n = Read (), m1 = Read (), m2 = Read ();
	Solve (m1, 0), Solve (m2, 1);
	
	for (int i = 0; i <= n; ++ i ) {
		Answer = max (Answer, f[0][i] + f[1][n - i]);
	}
	
	Write (Answer), putchar ('\n');
	return 0;
}

