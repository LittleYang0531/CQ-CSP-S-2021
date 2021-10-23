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
#define MAXN 1000005
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

int n,m,s,o,k;
int a[MAXN<<1];
int fr[MAXN<<1],ct[MAXN];
bool dp[2005][2005];
int ll[2005][2005],rr[2005][2005];
bool f[MAXN<<1];
char ti[MAXN<<1];
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T = read();
	while(T --) {
		n = read();
		for(int i = 1;i <= n;i ++) ct[i] = 0;
		for(int i = 1;i <= 2*n;i ++) {
			s = a[i] = read();
			if(!ct[s]) {
				ct[s] = i;
			}
			else {
				fr[i] = ct[s];
				fr[ct[s]] = i;
			}
		}
		if(n <= 1000) {
			for(int i = 1;i <= n+1;i ++) {
				for(int j = 2*n;j-i+1 >= n;j --) {
					ll[i][j] = 2*n+1; rr[i][j] = 0;
					if(i > 1) {
						ll[i][j] = min(ll[i-1][j],fr[i-1]);
						rr[i][j] = max(rr[i-1][j],fr[i-1]);
					}
					else if(j < 2*n) {
						ll[i][j] = min(ll[i][j+1],fr[j+1]);
						rr[i][j] = max(rr[i][j+1],fr[j+1]);
					}
				}
			}
			for(int le = n;le <= 2*n;le ++) {
				for(int i = 1;i+le-1 <= 2*n;i ++) {
					int j = i+le-1;
					dp[i][j] = 0;
					if(rr[i][j] > j || ll[i][j] < i || rr[i][j]-ll[i][j]+1 > i-1+2*n-j) continue;
//					printf("[%d,%d] pass\n",i,j);
					if(le == n) {
						dp[i][j] = 1;
					}
					else {
						if(fr[i] == ll[i][j]-1 || fr[i] == rr[i][j]+1 || rr[i][j] == 0) {
							dp[i][j] |= dp[i+1][j];
						}
						if(fr[j] == ll[i][j]-1 || fr[j] == rr[i][j]+1 || rr[i][j] == 0) {
							dp[i][j] |= dp[i][j-1];
						}
					}
//					if(dp[i][j]) printf("ok [%d,%d] (%d,%d)\n",i,j,ll[i][j],rr[i][j]);
				}
			}
			if(!dp[1][2*n]) {printf("-1\n");continue;}
			for(int i = 1;i <= 2*n;i ++) f[i] = 0;
			int ld = 1,rd = 2*n,ct = 0;
			while(ct < n) {
				ct ++;
				if(dp[ld+1][rd]) {
					putchar('L');
					int y = fr[ld];
					if(!f[y-1]) ti[ct] = 'L';
					else ti[ct] = 'R';
					f[y] = 1;
					ld ++;
				}
				else {
					putchar('R');
					int y = fr[rd];
					if(!f[y-1]) ti[ct] = 'L';
					else ti[ct] = 'R';
					f[y] = 1;
					rd --;
				}
			}
			while(ct > 0) putchar(ti[ct --]);
			ENDL;
			continue;
		}
		else printf("-1\n");
	}
	return 0;
}
