#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int T,n,arr[N],now[N];
string ans; 
bool check()
{
	for(int i=1;i<=n;i++)
		if(now[i] != now[2*n-i+1])	return false;
	return true;
}
bool DFS(int cnt,string Now,int l,int r)
{
	if(cnt == 2*n)//骗分
	{
		if(check())
		{
			ans = Now;
		}
		return check();
	}
	cnt++;
	now[cnt] = arr[l];
	if(DFS(cnt,Now+"L",l+1,r)) return true;
	now[cnt] = arr[r];
	if(DFS(cnt,Now+"R",l,r-1)) return true;
	now[cnt] = 0;
	return false;
 } 
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		ans = "";
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",arr+i);
		for(int i=1;i<=2*n;i++)
			ans += "R";
		if(DFS(0,"",1,2*n))//2*n次 
		{
			cout<<ans<<endl;
			continue;
		}
		puts("-1");
	}
	return 0;
}
/*
	十年OI一场空，图论DP高精度
	题虽简单需看清，一二爆零泪沾襟
*/ 
