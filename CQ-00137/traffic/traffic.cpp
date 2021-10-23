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
��û��ϸ����
���������������ֱ��****
���Ⱪ��������д��ܳ 

��Ҫ����������

����15���ӣ�Ӧ�ÿ�ʼ����ˣ������з־��ܹ�����Ҳ���ں�ʲôһ�Ƚ���һ�Ƚ���
�Ⱪ���ֲ�ҪҲ�� 

EDG vs RNG
������������ǿ���仹����ս�������飿�� 
����˵㲻����ɢ (md�ҿ��ܻ�û����
EDG��ȥ�϶�������RNG��ȥ����һ˿ϣ�����Ͼ�MSI�ھ�
showmaker̫�ֲ���
�����ҵ���ϣ������ڣ��������� 

��Ȼ����ܲ��ã�����д����Щ��ʱ�������Ѻܶ࣬�ֿ��Լ�������ˣ� 

fuck FPX 
*/
