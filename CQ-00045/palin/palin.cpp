#include<iostream>
#include<stdio.h>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<ctime>
#define maxn 500002
#define inf (1<<30)
typedef long long ll;
using namespace std;
int read()
{
	int f=1,x=0;
	char c=getchar();
	while(c<'0'||c>'9')c=='-'?f=-f,c=getchar():c=getchar();
	while(c>='0'&&c<='9')x=x*10+(c^48),c=getchar();
	return x*f;
}
int a[maxn*2];
bool ans[maxn*2];
int s[maxn];
bool bj[maxn];
int l,r;
bool vis;
int n;
void dfs(int x)
{
	if(x>n)
	{
		bool flag=1;
		int ll=l,rr=r;
		for(int i=n,j=n+1;i>=1;i--,j++)
		{
			if(a[l]==s[i])
			{
				ans[j]=0;
				l++;
			}else if(a[r]==s[i])
			{
				ans[j]=1;
				r--;
			}else
			{
				flag=0;
				break;
			}
		}
		if(flag)
		{
			vis=1;
			for(int i=1;i<=2*n;i++)
			{
				if(ans[i])
				{
					putchar('R');
				}else putchar('L');
			}
			putchar('\n');
		}
		l=ll;
		r=rr;
		return;
	}
	if(!bj[a[l]])
	{
		bj[a[l]]=1;
		s[x]=a[l];
		ans[x]=0;
		l++;
		dfs(x+1);
		l--;
		bj[a[l]]=0;
		if(vis)return;
	}
	if(!bj[a[r]])
	{
		bj[a[r]]=1;
		s[x]=a[r];
		ans[x]=1;
		r--;
		dfs(x+1);
		r++;
		bj[a[r]]=0;
		if(vis) return;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T=read();
	while(T--)
	{
		n=read();
		for(int i=1;i<=2*n;i++)
		{
			a[i]=read();
		}
		l=1,r=2*n;
		vis=0;
		dfs(1);
		if(!vis)
		{
			puts("-1");
		}
	}
	return 0;
}


