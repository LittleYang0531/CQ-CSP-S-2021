#include<bits/stdc++.h>
using namespace std;
int n,t;
int b1[1000001],b[1000001],vis[1000001],c;
bool ans[1000001],op[1000001];
int a[1000001];
void dfs(int st,int ed,int l)
{
	if(l==2*n)
	{
		c=1;
		if(b[1]!=0)
		{
			for(int i=1;i<=2*n;i++)
			{
				if(ans[i]!=op[i])
				{
					if(op[i]==1)
					break;
					else
					return;
				}
			}
			for(int i=1;i<=2*n;i++)
			{
				ans[i]=op[i];
				b1[i]=b[i];
			}
		}
		else
		{
			for(int i=1;i<=2*n;i++)
			{
				ans[i]=op[i];
				b[i]=b1[i];
			}
		}
		return;
	}
	if(l<n)
	{

		if(!vis[a[st+1]])
		{
			op[l+1]=1;
			b1[l+1]=a[st+1];
			vis[a[st+1]]=1;
			dfs(st+1,ed,l+1);
			op[l+1]=0;
			b1[l+1]=0;
			vis[a[st+1]]=0;
		}
		if(!vis[a[ed-1]])
		{
			b1[l+1]=a[ed-1];
			vis[ed-1]=1;
			dfs(st,ed-1,l+1);
			b1[l+1]=0;
			vis[ed-1]=0;
		}
	}
	else
	{
		int xx=b1[2*n-l];
		if(a[st+1]==xx)
		{
			op[l+1]=1;
			b1[l+1]=xx;
			dfs(st+1,ed,l+1);
			op[l+1]=0;
			b1[l+1]=0;
		}
		else
		{
			if(a[ed-1]==xx)
			{
				b1[l+1]=xx;
				dfs(st,ed-1,l+1);
			}
			return;
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=1;i<=t;i++)
	{
		cin>>n;
		c=0;
		for(int j=1;j<=2*n;j++)
		{
			cin>>a[j];
		}
		dfs(0,2*n+1,0);
		if(!c)
		{
			cout<<"-1"<<endl;
			return 0;
		}
		for(int i=1;i<=2*n;i++)
		{
			if(!ans[i])
			cout<<"R";
			else
			cout<<"L";
		}
		cout<<endl;
	}
	return 0;
}
