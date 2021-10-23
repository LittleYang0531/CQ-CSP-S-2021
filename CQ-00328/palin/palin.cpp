#include <deque>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 1000005
void Read(int &p)
{
	p = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';
}
int n, m, A[N], V[N];
int Idx(int x){return x <= n ? x + n : x - n;}
deque<int>Q[2];
char ans[N];
bool Solve()
{
	if (!Q[0].empty())V[Q[0].back()] = 1;
	if (!Q[1].empty())V[Q[1].back()] = 2;
	for (int i = 2; i <= n; i++)
	{
		int a = 0, b = 0;
		if (!Q[0].empty() && V[Idx(Q[0].front())])a = Q[0].front();
		if (!Q[1].empty() && V[Idx(Q[1].front())])b = Q[1].front();
		if (a)
		{
			ans[i] = 'L';
			ans[m - i + 1] = (V[Idx(a)] == 1 ? 'L' : 'R');
			Q[0].pop_front();
			int x = V[Idx(a)] - 1;
			Q[x].pop_back();
			if (!Q[x].empty())V[Q[x].back()] = x + 1;
			continue;
		}
		if (b)
		{
			ans[i] = 'R';
			ans[m - i + 1] = (V[Idx(b)] == 1 ? 'L' : 'R');
			Q[1].pop_front();
			int x = V[Idx(b)] - 1;			
			Q[x].pop_back();
			if (!Q[x].empty())V[Q[x].back()] = x + 1;
			continue;
		}
		return 0;
	}
	return 1;
}
int main()
{
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	int T;
	Read(T);
	while (T--)
	{
		Read(n), m = n * 2;
		for (int i = 1; i <= m; i++)
			V[A[i]] = 0;
		for (int i = 1; i <= m; i++)
		{
			Read(A[i]);
			if (V[A[i]])
				A[i] += n;
			else
				V[A[i]] = 1;
		}
		int flg;
		//×ó±ß
		ans[1] = 'L', ans[m] = 'L';
		while (!Q[0].empty())Q[0].pop_back();
		while (!Q[1].empty())Q[1].pop_back();
		for (int i = 1; i <= m; i++)
			V[A[i]] = 0;
		flg = 0;
		for (int i = 2; i <= m; i++)
		{
			if (A[i] == Idx(A[1]))
			{
				flg = 1;
				continue;
			}
			if (!flg)
				Q[0].push_back(A[i]);
			else
				Q[1].push_front(A[i]);
		}
		if (Solve())
		{
			puts(ans + 1);
			continue;
		}
		//ÓÒ±ß
		ans[1] = 'R', ans[m] = 'L';
		while (!Q[0].empty())Q[0].pop_back();
		while (!Q[1].empty())Q[1].pop_back();
		for (int i = 1; i <= m; i++)
			V[A[i]] = 0;
		flg = 0;
		for (int i = 1; i < m; i++)
		{
			if (A[i] == Idx(A[m]))
			{
				flg = 1;
				continue;
			}
			if (!flg)
				Q[0].push_back(A[i]);
			else
				Q[1].push_front(A[i]);
		}
		if (Solve())
		{
			puts(ans + 1);
			continue;
		}
		puts("-1");
	}
}
