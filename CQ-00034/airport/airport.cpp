#include <cstdio>
#include <algorithm>
#include <utility>
#include <set>
using namespace std;

int Max(int a, int b) { return (a > b) ? a : b; }
int Min(int a, int b) { return (a < b) ? a : b; }

int rint()
{
	int x = 0, fx = 1; char c = getchar();
	while (c < '0' || c > '9') { fx ^= (c == '-'); c = getchar(); }
	while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	if (!fx) return -x;
	return x;
}

const int MAX_n = 1e5;
const int MAX_m = 1e5;

int n, m1, m2;
pair<int, int> p1[MAX_m + 5];
pair<int, int> p2[MAX_m + 5];

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = rint(), m1 = rint(), m2 = rint();
	for (int i = 1; i <= m1; i++)
	{
		p1[i].first = rint();
		p1[i].second = rint();
	}
	for (int i = 1; i <= m2; i++)
	{
		p2[i].first = rint();
		p2[i].second = rint();
	}
	if (n >= m1 + m2) { printf("%d\n", m1 + m2); return 0; }
	sort(p1 + 1, p1 + m1 + 1);
	sort(p2 + 1, p2 + m2 + 1);
	int ans = 0, down = Max(n - m2, 0), up = Min(m1, n);
	for (int i = down; i <= up; i++)
	{
		int j = n - i, res = 0;
		set<int> s1, s2;
		for (int k = 1; k <= m1; k++)
		{
			if (s1.size() < i)
			{
				s1.insert(p1[k].second);
				++res;
			}
			else if (s1.size() && *s1.begin() < p1[k].first)
			{
				s1.erase(s1.begin());
				s1.insert(p1[k].second);
				++res;
			}
		}
		for (int k = 1; k <= m2; k++)
		{
			if (s2.size() < j)
			{
				s2.insert(p2[k].second);
				++res;
			}
			else if (s2.size() && *s2.begin() < p2[k].first)
			{
				s2.erase(s2.begin());
				s2.insert(p2[k].second);
				++res;
			}
		}
		ans = Max(ans, res);
	}
	printf("%d\n", ans);
	return 0;
}

