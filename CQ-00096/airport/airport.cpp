#include<bits/stdc++.h>
#define mp make_pair
#define ft first
#define sd second
using namespace std;
const int N = 1e5 + 10;
int n, m1, m2, ans1[N], ans2[N], ans;
pair <int, int> a[N], b[N];
queue <int> q;
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	for(int i = 1; i <= m1; ++i) scanf("%d%d", &a[i].ft, &a[i].sd);
	for(int i = 1; i <= m2; ++i) scanf("%d%d", &b[i].ft, &b[i].sd);
	sort(a + 1, a + m1 + 1); sort(b + 1, b + m2 + 1);
	for(int i = 1; i <= n; ++i) {
		int num = 0;
		for(int j = 1; j <= m1; ++j) {
			while(!q.empty() && a[q.front()].sd < a[j].ft) q.pop(), num--;
			if(num < i) q.push(j), ++ans1[i], num++;
		}
//		printf("1 ans1[%d] = %d\n", i, ans1[i]);
		while(!q.empty()) q.pop();
	}
	for(int i = 1; i <= n; ++i) {
		int num = 0;
		for(int j = 1; j <= m2; ++j) {
			while(!q.empty() && b[q.front()].sd < b[j].ft) q.pop(), num--;
			if(num < i) q.push(j), ++ans2[i], num++;
		}
//		printf("2 ans2[%d] = %d\n", i, ans2[i]);
		while(!q.empty()) q.pop();
	}
	for(int i = 0; i <= n; ++i) ans = max(ans1[i] + ans2[n - i], ans);
	printf("%d", ans);
	return 0;
}
