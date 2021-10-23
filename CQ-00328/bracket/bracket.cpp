#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 505
#define ll long long
#define mod 1000000007
void Read(int &p)
{
	p = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';
}
int n, k;
int F[N][N], G[N][N];
char S[N];
bool Islef(int c){return S[c] == '(' || S[c] == '?';}
bool Isrig(int c){return S[c] == ')' || S[c] == '?';}
bool Isemp(int c){return S[c] == '*' || S[c] == '?';}
void Add(int &a, int b)
{
	a += b;
	if (a >= mod)
		a -= mod;
}
void Dec(int &a, int b)
{
	a -= b;
	if (a < 0)
		a += mod;
}
queue<int>Q;
int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	Read(n), Read(k);
	scanf("%s", S + 1);
	for (int i = 1; i <= n; i++)
	{
		for (int j = i + 1; j <= n && j <= i + k + 1; j++)
		{
			if (Islef(i) && Isrig(j))
				F[i][j] = 1;
			if (!Isemp(j))
				break;
		}
	}
	for (int l = 2; l <= n; l++)
	{
		for (int i = 1; i + l - 1 <= n; i++)
		{
			int j = i + l - 1;
			//左右匹配的情况
			if (!Islef(i) || !Isrig(j))
				continue;
			for (int s = 0; s <= k; s++)
			{
				if (i + s + 1 >= j - 1)
					break;
				Add(F[i][j], G[i + s + 1][j - 1]);
				if (!Isemp(i + s + 1))
					break;
			}
			if (Isemp(j - 1))
				for (int s = 1; s <= k; s++)
				{
					if (j - s - 1 <= i + 1)
						break;
					Add(F[i][j], G[i + 1][j - s - 1]);
					if (!Isemp(j - s - 1))
						break;
				}
			//左右不匹配的情况
			G[i][j] = F[i][j];
			int all = 0;
			for (int s = i; s < j; s++)
			{
				if (!Isemp(s))
					while (!Q.empty())
					{
						Dec(all, F[i][Q.front()]);
						Q.pop();
					}
				if (!Q.empty() && s - Q.front() > k)
				{
					Dec(all, F[i][Q.front()]);
					Q.pop();
				}
				if (F[i][s])
				{
					Add(all, F[i][s]);
					Q.push(s);
				}
				G[i][j] = (G[i][j] + (ll)all * G[s + 1][j]) % mod;
			}
			while (!Q.empty())
				Q.pop();
		}
	}
	printf("%d\n", G[1][n]);
}
