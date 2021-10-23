#include<bits/stdc++.h>
using namespace std;
int k,n,num;
long long ans;
char a[505];
char c[506];
int pos[506];
bool check(int l,int r)
{
	stack<char> stk1;
	int lft=0;
	bool lft_hve=0,rgt_hve=0;
	for (int i=l;i<=r;i++)
	{
		stk1.push(c[i]);
		if (c[i]=='(') lft++;
		if (c[i]==')')
		{
			if (lft<=0) return false;
			int t=0;
			stk1.pop();
			while (!stk1.empty() && stk1.top()=='*')
			{
				stk1.pop();
				t++;
			}
			if (t>k) return false; 
			stk1.pop();
			lft--;
			t=0;
			if (!stk1.empty() && stk1.top()=='*') lft_hve=1;
			while (!stk1.empty() && stk1.top()=='*')
			{
				stk1.pop();
				t++;
			}
			if (t>k) return false;
			t=0;
			if (c[i+1]=='*')
			{
				rgt_hve=1;
				int k=i+1;
				while (c[k]=='*')
				{
					k++;
					t++;
				}
				if (t>k) return false;
				if (lft_hve==1 && rgt_hve==1 && k<=r) return check(k,r);
				else i=k;
			}
		}
	}
	if (stk1.empty()) return true;
	else return false;
}
void dfs(int x)
{
	if (x==num+1)
	{
		for (int i=1;i<=n;i++)
		{
			//cout<<c[i]<<" ";
		}
		//cout<<ans<<endl;
		if (check(1,n))
		{
			ans++;
		}
		if (ans>1e9+7) ans-=1e9+7;
	}
	else
	{
		if (pos[x]==1)
		{
			c[pos[x]]='(';
			dfs(x+1);
		}
		if (pos[x]==n)
		{
			c[pos[x]]=')';
			dfs(x+1);
		}
		else
		{
			c[pos[x]]='(';
			dfs(x+1);
			c[pos[x]]=')';
			dfs(x+1);
			c[pos[x]]='*';
			dfs(x+1);
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	ios::sync_with_stdio(0);
	cin>>n>>k;
	for (int i=1;i<=n;i++)
	{
		cin>>a[i];
		if (a[i]=='?')  
		{
			num++;
			pos[num]=i;
		}
		c[i]=a[i];
	}
	if (a[1]=='*' || a[n]=='*' || a[1]==')' || a[n]=='(') cout<<0;
	else
	{
		dfs(1);
		cout<<ans;
	}
	//RE 3221225477... 0pts
	return 0;
}
