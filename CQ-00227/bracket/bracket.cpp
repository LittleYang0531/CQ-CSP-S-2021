#include<bits/stdc++.h>
using namespace std;
#define re register int
#define LL long long

const int mo=1e9+7;
const int N=1e5+5;
char S[N];

int ans, n, k;
inline bool check()
{
	if(S[1]!='(' || S[n]!=')')return 0;
	stack<int>s;
	for(re i=1, tmp=0;i<=n;++i)
	{
		if(S[i]=='(')s.push(i);
		if(S[i]==')')
		{
			if(!s.size())return 0;
			int x=s.top();
			s.pop();
			int ff=0;
			for(re j=x+1;j<i;++j)if(S[j]!='*')ff=1;
			if(ff && S[x+1]=='*' && S[i-1] =='*')return 0;
		}
		if(S[i]!='*')tmp=0;
		else tmp++;
		if(tmp>k)return 0;
	}
	if(s.size())return 0;
	return 1;
}

int cnt;
void dfs(int x, int tmp)
{
	if(cnt<0 || tmp>k)return;
	if(x == n+1)
	{
		if(cnt)return;
		if(check())(ans+=1)%=mo;
		return;
	}
	
	if(S[x]=='?')
	{
		if(x==1){S[x]='(';cnt++;dfs(x+1, 0);return;}
		if(x==n){S[x]=')';cnt--;dfs(x+1, 0);cnt++;return;}
		S[x]='(';
		cnt++;
		dfs(x+1, 0);
		cnt--;
		
		S[x]=')';
		cnt--;
		dfs(x+1, 0);
		cnt++;
		
		S[x]='*';
		dfs(x+1, tmp+1);
		
		S[x]='?';
	}
	else
	{
		if(S[x]=='(')cnt++;
		if(S[x]==')')cnt--;
		dfs(x+1, (S[x]=='*'?tmp+1:0));
		if(S[x]=='(')cnt--;
		if(S[x]==')')cnt++;
	}
}
signed main()
{
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",&S[1]);
	dfs(1, 0);
	printf("%d", ans);
	return 0;
}

