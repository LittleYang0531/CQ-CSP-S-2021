#include <bits/stdc++.h>
using namespace std ;
const int N = 5e5+5 ;
int T,n ;
int a[N] ;
int main(){
	freopen("palin.in","r",stdin) ;
	freopen("palin.out","w",stdout) ;
	scanf("%d",&T) ;
	while(T--){
		scanf("%d",&n) ;
		for(int i = 1 ; i <= n*2 ; ++i ) scanf("%d",&a[i]) ;
		for(int i = 1 ; i <= n ; ++i ) printf("L") ;
		for(int i = 1 ; i < n ; ++i ) printf("R") ;
		printf("L\n") ;
	}
	return 0 ;
}
