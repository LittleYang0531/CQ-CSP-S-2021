#include<bits/stdc++.h>
using namespace std;

#define ll long long
#define re register

inline int read()
{
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9')
	{
		if(c=='-')
			f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')
	{
		x=(x<<1)+(x<<3)+(c^48);
		c=getchar();
	}
	return x*f;
}

const int MAX_NUM = 1e9+7;
int n,k;
long long ans;

char c[505];

inline bool cheak(char x[])
{
	if(x[1] != '(' || x[n] != ')')
		return false;
	queue <char> p;
	for(re int i = 1;i <= n;++i)
	{
		if(c[i] == '(')
			p.push(c[i]);
		if(c[i] == ')')
			p.pop();
	}
	if(p.empty())
		return true;
	return false;
}

inline void dfs(int x,int set1)
{
	if(set1 == n)
	{
		if(cheak(c))
			++ans,ans%=MAX_NUM;
		return;
	}
	if(x < k && c[set1] == '?')
	{
		c[set1] = '*';
		dfs(x+1,set1+1);
		c[set1] = '(';
		dfs(x,set1+1);
		c[set1] = ')';
		dfs(x,set1+1);
	}
	else{
		if(c[set1] == '?')
		{
			c[set1] = '(';
			dfs(x,set1+1);
			c[set1] = ')';
			dfs(x,set1+1);
		}
		else
			dfs(x,set1+1);
	}
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n = read();
	k = read();
	for(re int i = 1;i <= n;++i)
	{
		cin>>c[i];
		if(c[i] == '*')
			--k;
	}
	dfs(0,1);
	printf("%lld",ans);
	return 0;
}
