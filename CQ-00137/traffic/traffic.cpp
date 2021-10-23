//12252024832524
#include <bits/stdc++.h>
#define TT template<typename T>
using namespace std;

typedef long long LL;
const int MAXN = 505;
int n,m,T;
int ro[MAXN][MAXN],co[MAXN][MAXN];
int val[MAXN],ID[MAXN],c[MAXN]; 

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

int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n = Read(); m = Read(); T = Read();
	for(int i = 1;i < n;++ i)
		for(int j = 1;j <= m;++ j)
			ro[i][j] = Read();
	for(int i = 1;i <= n;++ i)
		for(int j = 1;j < m;++ j)
			co[i][j] = Read();
	while(T --> 0)//I love this style!
	{
		int k = Read();
		LL S0 = 0,S1 = 0;
		for(int i = 1;i <= k;++ i) 
		{
			val[i] = Read(),ID[i] = Read(),c[i] = Read();
			if(!c[i]) S0 += val[i];
			else S1 += val[i];
		}
		Put(Min(S0,S1),'\n');
	}
	return 0;
}
/*
还没仔细看题
如果是网络流，我直接****
这题暴力都不想写，艹 

不要再走神啦！

还有15分钟，应该开始检查了，反正有分就能过，我也不在乎什么一等奖不一等奖了
这暴力分不要也罢 

EDG vs RNG
究竟是明凯八强诅咒还是内战幻神显灵？！ 
今晚八点不见不散 (md我可能还没到家
EDG上去肯定被暴打，RNG上去还有一丝希望，毕竟MSI冠军
showmaker太恐怖了
不过我倒是希望李哥夺冠，光荣退役 

虽然走神很不好，但是写完这些顿时脑子清醒很多，又可以继续检查了！ 

fuck FPX 
*/
