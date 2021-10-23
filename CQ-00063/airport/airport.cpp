#include<bits/stdc++.h>
using namespace std;
struct ch{
	int begin;
	int leave;
	bool pd;
}a[100001];
struct na{
	int begin;
	int leave;
	bool pd;
}b[100001];	
int n,i,j,l,k,sum[100000]={0},last=0,ans=0;
int search(int k)
{
	int z=k;
	l=n-k;
	for(int time=0;time<=last;time++)
	{
		for(int s=1;s<=i;s++)
		{
			if(a[s].begin==time&&z>0)
			{
			a[s].pd=1;
			z=z-1;
			sum[k]=sum[k]+1;
			}	
			if(a[s].leave==time&&a[s].pd==1)
			{
				a[s].pd=0;
				z=z+1;
			}
		}	}	
	for(int time=0;time<=last;time++)
	{
		for(int s=1;s<=j;s++)
		{
			if(b[s].begin==time&&l>0)
			{
			b[s].pd=1;
			l=l-1;
			sum[k]=sum[k]+1;
			}	
			if(b[s].leave==time&&b[s].pd==1)
			{
				b[s].pd=0;
				l=l+1;
			}
		}	
	}
	if(k<n)	
	search(k+1);
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>i>>j; 
	for(int p=1;p<=i;p++)
	{
	cin>>a[p].begin;
	cin>>a[p].leave;
	a[p].pd=0;
	if(a[p].leave>last)
	last=a[p].leave;
	}
	for(int q=1;q<=j;q++)
	{
		cin>>b[q].begin;
		cin>>b[q].leave;
		b[q].pd=0;
		if(b[q].leave>last)
		last=b[q].leave;
	}
	search(0);
	for(int h=0;h<=n;h++)
	if(sum[h]>ans)
	ans=sum[h];
	cout<<ans;
	fclose(stdin);fclose(stdout);
}

