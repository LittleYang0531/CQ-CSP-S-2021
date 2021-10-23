#include<bits/stdc++.h>
using namespace std;
int n,k;
string s;
int t;
int a[501];
int st[501];
int sum[501];
int ans;
inline void dfs(int now)
{
	if(now>n&&s[n]==')'&&!st[0])
	{
		ans++;
		/*
		for(int i=1;i<=n;i++)
		{
			cout<<s[i];
		}
		cout<<endl;
		*/
		return ;
	}
	if(s[now]=='(')
	{
		st[++st[0]]=now;
		//cout<<now<<endl;
		dfs(now+1);
		st[0]--;
	}
	else if(s[now]==')')
	{
		if(st[0])
		{
			int r=st[st[0]];
			a[now]=r;
			st[0]--;
			dfs(now+1);
			st[++st[0]]=r;
		}
	}
	else if(s[now]=='*')
	{
		if(s[now-1]==')'&&s[a[now-1]-1]=='*')
		{
			return ;
		}
		/*
		if(s[now-1]==')')
		{
			cout<<a[now-1]<<endl;
		}
		*/
		sum[now]=sum[now-1]+1;
		if(sum[now]<=k)
		{
			dfs(now+1);
		}
		sum[now]=0;
	}
	else if(s[now]=='?')
	{
		s[now]='(';
		st[++st[0]]=now;
		dfs(now+1);
		st[0]--;
		//cout<<q.front()<<endl;
		s[now]=')';
		if(st[0])
		{
			int r=st[st[0]];
			a[now]=r;
			//cout<<now<<" "<<r<<endl;
			st[0]--;
			dfs(now+1);
			st[++st[0]]=r;
		}
		if(s[now-1]==')'&&s[a[now-1]-1]=='*')
		{
			s[now]='?';
			return ;
		}
		s[now]='*';
		sum[now]=sum[now-1]+1;
		if(sum[now]<=k)
		{
			dfs(now+1);
		}
		sum[now]=0;
		s[now]='?';
	}
	return ;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	s=" "+s;
	if(s[1]==')'||s[1]=='*'||s[n]=='('||s[n]=='*')
	{
		cout<<0<<endl;
		return 0;
	}
	dfs(1);
	cout<<ans<<endl;
	return 0;
}
