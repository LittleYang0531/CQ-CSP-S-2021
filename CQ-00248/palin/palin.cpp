#include<bits/stdc++.h>
using namespace std;
int t,n,a[1000007],ti[1000007];
bool flag=0;
char ans[1000007];
bool mp[500007];
void dfs(int top1,int top2,int id)
{
	if(flag==1) return;
	if(top1>top2||id>2*n) 
	{
		for(int i=1;i<=2*n;i++)	cout<<ans[i];
		printf("\n");
//		for(int i=1;i<=2*n;i++)
//		{
//			cout<<ti[i]<<" ";
//		}
		flag=1;
		return;
	}
//	if(top1>2*n||top2<0) return;
	if(id<=n)
	{
		if(top1<=2*n&&top2>=1)
		{
			if(mp[a[top1]]==0&&mp[a[top2]]==0)
			{
				if(a[top1]>a[top2]) 
				{
					mp[a[top2]]=1,ans[id]='R',ti[id]=a[top2];
					dfs(top1,top2-1,id+1);
					mp[a[top2]]=0;
					mp[a[top1]]=1,ans[id]='L',ti[id]=a[top1];
					dfs(top1+1,top2,id+1);
					mp[a[top1]]=0;
					return;
				}
				else
				{
					mp[a[top1]]=1,ans[id]='L',ti[id]=a[top1];
					dfs(top1+1,top2,id+1);
					mp[a[top1]]=0;	
					mp[a[top2]]=1,ans[id]='R',ti[id]=a[top2];
					dfs(top1,top2-1,id+1);
					mp[a[top2]]=0;
					return;
				}
			}
			else if(mp[a[top1]]==0)
			{
				mp[a[top1]]=1,ans[id]='L',ti[id]=a[top1];
				dfs(top1+1,top2,id+1);
				mp[a[top1]]=0;	
				return;
			}
			else if(mp[a[top2]]==0)
			{
				mp[a[top2]]=1,ans[id]='R',ti[id]=a[top2];
				dfs(top1,top2-1,id+1);
				mp[a[top2]]=0;
				return;
			}
			else return;
		}
		else if(top1<=2*n)
		{
			mp[a[top1]]=1,ans[id]='L',ti[id]=a[top1];
			dfs(top1+1,top2,id+1);
			mp[a[top1]]=0;	
			return;
		}
		else
		{
			mp[a[top2]]=1,ans[id]='R',ti[id]=a[top2];
			dfs(top1,top2-1,id+1);
			mp[a[top2]]=0;
			return;
		}
	}
	else
	{
		if(top1<=2*n&&a[top1]==ti[2*n-id+1])
		{
			ans[id]='L',ti[id]=a[top1];
			dfs(top1+1,top2,id+1);
			return;
		}
		else if(top2>=0&&a[top2]==ti[2*n-id+1])
		{
			ans[id]='R',ti[id]=a[top1];
			dfs(top1,top2-1,id+1);
			return;
		}
		else  return;
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		flag=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			scanf("%d",&a[i]);
		}
		memset(mp,0,sizeof(mp));
		dfs(1,2*n,1);
		if(flag==0) printf("-1\n");
	}
	
	return 0;
}
