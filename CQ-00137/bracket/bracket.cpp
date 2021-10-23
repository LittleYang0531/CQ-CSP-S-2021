//12252024832524
#include <bits/stdc++.h>
#define TT template<typename T>
using namespace std;

typedef long long LL;
const int MAXN = 502;
const int MOD = 1e9+7;
int n,b;//nb
char a[MAXN];

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

int ans[MAXN][MAXN][2],to[MAXN],pre[MAXN*MAXN/2][MAXN],ID[MAXN][MAXN],tot;
void Ad(int &x){if(x >= MOD) x -= MOD;if(x < 0) x += MOD;} 
bool check(int x,char c)
{
	if(a[x] == c || a[x] == '?') return 1;
	return 0;
}
int solve(int l,int r,bool f)//f=1表示l,r必须是匹配的左右括号 
{
	if(l > r) return 1;
	if(l == r) return 0;
	if(ans[l][r][f] >= 0) return ans[l][r][f];
	int ret = 0;
	if(check(l,'(') && check(r,')')) 
	{
		//直接开 
		Ad(ret += solve(l+1,r-1,0));
		//左右加 
		for(int i = l+1;i <= r-2 && i-l <= b;++ i)
			if(!check(i,'*')) break;
			else Ad(ret += solve(i+1,r-1,0));
		for(int i = r-1;i >= l+2 && r-i <= b;-- i)
			if(!check(i,'*')) break;
			else Ad(ret += solve(l+1,i-1,0));
		for(int i = l+1;r-l-1 <= b && i <= r-1;++ i)
			if(!check(i,'*')) break;
			else if(i == r-1) ++ret,Ad(ret);
	}
	//夹心(显然可以优化) 
	if(!f)
	{
		for(int i = l;i <= r-2;++ i) 
		{
			pre[ID[l][r]][i] = pre[ID[l][r]][i-1];
			if(check(i+1,'(')) Ad(pre[ID[l][r]][i] += solve(i+1,r,0));
		}
		for(int i = l+1;i <= r-2;++ i)
			if(check(l,'(') && check(i,')') && check(r,')'))
			{
				if(!to[i+1]) {Ad(ret += 1ll * solve(l,i,1) * solve(i+1,r,0) % MOD);continue;}
				int RR = Min(to[i+1],Min(i+b,r-2));
				if(RR > i-1) Ad(ret += 1ll * solve(l,i,1) * (pre[ID[l][r]][RR] - pre[ID[l][r]][i-1]) % MOD);
			}
	}
//	printf("solve %d %d %d %d\n",l,r,f,ret);
	return ans[l][r][f] = ret;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	memset(ans,-1,sizeof(ans));
	n = Read(); b = Read();
	scanf("%s",a+1);
	for(int i = 1;i <= n;++ i)
		for(int j = i;j <= n;++ j)
			if(!check(j,'*')) break;
			else to[i] = j;
	for(int i = 1;i <= n;++ i)
		for(int j = i;j <= n;++ j)
			ID[i][j] = ++tot;
	Put(solve(1,n,0),'\n');
	return 0;
}
/*
不会真的是区间DP吧
不会吧 不会吧
先来65pts 
100pts
*/
