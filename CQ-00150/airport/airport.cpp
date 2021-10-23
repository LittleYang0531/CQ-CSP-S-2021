#include <algorithm> 
#include <iostream> 
#include <cstring> 
#include <cstdio>
#include <vector> 
#include <ctime> 
#include <cmath> 
#include <queue>

const int M = 1e5 + 5;  

inline int read() {
	int f = 1, s = 0; char ch = getchar(); 
	while(!isdigit(ch)) (ch == '-') && (f = -1), ch = getchar(); 
	while(isdigit(ch)) s = (s << 1) + (s << 3) + (ch ^ 48), ch = getchar(); 
	return f * s; 
}
int n, m1, m2, tot1, tot2, pq1, pq2; 
int tmp1[M << 1], tmp2[M << 1];
int f1[M], f2[M], c[M], f[M]; 
struct Node {
	int l, r; 
	inline bool operator < (const Node &rhs) const {
	    return l < rhs.l; 
	}
} a[M], b[M];

std :: vector < int > P1[M], P2[M]; 
std :: priority_queue < int > pq; 

inline int solve1(int t) {
	int ans = 0; 
    while(!pq.empty()) pq.pop(); 
	for(int i = 1; i <= pq1; ++i) {
		for(int j = 0; j < P1[i].size(); ++j) {
			int r = P1[i][j]; 
			if(pq.size() < t) ans ++, pq.push(-r); 
		}
		while(!pq.empty() && -pq.top() <= i) pq.pop(); 
 	}
 	return ans; 
}

inline int solve2(int t) {
	int ans = 0; 
    while(!pq.empty()) pq.pop(); 
	for(int i = 1; i <= pq2; ++i) {
		for(int j = 0; j < P2[i].size(); ++j) {
			int r = P2[i][j]; 
			if(pq.size() < t) ans ++, pq.push(-r); 
		}
		while(!pq.empty() && -pq.top() <= i) pq.pop(); 
 	}
 	return ans; 
}
int main() 
{
    freopen("airport.in", "r", stdin);  
    freopen("airport.out", "w", stdout);
    n = read(), m1 = read(), m2 = read();  
    for(int i = 1; i <= m1; ++i) a[i].l = read(), a[i].r = read(), tmp1[++tot1] = a[i].l, tmp1[++tot1] = a[i].r; 
    for(int i = 1; i <= m2; ++i) b[i].l = read(), b[i].r = read(), tmp2[++tot2] = b[i].l, tmp2[++tot2] = b[i].r; 
	std :: sort(tmp1 + 1, tmp1 + tot1 + 1);  pq1 = std :: unique(tmp1 + 1, tmp1 + tot1 + 1) - tmp1 - 1; 
	std :: sort(tmp2 + 1, tmp2 + tot2 + 1);  pq2 = std :: unique(tmp2 + 1, tmp2 + tot2 + 1) - tmp2 - 1; 
	for(int i = 1; i <= m1; ++i) a[i].l = std :: lower_bound(tmp1 + 1, tmp1 + pq1 + 1, a[i].l) - tmp1, a[i].r = std :: lower_bound(tmp1 + 1, tmp1 + pq1 + 1, a[i].r) - tmp1, P1[a[i].l].push_back(a[i].r); 
	for(int i = 1; i <= m2; ++i) b[i].l = std :: lower_bound(tmp2 + 1, tmp2 + pq2 + 1, b[i].l) - tmp2, b[i].r = std :: lower_bound(tmp2 + 1, tmp2 + pq2 + 1, b[i].r) - tmp2, P2[b[i].l].push_back(b[i].r); 
	for(int i = 1; i <= m1; ++i) f1[i] = solve1(i); 
	for(int i = m1 + 1; i <= n; ++i) f1[i] = f1[m1]; 
	for(int i = 1; i <= m2; ++i) f2[i] = solve2(i); 
	for(int i = m2 + 1; i <= n; ++i) f2[i] = f2[m2];
    
	int ans = 0; 
	for(int i = 0; i <= n; ++i) ans = std :: max(ans, f1[i] + f2[n - i]); 
	std :: cout << ans;
	return 0; 
}
