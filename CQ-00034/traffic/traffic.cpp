#include <cstdio>
#include <cstdlib>
#include <ctime>
using namespace std;

long long Max(long long a, long long b) { return (a > b) ? a : b; }
long long Min(long long a, long long b) { return (a < b) ? a : b; }

int rint()
{
	int x = 0, fx = 1; char c = getchar();
	while (c < '0' || c > '9') { fx ^= (c == '-'); c = getchar(); }
	while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	if (!fx) return -x;
	return x;
}

const int MAX_n = 500;
const int MAX_m = 500;
const int MAX_T = 50;
const int MAX_k = 50;

int n, m, T;
int c[MAX_n + 5][MAX_m + 5];
int x1[MAX_n + 5][MAX_m + 5];
int x2[MAX_n + 5][MAX_m + 5];
int x3[MAX_k + 5], p[MAX_k + 5], t[MAX_k + 5];

int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	srand(time(0));
	n = rint(), m = rint(), T = rint();
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++)
			x1[i][j] = rint();
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++)
			x2[i][j] = rint();
	while (T--)
	{
		int k = rint();
		for (int j = 1; j <= k; j++)
			x3[j] = rint(), p[j] = rint(), t[j] = rint();
		long long ans = 5e18;
		for (int o = 1; o <= 300; o++)
		{
			long long tmp = 0;
			for (int i = n; i >= 1; i--)
			{
				for (int j = m; j >= 1; j--)
				{
					c[i][j] = rand() & 1;
					if (i + 1 <= n && c[i][j] != c[i + 1][j]) tmp += x1[i][j];
					if (j + 1 <= m && c[i][j] != c[i][j + 1]) tmp += x2[i][j];
				}
			}
			for (int j = 1; j <= k; j++)
			{
				if (p[j] <= m)
				{
					if (t[j] != c[1][p[j]]) tmp += x3[j];
				}
				else if (p[j] <= m + n)
				{
					if (t[j] != c[p[j] - m][m]) tmp += x3[j];
				}
				else if (p[j] <= 2 * m + n)
				{
					if (t[j] != c[n][2 * m + n + 1 - p[j]]) tmp += x3[j];
				}
				else
				{
					if (t[j] != c[2 * m + 2 * n + 1 - p[j]][1]) tmp += x3[j];
				}
			}
			ans = Min(ans, tmp);
		}
		printf("%lld\n", ans);
	}
	return 0;
}

