#include <iostream>
#include <cstdio>
#include <cstring>
using namespace std;
int n,k,ans;
char s[505],st[505];
bool flag[505];
void dfs(int t)
{
	if(t==n+1)
	{
		memset(flag,0,sizeof(flag));
		int pos=1,l=0,d=1;
		for(int i=1;i<=n;i++)
		{
			if(st[i]!='*')
			{
				if(i-pos-1>k) return;
				pos=i;
				if(st[i]=='(')
				{
					l++;
					if(st[i-1]=='*') flag[d]=1;
					d++;
				}
				else
				{
					l--;
					if(l<0||(flag[d]&&st[i+1]=='*')) return;
					d--;
				}
			}
		}
		if(l||st[1]=='*'||st[n]=='*') return;
		ans++;
		return;
	}
	if(s[t]!='?') st[t]=s[t],dfs(t+1);
	else
	{
		st[t]='('; dfs(t+1);
		st[t]='*'; dfs(t+1);
		st[t]=')'; dfs(t+1);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d %s",&n,&k,s+1);
	dfs(1);
	printf("%d",ans);
	return 0;
}

