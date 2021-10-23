#include<bits/stdc++.h>
using namespace std;
struct pd{
	int l, r, op;
	bool operator <(const pd &x) const{
		return r > x.r;
	}
}a[100005];
int n, m1, m2, ans;
priority_queue<pd> q1, q2;
bool cmp(pd x, pd y){
	return x.l < y.l;
}
int main(){
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d %d %d", &n, &m1, &m2);
	for (int i = 1; i <= m1 + m2; i++){
		scanf("%d %d", &a[i].l, &a[i].r);
		if (i <= m1) a[i].op = 1;
		else a[i].op = 2;
	}
	stable_sort(a + 1, a + m1 + m2 + 1, cmp);
	for (int i = 0; i <= n; i++){
		int res1 = 0, res2 = 0;
		while(!q1.empty()) q1.pop();
		while(!q2.empty()) q2.pop();
		for (int j = 1; j <= m1 + m2; j++){
			if (a[j].op == 1){
				while(!q1.empty() && q1.top().r < a[j].l) q1.pop();
				if (q1.size() + 1 <= i) res1++, q1.push(a[j]);	
			}
			if (a[j].op == 2){
				while(!q2.empty() && q2.top().r < a[j].l) q2.pop();
				if (q2.size() + 1 <= n - i) res2++, q2.push(a[j]);
			}
		}
		ans = max(ans, res1 + res2);
	}
	printf("%d", ans);
	return 0;
}
