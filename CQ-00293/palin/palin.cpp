#include <bits/stdc++.h>
using namespace std;
int t,n,x;
int a[500001],pos[250001][2],vis[500001];
int xl[500001];
int lw,rw,ll,rl,k;
bool flag=1;
char ans[500001];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		cin>>n;
		for(int i=1;i<=n*2;i++)
		{
			scanf("%d",&a[i]);
			if(!pos[a[i]][0]) pos[a[i]][0]=i;
			else pos[a[i]][1]=i;
		}
		lw=1;rw=n*2+1;
		ll=rl=pos[a[lw]][1];
		vis[a[1]]=1;
		ans[1]=ans[2*n]='L';
		k=1;
		while(k!=n)
		{
			if((pos[a[lw+1]][1]+1==ll||pos[a[lw+1]][1]-1==rl)&&(!vis[a[lw+1]]))
			{
				vis[a[lw+1]]=1;
				xl[k+1]=xl[2*n-k]=a[lw+1];
				ans[k+1]='L';
				k++;
				lw++;
				if(pos[a[lw]][1]+1==ll) ll--;
				else rl++;
			}
			else
			{
				if((pos[a[rw-1]][0]+1==ll||pos[a[rw-1]][0]-1==rl)&&(!vis[a[rw-1]]))
				{
					vis[a[rw-1]]=1;
					xl[k+1]=xl[2*n-k]=a[rw-1];
					ans[k+1]='R';
					k++;
					rw--;
					if(pos[a[rw]][0]+1==ll) ll--;
					else rl++;
				}
				else
				{
					flag=0;
					cout<<-1<<endl;
					break;
				}
			}
		}
		if(flag)
		{
			int q=1;
			while(rl!=ll)
			{
				if(a[ll]==xl[n+q])
				{
					ans[n+q]='L';
					ll++;
				}
				else
				{
					ans[n+q]='R';
					rl--;
				}
				q++;
			}
			for(int i=1;i<=2*n;i++) cout<<ans[i];
			cout<<endl;
		}
		memset(a,0,sizeof(a));
		memset(pos,0,sizeof(pos));
		memset(vis,0,sizeof(vis));
		memset(xl,0,sizeof(xl));
		flag=1;
	}
	return 0;
}
