#include <bits/stdc++.h>
using namespace std;
int n,m1,m2,ans;
const int maxn=2e5+10;
int vis[maxn],cnt1,cnt2;
struct node{
	int t,opt,id;
}f[maxn],g[maxn];
inline bool cmp(node x,node y)
{
	return x.t<y.t;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out ","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1,x,y;i<=m1;++i)
	{
		scanf("%d%d",&x,&y);
		f[++cnt1].opt=1,f[cnt1].id=i,f[cnt1].t=x;
		f[++cnt1].opt=2,f[cnt1].id=i,f[cnt1].t=y;
	}
	for(int i=1,x,y;i<=m2;++i)
	{
		scanf("%d%d",&x,&y);
		g[++cnt2].opt=1,g[cnt2].id=i,g[cnt2].t=x;
		g[++cnt2].opt=2,g[cnt2].id=i,g[cnt2].t=y;
	}
	sort(f+1,f+1+cnt1,cmp);
	sort(g+1,g+1+cnt2,cmp);
	for(int i=0,a,b,s;i<=n;++i)
	{
		a=i,b=n-i,s=0;
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=cnt1;++j)
		{
			if(vis[f[j].id]==1)	continue;
			if(f[j].opt==1)
			{
				if(a>0)	a--,s++;
				else	vis[f[j].id]=1;
			}
			else
			{
				a++;
			}
		}
		memset(vis,0,sizeof(vis));
		for(int j=1;j<=cnt2;++j)
		{
			if(vis[g[j].id]==1)	continue;
			if(g[j].opt==1)
			{
				if(b>0)	b--,s++;
				else	vis[g[j].id]=1;
			}
			else
			{
				b++;
			}
		}
		ans=max(ans,s);
//		cout<<"AAA "<<s<<endl;
	}
	printf("%d\n",ans);
	return 0;
}
