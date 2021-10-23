#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c;
	int x=0,f=0;
	c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+c-48;
		c=getchar();
	}
	return f==0?x:-x;
}
int n,k,ans;
char c[10010];
stack<char> st;
void dfs(int x)
{
	bool tmp=0;
	for(int i=x+1;i<=n;i++)
	{
		if(c[i]=='?')
		{
			tmp=1;
			c[i]='(';
			dfs(i);
			c[i]=')';
			dfs(i);
			c[i]='*';
			dfs(i);
			c[i]='?';
			return;
		}
	}
	if(tmp==0)
	{
		int cnt=0;
		bool tmp=0;
//		st.clear();
		while(!st.empty()) st.pop();
		for(int i=1;i<=n;i++)
		{
//			cerr<<c[i];
			if(c[i]==')')
			{
				cnt=0;
				while(!st.empty()&&st.top()!='(')
				{
					st.pop();
					cnt++;
				}
				if(cnt>=k)
				{
					cerr<<'\n';
//					cerr<<cnt<<"ERROR\n";
					tmp=1;
					break;
				}
			}
			else st.push(c[i]);
		}
//		cerr<<'\n';
//		cerr<<(tmp==0)<<' '<<(st.empty())<<"qiao"<<'\n';
		if(tmp==0&&st.empty())
		{
			ans++;
		}
	}
}
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
	}
	c[1]='(';
	c[n]=')';
	if(n<=15)
	{
		dfs(1);
		cout<<ans;
	}
	return 0;
}

