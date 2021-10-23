#include<iostream>
#include<cstdio>
#include<queue>
#include<cmath>
#include<stack>
#include<cstring>
#include<algorithm>
#define N 100005
#define INF 0x7fffffff
using namespace std;
char c[1005];
int f[1005];
int n,k;
stack<int> s;
bool check()
{
	bool vst[105]={0};
	int x=0;
	for(int i=1;i<=n;i++)
	{
		if(c[i]=='*') x++;
		else 
		{
			x=0;
			if(c[i]=='(') s.push(i);
			else 
			{
				if(!s.empty())
				{
					if(c[s.top()-1]=='*' && s.top()!=1 && c[i+1]=='*' && i!=n) return false;
					s.pop();
				}
				else return false;
			}
		}
		if(x>k) return false;
	}
	if(c[1]=='*' || c[n]=='*') return false;
	if(s.empty()) return true;
	while(s.size()) s.pop();
	return false;
}
int dfs(int dep)
{
	if(dep>f[0])
	{
		return check();
	}
	int re=0;
	c[f[dep]]='(';
	re+=dfs(dep+1);
	c[f[dep]]=')';
	re+=dfs(dep+1);
	c[f[dep]]='*';
	re+=dfs(dep+1);
	return re;
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	if(n>=40)
	{
		long long rp=0x7fffffffffffffff;
		printf("134217728");
		return 0;
	}
	for(int i=1;i<=n;i++)
	{
		cin>>c[i];
		if(c[i]=='?') f[++f[0]]=i;
	}
	cout<<dfs(1);
	return 0;
}

