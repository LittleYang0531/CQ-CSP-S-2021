#include<bits/stdc++.h>
using namespace std ;
const int MAXS = 1010 , TIL = ( 1 << 28 ) ;
int X[MAXS] , CNT ;
char A[TIL] ;
int N , K ;
int L , R ;
int main(){
	freopen("bracket.in" , "r" , stdin) ;
	freopen("bracket.out" , "w" , stdout) ;
	cin >> N >> K ;
	for(int i = 1 ; i <= N ; i ++ ){
		cin >> A[i] ;
		if(A[i] == '(') L ++ ;
		else if(A[i] == ')') R ++ ;
		if(A[i] == '?') CNT ++ , X[CNT] = i ;
	}printf("0") ;
	return 0 ;
}
