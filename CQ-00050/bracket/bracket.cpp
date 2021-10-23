#include <bits/stdc++.h>
using namespace std;
int n , m;
char s[550];
long long F[2][550][550] , G[550][550];
const int mod = 1e9 + 7;
int main()
{
	freopen("bracket.in" , "r" , stdin);
	freopen("bracket.out" , "w" , stdout);
	scanf("%d%d%s" , &n , &m , s + 1);
	for(int l = 1 ; l <= n ; l++ )
	{
		if(s[l] != '(' && s[l] != '?') continue;
		int cnt = 0;
		for(int r = l + 1 ; r <= n ; r++ )
		{
			if(s[r] == ')' || s[r] == '?') F[0][l][r] = 1;
			if(s[r] != '*' && s[r] != '?') break;
			cnt++;
			if(cnt > m) break;
		}
	}
	for(int d = 1 ; d < n ; d++ )
	{
		for(int l = 1 ; l + d <= n ; l++ )
		{
			int r = l + d , cnt = 0;
			for(int i = l ; i < r ; i++ )
			{
				if(s[i] != '*' && s[i] != '?') break;
				cnt++;
				if(cnt > m) break;
				(G[l][r] += F[0][i + 1][r] + F[1][i + 1][r]) %= mod;
			}
			for(int i = l ; i < r ; i++ )
			{
				(F[1][l][r] += F[0][l][i] * (G[i + 1][r] + F[1][i + 1][r] + F[0][i + 1][r]) % mod) %= mod;
			}
			if(s[l - 1] == '(' || s[l - 1] == '?')
			{
				int cnt = 0;
				for(int i = r + 1 ; i <= n ; i++ )
				{
					if(s[i] == ')' || s[i] == '?') 
						(F[0][l - 1][i] += F[0][l][r] + F[1][l][r]) %= mod;
					if(s[i] != '*' && s[i] != '?') break;
					cnt++;
					if(cnt > m) break;
				}
			}
			if(s[r + 1] == ')' || s[r + 1] == '?')
			{
				int cnt = 0;
				for(int i = l - 1 ; i >= 1 ; i-- )
				{
					if((s[i] == '(' || s[i] == '?') && i != l - 1) 
						(F[0][i][r + 1] += F[0][l][r] + F[1][l][r]) %= mod;
					if(s[i] != '*' && s[i] != '?') break;
					cnt++;
					if(cnt > m) break;
				}
			}
		}
	}
//	cerr << F[0][1][3] << endl;
//	cerr << F[1][1][n] << endl;
//	cerr << F[0][2][7] << ' ' << F[1][2][7] << endl;
	printf("%lld" , (F[0][1][n] + F[1][1][n]) % mod);
	return 0;
}
/*
7 3
(*??*??
*/
