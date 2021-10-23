#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <ctime>

const int M = 505; 
const int mod = 1e9 + 7; 

inline int read() {
	int f = 1, s = 0; char ch = getchar();
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
	while(isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
	return f * s;
}

int n, K, ans; 
char str[M];
int f[2][M][M][2][2]; 

int main()
{
    freopen("bracket.in", "r", stdin); 
    freopen("bracket.out", "w", stdout); 
    n = read(), K = read(); 
    scanf("%s", str + 1); 
    int now = 1;
    f[now][0][0][0][0] = 1; 
    for(int i = 1; i <= n; ++i) {
    	if(str[i] == '(') {
    		for(int j = 1; j <= i; ++j) 
    		    for(int k = 0; k <= K; ++k) f[!now][j][0][1][0] = (f[!now][j][0][1][0] + f[now][j - 1][k][0][0] + f[now][j - 1][k][1][0] + f[now][j - 1][k][1][1]) % mod; 
		}
		else if(str[i] == ')') {
			for(int j = 0; j <= i; ++j) 
			    for(int k = 0; k <= K; ++k) f[!now][j][0][1][1] = (f[!now][j][0][1][1] + f[now][j + 1][k][1][0] + f[now][j + 1][k][1][1]) % mod; 
		}
		else if(str[i] == '*') {
			for(int j = 0; j <= i; ++j) 
				for(int k = 1; k <= K; ++k) f[!now][j][k][1][0] = (f[!now][j][k][1][0] + f[now][j][k - 1][1][0] + f[now][j][k - 1][1][1]) % mod; 
		}
		else {
			for(int j = 1; j <= i; ++j) 
    		for(int k = 0; k <= K; ++k) f[!now][j][0][1][0] = (f[!now][j][0][1][0] + f[now][j - 1][k][0][0] + f[now][j - 1][k][1][0] + f[now][j - 1][k][1][1]) % mod; 
    		for(int j = 0; j <= i; ++j) 
			for(int k = 0; k <= K; ++k) f[!now][j][0][1][1] = (f[!now][j][0][1][1] + f[now][j + 1][k][1][0] + f[now][j + 1][k][1][1]) % mod; 
			for(int j = 0; j <= i; ++j) 
			for(int k = 1; k <= K; ++k) f[!now][j][k][1][0] = (f[!now][j][k][1][0] + f[now][j][k - 1][1][0] + f[now][j][k - 1][1][1]) % mod; 
		}
		for(int j = 0; j <= n; ++j)   
		    for(int k = 0; k <= n; ++k) f[now][j][k][0][0] = f[now][j][k][0][1] = f[now][j][k][1][0] = f[now][j][k][1][1] = 0; 
		now = !now; 
	}
	int ans = 0; 
	std :: cout << f[now][0][0][1][1] % mod; 
	return 0;
}

//7 3
//(*??*??
