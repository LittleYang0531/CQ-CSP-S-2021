#include<bits/stdc++.h>
using namespace std;
int n,a,b,f[100005],t[100005],g[100005],r[100005],l,k[100005],h[100005],x=0,y=0,z=-1;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>a>>b;
	if(n>=a+b)
	{cout<<a+b<<endl;
	return 0;}
	for(int i=1;i<=a;i++)
	cin>>f[i]>>t[i];
	for(int i=1;i<=b;i++)
	cin>>g[i]>>r[i];
	for(int i=1;i<a;i++)
	for(int j=i+1;j<=a;j++)
	if(f[i]<t[j])
	{swap(f[i],t[j]);
	swap(f[i],t[j]);}
	for(int i=1;i<b;i++)
	for(int j=i+1;j<=b;j++)
	if(g[i]<r[j])
	{swap(g[i],r[j]);
	swap(g[i],r[j]);}
	for(int i=0;i<=n;i++)
	{
		l=n-i;
		if(i>0)
		{for(int j=1;j<=a;j++)
		{
			for(int u=1;u<=i;u++)
			if(k[u]<=f[j])
			{x++;
			k[u]=t[j];
			break;}
		}}
		if(l>0)
		{for(int j=1;j<=b;j++)
		{
			for(int u=1;u<=l;u++)
			if(h[u]<=g[j])
			{y++;
			h[u]=r[j];
			break;}
		}}
		for(int i=1;i<=n;i++)
		{k[i]=0;
		h[i]=0;}
		if(z<x+y)
		z=x+y;
		x=0;
		y=0;
	}
	cout<<z<<endl;
	return 0;
}
