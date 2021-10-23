#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstring>
#include<algorithm>
#include<cstdio>
#include<queue>
using namespace std;
char an[500001];
int t;
int n;
int a[1000001],p[1000001];
int bj[1000001];
bool flag=false;
bool check(int l,int r)
{
	int k=n;
	for(int i=n;i>=1;i--)
	{
		if(a[p[i]]!=a[l]&&a[p[i]]!=a[r])return false;
		if(a[p[i]]==a[l])l++,an[++k]='L';
		else r--,an[++k]='R';
	}
	return true;
}
void dfs(int l,int r,int k)
{
	if(flag==true)return ;
	if(k==n+1)
	{
		if(check(l,r)==true)
		{
			for(int i=1;i<=2*n;i++)cout<<an[i];
			printf("\n");
			flag=true;
		}
		return ;
	}
	else
	{
		if(bj[l]==0)
		{
			bj[l]=1;
			an[k]='L';
			p[k]=l;
			dfs(l+1,r,k+1);
			if(flag==true)return ;
			bj[l]=0;
		}
		if(bj[r]==0)
		{
			bj[r]=1;
			an[k]='R';
			p[k]=r;
			dfs(l,r-1,k+1);
			if(flag==true)return ;
			bj[r]=0;
		}
		if(flag==true)return ;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		memset(p,0,sizeof(p));
		memset(bj,0,sizeof(bj));
		flag=false;
		
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		if(n>1000)
		{
			bool ff=true;
			for(int i=1;i<=n;i++)
			{
				if(a[i]!=a[2*n-i+1])
				{
					ff=false;
					break;
				}
			}
			if(ff==false)printf("-1\n");
			else 
			{
				for(int i=1;i<=2*n;i++)cout<<"L";
				cout<<endl;
			}
		}
		else
		{
			dfs(1,2*n,1);
			if(flag==false)printf("-1\n");
		}
		
	}
	return 0;
}
