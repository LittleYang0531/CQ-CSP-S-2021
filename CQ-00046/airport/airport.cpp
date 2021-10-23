#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,tot,cnt1[100009],cnt2[100009],res;
int bhi[1009],bhn[1009];
int sum,ans;
bool del[100009];
struct node
{
	int l,r,id;
}a[100009],b[100009];
bool cmp(node x,node y)
{
	return x.l<y.l;
}
void dfs1(int x,int t)
{
	if(bhn[x]) return;
	res=max(res,t);
	for(int i=1;i<=m1;i++)
	{
		if(a[i].l>a[x].r) del[i]=1,dfs1(i,t+1),del[i]=0;
	}
}
void dfs2(int x,int t)
{
	if(bhi[x]) return;
	res=max(res,t);
	for(int i=1;i<=m2;i++)
	{
		if(b[i].l>b[x].r) del[i]=1,dfs2(i,t+1),del[i]=0;
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++) scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;i++) scanf("%d%d",&b[i].l,&b[i].r);
	sort(a+1,a+1+m1,cmp);
	sort(b+1,b+1+m2,cmp);
	for(int i=1;i<=m1;i++) //包含数 
	{
		for(int j=i+1;j<=m1;j++)
		{
			if(a[j].l>=a[i].l&&a[j].r<=a[i].r) 
				bhn[j]=1;
		}
	}
	for(int i=1;i<=m2;i++) //包含数 
	{
		for(int j=i+1;j<=m2;j++)
		{
			if(b[j].l>=b[i].l&&b[j].r<=b[i].r) 
				bhi[j]=1;
		}
	}
//	for(int i=1;i<=m1;i++) printf("%d ",bhn[i]);
//	cout<<endl;
//	for(int i=1;i<=m2;i++) printf("%d ",bhi[i]);
	for(int i=1;i<=m1;i++)
	{
		if(!del[i]&&!bhn[i]) 
		{
			res=0;
			del[i]=1;
			dfs1(i,1);
			cnt1[++tot]=res+cnt1[tot-1];
			memset(bhn,0,sizeof bhn);
			for(int i=1;i<=m1;i++) //包含数 
			{
				if(del[i]) continue;
				for(int j=i+1;j<=m1;j++)
				{
					if(del[j]) continue;
					if(a[j].l>=a[i].l&&a[j].r<=a[i].r) 
						bhn[j]++;
				}
			}
		}
	}
//	for(int i=1;i<=tot;i++) printf("%d ",cnt1[i]);
//	printf("\n");
	memset(del,0,sizeof del);
	tot=0;
	for(int i=1;i<=m2;i++)
	{
		if(!del[i]&&!bhi[i]) 
		{
			res=0;
			del[i]=1;
			dfs2(i,1);
			cnt2[++tot]=res+cnt2[tot-1];	
			memset(bhi,0,sizeof bhi);
			for(int i=1;i<=m2;i++) //包含数 
			{
				if(del[i]) continue;
				for(int j=i+1;j<=m2;j++)
				{
					if(del[j]) continue;
					if(b[j].l>=b[i].l&&b[j].r<=b[i].r) 
						bhi[j]++;
				}
			}
		}
	}
//	for(int i=1;i<=tot;i++) printf("%d ",cnt2[i]);
//	printf("\n");
	for(int i=1;i<=n;i++)
	{
		sum=cnt1[i]+cnt2[n-i];
//		for(int j=1;j<=m1;j++) sum-=bhn[j];
//		for(int j=1;j<=m2;j++) sum-=bhi[j];
		ans=max(ans,sum);
	}
	printf("%d",ans);
	return 0;
}

