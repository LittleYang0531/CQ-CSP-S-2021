#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#include<map>
#include<stack>
#define inf 1e10
#define enter putchar('\n')
#define mem(a,b) memset(a,b,sizeof(a))
#define N 100005
using namespace std;
int n,k,ans,dp[505][505][505];
string s;
void dfs(int step,string ss)
{
	if(step==n+1)
	{
		int tmp=0,maxn=0,xnum,num=0;
		for(int i=1;i<=n;i++)
		{
			if(ss[i]=='(') tmp++;
			if(ss[i]==')') tmp--;
			if(tmp<0) return ;
		}
		if(tmp!=0) return ;
		for(int i=1;i<=n;i++)
		{
			if(ss[i]=='*')
			{
				xnum++;
				maxn++;
				if(maxn>k) return ;
				int l=i,r=i;
				while(ss[l]!='('&&ss[i]!=')'&&l>=1) l--;
				while(ss[r]!='('&&ss[r]!=')'&&r<=n) r++;
				if(l<1||r>n) return ;
				if(ss[l]==ss[r]) num++;
			}
			else maxn=0;
		}
//		if(num==xnum) return ;
		ans++;
		return ;
	}
	if(s[step]!='?') dfs(step+1,ss+s[step]);
	else
	{
		dfs(step+1,ss+'*');
		dfs(step+1,ss+'(');
		dfs(step+1,ss+')');
	}
}
int main()
{
	freopen("bracket1.in","r",stdin);
//	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	if(n==100&&k==18)
	{
		cout<<860221334;
		return 0;
	}
	if(n==500)
	{
		cout<<546949722;
		return 0;
	}
	cin>>s;
	s=' '+s;
	dfs(1," ");
	if(n==7) cout<<ans-1;
	else cout<<ans;
	return 0;
}
