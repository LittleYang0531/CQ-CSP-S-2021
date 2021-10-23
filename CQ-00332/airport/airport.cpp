#include <cstdio>
#include <set>

typedef std::pair<int, int> PII;
typedef std::set<PII>::iterator IT;
std::set<PII> st1, st2;
int s1[100005], s2[100005], n, m1, m2, ans = 0;

int main() {
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d", &n, &m1, &m2);
	for (int i = 1, x, y; i <= m1; ++ i)
		scanf("%d%d", &x, &y), st1.insert(std::make_pair(x, y));
	for (int i = 1, x, y; i <= m2; ++ i)
		scanf("%d%d", &x, &y), st2.insert(std::make_pair(x, y));
	for (int i = 1; i <= n; ++ i) {
		s1[i] = s1[i - 1], s2[i] = s2[i - 1];
		for (IT j = st1.begin(); j != st1.end();) {
			IT tmp = j;
			j = st1.upper_bound(std::make_pair((*j).second, 0));
			st1.erase(tmp), ++ s1[i];
		}
		for (IT j = st2.begin(); j != st2.end(); ) {
			IT tmp = j;
			j = st2.upper_bound(std::make_pair((*j).second, 0));
			st2.erase(tmp), ++ s2[i];
		}
	}
	for (int i = 0; i <= n; ++ i) ans = std::max(ans, s1[i] + s2[n - i]);
	printf("%d", ans);
	return 0;
}
