//12252024832524
#include <bits/stdc++.h>
#define TT template<typename T>
using namespace std;

typedef long long LL;
const int MAXN = 100005;
int n,m1,m2;
int pre[2][MAXN];

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

struct feiji//ping yin zong bu neng zhuang guan jian zi ba
{
	int a,b;
	bool operator < (const feiji &px)const{
		return a < px.a;
	}
}nei[MAXN],wai[MAXN];

#define lc (x<<1)
#define rc (x<<1|1)
int MIN[MAXN<<2];
void up(int x){MIN[x] = Min(MIN[lc],MIN[rc]);}
void Build(int x,int l,int r)
{
	MIN[x] = 0;
	if(l == r) return;
	int mid = (l+r) >> 1;
	Build(lc,l,mid); Build(rc,mid+1,r);
}
int Query(int x,int l,int r,int pos,feiji A)
{
	if(l == r)
	{
		MIN[x] = A.b;
		return l;
	}
	int mid = (l+r) >> 1,ret;
	if(pos <= mid)
		ret = Query(lc,l,mid,pos,A);
	else
	{
		if(MIN[lc] < A.a) ret = Query(lc,l,mid,pos,A);
		else ret = Query(rc,mid+1,r,pos,A);
	}
	up(x);
	return ret;
}

int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n = Read(); m1 = Read(); m2 = Read();
	for(int i = 1;i <= m1;++ i) nei[i].a = Read(),nei[i].b = Read();
	for(int i = 1;i <= m2;++ i) wai[i].a = Read(),wai[i].b = Read();
	sort(nei+1,nei+m1+1); sort(wai+1,wai+m2+1);
	int N = Max(Max(m1,m2),n),tot = 0;
	Build(1,1,N);
	for(int i = 1;i <= m1;++ i)
	{
		int ret = Query(1,1,N,tot+1,nei[i]);
		tot = Max(tot,ret);
		++pre[0][ret];
	}
	Build(1,1,N); tot = 0;
	for(int i = 1;i <= m2;++ i)
	{
		int ret = Query(1,1,N,tot+1,wai[i]);
		tot = Max(tot,ret);
		++pre[1][ret];
	}
	for(int i = 0;i < 2;++ i)
		for(int j = 1;j <= n;++ j)
			pre[i][j] += pre[i][j-1];
	int ans = 0;
	for(int i = 0;i <= n;++ i) ans = Max(ans,pre[0][i]+pre[1][n-i]);
	Put(ans,'\n');
	return 0;
}
