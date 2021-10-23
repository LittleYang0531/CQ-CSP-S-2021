#include <bits/stdc++.h>
using namespace std;
const int N = 500010;
int t, n, a[N << 1], ot[N << 1], pos[N << 1];
char s[N << 1];
inline int read()
{
	int r = 0, f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-')f = -1;ch = getchar();}
	while (ch >= '0' && ch <= '9') r = (r << 1) + (r << 3) + (ch ^ 48), ch = getchar();
	return r * f;
}
int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	
	t = read();
	while (t --)
	{
		n = read();
		s[n << 1 | 1] = '\0';
		for (int i = 1;i <= (n << 1);i ++) pos[i] = 0; 
		for (int i = 1;i <= (n << 1);i ++)
		{
			a[i] = read();
			if (pos[a[i]]) ot[i] = pos[a[i]], ot[pos[a[i]]] = i;
			else pos[a[i]] = i;
		}
//		if (t == 1)continue;
		//L
		s[1] = 'L', s[n << 1] = 'L';
		int l = 2, r = n << 1, x1 = ot[1] - 1, x2 = ot[1] + 1;
		if (x1 < l || x1 > r) x1 = 0;
		if (x2 < l || x2 > r) x2 = 0;
		bool ok = 1;
		for (int i = 2;i <= n;i ++)
		{
			if (ot[x2] == l || x1 == 0 || (ot[x1] != l && ot[x1] != r)) swap(x1, x2);
//			cout<<i<<' '<<x1<<' '<<x2<<endl;
			if (ot[x1] == l)
			{
				l ++;
				s[i] = 'L';
				if (x1 < x2)
				{
					x1 --;
					if (x1 < l) x1 = 0;
					s[(n << 1) - i + 1] = 'L';
				}
				else x1 ++, s[(n << 1) - i + 1] = 'R';
			}
			else if (ot[x1] == r)
			{
				r --;
				s[i] = 'R';
				if (x1 > x2)
				{
					x1 ++;
					if (x1 > r) x1 = 0;
					s[(n << 1) - i + 1] = 'R';
				}
				else x1 --, s[(n << 1) - i + 1] = 'L';
			}
			else
			{
				ok = 0;
				break;
			}
		}
		if (ok)
		{
			printf("%s\n", s + 1);
			continue;
		}
		//R
		s[1] = 'R', s[n << 1] = 'L';
		l = 1, r = (n << 1) - 1, x1 = ot[n << 1] + 1, x2 = ot[n << 1] - 1;
		if (x1 < l || x1 > r) x1 = 0;
		if (x2 < l || x2 > r) x2 = 0;
		ok = 1;
		for (int i = 2;i <= n;i ++)
		{
			if (ot[x2] == l || x1 == 0 || (ot[x1] != l && ot[x1] != r)) swap(x1, x2);
//			cout<<i<<' '<<x1<<' '<<x2<<endl;
			if (ot[x1] == l)
			{
				l ++;
				s[i] = 'L';
				if (x1 < x2)
				{
					x1 --;
					if (x1 < l) x1 = 0;
					s[(n << 1) - i + 1] = 'L';
				}
				else x1 ++, s[(n << 1) - i + 1] = 'R';
			}
			else if (ot[x1] == r)
			{
				r --;
				s[i] = 'R';
				if (x1 > x2)
				{
					x1 ++;
					if (x1 > r) x1 = 0;
					s[(n << 1) - i + 1] = 'R';
				}
				else x1 --, s[(n << 1) - i + 1] = 'L';
			}
			else
			{
				ok = 0;
				break;
			}
		}
		if (ok)
		{
			printf("%s\n", s + 1);
			continue;
		}
		puts("-1");
	}
	return 0;
}
