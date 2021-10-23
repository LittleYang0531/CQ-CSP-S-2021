#include <bits/stdc++.h>
using namespace std;
int T , n , m , a[4400] , p[4400] , pl[4400] , ok[4400][4400] , f[4400] , id[4400] , tot;
int L[4400][4400] , R[4400][4400] , dp[4400][4400] , gt[4400][4400];
void gu( int &x )
{
	if(x >= m) x -= m;
}
int ni( int l1 , int r1 , int l2 , int r2 )
{
	gu(l1); gu(r1); gu(l2); gu(r2); 
//	cerr << l1<<' '<<r1<<' '<<l2<<' '<<r2<<endl;
	return !((r1 >= l2 && r1 <= r2) || (r2 >= l1 && r2 <= r1));
}
int main()
{
	freopen("palin.in" , "r" , stdin);
	freopen("palin.out" , "w" , stdout);
	scanf("%d" , &T);
	while(T--)
	{
		scanf("%d" , &n); m = 2 * n; tot = 0;
		for(int i = 0 ; i < m ; i++ ) 
			scanf("%d" , &a[i]) , a[i + m] = a[i];
		for(int i = 1 ; i <= n ; i++ ) pl[i] = 0;
		for(int i = n ; i < m + n ; i++ )
			for(int j = n ; j < m + n ; j++ )
				dp[i][j] = gt[i][j] = ok[i][j] = 0;
		for(int i = n ; i < m + n ; i++ )
		{
			if(pl[a[i]]) p[i] = pl[a[i]] , p[pl[a[i]]] = i;
			else pl[a[i]] = i;
		}
		for(int l = n ; l < m + n ; l++ )
			L[l][l] = R[l][l] = p[l] , ok[l][l] = 1;
		for(int d = 1 ; d < n ; d++ )
		{
			for(int l = n ; l < m + n ; l++ )
			{
				int r = l + d;
				if(r >= m + n) break;
				if(ok[l][r - 1])
				{
					int qwq = (L[l][r - 1] - 1 + m) % m;
//					if(l ==8 &&r== 11) cerr << qwq << ' ' << p[r] % m << ' ' << ni(l , r , qwq , R[l][r - 1]) << endl;
					if(p[r] % m == qwq && ni(l , r , qwq , R[l][r - 1])) 
						L[l][r] = p[r] % m , R[l][r] = R[l][r - 1] , ok[l][r] = 1;
					else
					{
						int qwq = (R[l][r - 1] + 1 + m) % m;
						if(p[r] % m == qwq && ni(l , r , L[l][r - 1] , qwq)) 
							L[l][r] = L[l][r - 1] , R[l][r] = p[r] % m , ok[l][r] = 1;
					}
				}
				if(ok[l][r]) continue;
				if(ok[l + 1][r])
				{
					int qwq = (L[l + 1][r] - 1 + m) % m;
					if(p[l] % m == qwq && ni(l , r , qwq , R[l + 1][r])) 
						L[l][r] = p[l] % m , R[l][r] = R[l + 1][r] , ok[l][r] = 1;
					else
					{
						int qwq = (R[l + 1][r] + 1 + m) % m;
//					if(l == 6 && r == 7) cerr << qwq << ' ' << p[l] % m << endl;
						if(p[l] % m == qwq && ni(l , r , L[l + 1][r] , qwq)) 
							L[l][r] = L[l + 1][r] , R[l][r] = p[l] % m , ok[l][r] = 1;
					}
				}
			}
		}
//		for(int l = n ; l < m + n ; l++ )
//			for(int r = l ; r < m + n ; r++ )
//				cerr << l << ' ' << r << ' ' << ok[l][r] << endl;
		dp[m][m] = dp[m - 1][m - 1] = 1;
		for(int d = 1 ; d < n ; d++ )
		{
			for(int l = n ; l < m + n ; l++ )
			{
				int r = l + d;
				if(r >= m + n) break;
				if(!ok[l][r]) continue;
				if(dp[l + 1][r] || dp[l][r - 1]) dp[l][r] = 1;
//				cerr << l << ' ' << r << ' ' << dp[l][r] << endl;
			}
		}
		for(int l = n ; l < m + n ; l++ )
		{
			int r = l + n - 1;
			if(r >= m + n) break;
			gt[l][r] = dp[l][r];
//			cerr << gt[l][r] << ' ';
		}
		for(int d = n - 2 ; d >= 0 ; d-- )
		{
			for(int l = n ; l < m + n ; l++ )
			{
				int r = l + d;
				if(r >= m + n) break;
				if(!dp[l][r]) continue;
				gt[l][r] = gt[l][r + 1] | gt[l - 1][r];
//				cerr << l << ' ' << r << ' ' << gt[l][r] << endl;
			}
		}
		if(!gt[m][m] && !gt[m - 1][m - 1])
		{
			printf("-1\n");
			continue;
		}
		int ll = m , rr = m - 1;
		for(int i = 1 ; i <= n ; i++ )
		{
			if(gt[ll][rr + 1]) 
			{
				printf("L") , rr++;
				f[rr] = 1; id[++tot] = a[rr];
			}
			else 
			{
				printf("R") , ll--;
				f[ll] = 1; id[++tot] = a[ll];
			}
		}
		for(int i = tot ; i >= 1 ; i-- )
		{
			if(a[rr + 1] == id[i]) printf("L") , rr++;
			else printf("R") , ll--;
		}
		printf("\n");
	}
	return 0;
}
