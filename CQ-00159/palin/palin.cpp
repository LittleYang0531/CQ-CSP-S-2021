#include "bits/stdc++.h"
using namespace std;
const int Len = 5e5 + 5;
int n,m,a[25];
//本质是裂区间
//快速判断是否有解
//不会了
int Print[25],num[25],Ans[25],flag;
bool check()
{
	for(int i = 1 ; i <= n ; i ++) if(num[i] != num[(n << 1) - i + 1]) return false;
	return true;
}
void Sp()
{
	if(!flag)
	{
		for(int i = 1 ; i <= (n << 1) ; i ++) Ans[i] = Print[i];
		flag = 1;
	}
	else
	{
		for(int i = 1 ; i <= (n << 1) ; i ++) 
		{
			if(Print[i] == Ans[i]) continue;
			if(Print[i] < Ans[i]) 
			{
				for(int j = i ; j <= (n << 1) ; j ++) Ans[j] = Print[j];
				break;
			}
			else break;
		}
	}
}
void dfs(int x,int l,int r)
{
	if(x == (n << 1) + 1)
	{
		if(check()) Sp();
		return; 
	}
	Print[x] = 0 , num[x] = a[l];
	dfs(x + 1 , l + 1 , r);
	Print[x] = 1 , num[x] = a[r];
	dfs(x + 1 , l , r - 1);
} 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;scanf("%d",&t);
	while(t --)
	{
		scanf("%d",&n);flag = 0;
		for(int i = 1 ; i <= (n << 1) ; i ++) scanf("%d",&a[i]);
		dfs(1 , 1 , (n << 1));
		if(!flag) puts("-1");
		else
		{
			for(int i = 1 ; i <= (n << 1) ; i ++) 
			{
				if(Ans[i] == 0) putchar('L');
				else putchar('R');
			}
			puts("");
		}
	}
	return 0;
}
