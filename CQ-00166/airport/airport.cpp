#include <cstdio>
#include <algorithm>
#include <cmath>
#include <cstring>
#include <set>
#define pr pair <int, int>
#define mr make_pair
using namespace std;
const int MAXN = 2e5 + 5;
// 处理出分配第 i 个名额增加的贡献 
// 自然想到二分，发现这样的二分只用做 n 次
int n, u, v, a[MAXN], b[MAXN], maxx; 
struct Node {
	int X, Y;
	bool operator < (const Node P) const { return X < P.X; } 
}arr1[MAXN], arr2[MAXN];
set <pr > s1, s2;
set <pr > :: iterator it;
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &u, &v);
	for(int i = 1; i <= u; i ++) scanf("%d%d", &arr1[i].X, &arr1[i].Y), s1.insert(mr(arr1[i].X, arr1[i].Y));
	for(int i = 1; i <= v; i ++) scanf("%d%d", &arr2[i].X, &arr2[i].Y), s2.insert(mr(arr2[i].X, arr2[i].Y));
	for(int i = 1; i <= n; i ++) {
		if(s1.empty()) { a[i] = a[i - 1]; continue; }
		pr pii = *s1.begin(); a[i] = 1; it = s1.begin(); s1.erase(it);
		while(1) {
			it = s1.lower_bound(mr(pii.second, 0));
			if(it == s1.end()) break;
			s1.erase(it); a[i] ++; pii = (*it);
		}
	}
	for(int i = 1; i <= n; i ++) {
		if(s2.empty()) { b[i] = b[i - 1]; continue; }
		pr pii = *s2.begin(); b[i] = 1; it = s2.begin(); s2.erase(it);
		while(1) {
			it = s2.lower_bound(mr(pii.second, 0));
			if(it == s2.end()) break;
			s2.erase(it); b[i] ++; pii = (*it);
		}
	}
	for(int i = 1; i <= n; i ++) a[i] += a[i - 1];
	for(int i = 1; i <= n; i ++) b[i] += b[i - 1];
	for(int i = 0; i <= n; i ++) maxx = max(maxx, a[i] + b[n - i]);
	printf("%d", maxx);
	return 0;
}
