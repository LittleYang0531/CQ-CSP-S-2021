#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
#define int long long
using namespace std;

const int mod = 100000007;
const int N = 505;
char s[N];
int n,K;

inline bool check(){
	int maxxin = 0,leftcnt = 0,hfcnt = 0;
	for(int k=1;k<=n;k++){
		if(leftcnt<0)
			return 0;
		if(s[k]=='*'){
			maxxin++;
			if(maxxin>K)
				continue;
		}
		else{
			if(s[k]=='('){
				leftcnt++;
			}
			else{
				leftcnt--;
				hfcnt--;
			}
			maxxin = 0;
		}
	}
	return !leftcnt;
}

inline int mymod(int x){
	if(x>=mod)
		return x-mod;
	return x;
}

namespace fen15{
	int dfs(int wei=1,int xinlen=0){
		if(xinlen>K)
			return 0;
		if(wei>=n)
			return check();
		if(s[wei]!='?')
			return dfs(wei+1,s[wei]=='*'?xinlen+1:0);
		s[wei] = '*';
		int ans1 = dfs(wei+1,xinlen+1);
		s[wei] = '(';
		int ans2 = dfs(wei+1,0);
		s[wei] = ')';
		int ans3 = dfs(wei+1,0);
		s[wei] = '?';
		return mymod(mymod(ans1+ans2)+ans3);
	}
	int main(){
		printf("%lld",dfs());
		return 0;
	}
}

signed main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%lld%lld",&n,&K);
	scanf("%s",s+1);
	if(s[1]=='?')
		s[1] = '(';
	if(s[n]=='?')
		s[n] = ')';
	if(n<=100){
		fen15::main();
		return 0;
	}
}
/*
7 3
(*??*??
*/
