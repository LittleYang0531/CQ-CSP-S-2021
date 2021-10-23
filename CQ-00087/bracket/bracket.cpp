#include<bits/stdc++.h>
using namespace std;
int n,k;
char ch[100005];
int ans;
void dfs(int x,int cnt,int top)
{
//	printf("%d %d %d\n",x,cnt,top);
//	system("pause");
	if(x==n+1)
	{
//		printf("%d %d\n",cnt,top);
		if(cnt>k)return ;
		if(top>0)return ;
		ans++;
//		printf("%d\n",ans);
//		system("pause");
		return ;
	}
	if(cnt>k)return ;
	if(ch[x]=='(')dfs(x+1,cnt,top+1);
	else if(ch[x]==')')
	{
		if(top==0)return ;
		else dfs(x+1,0,top-1);
	}
	else if(ch[x]=='*')dfs(x+1,cnt+1,top);
	else
	{
		if(top>0)dfs(x+1,cnt,top-1);
		if(top>0)dfs(x+1,cnt+1,top);
		dfs(x+1,0,top+1);
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	scanf("%s",ch+1);
	dfs(1,0,0);
	printf("%d",ans);
	return 0;
}
