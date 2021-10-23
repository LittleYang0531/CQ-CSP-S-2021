#include<bits/stdc++.h>
#define N 505
using namespace std;
int ans,n,k,tot,a[N],st[N],top,p[N];
char s[N];
int read()
{
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') 
	{
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
	{
		x=(x<<1)+(x<<3)+ch-48;
		ch=getchar();
	}
	return x*f;
}
void dfs(int k)
{
	if(k==tot+1)
	{
		int cnt=0,mmax=0,pd=1;
		for(int i=1;i<=n;i++)
		{
			if(s[i]=='?')
			{
				p[i]=a[++cnt];
			}
		
		}
		cnt=0;top=0;
		for(int i=1;i<=n;i++)
		{
			if(p[i]==3&&p[i-1]==3) cnt++;
			else 
			{
				if(p[i]==3) cnt=1;
				else cnt=0;
			}
			mmax=max(cnt,mmax);
			if(p[i]==1) st[++top]=i;
			if(p[i]==2) 
			{
				if(i==n&&p[n-1]==3&&p[n]==2&&st[1]==1&&top==1)
				{
					return;
				}
				if(top==0) 
				{
					pd=0;
					break;
				}
				else 
				{
				//	cout<<st[top]<<endl;
					top--;
				}
			}
		}
		
		if(mmax<=k&&pd&&top==0&&p[1]!=3&&p[n]!=3)
		{
			ans++;
		}
		return;
	}
	else
	{
		for(int i=1;i<=3;i++)
		{
			a[k]=i;
			dfs(k+1);
		}
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();k=read();
	scanf("%s",s+1);
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='?')
		{
			tot++;
		}
		if(s[i]=='(') p[i]=1;
		if(s[i]==')') p[i]=2;
		if(s[i]=='*') p[i]=3;
	}
	dfs(1);
	cout<<ans;
	return 0;
}
