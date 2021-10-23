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
const int MAXN = 1e6 + 10, INF = ~0U >> 1, inf = ~0U >> 2;

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
int T, n, a[MAXN], b[MAXN];
bool f, vis[MAXN];

il bool isa()
{
	rep1(i, 1, (n >> 1)) if (b[i]^b[n + 1 - i]) return false;
	return true;
}

il void dfs(int step, string ans, int l, int r)
{
	if (f) return;
	if (step > (n >> 1))
	{
		rep2(i, (n >> 1), 1)
			if (a[l] == b[i]) ans += 'L', l++;
			else if (a[r] == b[i]) ans += 'R', r--;
			else return;
		cout << ans; f = true;
		return;
	}
	if (!vis[a[l]])
		b[step] = a[l], vis[a[l]] = true,
		dfs(step + 1, ans + 'L', l + 1, r), vis[a[l]] = false;
	if (step^n && !vis[a[r]])
		b[step] = a[r], vis[a[r]] = true,
		dfs(step + 1, ans + 'R', l, r - 1), vis[a[r]] = false;
}

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	read(T);
	while (T--)
	{
		read(n); n <<= 1; f = false;
		rep1(i, 1, n) read(a[i]), b[i] = a[i];
		if (isa())
		{
			rep1(i, 1, n) ptc('L');
			ptc('\n'); continue;
		}
		dfs(1, "", 1, n);
		if (!f) puts("-1");
		else ptc('\n');
	}
	return 0;
}

