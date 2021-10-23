#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int T;
int n;
int a[N],b[N];
int l,r;
char ans[N];
int top;
bool flag=false;
bool st[N];
int id[N],cnt;
bool check()
{
	int suml=0,sumr=0;
	for(int i=n;i>=1;i--)
	{
		if(a[l]!=b[i] && a[r]!=b[i])
		{
			l-=suml,r+=sumr;
			return false;
		}
		if(a[l]==b[i])
			l++,suml++;
		else
			r--,sumr++;
	}
	l-=suml,r+=sumr;
	for(int i=n;i>=1;i--)
	{
		if(a[l]==b[i])
		{
			l++,top++;
			ans[top]='L';
		}
		else
		{
			r--,top++;
			ans[top]='R';
		}
	}
	return true;
}
void dfs(int u)
{
	if(flag)
		return;
	if(u==n+1)
	{
		if(check())
		{
			for(int i=1;i<=top;i++)
				cout<<ans[i];
			cout<<endl;
			flag=true;
		}
		return;
	}
	top++;
	if(!st[id[a[l]]])
	{
		st[id[a[l]]]=true;
		b[u]=a[l];
		l++;
		ans[top]='L';
		dfs(u+1);
		l--;
		st[id[a[l]]]=false;
	}
	if(!st[id[a[r]]])
	{
		st[id[a[r]]]=true;
		b[u]=a[r];
		r--;
		ans[top]='R';
		dfs(u+1);
		r++;
		st[id[a[r]]]=false;
	}
	top--;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--)
	{
		memset(id,-1,sizeof id);
		memset(st,false,sizeof st);
		cnt=0,top=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
			if(id[a[i]]==-1)
				id[a[i]]=++cnt;
		}
		l=1,r=2*n;
		flag=false;
		dfs(1);
		if(!flag)
			cout<<"-1"<<endl;
	}
	return 0;
}
