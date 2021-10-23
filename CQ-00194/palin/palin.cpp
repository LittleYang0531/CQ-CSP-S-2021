#include<bits/stdc++.h>
using namespace std ;
const int MAXS = 600010 , TIL = ( 1 << 28 ) ;
int A[MAXS] , Z[MAXS] , B[MAXS];
int ANS[MAXS] ;
int T , N ;
bool FCS ;
void SW() {
	FCS = true ;
	bool FALG = false ;
	for(int i = 1 ; i <= N ; i ++ ){
		if(Z[i] > ANS[i]) break ;
		else if(Z[i] < ANS[i]){
			FALG = true ;
			break ;
		}
	} if(FALG == true) for(int i = 1 ; i <= N ; i ++ ) ANS[i] = Z[i] ;
}
int main() {
	freopen("palin.in" , "r" , stdin) ;
	freopen("palin.out" , "w" , stdout) ;
	cin >> T ;
	while(T -- ) {
		FCS = false ;
		cin >> N ;
		N = N * 2 ;
		for(int i = 1 ; i <= N ; i ++ ) ANS[i] = 1 ;
		for(int i = 1 ; i <= N ; i ++ ) cin >> A[i] ;
		for(long long i = 0 ; i <= ( 1 << N ) - 1 ; i ++ ) {
			long long S = i , M = 1 ;
			while(S) {
				Z[M] = S & 1 ;
				S = S >> 1 ;
				M ++ ;
			}int TOP = 0 , TAIL = N + 1 ;
			for(int l = 1 ; l <= N ; l ++ ) {
				if(Z[l] == 0) B[l] = A[ ++ TOP] ;
				else B[l] = A[ -- TAIL] ;
			}bool FALG = true ;
			for(int l = 1 ; l <= N ; l ++ ) if(B[l] != B[N - l + 1]) {
					FALG = false ;
					break ;
				}
			if(FALG == true) {
				SW( ) ;
			}
		}
		if(FCS == false) printf("-1") ;
		else for(int i = 1 ; i <= N ; i ++ ) if(ANS[i] == 0 ) printf("L") ;
				else  printf("R") ;
		printf("\n") ;
	}
	return 0 ;
}
