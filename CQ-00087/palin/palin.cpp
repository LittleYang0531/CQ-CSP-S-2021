#include<bits/stdc++.h>
using namespace std;
int n,t;
int a[100005],b[100005],cnt;
bool flag;
char ans[100005];
void dfs(int x,int l,int r)
{
//	printf("%d\n",x);
	if(flag==1)return ;
	if(x>n*2)
	{
		bool flag1=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=b[n*2-i+1])
			{
				flag1=1;
				break;
			}
		}
		if(flag1==0)
		{
			flag=1;
			return ;
		}
		return ;
	}
//	if(x<=n || b[n-x+1]==a[l])
//	{
		b[x]=a[l];
		ans[x]='L';
		dfs(x+1,l+1,r);
//	}
	if(flag==1)return ;
//	if(x<=n || b[n-x+1]==a[r])
//	{
		ans[x]='R';
		b[x]=a[r];
		dfs(x+1,l,r-1);
//	}
	if(flag==1)return ;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		flag=0;
		for(int i=1;i<=n*2;i++)
		{
			scanf("%d",&a[i]);
		}
		dfs(1,1,n*2);
		if(flag==1)
		{
			for(int i=1;i<=n*2;i++)
			{
				printf("%c",ans[i]);
			}
			printf("\n");
		}
		else printf("-1\n");
	}
	return 0;
}

