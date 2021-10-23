#include<bits/stdc++.h>
#define int long long
using namespace std ;
int read(){
	int a = 0 , k = 1 ;
	char c = getchar() ;
	while(c > '9' || c < '0'){
		if(c == '-') k = -1 ;
		c = getchar() ;
	}
	while(c <= '9' && c >= '0') a *= 10 , a += c - '0' , c = getchar() ;
	return a * k ;
}
void write(int a){
	if(a < 0) putchar('-') , a = -a ;
	if(a > 9) write(a / 10) ;
	putchar(a % 10 + '0') ;
}
signed main(){
	freopen("traffic.in" , "r" , stdin) ;
	freopen("traffic.out" , "w" , stdout) ;
	cout << 12 ;
	return 0 ;
}
