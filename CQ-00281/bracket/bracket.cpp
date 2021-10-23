#include<bits/stdc++.h>
using namespace std;
stack<int> st;
string s;int n,k;int ans;int len;
bool cheak1(string b)
{
	while(!st.empty()) st.pop();
	for(int i=0;i<b.length();i++)
	{
		if(b[i]=='(') st.push(10);
		if(b[i]==')'&&!st.empty()) st.pop();
	}
	if(!st.empty()) return 1;
	else return 0;
}
bool cheak(string a)
{
	if(a[0]=='*') return 0;
	int sss=0;
	for(int i=0;i<a.length();i++)
	{
		for(int j=1;j>=0;j--)
		{
			if(a[j]=='*') continue;
			if(a[j]=='(') 
			{
				sss++;
				break;
			}
		}
		if(a[i+1]=='(') sss++;
		int ttot;
		for(int j=i;j<a.length();j++)
		{
			if(a[j]=='*') continue;
			if(a[j]==')') 
			{ttot=j;
			sss++;break	;
			}
		}
		if(a[ttot+1]=='*') sss++;
		for(int j=ttot+1;j<a.length();j++)
		{
			if(a[j]=='*') continue;
			if(a[j]==')')
			{
				 sss++;break;
			 }
		}
	}
	if(sss==5) return 0;
	if(a[a.length()-1]=='*') return 0;
	int l=0;
	for(int i=0;i<=a.length();i++)
	{
		if(a[i]=='*') 
		{
			l++;
			if(l>k) return 0;
		}
		else l=0;
	}
	if(cheak1(a)) return 0;
	int p=0;int q=0;
	for(int i=0;i<=a.length();i++)
	{
		if(a[i]=='(') p++;
		if(a[i]==')') q++;
	}
	if(q!=p) return 0;
	return 1;
}
void dfs(int dep)
{
	if(dep==s.length())
	{
		if(cheak(s)) ans++;
		return;
	}
	if(s[dep]=='(') dfs(dep+1);
	else if(s[dep]==')') dfs(dep+1);
	else if(s[dep]=='*') dfs(dep+1);
	else if(s[dep]=='?')
	{
		s[dep]=')';dfs(dep+1); s[dep]='?';
		s[dep]='(';dfs(dep+1);s[dep]='?';
		s[dep]='*';dfs(dep+1);s[dep]='?';
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	dfs(0);
	cout<<ans;
	return 0;
}
