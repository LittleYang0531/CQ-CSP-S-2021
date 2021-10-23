#include "bits/stdc++.h"
using namespace std;
const int Len = 5e2 + 5;
const int mod = 1e9 + 7;
int n,K,dp[Len][Len],sum[Len][Len];
char s[Len];
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&K);
	scanf("%s",s + 1);
	for(int i = 1 ; i <= n ; i ++)
		for(int j = i ; j <= n ; j ++)
		{
			if(s[j] == '(' || s[j] == ')') sum[i][j] = sum[i][j - 1] + 1;
			else sum[i][j] = sum[i][j - 1];
		}
	bool flaw = 0;
	for(int len = 2 ; len <= n ; len ++)
	{
		for(int i = 1 ; i + len - 1 <= n ; i ++)
		{
			int j = i + len - 1;
			if((s[i] == '(' && s[j] == ')') || (s[i] == '(' && s[j] == '?') || (s[i] == '?' && s[j] == '?') || (s[i] == '?' && s[j] == ')')) 
			{
				if(len == 2 || (!sum[i + 1][j - 1] && (j - 1 - i) <= K)) dp[i][j] ++ , dp[i][j] %= mod;//(),(S)
				//if(i == 1 && j == 4) printf("%d\n",dp[i][j]);
				if(i + 1 <= j - 1) dp[i][j] += dp[i + 1][j - 1] , dp[i][j] %= mod;//(A)
				//if(i == 1 && j == 4) printf("%d\n",dp[i][j]);
				for(int k = i + 1 ; k < j - 1 ; k ++)
				{
					if(!sum[i + 1][k] && k - i <= K) dp[i][j] += dp[k + 1][j - 1] , dp[i][j] %= mod;//(SA)
					if(!sum[k + 1][j - 1] && j - 1 - k <= K) dp[i][j] += dp[i + 1][k] , dp[i][j] %= mod;//(AS)
				}
				//if(i == 1 && j == 4) printf("%d\n",dp[i][j]);
			}//初始化 
		//	int res1 = 0 , res2 = 0;
			for(int k = i ; k < j ; k ++)
				for(int p = k + 1 ; p <= j ; p ++)//[i,k] ^ [k + 1 , p - 1] ^ [p , j]的答案 
				{
					if(k + 1 > p - 1) 
					{
					//if(i == 1 && j == 4 && dp[i][k] * dp[p][j]) printf("1:%d %d %d %d\n",i,k,p,j);
					//	res1 += dp[i][k] * dp[p][j];
						dp[i][j] += dp[i][k] * dp[p][j] % mod , dp[i][j] %= mod;//AB
					}
					else//ASB 
					{
						if(!sum[k + 1][p - 1] && p - 1 - k <= K) 
						{
					//		res2 += dp[i][k] * dp[p][j];
					//		if(i == 1 && j == 4 && dp[i][k] * dp[p][j]) printf("2:%d %d %d %d\n",i,k,p,j);
							dp[i][j] += dp[i][k] * dp[p][j] % mod , dp[i][j] %= mod; 
						}
					}
				}
			//if(i == 1 && j == 4) printf("%d\n",dp[i][j]);
			//if(i == 1 && j == 4) printf("%d %d\n",res1,res2);
			//if(len >= 6) 
			//	printf("%d %d %d\n",i,j,dp[i][j]);
		}
	}
	printf("%d\n",dp[1][n]);
	return 0;
}
