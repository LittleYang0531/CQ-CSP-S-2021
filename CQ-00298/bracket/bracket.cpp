#include<bits/stdc++.h>
#define inl inline
typedef long long ll;
using namespace std;
const int maxn=505,mod=1e9+7;
int n,K,ans;
char s[maxn];
bool flag;
inl bool Check()
{
	int sum=0;
	for(int i=1;i<=n;++i)
		if(s[i]!='*') sum=0;
		else if(++sum>K) return false;
	for(int i=1,j;i<=n;++i)
		if(s[i]=='(')
		{
			flag=false;
			for(sum=1,j=i+1;sum;++j)
			{
				if(s[j]=='(') ++sum;
				else if(s[j]==')') --sum;
				if(sum>1) flag=true;
			}
			if(flag&&s[i+1]=='*'&&s[j-2]=='*') return false;
		}
	return true;
}
void DFS(int now,int sum)
{
	if(sum<0) return;
	if(now==n+1)
	{
		if(s[1]=='('&&s[n]==')'&&sum==0&&Check()) ++ans;
		return;
	}
	if(s[now]!='?')
	{
		if(s[now]=='(') ++sum;
		else if(s[now]==')') --sum;
		DFS(now+1,sum);
		return;
	}
	s[now]='('; DFS(now+1,sum+1);
	s[now]='*'; DFS(now+1,sum);
	s[now]=')'; DFS(now+1,sum-1);
	s[now]='?';
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&K,s+1);
	if((s[1]!='?'&&s[1]!='(')||(s[n]!='?'&&s[n]!=')')) return puts("0"),0;
	DFS(1,0); printf("%d\n",ans);
	return 0;
}
