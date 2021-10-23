#include<bits/stdc++.h>
using namespace std;
int n,k,uf;
unsigned long long ans;
unsigned long long mo=10e9+7;
char c[505];
stack <int> s;
void dfs(int x,int al,int cur)
{
	/*cout<<"x: "<<x<<"al "<<al<<"cur "<<cur<<"size "<<s.size();
	for(int i=0;i<n;i++)
	{
		cout<<c[i];
	}
	cout<<endl;*/
	if(c[0]=='*') return;
	if(cur>k) return;
	if(x>=n)
	{
		if(!s.empty()) return;
		if(c[n-1]=='*') return;
		if(c[0]=='*') return;
		/*for(int i=0;i<n;i++)
		{
			cout<<c[i];
		}
		cout<<endl;*/
		ans++;
		ans=ans%mo;
		return;
	}
	if(c[x]=='(')
	{
		s.push('(');
		dfs(x+1,al,0);
		s.pop();
	}
	else if(c[x]==')')
	{
		if(s.empty()) return;
		s.pop();
		dfs(x+1,al,0);
		s.push('(');
	}
	else if(c[x]=='*')
	{
		dfs(x+1,al,cur+1);
	}
	else if(c[x]=='?')
	{
		if(al>s.size()+1)
		{
			s.push('(');
			dfs(x+1,al-1,0);
			s.pop();
		}
		if(!s.empty())
		{
			s.pop();
			dfs(x+1,al-1,0);
			s.push('(');
		}
		if(cur<k)
		{
			c[x]='*';
			dfs(x+1,al-1,cur+1);
			c[x]='?';
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	if(n==0)
	{
		cout<<"0"<<endl;
		return 0;
	}
	cin>>c;
	for(int i=0;i<n;i++)
	{
		if(c[i]=='?') uf++;
	}
	dfs(0,uf,0);
	cout<<ans<<endl;
	return 0;
}
