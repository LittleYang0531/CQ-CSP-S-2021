#include<bits/stdc++.h>
using namespace std;
const int N=1e5;
int n,m1,m2;
int a1[N],b1[N];
int a2[N],b2[N];
int ic[N],itn[N];
int ans;
int max1,max2;
int ly[N],p[N];
int ma1,ma2;
int us=1,uf=1;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=0;i<m1;i++)
	{
		cin>>a1[i]>>b1[i];
		for(int j=a1[i];j<=b1[i];j++)
		{
			ic[j]++;
			ma1=max(ma1,ic[j]);
		}
		max1=max(max1,b1[i]);
	}
	for(int i=0;i<m2;i++)
	{
		cin>>a2[i]>>b2[i];
		for(int j=a2[i];j<=b2[i];j++)
		{
			itn[j]++;
			ma2=max(ma2,itn[j]);
		}
		max2=max(max2,b2[i]);
	}
	//cout<<ma1<<" "<<ma2<<endl;
	int maxe=max(max1,max2);
	int mae=min(n,ma1);
	/*if(m1>=m2)
	{
		if(ma1<=n)
		{
			mae=ma1;
		}
		else
		{
			mae=n;
		}
	}
	else
	{
		if(m1<m2)
		{
			if(ma2<=n)
			{
				mae=n-ma2;
			}
			else
			{
				mae=0;
			}
		}
	}*/
	int mfb=n-mae;
	//swap(mfb,mae);
	//cout<<mae<<" "<<mfb<<endl;
	if(mae>0)
	for(int i=0;i<=max1;i++)
	{
		for(int j=0;j<m1;j++)
		{
			for(int k=1;k<=us;k++)
			{
				if(b1[ly[k]]==i)
				{
					mae++;
					b1[ly[k]]=0;
					break;
				}
			}
			if(a1[j]==i)
			{
				if(mae>0)
				{
					ans++;
					mae--;
					a1[j]=0;
					ly[us++]=i;
				}
			}
			
		}
	}
	if(mfb>0)
	for(int i=0;i<=max2;i++)
	{
		for(int j=0;j<m2;j++)
		{
			if(b2[j]==i)
			{
				mfb++;
				b2[j]=0;
			}
			for(int k=1;k<=uf;k++)
			{
				if(b2[p[k]]==i)
				{
					mae++;
					b2[p[k]]=0;
					break;
				}
			}
			if(a2[j]==i)
			{
				if(mfb>0)
				{
					ans++;
					mfb--;
					p[uf++]=i;
					a2[j]=0;
				}
			}
			
		}
	}
	//cout<<mae<<" "<<mfb<<endl;
	//cout<<mae<<" "<<n-mae;
	cout<<ans+1;
	return 0;
}
