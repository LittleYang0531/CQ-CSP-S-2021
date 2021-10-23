#include <bits/stdc++.h>
using namespace std;
int n,m1,m2;
struct node{
	int ar,tk;
};
node gn[1000001],gw[1000001];
int vis[1000001],sum;
int t1[1000001],t2[1000001],t,id=1;
int ans=-1;
bool cmp(node a,node b)
{
	return a.ar<b.ar;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
	{
		cin>>gn[i].ar>>gn[i].tk;
	}
	for(int i=1;i<=m2;i++)
	{
		cin>>gw[i].ar>>gw[i].tk;
	}
	sort(gn+1,gn+m1+1,cmp);
	sort(gw+1,gw+m2+1,cmp);
	while(sum!=m1)
	{
		for(int i=1;i<=m1;i++)
		{
			if(!vis[i]&&gn[i].ar>t)
			{
				t1[id]++; 
				vis[i]=1;
				t=gn[i].tk;
				sum++;
			}
		}
		t1[id]+=t1[id-1];
		id++;
		t=0;
	}
	sum=0;
	memset(vis,0,sizeof(vis));
	id=1;
	while(sum!=m2)
	{
		for(int i=1;i<=m2;i++)
		{
			if(!vis[i]&&gw[i].ar>t)
			{
				t2[id]++; 
				vis[i]=1;
				t=gw[i].tk;
				sum++;
			}
		}
		t2[id]+=t2[id-1];
		id++;
		t=0;
	}
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,t1[i]+t2[n-i]);
	}
	cout<<ans;
	return 0;
}
