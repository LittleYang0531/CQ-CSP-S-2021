#include<iostream>
#include<cstring>
#include<cstdio>

#define maxn 505
#define rc() getchar()

using namespace std;

char c[maxn],b[maxn];
int stk[maxn],a[maxn];
int n,m,ans;
const int mod=1e9+7;

inline int read()
{
	int x=0,b=1;char c=rc();
	while(c<'0'||c>'9') (c=='-')&&(b=-1),c=rc();
	while(c>='0'&&c<='9') x=x*10+(c^48),c=rc();
	return x*b;
}

inline bool pd()
{
	int tot=0;memset(a,0,sizeof(a));
	for(int i=1;i<=n;++i)
	{
		if(b[i]=='(') stk[++tot]=i;
		if(b[i]==')')
		{
			int now=stk[tot--];
			if(a[tot+1]!=0&&b[now+1]=='*'&&b[i-1]=='*')return false;
			a[tot]+=a[tot+1]+1;a[tot+1]=0;
		}
	}
	return true;
}

void f(int i,int k,int w)
{
	if(i==n+1)
	{
		if(k!=0||w!=0) return;
		if(pd()) ans++;
		return ;
	}
	if(c[i]=='?')
	{
		if(w!=m) b[i]='*',f(i+1,k,w+1);
		if(k<=n) b[i]='(',f(i+1,k+1,0);
		if(k!=0) b[i]=')',f(i+1,k-1,0);
		return;
	}
	if(c[i]=='*'&&w!=m) b[i]='*',f(i+1,k,w+1);
	if(c[i]=='('&&k<=n) b[i]='(',f(i+1,k+1,0);
	if(c[i]==')'&&k!=0) b[i]=')',f(i+1,k-1,0);
	return;
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	
	n=read(),m=read();
	scanf("%s",c+1);
	if(c[1]!='?'&&c[1]!='(')
	{
		cout<<0;
		return 0;
	}
	b[1]='(';f(2,1,0);
	cout<<ans;
	return 0;
}

