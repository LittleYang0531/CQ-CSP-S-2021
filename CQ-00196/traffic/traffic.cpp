#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define MAXN 105

template <typename T> inline void read (T &x){
	x = 0;char c = getchar();int f = 1;
	while (!isdigit (c)) f *= (c == '-' ? -1 : 1),c = getchar();
	while (isdigit (c)) x = x * 10 + c - '0',c = getchar();
	x *= f;
}
template <typename T> inline void write (T x){
	if (x < 0) putchar ('-'),x = -x;
	if (x > 9) write (x / 10);putchar (x % 10 + '0');
}
template <typename T> inline void chkmin (T &a,T b){a = min (a,b);}

bool app[MAXN];
int n,m,T,ans,val[MAXN],pos[MAXN],col[MAXN],c[MAXN][MAXN],val1[MAXN][MAXN],val2[MAXN][MAXN];

void dfs (int tx,int ty,int res){
	if (tx > n){
		chkmin (ans,res);
		return ;
	}
	if (ty > m){
		dfs (tx + 1,1,res);
		return ;
	}
	for (Int i = 0;i < 2;++ i){
		int tmp = 0,ind = 0;c[tx][ty] = i;
		if (tx == 1) ind = ty;
		else if (tx == n) ind = m - ty + 1 + n + m;
		else if (ty == 1) ind = 2 * m + n + n - tx + 1;
		else ind = m + tx;
		if (tx == 1 && ty == 1){
			if (app[1]) tmp += (col[1] ^ i) * val[1];
			if (app[2 * n + 2 * m]) tmp += (col[2 * n + 2 * m] ^ i) * val[2 * n + 2 * m]; 
		}
		else if (tx == 1 && ty == m){
			if (app[m]) tmp += (col[m] ^ i) * val[m];
			if (app[m + 1]) tmp += (col[m] ^ i) * val[m + 1];
		}
		else if (tx == n && ty == m){
			if (app[m + n]) tmp += (col[n + m] ^ i) * val[n + m];
			if (app[n + m + 1]) tmp += (col[n + m + 1] ^ i) * val[n + m];
		}
		else if (tx == n && ty == 1){
			if (app[2 * m + n]) tmp += (col[2 * m + n] ^ i) * val[2 * m + n];
			if (app[2 * m + n + 1]) tmp += (col[2 * m + n + 1] ^ i) * val[2 * m + n + 1];
		}
		else if (tx == 1 || ty == 1 || tx == n || ty == m){
			if (app[ind]) tmp += (col[ind] ^ i) * val[ind];
		}
		if (tx >= 2) tmp += (i ^ c[tx - 1][ty]) * val1[tx - 1][ty];
		if (ty >= 2) tmp += (i ^ c[tx][ty - 1]) * val2[tx][ty - 1];
		dfs (tx,ty + 1,res + tmp);
	} 
}

signed main(){
	freopen ("traffic.in","r",stdin);
	freopen ("traffic.out","w",stdout);
	read (n),read (m),read (T);
	for (Int i = 1;i < n;++ i) for (Int j = 1;j <= m;++ j) read (val1[i][j]);
	for (Int i = 1;i <= n;++ i) for (Int j = 1;j < m;++ j) read (val2[i][j]);
	while (T --> 0){
		int k;read (k);memset (app,0,sizeof (app));
		for (Int i = 1,v,color;i <= k;++ i) read (v),read (pos[i]),read (color),col[pos[i]] = color,app[pos[i]] = 1,val[pos[i]] = v;
		ans = 1e9,dfs (1,1,0),write (ans),putchar ('\n');
	}
	return 0;
}
