#include <cstdio>
#include <iostream>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;
# define rep(i,a,b) for(int i=(a); i<=(b); ++i)
# define drep(i,a,b) for(int i=(a); i>=(b); --i)
typedef long long int_;
inline int readint(){
	int a = 0, c = getchar(), f = 1;
	for(; '0'>c||c>'9'; c=getchar())
		if(c == '-') f = -f;
	for(; '0'<=c&&c<='9'; c=getchar())
		a = (a<<3)+(a<<1)+(c^48);
	return a*f;
}
void writeint(int x){
	if(x > 9) writeint(x/10);
	putchar((x-x/10*10)^48);
}

const int MAXN = 505;
const int Mod = 1e9+7;
/**
 * 0: no S allowed
 * 1: only on the left
 * 2: only on the right
 * 3: on both sides
 * 4: at most one side (answer)
 */
int dp[MAXN][5][MAXN];
char str[MAXN];

int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	int n = readint(), k = readint();
	scanf("%s",str+1);
	rep(i,1,n+1) rep(d,0,4)
		dp[i][d][i-1] = 1;
	for(int l=n; l>=1; --l){
		if(str[l] == ')') continue;
		rep(d,0,4) rep(r,l,n){
			if(str[l] != '*'){ // try '('
				const int ys = (d == 4) ? 3 : (d|1);
				long long t; // temporary
				for(int i=l+1; i<=r; ++i){
					if(str[i] == '(' || str[i] == '*')
						continue; // cannot be ')'
					t = dp[i+1][ys][r]; // always acceptable
					dp[l][d][r] = (dp[l][d][r]
						+t*dp[l+1][4][i-1])%Mod; // answer
				}
			}
			if(d == 0 || d == 2) continue;
			bool full = (r-l+1 <= k) // full '*'
				&& str[r] != '(' && str[r] != ')';
			const int LEN = min(r,l+k)-1;
			for(int i=l,t; i<=LEN; ++i){
				if(str[i] == '(' || str[i] == ')'){
					full = false; break; // cannot be '*'
				}
				t = dp[i+1][d&2][r]; // cannot choose left anymore
				dp[l][d][r] += t; // direct transfer
				if(dp[l][d][r] >= Mod)
					dp[l][d][r] -= Mod;
			}
			if(full && (d == 3 || d == 4))
				++ dp[l][d][r]; // only a single S
		}
	}
	printf("%d\n",dp[1][0][n]);
	return 0;
}

