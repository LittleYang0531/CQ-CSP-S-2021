#include<bits/stdc++.h>
using namespace std;
long long n,x,y,a[1005][2],b[1005][2],num1=0,num2=0,dl[1005],tot=1,tet=1,num=0,ans=0,flag=1,ma=1;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>x>>y;
	if(x<=1000&&y<=1000)
	{
		for(int i=1;i<=x;i++)
	{
		cin>>a[i][0]>>a[i][1];
	}
	for(int i=1;i<=y;i++)
	{
		cin>>b[i][0]>>b[i][1];
	}
	for(int i=0;i<=n;i++)
	{
		num=0;
		long long j=n-i;tot=1,tet=1;
		if(i!=0)
		{
		for(int k=1;k<=n;k++) dl[k]=0;
		for(int k=1;k<=x;k++)
		{
			flag=0;
			for(int r=tot;r<=tet;r++)
			{
				if(dl[r]<=a[k][0]&&i!=0)
				{
					dl[r]=a[k][1];
					num++;
					flag=1;
					break;
				
				}
			}
			if(flag==0)
			{
				if(tet-tot<i-1)
				{
					dl[tet]=a[k][1];num++,tet++;
				}
			}
			
		}
		}
		for(int k=1;k<=n;k++) dl[k]=0;
		tot=1,tet=1;
		if(j!=0)
		{
		for(int k=1;k<=y;k++)
		{
			for(int r=tot;r<=tet;r++)
			{
				if(dl[r]<=b[k][0]&&j!=0)
				{
					dl[r]=b[k][1];
					num++,flag=1;
					break;
				}
			}
			if(flag==0)
			{
				if(tet-tot<j-1)
				{
					dl[tet]=b[k][1];num++,tet++;
				}
			}
		}
		}
		ans=max(ans,num);
	}
	cout<<ans;
	}
	else cout<<n;
	return 0;
}
