#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cstring>
#define int long long
#define inlint inline int
#define inloid inline void
#define inbool inline bool
#define MAXN 505
#define MODNUM 1000000007
using namespace std;

namespace _MAIN{
	int n, k;
	inlint read() {
		register int nega = 1, num = 0, c = getchar();
		for(;~c && !isdigit(c); c = getchar()) if(c == '-') nega = -1;
		for(;~c &&  isdigit(c); c = getchar()) num = num * 10 + c - '0';
		return nega * num;
	}
} using namespace _MAIN;

namespace _SOLV{
	int f[MAXN][MAXN][MAXN];
	char seq[MAXN];
	inloid dp() {
		f[0][0][0] = 1;
		for(int i = 1; i <= n; i++) {
			if(seq[i] == '(') {
				for(int l = 1; l <= i; l++) {
					for(int c = 0; c <= min(i - l, k); c++) {  
						(f[i][l][0] += f[i - 1][l - 1][c]) %= MODNUM;
					}
				}
			} else if(seq[i] == ')') {
				for(int l = 0; l <= i - 2; l++) {
					for(int c = 0; c <= min(i - 1 - l, k); c++) { 
						(f[i][l][0] += f[i - 1][l + 1][c]) %= MODNUM; 
					}
				}
			} else if(seq[i] == '*') {
				for(int l = 0; l <= i - 1; l++) {
					for(int c = 1; c <= min(i - l, k); c++) {
						(f[i][l][c] += f[i - 1][l][c - 1]) %= MODNUM;
					}
				}
			} else if(seq[i] == '?') {
				for(int l = 1; l <= i; l++) {
					for(int c = 0; c <= min(i - l, k); c++) {  
						(f[i][l][0] += f[i - 1][l - 1][c]) %= MODNUM;
					}
				}
				for(int l = 0; l <= i - 2; l++) {
					for(int c = 0; c <= min(i - 1 - l, k); c++) { 
						(f[i][l][0] += f[i - 1][l + 1][c]) %= MODNUM; 
					}
				}
				if(i >= 2 && i <= n - 1) for(int l = 0; l <= i - 1; l++) {
					for(int c = 1; c <= min(i - l, k); c++) {
						(f[i][l][c] += f[i - 1][l][c - 1]) %= MODNUM;
					}
				}
			}
		}
	}
} using namespace _SOLV;

signed main(void){
	freopen("bracket.in", "r", stdin), freopen("bracket.out", "w", stdout);
	n = read(), k = read();
	scanf("%s", seq + 1);
	dp();
	cout << f[n][0][0] << "\n";
	return fclose(stdin), fclose(stdout), 0;
}
