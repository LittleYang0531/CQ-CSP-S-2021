#include <queue>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
using namespace std;
#define N 505
#define V 260005
#define E (V << 2)
#define ll long long
void Read(int &p)
{
	p = 0;
	char c = getchar();
	for (; c < '0' || c > '9'; c = getchar());
	for (; c >= '0' && c <= '9'; c = getchar())p = p * 10 + c - '0';
}
int n, m, g, s, T;
int D[N][N], R[N][N], X[N][N];
struct Node
{
	int x;
	ll d;
	Node(){}
	Node(int a, ll b){x = a, d = b;}
	bool operator < (const Node &b)const{return d > b.d;}
};
struct Point
{
	int p, s, c;
}tmp[N];
bool cmp(Point a, Point b){return a.p < b.p;}
int fir[V], nex[E], tar[E], len[E], cnt;
ll dis[55][V], F[105][105][2];
int vis[V], C[N];
void add(int a, int b, int c)
{
	++cnt;
	tar[cnt] = b;
	len[cnt] = c;
	nex[cnt] = fir[a];
	fir[a] = cnt;
}
void Add(int a, int b, int c){add(a, b, c), add(b, a, c);}
void Link(int x, int k)
{
	if (k == m || k == m + n || k == 2 * m + n || k == 2 * m + 2 * n)
		return;
	if (k < m){Add(x, X[1][k], R[1][k]); return;}
	k -= m;
	if (k < n){Add(x, X[k][m - 1], D[k][m]); return;}
	k -= n;
	if (k < m){Add(x, X[n - 1][m - k], R[n][m - k]); return;}
	k -= m;
	if (k < n){Add(x, X[n - k][1], D[n - k][1]); return;}
}
priority_queue<Node>Q;
void Dijkstra(int s, int g, ll *d)
{
	for (int i = 1; i <= g; i++)
		d[i] = 1ll << 60, vis[i] = 0;
	d[s] = 0;
	Q.push(Node(s, 0));
	while (!Q.empty())
	{
		int x = Q.top().x;
		Q.pop();
		if (vis[x])
			continue;
		vis[x] = 1;
		for (int i = fir[x]; i; i = nex[i])
		{
			int v = tar[i];
			if (d[v] > d[x] + len[i])
			{
				d[v] = d[x] + len[i];
				Q.push(Node(v, d[v]));
			}
		}
	}
}
ll Getdis(int a, int b)
{
	if (a <= 0)a += s;
	if (b <= 0)b += s;
	if (a > s)a -= s;
	if (b > s)b -= s;
	return dis[a][g + b];
}
int main()
{
	freopen("traffic.in", "r", stdin);
	freopen("traffic.out", "w", stdout);
	Read(n), Read(m), Read(T);
	for (int i = 1; i < n; i++)
		for (int j = 1; j <= m; j++)
			Read(D[i][j]);
	for (int i = 1; i <= n; i++)
		for (int j = 1; j < m; j++)
			Read(R[i][j]);
	for (int i = 1; i < n; i++)
		for (int j = 1; j < m; j++)
			X[i][j] = (i - 1) * (m - 1) + j;
	while (T--)
	{
		Read(s);
		int flg = 0;
		for (int i = 1; i <= s; i++)
		{
			Read(tmp[i].s), Read(tmp[i].p), Read(tmp[i].c);
			if (i > 1)
				flg |= (tmp[i].c != tmp[i - 1].c);
		}
		if (!flg)
		{
			puts("0");
			continue;
		}
		sort(tmp + 1, tmp + s + 1, cmp);
		for (int i = 1; i < n; i++)
		{
			for (int j = 1; j < m; j++)
			{
				if (i + 1 < n)
					Add(X[i][j], X[i + 1][j], R[i + 1][j]);
				if (j + 1 < m)
					Add(X[i][j], X[i][j + 1], D[i][j + 1]);
			}
		}
		g = (n - 1) * (m - 1);
		for (int i = 1; i <= s; i++)
		{
			C[i] = C[s + i] = tmp[i].c;
			int j = (i == s) ? 1 : i + 1;
			Add(g + i, g + j, tmp[j].s);//相邻两位
			for (int k = tmp[i].p; k != tmp[j].p; )
			{
				Link(g + i, k);
				k++;
				if (k > 2 * (n + m))
					k = 1;
			}
		}
		for (int i = 1; i <= s; i++)
			Dijkstra(g + i, g + s, dis[i]);
		
		for (int i = 1; i <= 2 * s; i++)
		{
			F[i][i][C[i]] = 0;
			F[i][i][!C[i]] = 1ll << 60;
		}
		for (int l = 2; l <= s; l++)
		{
			for (int i = 1; i + l - 1 <= 2 * s; i++)
			{
				int j = i + l - 1;
				for (int c = 0; c < 2; c++)
				{
					F[i][j][c] = 1ll << 60;
					//第0种，如果全部一样
					int flg = 0;
					for (int k = i; k <= j; k++)
						if (C[k] != c)
							flg = 1;
					if (!flg)
					{
						F[i][j][c] = 0;
						continue;
					}
					
					//第1种，中间划出一坨
					for (int p = i + 1; p <= j; p++)
					{
						for (int q = j - 1; q >= p; q--)
						{
							if (p > i || q < j)
								F[i][j][c] = min(F[i][j][c], F[p][q][!c] + Getdis(p - 1, q));
							if (C[q] != c)
								break;
						}
						if (C[p] != c)
							break;
					}
					//第2种，分成两堆
					for (int k = i; k < j; k++)
						F[i][j][c] = min(F[i][j][c], F[i][k][c] + F[k + 1][j][c]);
				}
			}
		}
		ll ans = 1ll << 60;
		for (int i = 1; i <= s; i++)
		{
			int j = i + s - 1;
			for (int k = i; k <= j; k++)
				ans = min(ans, F[i][k][0] + F[k + 1][j][1] + Getdis(i - 1, k));
		}
		printf("%lld\n", ans);
		for (int i = 1; i <= g + s; i++)
			fir[i] = 0;
		cnt = 0;
	}
}
