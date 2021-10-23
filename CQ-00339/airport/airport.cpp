#include <stdio.h>
#include <algorithm>
#include <queue>
#include <vector>
using namespace std;
const int M = 100005;

int n, m1, m2, ans;
priority_queue<int, vector<int>, greater<int> > pq;

class plane {
	public:
		int arr, lea;
		
		bool operator < (const plane& oth) {
			return arr < oth.arr;
		}
}; 
plane p1[M], p2[M];

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for (int i = 1; i <= m1; i++) scanf("%d %d", &p1[i].arr, &p1[i].lea);
	for (int i = 1; i <= m2; i++) scanf("%d %d", &p2[i].arr, &p2[i].lea);
	sort(p1 + 1, p1 + 1 + m1);
	sort(p2 + 1, p2 + 1 + m2);
	for (int i = 0; i <= n; i++) {
		int j = n - i, tot = i, temp = 0;
		while (!pq.empty()) pq.pop();
		for (int j = 1; j <= m1; j++) {
			while (!pq.empty() && pq.top() < p1[j].arr) {
				pq.pop();
				tot++;
			}
			if (tot > 0) {
				temp++;
				tot--;
				pq.push(p1[j].lea);
			}
		}
		tot = j;
		while (!pq.empty()) pq.pop();
		for (int j = 1; j <= m2; j++) {
			while (!pq.empty() && pq.top() < p2[j].arr) {
				pq.pop();
				tot++;
			}
			if (tot > 0) {
				temp++;
				tot--;
				pq.push(p2[j].lea);
			}
		}
		ans = max(ans, temp);
	}
	printf("%d", ans);
	return 0;
}
/*
2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
