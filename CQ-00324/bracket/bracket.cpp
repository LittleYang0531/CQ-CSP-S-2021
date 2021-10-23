#include<bits/stdc++.h>
#define int long long
#define mes(x, i) memset(x, i, sizeof x)
#define max(i, j) (i > j ? i : j)
#define min(i, j) (i < j ? i : j)
using namespace std;
int dp[505][505][2], sum[505], kkk = 1000000007;
char s[505];
signed main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	int n, k, tot, last;
	scanf("%lld %lld\n%s", &n, &k, s + 1);
	for(int i = 1; i < n; i++){
		if((s[i] == '(' || s[i] == '?') && (s[i + 1] == ')' || s[i + 1] == '?')) dp[i][i + 1][1] = dp[i][i + 1][0] = 1;
	}
	for(int len = 2; len < n; len++){
		for(int l = 1, r = 1 + len; r <= n; l++, r++){
			if((s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?')){
				dp[l][r][1] = dp[l][r][0] = dp[l + 1][r - 1][0];
				for(int j = l + 1; j <= l + k; j++){
					if(s[j] != '*' && s[j] != '?') break;
					if(j + 1 == r){
						dp[l][r][0] = (dp[l][r][0] + 1) % kkk;
						dp[l][r][1] = (dp[l][r][1] + 1) % kkk;
						break;
					}
					dp[l][r][1] = (dp[l][r][1] + dp[j + 1][r - 1][0]) % kkk;
					dp[l][r][0] = (dp[l][r][0] + dp[j + 1][r - 1][0]) % kkk;
				}
				for(int j = r - 1; j >= r - k; j--){
					if(s[j] != '*' && s[j] != '?') break;
					if(j - 1 == l) break;
					dp[l][r][1] = (dp[l][r][1] + dp[l + 1][j - 1][0]) % kkk;
					dp[l][r][0] = (dp[l][r][0] + dp[l + 1][j - 1][0]) % kkk;
				}
			}
			tot = 0;
			last = l + 2;
			for(int j = l + 1; j < r; j++){
				if(j - k == last){
					tot = (tot - dp[l][j - k - 1][1] + kkk) % kkk;
					last++;
				}
				if(s[j] != '*' && s[j] != '?'){
					tot = 0;
					last = j + 1;
				}
				tot = (tot + dp[l][j][1]) % kkk;
				dp[l][r][0] = (dp[l][r][0] + tot * dp[j + 1][r][0] % kkk) % kkk;
			}
//			printf("%d %d:%d %d\n", l, r, dp[l][r][0], dp[l][r][1]);
		}
	}
	printf("%lld", dp[1][n][0]);
//	system("Pause");//Ìá½»Ç°×¢ÊÍ£¡£¡£¡
	return 0;
}
