#include <bits/stdc++.h>
using namespace std;

const int maxn = (int) 1e5 + 5;

struct node { int s, t; } a[maxn], b[maxn];
struct que { int Time, num; };
int n, tot, m1, m2, ans, s1[maxn], s2[maxn], sum1[maxn], sum2[maxn];
bool is_zhan[maxn];
priority_queue <que> q;

bool cmp(node x, node y) { return x.s < y.s; }
operator<(const que x, const que y) { return x.Time > y.Time; }

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for(int i = 1; i <= m1; i++) scanf("%d %d", &a[i].s, &a[i].t);
	for(int i = 1; i <= m2; i++) scanf("%d %d", &b[i].s, &b[i].t);
	stable_sort(a + 1, a + m1 + 1, cmp);
	stable_sort(b + 1, b + m2 + 1, cmp);
	//国内
	for(int i = 1; i <= m1; i++) {
		while(!q.empty() && q.top().Time < a[i].s) {
			is_zhan[q.top().num] = 0;
			q.pop();
		}
		tot = 1;
		while(is_zhan[tot]) ++tot;
		is_zhan[tot] = 1;
		++s1[tot];
		que qwq;
		qwq.Time = a[i].t;
		qwq.num = tot;
		q.push(qwq);
	}
	memset(is_zhan, 0,sizeof(is_zhan));
	while(!q.empty()) q.pop();
	//国际 
	for(int i = 1; i <= m2; i++) {
		while(!q.empty() && q.top().Time < b[i].s) {
			is_zhan[q.top().num] = 0;
			q.pop();
		}
		tot = 1;
		while(is_zhan[tot]) ++tot;
		is_zhan[tot] = 1;
		++s2[tot];
		que qwq;
		qwq.Time = b[i].t;
		qwq.num = tot;
		q.push(qwq);
	}
	//汇总 
	for(int i = 1; i <= n; i++) sum1[i] = sum1[i - 1] + s1[i];
	for(int i = 1; i <= n; i++) sum2[i] = sum2[i - 1] + s2[i];
	for(int i = 0; i <= n; i++) ans = max(ans, sum1[i] + sum2[n - i]);
	printf("%d", ans);
	return 0;
}

/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

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
