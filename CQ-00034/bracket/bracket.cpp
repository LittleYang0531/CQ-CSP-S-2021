#include <cstdio>

int rint()
{
	int x = 0, fx = 1; char c = getchar();
	while (c < '0' || c > '9') { fx ^= (c == '-'); c = getchar(); }
	while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	if (!fx) return -x;
	return x;
}

const int mod = 1e9 + 7;
const int MAX_n = 500;
const int MAX_k = 500;

char s[MAX_n + 5];
int n, k, pre[MAX_n + 5];
int f[MAX_n + 5][MAX_n + 5];
long long g[MAX_n + 5][MAX_n + 5];
long long dp[MAX_n + 5][MAX_n + 5];
long long dpp[MAX_n + 5][MAX_n + 5];
long long dps[MAX_n + 5][MAX_n + 5];

int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	n = rint(), k = rint();
	scanf("%s", s + 1);
	for (int i = 1; i <= n; i++)
	{
		pre[i] = pre[i - 1] + (s[i] == '*' || s[i] == '?');
		if (i < n && (s[i] == '(' || s[i] == '?') && (s[i + 1] == ')' || s[i + 1] == '?')) g[i][i + 1] = dp[i][i + 1] = 1;
	}
	for (int len = 1; len <= 2 && len <= k; len++)
		for (int i = 1, j = len; j <= n; i++, j++)
			if (pre[j] - pre[i - 1] == len) f[i][j] = 1;
	for (int len = 3; len <= n; len++)
	{
		for (int i = 1, j = len; j <= n; i++, j++)
		{
			if (pre[j] - pre[i - 1] == len && len <= k) f[i][j] = 1;
			if ((s[i] == '(' || s[i] == '?') && (s[j] == ')' || s[j] == '?'))
			{
				dp[i][j] = g[i][j] = (f[i + 1][j - 1] + dp[i + 1][j - 1] + dpp[i + 1][j - 1] + dps[i + 1][j - 1]) % mod;
				for (int x = i; x < j; x++)
					dp[i][j] = (dp[i][j] + g[i][x] * dp[x + 1][j] % mod + g[i][x] * dpp[x + 1][j] % mod) % mod;
			}
			for (int x = i; x < j && f[i][x]; x++)
				dpp[i][j] = (dpp[i][j] + dp[x + 1][j]) % mod;
			for (int x = j; x > i && f[x][j]; x--)
				dps[i][j] = (dps[i][j] + dp[i][x - 1]) % mod;
//			printf(" %d %d %d %lld %lld %lld %lld\n", i, j, f[i][j], g[i][j], dp[i][j], dpp[i][j], dps[i][j]);
		}
	}
	printf("%lld\n", dp[1][n]);
	return 0;
}

