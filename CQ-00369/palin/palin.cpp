#include<bits/stdc++.h>
using namespace std;
int t,n,a[10005],b[10005],c[10005],sum,h,en;
char s[10005],ans[10005];
bool check(int a)
{
	if(a==1)return 0;
	for(int i=1;i<=a;i++)
		if(b[i]!=b[n-i+1])return 0;
	return 1;
}
void dfs(int x,bool l)
{
	if(h==en)return;
	if(l==0)
	{
		s[++ans[0]]='L';
		b[++b[0]]=a[h];
		h++;
		if(check(b[0]))
		{
			if(c[0]<b[0]&&c[0]!=0)return;
			memset(c,0,sizeof(c));
			c[0]=b[0];
			for(int i=1;i<=b[0];i++)
			{
				c[i]=b[i];
				s[i]=ans[i];
			}
		}
	}
	if(l==1)
	{
		s[++ans[0]]='R';
		b[++b[0]]=a[h];
		h++;
		if(check(b[0]))
		{
			if(c[0]<b[0]&&c[0]!=0)return;
			memset(c,0,sizeof(c));
			c[0]=b[0];
			for(int i=1;i<=b[0];i++)
			{
				c[i]=b[i];
				s[i]=ans[i];
			}
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	sum=0;
	while(t--)
	{
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		sum=0;h=1;en=n;
		dfs(1,0);dfs(1,1);
		for(int i=1;i<=b[0];i++)cout<<ans[i];
	}
	return 0;
}
