#include <bits/stdc++.h>
using namespace std;
const int N = 100010;
int n, m1, m2, a[N << 1], tt[N << 1], dd[N << 1], ans1[N], ans2[N], c[N], pos[N], t;
inline int read()
{
	int r = 0, f = 1;char ch = getchar();
	while (ch < '0' || ch > '9'){if (ch == '-')f = -1;ch = getchar();}
	while (ch >= '0' && ch <= '9') r = (r << 1) + (r << 3) + (ch ^ 48), ch = getchar();
	return r * f;
}
bool cmp(int i, int j){return a[i] < a[j];}
void insert(int x, int v)
{
	for (;x <= n;x += x & -x) c[x] += v;
}
void solve(int *ans, int m)
{
	memset(pos, 0, sizeof pos);
	memset(c, 0, sizeof c);
	for (int i = 1;i <= m;i ++)
	{
		a[i] = read();a[i + m] = read();
		tt[i] = i, tt[i + m] = i + m;
	}
	sort(tt + 1, tt + 1 + (m << 1), cmp);
	for (int i = 1;i <= (m << 1);i ++) a[tt[i]] = i;
//	for (int i = 1;i <= m;i ++) cout << i << ' ' << a[i] << ' ' << a[i + m] << endl;
	for (int i = 1;i <= m;i ++) dd[a[i]] = i, dd[a[i + m]] = i;
	t = log2(m) + 1;
	for (int i = 1;i <= (m << 1);i ++)
	{
		if (!pos[dd[i]]){
			int x = 0, sum = 0;
			for (int j = t;~ j;j --)
				if (x + (1 << j) <= min(m, n))
				{
					int ns = sum + c[x + (1 << j)];
					if (ns == x + (1 << j)) x += (1 << j), sum = ns;
				}
			pos[dd[i]] = x + 1;
//			cout<<">>>"<<i<<' '<<x + 1  << endl;
			insert(x + 1, 1);
			ans[x + 1] ++;
		}
		else insert(pos[dd[i]], -1);
	}
//	cout<<"<<<";
	for (int i = 1;i <= n;i ++) ans[i] += ans[i - 1];//, cout << ans[i] << ' ';
//	cout<<"<<<\n";
}
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	n = read();m1 = read();m2 = read();
	solve(ans1, m1);solve(ans2, m2);
	int res = 0;
	for (int i = 0;i <= n;i ++) res = max(res, ans1[i] + ans2[n - i]);
	printf("%d", res);
	return 0;
}
