#include<bits/stdc++.h>
using namespace std;
inline int read(){
	char c;
	int x=0,f=0;
	c=getchar();
	while(!isdigit(c))
	{
		if(c=='-') f=1;
		c=getchar();
	}
	while(isdigit(c))
	{
		x=x*10+c-48;
		c=getchar();
	}
	return f==0?x:-x;
}
int T,n,l,r,a[100010],tmp[100010];
bool flag=0;
string ans;
void dfs(int x)
{
	if(x==n+1)
	{
		int ll=l,rr=r;
		for(int i=n;i>=1;i--)
		{
			if(a[ll]==tmp[i])
			{
				ll++;
				continue;
			}
			else if(a[rr]==tmp[i])
			{
				rr--;
				continue;
			}
			else
			{
				return;
			}
		}
		ll=l,rr=r;
		for(int i=n;i>=1;i--)
		{
			if(a[ll]==tmp[i])
			{
				ll++;
				ans=ans+"L";
			}
			else if(a[rr]==tmp[i])
			{
				rr--;
				ans=ans+"R";
			}
		}
		flag=1;
		return;
	}
	tmp[x]=a[l++];
	dfs(x+1);
	l--;
	if(flag==1)
	{
		ans="L"+ans;
		return;
	}
	tmp[x]=a[r--];
	dfs(x+1);
	r++;
	if(flag==1)
	{
		ans="R"+ans;
		return;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--)
	{
		ans="";
		flag=0;
		n=read();
		for(int i=1;i<=2*n;i++)
		{
			a[i]=read();
		}
		l=1,r=2*n;
		dfs(1);
		if(flag==0)
		{
			cout<<-1<<'\n';
			continue;
		}
		cout<<ans<<"\n";
	}
	return 0;
}

