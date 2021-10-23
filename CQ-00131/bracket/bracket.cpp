#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
int n,K,pr[505],ans;
char s[505];
int solve(int l,int r)
{
	if(l>r)	return 1;
	for(int i=l;i<=r;++i)
	{
		if(s[i]!='*')	goto fail;
	}
	return 1;
	fail:;
	if(s[l]=='*')
	{
		while(s[l]=='*')	++l;
		return solve(l,r);
	}
	else if(s[r]=='*')
	{
		while(s[r]=='*')	--r;
		return solve(l,r);
	}
	else
	{
		int L=l,R=pr[l];
		if(R==r)	return solve(L+1,R-1);
		if(!solve(L,R))	return 0;
		return solve(R+1,r);
	}
}
int check()
{
	if(s[1]!='(' || s[n]!=')')	return 0;
	stack<int> S;
	int lst=0;
	for(int i=1;i<=n;++i)	pr[i]=0;
	for(int i=1;i<=n;++i)
	{
		if(s[i]==')')
		{
			if(S.empty())	return 0;
			pr[i]=S.top();
			pr[S.top()]=i;
			S.pop();
			lst=0;
		}
		if(s[i]=='(')
		{
			S.push(i);
			lst=0;
		}
		if(s[i]=='*')
		{
			++lst;
			if(lst>K)	return 0;
		}
	}
	if(!S.empty())	return 0;
	return solve(1,n);
}
void dfs(int now)
{
	if(now>n)
	{
		ans+=check();
		return ;
	}
	if(s[now]=='?')
	{
		s[now]='*';
		dfs(now+1);
		s[now]='(';
		dfs(now+1);
		s[now]=')';
		dfs(now+1);
		s[now]='?';
	}
	else	dfs(now+1);
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&K);
	scanf("%s",s+1);
	dfs(1);
	printf("%d",ans);
	return 0;
}
