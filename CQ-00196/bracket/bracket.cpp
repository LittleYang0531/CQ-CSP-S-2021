#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define mod 1000000007
#define MAXN 505

char s[MAXN];
bool vis[MAXN][MAXN];
int n,K,f[MAXN][MAXN];

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

int mul (int a,int b){return 1ll * a * b % mod;}
int dec (int a,int b){return a >= b ? a - b : a + mod - b;}
int add (int a,int b){return a + b >= mod ? a + b - mod : a + b;}
void Add (int &a,int b){a = add (a,b);}
void Sub (int &a,int b){a = dec (a,b);}

int g[MAXN][MAXN];
bool vis1[MAXN][MAXN];
int getg (int l,int r);
int dfs (int l,int r);

signed main(){
	freopen ("bracket.in","r",stdin);
	freopen ("bracket.out","w",stdout);
	read (n),read (K),scanf ("%s",s + 1);
	write (dfs (1,n)),putchar ('\n');
	return 0;
}

int getg (int l,int r){
	if (l == r) return 0;
	if (vis1[l][r]) return g[l][r];
	if ((s[l] == '(' || s[l] == '?') || (s[r] == ')' || s[r] == '?')){
		vis1[l][r] = 1;int &res = g[l][r] = 0;
		bool flg = 1;for (Int i = l + 1;i <= r - 1;++ i) flg &= (s[i] == '*' || s[i] == '?');
		if (r - l - 1 <= K) Add (res,flg);		
		if (l + 1 <= r - 1) Add (res,dfs (l + 1,r - 1));
		flg = 1;
		for (Int i = l + 1;i <= r - 2 && i - l <= K;++ i){
			flg &= (s[i] == '*' || s[i] == '?');
			if (!flg) break;
			Add (res,dfs (i + 1,r - 1));
		}
		flg = 1;
		for (Int i = r - 1;i >= l + 2 && r - i <= K;-- i){
			flg &= (s[i] == '*' || s[i] == '?');
			if (!flg) break;
			Add (res,dfs (l + 1,i - 1));
		}
		return res;
	}
	else return 0;
}

int dfs (int l,int r){
	if (l == r) return 0;
	if (vis[l][r]) return f[l][r];
	if ((s[l] == '(' || s[l] == '?') && (s[r] == ')' || s[r] == '?')){
		vis[l][r] = 1;int &res = f[l][r] = 0;
		bool flg = 1;for (Int i = l + 1;i <= r - 1;++ i) flg &= (s[i] == '*' || s[i] == '?');
		if (r - l - 1 <= K) Add (res,flg);
		vector <int> suf,nxt;nxt.resize (n + 1),suf.resize (n + 1);
		for (Int j = l;j <= r;++ j) suf[j] = dfs (j,r);
		for (Int j = r - 1;j >= l;-- j) Add (suf[j],suf[j + 1]);
		for (Int j = r,nt = r + 1;j >= l;-- j){
			nxt[j] = nt;
			if (!(s[j] == '*' || s[j] == '?')) nt = j;
		}
		for (Int i = l + 1;i <= r - 2;++ i)
			if (s[i] == ')' || s[i] == '?'){
				int qL = i + 1,qR = min (min (r - 1,K + i + 1),nxt[i]);
				Add (res,mul (getg (l,i),dec (suf[qL],suf[qR + 1])));
				}
		if (l + 1 <= r - 1) Add (res,dfs (l + 1,r - 1));
		flg = 1;
		for (Int i = l + 1;i <= r - 2 && i - l <= K;++ i){
			flg &= (s[i] == '*' || s[i] == '?');
			if (!flg) break;
			Add (res,dfs (i + 1,r - 1));
		}
		flg = 1;
		for (Int i = r - 1;i >= l + 2 && r - i <= K;-- i){
			flg &= (s[i] == '*' || s[i] == '?');
			if (!flg) break;
			Add (res,dfs (l + 1,i - 1));
		}
		return res;
	}
	else return 0;
}
