#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=1e5+5,INF=0x3f3f3f3f,mod=1e9+7;
int read()
{
	int r=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)) r=r*10+(ch^48),ch=getchar();
	return r*f;
}
using namespace std;
int n,k,ans;
string s;
void dfs(int now,int sum,int top)
{
	if(top>n-now) return ;
	if(top<0||sum>k) return ;
	if(now==n)
	{
		if(top==0) ans++;
		return ;
	}
	if(now==n-1) dfs(now+1,0,top-1);
	else
	{
	if(s[now]=='(') dfs(now+1,0,top+1);
	else if(s[now]==')')	dfs(now+1,0,top-1);
	else if(s[now]=='?') dfs(now+1,sum+1,top),dfs(now+1,0,top+1),dfs(now+1,0,top-1);
	else if(s[now]=='*') dfs(now+1,sum+1,top);	
	}
	
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();k=read();
	cin>>s;
	dfs(1,0,1);
	printf("%d",ans);
	return 0;
}


