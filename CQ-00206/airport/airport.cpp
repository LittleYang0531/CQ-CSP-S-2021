#include<bits/stdc++.h>
using namespace std;
int n,m1,m2;
struct node1
{
	int nei1,nei2;
}nod1[100010];
struct node2
{
	int wai1,wai2;
}nod2[100010];
int langn[100010],langw[100010];
int da=0;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++)
	  cin>>nod1[i].nei1>>nod1[i].nei2;
	for(int i=0;i<m2;i++)
	  cin>>nod2[i].wai1>>nod2[i].wai2;
	for(int i=0;i<m1;i++)
		for(int j=i+1;j<m1;j++)
			if(nod1[i].nei1>nod1[j].nei1)
			swap(nod1[i],nod1[j]);
	for(int i=0;i<m2;i++)
		for(int j=i+1;j<m2;j++)
			if(nod2[i].wai1>nod2[i].wai1)
			swap(nod2[i],nod2[j]);
	for(int i=0;i<=n;i++)
	{
		int neip=0,waip=0;
		for(int j=0;j<m1;j++)
		{
			for(int a=0;a<i;a++)
			{
				if(nod1[j].nei1>langn[a])
				{
					langn[a]=nod1[j].nei2;
					neip++;
					break;
				}
			}
		}
		for(int j=0;j<m2;j++)
		{
			for(int a=0;a<(n-i);a++)
			{
				if(nod2[j].wai1>langw[a])
				{
					langw[a]=nod2[j].wai2;
					waip++;
					break;
				}
			}
		}
		for(int a=0;a<i;a++)
		  langn[a]=0;
		for(int a=0;a<(n-i);a++)
		  langw[a]=0;
		if(da<(neip+waip))da=neip+waip;
	}
	cout<<da<<"\n";
	return 0;
}
