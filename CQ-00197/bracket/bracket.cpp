#include<bits/stdc++.h>
using namespace std;
const int N=502,mod=1e9+7;
int n,k;
char a[N];
int f[N][N][N];
bool g[N][N];
int p[N],cnt;
int ans;
string res;
stack<char>stk,stk2;
bool check(string s)
{
	while(!stk.empty())
		stk.pop();
	int len=s.size();
	for(int i=0;i<len;i++)
	{
		if(s[i]=='(' || s[i]=='*')
			stk.push(s[i]);
		
		else if(s[i]==')')
		{
			int cnt=0;
			while(!stk.empty() && stk.top()!='(')
			{
				char op=stk.top();
				stk.pop();
				cnt++;
				if(cnt>k) return false;
			}
			if(stk.empty()) return false;
			stk.pop();
		}
	}
	if(!stk.empty()) return false;
	return true;
}
void dfs(int u)
{
	if(u == cnt+1)
	{
		if(check(res))
			ans++;
		return;
	}
	
	res[p[u]]='(';
	dfs(u+1);
	res[p[u]]=')';
	dfs(u+1);
	res[p[u]]='*';
	dfs(u+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>a[i],res+=a[i];
	
	for(int i=1;i<=n;i++)
		if(a[i]=='?')
			p[++cnt]=i;
	
	dfs(1);
	if(n==1) cout<<0<<endl;
	else cout<<ans<<endl;
	return 0;
}
