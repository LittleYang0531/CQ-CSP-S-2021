#include <cstdio>

int rint()
{
	int x = 0, fx = 1; char c = getchar();
	while (c < '0' || c > '9') { fx ^= (c == '-'); c = getchar(); }
	while ('0' <= c && c <= '9') { x = (x << 3) + (x << 1) + (c ^ 48); c = getchar(); }
	if (!fx) return -x;
	return x;
}

const int MAX_n = 5e5;
const int MAX_m = 1e6;

int n, m, k;
int a[MAX_m + 5];
char ans[MAX_m + 5];

bool chk(int l, int r)
{
	for (int i = l; i <= r; i++)
		if (a[i] != a[r - (i - l)]) return false;
	return true;
}

bool dfs(int p, int l1, int r1, int l2, int r2)
{
	if (p > n)
	{
		return true;
	}
	else if (l1 > r1)
	{
		if (chk(l2, r2))
		{
			for (int i = p; i <= n; i++)
				ans[i] = ans[m + 1 - i] = 'R';
			return true;
		}
		return false;
	}
	else if (l2 > r2)
	{
		if (chk(l1, r1))
		{
			for (int i = p; i <= n; i++)
				ans[i] = ans[m + 1 - i] = 'L';
			return true;
		}
		return false;
	}
	if (l1 != r1 && a[l1] == a[r1])
	{
		ans[p] = 'L'; ans[m + 1 - p] = 'L';
		if (dfs(p + 1, l1 + 1, r1 - 1, l2, r2)) return true;
	}
	else if (l1 != l2 && a[l1] == a[l2])
	{
		ans[p] = 'L'; ans[m + 1 - p] = 'R';
		if (dfs(p + 1, l1 + 1, r1, l2 + 1, r2)) return true;
	}
	if (r2 != r1 && a[r2] == a[r1])
	{
		ans[p] = 'R'; ans[m + 1 - p] = 'L';
		if (dfs(p + 1, l1, r1 - 1, l2, r2 - 1)) return true;
	}
	else if (r2 != l2 && a[r2] == a[l2])
	{
		ans[p] = 'R'; ans[m + 1 - p] = 'R';
		if (dfs(p + 1, l1, r1, l2 + 1, r2 - 1)) return true;
	}
	return false;
}

int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T = rint();
	while (T--)
	{
		int p1, p2;
		n = rint(); m = n << 1;
		for (int i = 1; i <= m; i++)
		{
			a[i] = rint();
			if (a[i] == a[1]) p1 = i;
		}
		for (int i = m - 1; i >= 1; i--)
			if (a[i] == a[m]) { p2 = i; break; }
		if (a[1] == a[m])
		{
			if (chk(2, m - 1))
			{
				for (int i = 1; i <= m; i++) printf("L");
				printf("\n");
			}
			else
			{
				printf("-1\n");
			}
		}
		else
		{
			if (dfs(2, 2, p1 - 1, p1 + 1, m))
			{
				ans[1] = 'L'; ans[m] = 'L';
				printf("%s\n", ans + 1);
			}
			else if (dfs(2, 1, p2 - 1, p2 + 1, m - 1))
			{
				ans[1] = 'R'; ans[m] = 'L';
				printf("%s\n", ans + 1);
			}
			else
			{
				printf("-1\n");
			}
		}
	}
	return 0;
}

