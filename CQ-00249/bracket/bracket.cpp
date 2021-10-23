#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
string ss;
int k;
int n;
bool check(string s)
{
	stack<int>st;
	int point=0;
	if(s[0]=='*')
	{
		return 0;
	}
	if(s[s.size()-1]=='*')
	{
		return 0;
	}
	bool f=0;
	int need=0;
	while(point<s.size())
	{
		if(s[point]=='(')
		{
			
			st.push(f);
			point++;
			f=0;
		}
		else if(s[point]==')')
		{
			
			if(st.size())
			{
				need=0;
				int key=st.top();
				st.pop();
				need=key;
			}
			else
			{
				return 0;
			}
			
			point++;
		}
		else
		{
			int l=point;
			++point;
			while(s[point]=='*')
			{
				++point;
			}
			int r=point-1;
			if(r-l+1>k)
			{
				return 0;
			}
			if(s[l-1]=='('&&s[r+1]=='(')
			{
				f=1;
			}
			else if(s[l-1]==')'&&s[r+1]==')')
			{
				if(need)
				{
					return 0;
				}
			}
		}
	}
	if(st.size())
	{
		return 0;
	}
	return 1;
}
string sf;
int ans=0;
void dfs(int x)
{
	if(x==ss.size())
	{
	//	cout<<sf;
	//	printf("\n");
		if(check(sf))
		{
		
			ans++;
			ans%=MOD;
		}
		return;
	}
	if(ss[x]=='(')
	{
		sf+='(';
		dfs(x+1);
		sf.pop_back();
	}
	else if(ss[x]==')')
	{
		sf+=')';
		dfs(x+1);
		sf.pop_back();
	}
	else if(ss[x]=='*')
	{
		sf+='*';
		dfs(x+1);
		sf.pop_back();
	}
	else
	{
		sf+='(';
		dfs(x+1);
		sf.pop_back();
		sf+=')';
		dfs(x+1);
		sf.pop_back();
		sf+='*';
		dfs(x+1);
		sf.pop_back();
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d",&n);
	scanf("%d",&k);
	cin>>ss;
	
	dfs(0);
	printf("%d",ans);
	return 0;
}
