#include<bits/stdc++.h>
using namespace std;
const int P=1e9+7,N=500;
int n,k,top,ans,len,vis[N+5];
char s[N+5],sta[N+5],d[N+5],tmp[N+5];
int check()
{
	top=0;
	for(int i=1; i<=n; i++)
	{
		if(d[i]=='(') sta[++top]='(';
		else
		{
			if(d[i]=='*')
			{
				int j=i;
				while(j<n&&d[j+1]=='*') ++j;
				if(j-i+1>k) return 0;i=j;
				sta[++top]='S';
			}
			else
			if(d[i]==')')
			{
				len=0;
				while(top&&sta[top]!='(') tmp[++len]=sta[top],--top,vis[len]=0;
				if(sta[top]!='(') return 0;
				vis[0]=vis[len+1]=1;
				for(int i=1; i<=len; i++)
					if(tmp[i]=='S')
					{
						if(!vis[i-1]&&tmp[i-1]=='A') vis[i-1]=1;
						else if(!vis[i+1]&&tmp[i+1]=='A') vis[i+1]=1;
						else if(len!=1) return 0;
					}
				--top;sta[++top]='A';
			}
		}
	}
	if(top==1) return (sta[top]=='S')?0:1;
	for(int i=1; i<=top; i++)
	{
		if(sta[i]=='S')
		{
			if(i==1||i==top) return 0;
		}
		if(sta[i]=='(') return 0;
	}
	return 1;
}
void  dfs(int p)
{
	if(p==n+1) {ans+=check();return;}
	if(s[p]!='?') d[p]=s[p],dfs(p+1);
	else d[p]=')',dfs(p+1),d[p]='(',dfs(p+1),d[p]='*',dfs(p+1);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d\n%s",&n,&k,s+1);
	dfs(1);printf("%d\n",ans);
	return 0;
}
