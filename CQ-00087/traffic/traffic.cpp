#include<bits/stdc++.h>
using namespace std;
int n,m,T,k,x3[1005],t[1005],p[1005];
int ch1[1005][1005],ch2[1005][1005];
int ch[1005][1005];
int ans;
void dfs(int x,int y)
{
//	cout<<x<<" "<<y<<endl;
	if(x==n+1)
	{
		int sum=0;
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<m;j++)
			{
				if(ch[i][j]!=ch[i][j+1])
				{
					sum+=ch1[i][j];
				}
			}
		}
		for(int i=1;i<n;i++)
		{
			for(int j=1;j<=m;j++)
			{
				if(ch[i][j]!=ch[i+1][j])
				{
					sum+=ch2[i][j];
				}
			}
		}
		for(int i=1;i<=k;i++)
		{
			int ax,ay;
			if(p[i]<=m)ax=1,ay=p[i];
			else if(p[i]<=m+n)ax=p[i]-m,ay=m;
			else if(p[i]<=2*m+n)ax=n,ay=m*2-p[i]+n+1;
			else ax=2*m+2*n-p[i]+1,ay=1;
			if(ch[ax][ay]!=t[i])sum+=x3[i];
		}
		ans=min(ans,sum);
		return ;
	}
	if(y<m)
	{
		ch[x][y]=1;
		dfs(x,y+1);
		ch[x][y]=0;
		dfs(x,y+1);
	}
	else
	{
		ch[x][y]=1;
		dfs(x+1,1);
		ch[x][y]=0;
		dfs(x+1,1);
	}
}
int main()
{
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d %d %d",&n,&m,&T);
	for(int i=1;i<n;i++)
	{
		for(int j=1;j<=m;j++)
		{
			scanf("%d",&ch1[i][j]);
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<m;j++)
		{
			scanf("%d",&ch2[i][j]);
		}
	}
	while(T--)
	{
		ans=0x7fffffff;
		scanf("%d",&k);
		for(int i=1;i<=k;i++)
		{
			scanf("%d %d %d",&x3[i],&p[i],&t[i]);
		}
		if(n<=18 && m<=18)
		{
			dfs(1,1);
			printf("%d\n",ans);
			continue;
		}
//		if(k<=2)
//		{
//			if(k==1)
//			{
//				printf("0\n");
//				continue;
//			}
//			int ans=min(x[1],x[2]);
//			int ax,ay,bx,by;
//			if(p[1]<=m)ax=1,ay=p[1];
//			else if(p[1]<=m+n)ax=p[1]-m,ay=m;
//			else if(p[1]<=2*m+n)ax=n,ay=m*2-p[1]+n+1;
//			else ax=2*m+2*n-p[1]+1,ay=1;
//			if(p[2]<=m)bx=1,by=p[2];
//			else if(p[2]<=m+n)bx=p[2]-m,by=m;
//			else if(p[2]<=2*m+n)bx=n,by=m*2-p[2]+n+1;
//			else bx=2*m+2*n-p[2]+1,by=1;
//			if(ax==bx && ay==by)
//			{
//				printf("%d\n",ans);
//				continue;
//			}
//			if(t[1]==t[2])
//			{
//				printf("0\n");
//				continue;
//			}
//		}
	}
	return 0;
}
