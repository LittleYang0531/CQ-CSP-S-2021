#include <cstdio>
#include <iostream>
#include <algorithm>
#include <cstring>
using namespace std;
inline int Max(int x, int y) {return x > y ? x : y;}

struct node1 {
	int rea, lea;
} p1[100005];
inline bool operator < (node1 x, node1 y) {
	return x.rea < y.rea;
}
struct node2 {
	int rea, lea;
} p2[100005];
inline bool operator < (node2 x, node2 y) {
	return x.rea < y.rea;
}

int sum1[100005], sum2[100005];
bool mark[100005];

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	int n, m1, m2, ans = 0, head = 1;
	scanf("%d %d %d", &n, &m1, &m2);
	for (int i = 1; i <= m1; i++) scanf("%d %d", &p1[i].rea, &p1[i].lea);
	sort(p1 + 1, p1 + 1 + m1);
	for (int i = 1; i <= m2; i++) scanf("%d %d", &p2[i].rea, &p2[i].lea);
	sort(p2 + 1, p2 + 1 + m2);
	for (int i = 1; i <= n; i++) {
		int r = -1;
		for (int j = 1; j <= m1; j++) {
			if (mark[j]) continue;
			if (p1[j].rea < r) continue;
			mark[j] = true;
			sum1[i]++;
			r = p1[j].lea;
		}
	}
	memset(mark, false, sizeof(mark));
	for (int i = 1; i <= n; i++) {
		int r = -1;
		for (int j = 1; j <= m2; j++) {
			if (mark[j]) continue;
			if (p2[j].rea < r) continue;
			mark[j] = true;
			sum2[i]++;
			r = p2[j].lea;
		}
	}
	for (int i = 1; i <= n; i++) sum1[i] += sum1[i - 1], sum2[i] += sum2[i - 1];
	for (int i = 0; i <= n; i++) ans = Max(ans, sum1[i] + sum2[n - i]);
	printf("%d", ans);
	return 0;
}
