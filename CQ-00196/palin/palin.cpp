#include <bits/stdc++.h>
using namespace std;

#define Int register int
#define MAXN 500005

int n,m,a[MAXN],b[MAXN];
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

void Work (){
	read (n),m = n * 2;
	for (Int i = 1;i <= m;++ i) read (a[i]);
	for (Int S = 0;S < (1 << m);++ S){
		int cnt = 0,l = 1,r = m;
		for (Int i = m;i >= 1;-- i)
			if (S >> i - 1 & 1) cnt ++,b[cnt] = a[r],-- r;
			else cnt ++,b[cnt] = a[l],++ l;
		bool flg = 1;
		for (Int i = 1;i <= m;++ i) if (b[i] != b[m - i + 1]){flg = 0;break;}
		if (flg){
			for (Int i = m;i >= 1;-- i) putchar (S >> i - 1 & 1 ? 'R' : 'L');
			putchar ('\n');
			return ;
		}
	}
	puts ("-1");
}

signed main(){
	freopen ("palin.in","r",stdin);
	freopen ("palin.out","w",stdout);
	int T;read (T);
	while (T --> 0) Work ();
	return 0;
}
