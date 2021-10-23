#include<bits/stdc++.h>
using namespace std;
long long n,a[5005],b[25005],t,ls[5005],flag=0;
char ans[5005],tot[5005];
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int k=1;k<=t;k++)
	{
		cin>>n;
		for(int i=1;i<=2*n;i++)
		{
			cin>>a[i];
			b[a[i]]++;
		}
		for(int i=1;i<=25000;i++)
		{
			if(b[i]%2!=0)
			{
				flag=1;
				cout<<"-1";
				break; 
			}
		}
		if(flag==0)
		for(int p=1;p<=2*n;p++)
		{
			cout<<"L";
		}
		
		cout<<"\n";
	}
	return 0;
}
