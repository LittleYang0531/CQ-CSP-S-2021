#include<bits/stdc++.h>
#define int long long
using namespace std ;
string s ;
int n , k ;
bool check(string now){
	bool ans = true ;
	int left , right , id ;
	for(int i = 0 ; i < now.size() ; i ++){
		if(now[i] == '(') left ++ ;
		if(now[i] == ')') right ++ ;
		if(right - left == 1){
			id = i ;
			break ;
		}
	}
	
}
int dfs(string now , int id , int l , int star){
	if(star > k) return 0 ;
	if(id >= n){
		if(now[n - 1] != ')') return 0 ;
		if(l == 0){
			return 1 ;
		} 
		return 0 ;
	}
	int sum = 0 ;
	if(now[id] != '?'){
		if(now[id] == '*') star ++ ;
		if(now[id] == '(') l ++ ;
		return dfs(now , id + 1 , l , star) ;
		return dfs(now , id + 1 , l , 0) ;
	}
	else{
		now[id] = '(' , sum += dfs(now , id + 1 , l + 1 , star) ;
		if(l > 0) now[id] = ')' , sum += dfs(now , id + 1 , l - 1 , star) ;
		now[id] = '*' , sum += dfs(now , id + 1 , l , star + 1) ;
		return sum ;
	}
}
signed main(){
	freopen("bracket.in" , "r" , stdin) ;
	freopen("bracket.out" , "w" , stdout) ;
	cin >> n >> k ;
	cin >> s ;
	cout << dfs(s , 0 , 0 , 0) ;
	return 0 ;
}
