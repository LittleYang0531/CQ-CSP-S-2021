#include<set>
#include<map>
#include<cmath>
#include<stack>
#include<queue>
#include<bitset>
#include<vector>
#include<cstdio>
#include<cstring>
#include<iostream>
#include<algorithm>
using namespace std;
#define MAXN 1005
#define LL long long
#define DB double
#define ENDL putchar('\n')
#define lowbit(x) (-(x) & (x))
LL read() {
	LL f=1,x=0;int s = getchar();
	while(s < '0' || s > '9') {if(s<0)return -1;if(s=='-')f=-f;s=getchar();}
	while(s >= '0' && s <= '9') {x = (x<<3) + (x<<1) + (s^48);s = getchar();}
	return f * x;
}
void putpos(LL x) {if(!x)return ;putpos(x/10);putchar((x%10)^48);};
void putnum(LL x) {
	if(!x) {putchar('0');return ;}
	if(x<0) putchar('-'),x = -x;
	return putpos(x);
}
void AIput(LL x,int c) {putnum(x);putchar(c);}

const int MOD = 1000000007;
int n,m,s,o,k;
char a[MAXN];
int dp[MAXN][MAXN],dpl[MAXN][MAXN],dpb[MAXN][MAXN];
void AD(int &a,int b) {a += b;if(a >= MOD) a -= MOD;}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n = read();m = read();
	scanf("%s",a + 1);
	for(int i = 1;i <= n;i ++) {
		if(a[i] == '(' || a[i] == '?') {
			for(int j = 0;j <= m && i+j+1 <= n;j ++) {
				if(a[i+j+1] == ')' || a[i+j+1] == '?') AD(dp[i][i+j+1],1);
				if(a[i+j+1] != '?' && a[i+j+1] != '*') break;
			}
		}
	}
	for(int i = 1;i < n;i ++) dpb[i][i+1] = dpl[i][i+1] = dp[i][i+1];
//	for(int i = 1;i < n;i ++) {
//		printf("dp[%d][%d] = %d\n",i,i+1,dp[i][i+1]);
//	}
	for(int le = 3;le <= n;le ++) {
		for(int i = 1;i+le-1 <= n;i ++) {
			int j = i+le-1;
			if(a[i] == '(' || a[i] == '?') {
				if(a[j] == ')' || a[j] == '?') {
					AD(dp[i][j],dpl[i+1][j-1]);
					for(int k = j-1,l = 1;k > i+1 && l <= m;k --,l ++) {
						if(a[k] == '*' || a[k] == '?') {
							AD(dp[i][j],dp[i+1][k-1]);
						}else break;
					}
				}
			}
			dpb[i][j] = dp[i][j];
			for(int k = i+1;k < j;k ++) {
				AD(dp[i][j],dpb[i][k] *1ll* dpl[k+1][j] % MOD);
			}
			
			dpl[i][j] = dp[i][j];
			for(int k = i,l = 1;k < j && l <= m;k ++,l ++) {
				if(a[k] == '*' || a[k] == '?') {
					AD(dpl[i][j],dp[k+1][j]);
				}else break;
			}
//			printf("(%d) dp[%d] = %d  dpl = %d\n",le,i,dp[i][j],dpl[i][j]);
		}
	}
	AIput(dp[1][n],'\n');
	return 0;
}
