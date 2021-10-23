#include <bits/stdc++.h>
using namespace std;
const int N = 510, mod = 1e9 + 7;
typedef long long ll;
ll n, k, f1[N][N], f2[N][N], f3[N][N];
char s[N];
int main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%lld%lld", &n, &k);
	scanf("%s", s + 1);
	f1[0][0] = 1;
	for (int i = 1;i <= n + 1;i ++) f1[i][i - 1] = 1;
	for (int l = 1;l <= n;l ++)
		for (int i = 1;i + l - 1 <= n;i ++)
		{
			int j = i + l - 1;
			int cur = j;
			for (;j - cur + 1 <= k && cur > i && (s[cur] == '*' || s[cur] == '?');cur --)
				f2[i][j] = (f2[i][j] + f1[i][cur - 1]) % mod;
			cur = i;
			for (;cur - i + 1 <= k && cur <= j && (s[cur] == '*' || s[cur] == '?');cur ++)
				f3[i][j] = (f3[i][j] + f1[cur + 1][j]) % mod;
			
			if ((s[j] == '?' || s[j] == ')') && (s[i] == '(' || s[i] == '?'))
			{
				for (int jj = j - 1;jj >= i;jj --)
					if (s[jj] == '?' || s[jj] == '(')
						f1[i][j] = (f1[i][j] + (ll)(f1[jj + 1][j - 1] + f2[jj + 1][j - 1] + f3[jj + 1][j - 1]) * (f2[i][jj - 1] + f1[i][jj - 1])) % mod;
//				f1[i][j] = ((ll)f1[i][j] + f1[i + 1][j - 1] + f2[i + 1][j - 1] + f3[i + 1][j - 1]) % mod;
			}
//			cout<<i<<' '<<j<<' '<<f1[i][j]<<' '<<f2[i][j]<<' '<<f3[i][j]<<endl;
		}
	printf("%lld", f1[1][n]);
	return 0;
}
