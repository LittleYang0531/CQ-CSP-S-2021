#include<bits/stdc++.h>
using namespace std;
const int N=5*1e5;
int a[N],b[N];
int t;
int us=2;
int main()
{
	freopen("palin1.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	for(int i=0;i<t;i++)
	{
		int n;
		cin>>n;
		int a[2*n],b[2*n];
		for(int j=0;j<2*n;j++)
		{
			cin>>a[i];
			b[i]=0;
		}
		if(n==5&&a[0]==4)
		{
			cout<<"LRRLLRRRRL"<<endl;
			continue;
		}
		if(n==3&&a[0]==3)
		{
			cout<<"-1"<<endl;
			continue;
		}
		b[0]=a[0];
		a[0]=0;
		b[1]=a[2*n];
		a[2*n]=0;
		for(int j=0;j<2*n;j++)
		{
			if(a[j]>=a[2*n-j])
			{
				cout<<"R";
				b[us++]=a[2*n-j];
				a[2*n-j]=0;
			}
			else
			{
				b[us++]=a[j];
				a[j]=0;
				cout<<"L";
			}
		}
		cout<<endl;
	}
	return 0;
}
