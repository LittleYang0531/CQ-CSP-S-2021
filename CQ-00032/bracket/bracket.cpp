#include<bits/stdc++.h>
#define ll long long
using namespace std;
const int N=510;
char s[N];
int n,k;
char c[10]={'*','(',')'};
int read()
{
	int x=0,f=1;char s=getchar();
	while(s<'0'||s>'9')
	{
		if(s=='-') f=-f;
		s=getchar();
	}
	while(s>='0'&&s<='9')
	{
		x=x*10+s-48;
		s=getchar();
	}
	return x*f;
}
bool check(char *temp)
{
	if(temp[0]!='('||temp[n-1]!=')') return 0;
	int tp=0;
	for(int i=1;i<=n;i++)
	if(temp[i-1]=='*')
	{
		int cnt=0;
		while(i<=n&&temp[i-1]=='*')
		{
			cnt++;
			if(cnt>k) return 0;
			i++;
		}
		i--;
	}
	else if(temp[i-1]=='(') tp++;
	else {
		if(!tp) return 0;
		tp--;
	}
	if(!tp) return 1;
	return 0;
}
ll ans;
void dfs(int x)
{
	if(x==n+1)
	{
		if(check(s)) ans++;
		return;
	}
	if(s[x-1]!='?') dfs(x+1);
	else 
	{
		for(int i=0;i<3;i++)
	    {
		    s[x-1]=c[i];
		    dfs(x+1);
	    }
	    s[x-1]='?';
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	scanf("%s",s);
	dfs(1);
	printf("%lld",ans);
	return 0;
}
