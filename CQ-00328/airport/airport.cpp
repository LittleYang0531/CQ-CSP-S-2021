#include <set>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 100005
void Read(int &p)
{
	p = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';
}
int n, m1, m2;
set<pair<int, int> >A[2];
int F[2][N];
int main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	Read(n), Read(m1), Read(m2);
	for (int i = 1; i <= m1; i++)
	{
		int a, b;
		Read(a), Read(b);
		A[0].insert(make_pair(a, b));
	}
	for (int i = 1; i <= m2; i++)
	{
		int a, b;
		Read(a), Read(b);
		A[1].insert(make_pair(a, b));
	}
	for (int s = 0; s < 2; s++)
		for (int i = 1; i <= n; i++)
		{
			F[s][i] = F[s][i - 1];
			if (A[s].empty())
				continue;
			pair<int, int> x = *A[s].begin();
			for (; ; )
			{
				F[s][i]++;
				A[s].erase(x);
				if (A[s].lower_bound(make_pair(x.second, 0)) != A[s].end())
					x = *A[s].lower_bound(make_pair(x.second, 0));
				else
					break;
			}
		}
	int ans = 0;
	for (int i = 0; i <= n; i++)
		ans = max(ans, F[0][i] + F[1][n - i]);
	printf("%d\n", ans);
}
