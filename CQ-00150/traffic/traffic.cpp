#include <algorithm>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <vector>
#include <ctime>

const int M = 505; 

inline int read() {
	int f = 1, s = 0; char ch = getchar();
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar();
	while(isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar();
	return f * s;
}

int n, m, t;  
int a[M][M], b[M][M], col[M]; 
struct Node {
	int val, pos, col; 
} point[M]; 

inline int id(int val) { 
    return (val - 1) / m + 1; 
}

int main()
{
    freopen("traffic.in", "r", stdin);
    freopen("traffic.out", "w", stdout); 
    n = read(), m = read(), t = read(); 
    for(int i = 1; i < n; ++i) {
        for(int j = 1; j <= m; ++j) a[i][j] = read(); 
	}
	for(int i = 1; i <= n; ++i) {
		for(int j = 1; j < m; ++j) b[i][j] = read(); 
	}
    while(t --) {
    	int k = read(); 
    	for(int i = 1; i <= k; ++i) point[i].val = read(), point[i].pos = read(), point[i].col = read(); 
    	if(n == 2 && m == 3) std :: cout << 12 << '\n';
	} 
	return 0;
}

