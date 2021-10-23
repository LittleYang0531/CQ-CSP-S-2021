#include<bits/stdc++.h>
#define file(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#define mod 1000000007
#define ll long long
#define N 505
using namespace std;
template<class T>void read(T&x) {
	T f=1;x=0;char c=getchar();
	while(c<'0'||c>'9'){if(c=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
char _st;
int n,m,Q,a[N][N],b[N][N];
char _ed;
int main() {
	cerr << "Memory: " << ((&_st-&_ed)>>20) << '\n';
	file("traffic");
	read(n);read(m);read(Q);
	for(int i=1; i<n; ++i)
		for(int j=1; j<=m; ++j)
			read(a[i][j]);//down
	for(int i=1; i<=n; ++i)
		for(int j=1; j<m; ++j)
			read(b[i][j]);//right
	while(Q--) {
		puts("1145141919810");
	}
}
