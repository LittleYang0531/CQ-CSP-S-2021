#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <ctime>

const int M = 1e6 + 5; 

inline int read() {
	int f = 1, s = 0; char ch = getchar();
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
	while(isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
	return f * s;
}

int t; 
int n, mark; 
int a[M], b[M], opt[M]; 

inline void Solve() {
    int l = 1, r = 2 * n; 
	for(int i = 1; i <= 2 * n; ++i) {
		if(opt[i] == 0) b[i] = a[l ++]; 
		else b[i] = a[r --]; 
	}
	for(int i = 1; i <= n; ++i) if(b[i] != b[2 * n - i + 1]) return ; 
	mark = 0; 
}

inline void dfs(int k) {
	if(!mark) return ; 
	if(k == 2 * n + 1) {Solve(); return ;}
	opt[k] = 0, dfs(k + 1); if(!mark) return ;
	opt[k] = 1, dfs(k + 1); if(!mark) return ; 
}

int main()
{
    freopen("palin.in", "r", stdin); 
    freopen("palin.out", "w", stdout); 
    t = read(); 
    while(t --) {
    	n = read(); mark = 1; 
    	for(int i = 1; i <= 2 * n; ++i) a[i] = read();
		for(int i = 1; i <= n; ++i) opt[i] = 0, opt[i + n] = 1;   
		if(n > 20) {
			int tim = 10000; 
			while(tim --) {
			    mark = 1; 
				std :: random_shuffle(opt + 1, opt + 2 * n + 1); 
				Solve(); 
				if(!mark) break; 
			}
		}
    	dfs(1); 
		if(mark) puts("-1"); 
		else {
			for(int i = 1; i <= 2 * n; ++i) putchar(opt[i] == 0 ? 'L' : 'R'); 
			puts(""); 
		}
	}
	return 0;
}
//2
//5
//4 1 2 4 5 3 1 2 3 5
//3
//3 2 1 2 1 3
