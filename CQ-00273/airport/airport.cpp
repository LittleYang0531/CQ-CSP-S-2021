#include <bits/stdc++.h>
using namespace std;
long long n, m1, m2, s[200007], s1[200007], ans, fath[200007], fath1[200007];
bool vis1[200007], vis[200007];
struct stu {
	long long a, b;
}x[200007], y[200007];
bool cmp(stu x, stu y) {
	return x.a < y.a;
}
long long find1(long long x) {
	long long ans = 0;
	for(long long i = 1; i <= m1 && x; i++) {
		if(vis[i] == 0) {
			x--;
			ans += s[i];
		}
	}
	return ans;
}
long long find2(long long x) {
	long long ans = 0;
	for(long long i = 1; i <= m2 && x; i++) {
		if(vis1[i] == 0) {
			x--;
			ans += s1[i];
		}
	}
	return ans;
}
int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%lld %lld %lld", &n, &m1, &m2);
	for(long long i = 1; i <= m1; i++) {
		fath[i] = i;
	}
	for(long long i = 1; i <= m1; i++) {
		scanf("%lld %lld", &x[i].a, &x[i].b);
	}
	sort(x + 1, x + 1 + m1, cmp);
	for(long long i = m1; i >= 1; i--) {
		s[i] = 1;
		for(long long j = i + 1; j <= m1; j++) {
			if(x[j].a > x[i].b && fath[j] == j) {
				fath[j] = i;
			}
		}
	}
	for(long long i = m1; i >= 1; i--) {
		if(fath[i] != i) {
			s[fath[i]] += s[i];
			vis[i] = 1;
		}
	}
	for(long long i = 1; i <= m2; i++) {
		fath1[i] = i;
	}
	for(long long i = 1; i <= m2; i++) {
		scanf("%lld %lld", &y[i].a, &y[i].b);
	}
	sort(y + 1, y + 1 + m2, cmp);
	for(long long i = m2; i >= 1; i--) {
		s1[i] = 1;
		for(long long j = i + 1; j <= m2; j++) {
			if(y[j].a > y[i].b && fath1[j] == j) {
				fath1[j] = i;
			}
		}
	}
	for(long long i = m2; i >= 1; i--) {
		if(fath1[i] != i) {
			s1[fath1[i]] += s1[i];
			vis1[i] = 1;
		}
	}
	
	for(long long i = 1; i <= n; i++) {
		ans = max(ans, find1(i) + find2(n - i));
	}
	cout << ans << endl;
	return 0;
}
