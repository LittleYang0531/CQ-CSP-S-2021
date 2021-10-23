#include<bits/stdc++.h>
using namespace std ;
const int MAXS =  10000010 , TIL = ( 1 << 28 ) ;
struct NODE {
	int X , Y ;
} A[MAXS] , B[MAXS] ;
int MINA = TIL , MAXA , MINB = TIL , MAXB ;
int PUA[MAXS] , PUB[MAXS] ;
int AS[MAXS] , BS[MAXS] ;
int N , R , L ;
int Ans ;
int ANS ;
bool CMP(NODE X , NODE Y) {
	return X.X < Y.X ;
}
int main() {
	freopen("airport.in" , "r" , stdin) ;
	freopen("airport.out" , "w" , stdout) ;
	cin >> N >> R >> L ;
	for(int i = 1 ; i <= R ; i ++ ) {
		cin >> A[i].X >> A[i].Y ;
		MINA = min (MINA , A[i].X)  ;
		MAXA = max (MAXA , A[i].Y) ;
	}
	for(int i = 1 ; i <= L ; i ++ ) {
		cin >> B[i].X >> B[i].Y	;
		MINB = min (MINB , B[i].X) ;
		MAXB = max (MAXB , B[i].Y) ;
	}
	sort(A + 1 , A + R + 1 , CMP) ;
	sort(B + 1 , B + L + 1 , CMP) ;
	for(int i = 0 ; i <= N ; i ++ ) {
		if(i == 0) {
			AS[i] = BS[i] = 0 ;
			continue ;
		}
		for(int l = MINA ; l <= MAXA ; l ++ ) PUA[l] = 0 ;
		for(int l = MINB ; l <= MAXB ; l ++ ) PUB[l] = 0 ;
		Ans = 0 ;
		for(int S = 1 ; S <= R ; S ++ ) {
			bool FALG = true ;
			int l ;
			for(l = A[S].X ; l <= A[S].Y ; l ++ ) {
				PUA[l] ++ ;
				if(PUA[l] > i) {
					FALG = false ;
					break;
				}
			}
			for(int S = l ; S >= A[S].X ; S -- ) PUA[l] -- ;
			if(FALG == true ) Ans ++ ;
		}
		AS[i] = Ans ;
		Ans = 0 ;
		for(int S = 1 ; S <= L ; S ++ ) {
			bool FALG = true ;
			int l ;
			for(l = B[S].X ; l <= B[S].Y ; l ++ ) {
				PUB[l] ++ ;
				if(PUB[l] > i) {
					FALG = false ;
					break;
				}
			}
			for(int S = l ; S >= B[S].X ; S -- ) PUB[l] -- ;
			if(FALG == true ) Ans ++ ;
		}
		BS[i] = Ans ;
	}
	for(int i = 0 ; i <= N ; i ++ ) {
		int l = N - i ;
		ANS = max(ANS , AS[i] + BS[l]) ;
	}
	printf("%d\n" , ANS) ;
	return 0 ;
}
