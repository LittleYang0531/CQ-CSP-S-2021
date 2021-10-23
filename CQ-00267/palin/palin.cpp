#include <bits/stdc++.h>
#define re register
//#define int long long
#define mp(a, b) make_pair(a, b)
using namespace std;
//#define getchar() (p1 == p2 && (p2 = (p1 = buf) + fread(buf, 1, 1 << 21, stdin), p1 == p2) ? EOF : *p1++)
//char buf[1 << 21], *p1 = buf, *p2 = buf;
inline int read()
{
	re int x = 0;
	bool f = 0;
	re char ch = getchar();
	while (!isdigit(ch)) {if (ch == '-') f = 1;ch = getchar();}
	while (isdigit(ch)) x = (x << 1) + (x << 3) + ch - '0', ch = getchar();
	return f ? -x : x;
}
const int N = 5e5 + 5;
bool vis[N];
int a[N << 1];
int num1, num2, ll, rr, LL, RR, n, nn;
bool ans1[N], ans2[N];
inline bool check()
{
	int l = 1, L = 0, r = LL, R = ll;
	num1 = num2 = 0;
	while (num1 < n)
	{
		if (a[l] == a[L] && a[r] == a[R] && R <= nn) ans1[++num1] = ans2[++num2] = 1, r--, R++;
		else
		{
			if (a[l] == a[R] && R <= nn)
			{
				ans1[++num1] = 1;
				ans2[++num2] = 0;
				R++, l++;
			}
			else if (a[l] == a[L] && L >= 1)
			{
				ans1[++num1] = 0;
				ans2[++num2] = 0;
				L--, l++;
			}
			else if (a[r] == a[L] && L >= 1)
			{
				ans1[++num1] = 0;
				ans2[++num2] = 1;
				L--, r--;
			}
			else if (a[r] == a[R] && R <= nn)
			{
				ans1[++num1] = 1;
				ans2[++num2] = 1;
				R++, r--;
			}
			else
			{
				printf("-1\n");
				return 0;
			}
		}
	}
	for (re int i = num1; i; --i)
	{
		if (ans1[i]) putchar('R');
		else putchar('L');
	}
	for (re int i = 1; i <= num2; ++i)
	{
		if (ans2[i]) putchar('R');
		else putchar('L');
	}
	putchar('\n');
	return 1;
}
inline bool check2(int &x, int &y)
{
	for (re int i = 1; i <= n; ++i) vis[i] = 0;
	int l = 1, r = nn;
	while (!vis[a[r]]) vis[a[r]] = 1, --r;
	while (!vis[a[l]]) vis[a[l]] = 1, ++l;
	if (r - l + 1 != n) return 0;
	x = l, y = r;
	return 1;
}
signed main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T = read();
	while (T--)
	{
		n = read(), nn = n << 1;
		num1 = num2 = 0;
		for (re int i = 1; i <= n; ++i) vis[i] = 0;
		for (re int i = 1; i <= nn; ++i) a[i] = read();
		int l = 1, r = nn;
		while (!vis[a[l]]) vis[a[l]] = 1, ++l;
		while (!vis[a[r]]) vis[a[r]] = 1, --r;
		if (r - l + 1 != n)
		{
			if(!check2(l, r))
			{
				printf("-1\n");
				continue;	
			}
		}
		int L = l - 1, R = r + 1;
		bool flag = 0;
		if (R > nn) flag = 1, ll = l, rr = r, LL = L, RR = R;
		while (num1 < n)
		{
			if (a[l] == a[L] && a[r] == a[R] && R <= nn) ans1[++num1] = ans2[++num2] = 1, r--, R++;
			else
			{
				if (a[l] == a[R] && R <= nn)
				{
					ans1[++num1] = 1;
					ans2[++num2] = 0;
					R++, l++;
				}
				else if (a[l] == a[L] && L >= 1)
				{
					ans1[++num1] = 0;
					ans2[++num2] = 0;
					L--, l++;
				}
				else if (a[r] == a[L] && L >= 1)
				{
					ans1[++num1] = 0;
					ans2[++num2] = 1;
					L--, r--;
				}
				else if (a[r] == a[R] && R <= nn)
				{
					ans1[++num1] = 1;
					ans2[++num2] = 1;
					R++, r--;
				}
				else
				{
					if (flag && check()) goto END;
					else
					{
						printf("-1\n");
						goto END;
					}
					
				}
			}
		}
		for (re int i = num1; i; --i)
		{
			if (ans1[i]) putchar('R');
			else putchar('L');
		}
		for (re int i = 1; i <= num2; ++i)
		{
			if (ans2[i]) putchar('R');
			else putchar('L');
		}
		putchar('\n');
		END:;
	}
	return 0;
}
