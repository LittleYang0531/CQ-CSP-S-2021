#include<bits/stdc++.h>
using namespace std;
int t,n;
const int maxn=2e3+5;
int f[maxn][2][2];
int a[maxn];
int u[maxn];
deque<int>w;
deque<int>e;
char d[maxn],tr[maxn];
int mm;
int print()
{
	int p=1,q=2*n;
	while(p<=q)
	{
		if(u[p]!=u[q])
		return 0;
		p++,q--;
	}
	return 1;
}
int zz;
void dfs(int x,int g)
{
	for(int i=x;i<=n;i++)
	{
		for(int j=0;j<=1;j++)
		{
			u[x]=f[i][g][j];
			if(j==0)
			d[x]='L';
			else d[x]='R';
			if(x==2*n)
			{
				if(print()==1)
				{
					zz=1;
					int y=0;
					for(int j=1;j<=2*n;j++)
					{
						if(tr[j]>d[j]||tr[j]=='0')
						{
						    y=1;
							break;	
						}
					}
					if(y==1)
					{
						for(int j=1;j<=2*n;j++)
						{
							tr[j]=d[j];
						}
					}
				}
			}
			dfs(x+1,j);
		}
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		for(int i=1;i<=2*n;i++)
		tr[i]='0';
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
		{
			int u;
			scanf("%d",&u);
			w.push_back(u);
			e.push_back(u);
		}
		for(int i=1;i<=n;i++)
		{
			f[i][0][0]=w.front();//w
			f[i][1][0]=w.front();//w
			w.pop_front();
			f[i][0][1]=w.back();//e
			f[i][1][1]=w.back();//e
			e.pop_back();
		}
		dfs(1,0);
		if(zz==1)
		for(int i=1;i<=2*n;i++)
		{
			cout<<tr[i];
		}
		else cout<<"-1\n";
	}
	return 0;
}
