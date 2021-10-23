#include<bits/stdc++.h>
using namespace std;
const int N = 510, mod = 1e9 + 7;
int n, k, f[N][N], a[N];
char c[N];
int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	cin >> n >> k >> c + 1;
	for(int i = n; i >= 1; i--)
		for(int j = i; j <= n; j++)
		{
			if((c[j] == '*' || c[j] == '?' ) && a[i] == j - i && a[i] < k)
				a[i]++;
			if(i == j)
				continue;
			if((c[i] == '?' || c[i] == '(') && (c[j] == '?' || c[j] == ')'))
			{
				if(j == i + 1)
				{
					f[i][j] = 1;
					continue;
				}
				if(a[i + 1] == j - i - 3)
					f[i][j] += 1;
				f[i][j] = (f[i][j] + f[i + 1][j - 1]) % mod;
				for(int k = i + 1; k <= j - 1; k++)
				{
					if(c[k] != '*')
					{
						f[i][j] = (f[i][j] + f[k][j - 1]) % mod;
						break;
					}
				}
				for(int k = j - 1; k <= i + 1; k--)
				{
					if(c[k] != '*')
					{
						f[i][j] = (f[i][j] + f[i + 1][k]) % mod;
						break;
					}
				}
			}
			for(int k = i; k <= j - 1; k++)
				f[i][j] = (f[i][j] + 1LL * f[i][k] * (f[k + 1][j] + f[a[k + 1] + i][j])) % mod;
		}
	cout << f[1][n] % mod << endl;
	return 0;
}

