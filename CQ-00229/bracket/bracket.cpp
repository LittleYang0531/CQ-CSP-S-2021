#include <map>
#include <set>
#include <queue>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <algorithm>
#define pii pair <int , int>
#define mp make_pair
#define fs first
#define sc second
using namespace std;
typedef long long LL;

template <typename T>
void read(T &x) {
	T f=1;x=0;char s=getchar();
	while(s<'0'||s>'9') {if(s=='-') f=-1;s=getchar();}
	while(s>='0'&&s<='9') {x=(x<<3)+(x<<1)+(s-'0');s=getchar();}
	x *= f;
}

template <typename T>
void write(T x , char s='\n') {
	if(!x) {putchar('0');putchar(s);return;}
	if(x<0) {putchar('-');x=-x;}
	T tmp[25]={},t=0;
	while(x) tmp[t++]=x%10,x/=10;
	while(t-->0) putchar(tmp[t]+'0');
	putchar(s); 
}

const LL mod = 1e9 + 7;

LL f[505][505][4] , n , K , g[505][505];
char s[505];

int main() {
	freopen("bracket.in" , "r" , stdin);
	freopen("bracket.out" , "w" , stdout);
	read(n),read(K);
	scanf("%s" , s + 1);
	for (int len = 1; len <= n; ++len) {
		for (int i = 1; i + len - 1 <= n; ++i) {
			int j = i + len - 1;
			if((s[i] == '(' || s[i] == '?') && (s[j] == ')' || s[j] == '?')) {
				g[i][j] = f[i][j][0] = (f[i + 1][j - 1][0] + f[i + 1][j - 1][1] + f[i + 1][j - 1][2] + f[i + 1][j - 1][3]) % mod;
				if(len == 2) g[i][j] = f[i][j][0] = 1;
				for (int k = i + 1; k < j - 1; ++k) f[i][j][0] = (f[i][j][0] + g[i][k] * f[k + 1][j][2] % mod + g[i][k] * f[k + 1][j][0] % mod) % mod;  
			}
			f[i][j][1] = ((j - i + 1) <= K);
			for (int k = i; k <= j; ++k) if(s[k] != '?' && s[k] != '*') f[i][j][1] = 0;
			for (int p = i; p <= j && p - i + 1 <= K; ++p) 
				f[i][j][2] = (f[i][j][2] + f[i][p][1] * f[p + 1][j][0] % mod) % mod;
			for (int p = j; p >= i && j - p + 1 <= K; --p) 
				f[i][j][3] = (f[i][j][3] + f[i][p - 1][0] * f[p][j][1] % mod) % mod;
		}
	}
	write(f[1][n][0]);
	return 0;
}
