#include <bits/stdc++.h>
#define rep1(i, l, r) for (int i = l; i <= r; ++i)
#define rep2(i, l, r) for (int i = l; i >= r; --i)
#define fst first
#define snd second
#define mp make_pair
#define pb push_back
#define il inline
#define ptc putchar
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef pair <ll, ll> pll;
const int MAXN = 1e5 + 10, INF = ~0U >> 1, inf = ~0U >> 2;

template <typename T>
il void read(T &x)
{
	x = 0; T f = 1; char ch;
	while (!isdigit(ch = getchar())) if (ch == '-') f = -1;
	while (isdigit(ch)) x = (x << 1) + (x << 3) + (ch & 15), ch = getchar(); x *= f;
}

template <typename T>
il void write(T x)
{
	if (x < 0) ptc('-'), x = -x;
	if (x > 9) write(x / 10);
	ptc(x % 10 + '0');
}

int n, m1, m2, ans; pii loc[MAXN], ard[MAXN];
priority_queue <int>t;

il int numl(int p)
{
	while (t.size()) t.pop();
	int cnt = 0, ans = 0;
	rep1(i, 1, m1)
	{
		if (t.size() && -t.top() <= loc[i].fst) --cnt, t.pop();
		if (cnt < p) ++cnt, ++ans, t.push(-loc[i].snd);
	}
	return ans;
}

il int numa(int p)
{
	while (t.size()) t.pop();
	int cnt = 0, ans = 0;
//	cout << "?!" << p << endl;
	rep1(i, 1, m2)
	{
		if (t.size() && -t.top() <= ard[i].fst) --cnt, t.pop();
		if (cnt < p) ++cnt, ++ans, t.push(-ard[i].snd);
//		cout << "!!!" << cnt << endl;
	}
	return ans;
}

int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	read(n); read(m1); read(m2);
	rep1(i, 1, m1) read(loc[i].fst), read(loc[i].snd);
	rep1(i, 1, m2) read(ard[i].fst), read(ard[i].snd);
	if (m1 > m2) swap(m1, m2), swap(loc, ard);
	sort(loc + 1, loc + 1 + m1); sort(ard + 1, ard + 1 + m2);
	int p = min(n, min(m1, m2));
	if (p * (m1 + m2) <= 2e8)
	{
		rep1(i, 0, p)
		{
			ans = max(ans, numl(i) + numa(n - i));
	//		cout << numl(i) << " " << numa(n - i) << endl;
		}
		write(ans); cout << endl; return 0;
	}
	int l = p / 2;
	ans = max(numl(l) + numa(n - l), numl(l + 1) + numa(n - l - 1));
	return 0;
}

