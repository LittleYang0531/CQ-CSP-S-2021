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
const int N = 1e5 ;
int n , m1 , m2 ;
struct Node{
	int start , end ;
}p1[N] , p2[N] ;
int num1[N] , num2[N] ;
int search1[N] , search2[N] ;
int cnt1[N] , cnt2[N] ;
int end1[N] , end2[N] , id1 , id2 ; 
bool cmp1(Node a , Node b){
	return a . start < b . start ;
}
bool cmp2(Node a , Node b){
	return a . end < b . end ;
}
bool cmp(int a , int b){
	return a > b ;
}
int ans = INT_MIN ;
signed main(){
	freopen("airport.in" , "r" , stdin) ;
	freopen("airport.out" , "w" , stdout) ;
	n = read() ;
	m1 = read() ;
	m2 = read() ;
	for(int i = 0 ; i < m1 ; i ++) num1[i * 2] = p1[i] . start = read() , num1[i * 2 + 1] = p1[i] . end = read() ;
	sort(num1 , num1 + 2 * m1) ;
	int tot1 = 0 ;
	for(int i = 0 ; i < 2 * m1 ; i ++) search1[tot1 ++] = num1[i] ;
	for(int i = 0 ; i < m1 ; i ++){
		bool flag = true ;
		int choose_id = 0 , choose = INT_MIN ;
		for(int j = 0 ; j < id1 ; j ++) 
		if(p1[i] . start > end1[j]){
			if(choose < end1[j]) choose_id = j , choose = end1[j] ;
			flag = false ;
		}
		if(flag) choose_id = id1 , id1 ++ ;
		end1[choose_id] = p1[i] . end ;
		cnt1[choose_id] ++ ;
	}
	for(int i = 0 ; i < m2 ; i ++) num2[i * 2] = p2[i] . start = read() , num2[i * 2 + 1] = p2[i] . end = read() ;
	sort(num2 , num2 + 2 * m2) ;
	int tot2 = 0 ;
	for(int i = 0 ; i < 2 * m2 ; i ++) search2[tot2 ++] = num2[i] ;
	for(int i = 0 ; i < m2 ; i ++){
		bool flag = true ;
		int choose_id = 0 , choose = INT_MIN ;
		for(int j = 0 ; j < id2 ; j ++) 
		if(p2[i] . start > end2[j]){
			if(choose < end2[j]) choose_id = j , choose = end2[j] ;
			flag = false ;
		}
		if(flag) choose_id = id2 , id2 ++ ;
		end2[choose_id] = p2[i] . end ;
		cnt2[choose_id] ++ ;
	}
	for(int i = 0 ; i <= id1 ; i ++){
		int cnt = 0 ;
		for(int j = 0 ; j < i ; j ++) cnt += cnt1[j] ;
		for(int j = 0 ; j < n - i ; j ++) cnt += cnt2[j] ;
		ans = max(ans , cnt) ;
	}
	write(ans) ;
	return 0 ;
}
