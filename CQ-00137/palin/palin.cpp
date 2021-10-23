//12252024832524
#include <bits/stdc++.h>
#define TT template<typename T>
using namespace std;

typedef long long LL;
const int MAXN = 1000005;
int n;
int a[MAXN],w[MAXN],cs[MAXN];

LL Read()
{
	LL x = 0,f = 1; char c = getchar();
	while(c > '9' || c < '0'){if(c == '-')f = -1;c = getchar();}
	while(c >= '0' && c <= '9'){x = (x*10) + (c^48);c = getchar();}
	return x * f;
}
TT void Put1(T x)
{
	if(x > 9) Put1(x/10);
	putchar(x%10^48);
}
TT void Put(T x,char c = -1)
{
	if(x < 0) putchar('-'),x = -x;
	Put1(x); if(c >= 0) putchar(c);
}
TT T Max(T x,T y){return x > y ? x : y;}
TT T Min(T x,T y){return x < y ? x : y;}
TT T Abs(T x){return x < 0 ? -x : x;}

char ans[MAXN];
bool win;
int QL,QR;
bool dfs(int l,int r,int ql,int qr)
{
//	printf("%d %d %d %d\n",l,r,ql,qr);
	int now = l-1+2*n-r+1;
	if(now == n+1) {QL = ql;QR = qr;return 1;}
	if(l == 1 && r == 2*n)
	{
		ans[now] = 'L'; cs[now] = a[1];
		if(dfs(l+1,r,w[a[1]]^1,w[a[1]]^1)) return 1;
		ans[now] = 'R'; cs[now] = a[r];
		return dfs(l,r-1,w[a[r]]^r,w[a[r]]^r);
	}
	int nd = w[a[l]]^l; ans[now] = 'L'; cs[now] = a[l]; 
	if(nd == ql-1 && l != ql && dfs(l+1,r,ql-1,qr)) return 1;
	if(nd == qr+1 && l != ql && dfs(l+1,r,ql,qr+1)) return 1;
	nd= w[a[r]]^r; ans[now] = 'R'; cs[now] = a[r];
	if(nd == ql-1 && r != qr && dfs(l,r-1,ql-1,qr)) return 1;
	if(nd == qr+1 && r != qr && dfs(l,r-1,ql,qr+1)) return 1;
	return 0;
} 

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	for(int T = Read(); T ;-- T)
	{
		n = Read(); bool f1 = 1;
		for(int i = 1;i <= n;++ i) w[i] = 0;
		for(int i = 1;i <= n;++ i) a[i] = Read(),w[a[i]] ^= i;
		for(int i = 1;i <= n;++ i) a[i+n] = Read(),f1 &= (a[i+n] == a[n-i+1]),w[a[i+n]] ^= i+n;
		if(f1)
		{
			for(int i = 1;i <= (n<<1);++ i) putchar('L');
			putchar('\n'); continue;
		}
		win = 0;
		if(!dfs(1,2*n,0,0)) Put(-1,'\n');
		else
		{
			for(int i = 1;i <= n;++ i) putchar(ans[i]);
			for(int i = n;i >= 1;-- i)
			{
				if(a[QL] == cs[i]) putchar('L'),++QL;
				else putchar('R'),--QR;
			}
			putchar('\n');
		}
	}
	return 0;
}
/*
1
20
2 10 13 6 15 5 20 12 1 18 8 9 11 14 17 17 14 11 9 8 18 16 4 12 20 5 19 15 7 6 13 10 2 1 3 3 16 4 19 7
如果我可以快速判无解就好了 
随机数据我就是神！ 
*/
