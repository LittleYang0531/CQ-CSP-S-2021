#include<bits/stdc++.h>
using namespace std;
int n,m_1,m_2,t_1[1000005],t_2[1000005];
pair <int,int> a[5005],b[5005];
int max1,max2,maxt1,maxt2,sum[100005],ans;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m_1>>m_2;
	for(int i=1;i<=m_1;i++)
	{
		cin>>a[i].first>>a[i].second;
		int tn=a[i].first;
		while(tn<=a[i].second)
		{
			t_1[tn]++;
			tn++;
		}
		maxt1=max(maxt1,a[i].second);
	}
	for(int i=1;i<=maxt1;i++)
	{
		max1=max(max1,t_1[i]);
	}
	for(int i=1;i<=m_2;i++)
	{
		cin>>b[i].first>>b[i].second;
		int tn=b[i].first;
		while(tn<=b[i].second)
		{
			t_2[tn]++;
			tn++;
		}
		maxt2=max(maxt2,b[i].second);
	}
	for(int i=1;i<=maxt2;i++)
	{
		max2=max(max2,t_2[i]);
	}
	if(max1+max2<=n)
	{
		cout<<m_1+m_2<<endl;
		return 0;
	}
	for(int i=0;i<=n;i++)
	{
		//cout<<i<<": "<<endl;
		if(i==0)
		{
			sum[i]+=0;
			continue;
		}
		int cnt=0;
		memset(t_1,0,sizeof(t_1));
		for(int j=1;j<=m_1;j++)
		{
			int err=0;
			if(t_1[a[j].first]<i)
			{
				//cout<<a[j].first<<" "<<a[j].second<<" "<<j<<endl;
				cnt++;
				int now=a[j].first;
				while(now<=a[j].second)
				{
					t_1[now]++;
					if(t_1[now]>i)
					{
						//cout<<"break: "<<now<<endl;
						err=1;
						break;
					}
					now++;
				}
				if(err==1)
				{
					cnt--;
					continue;
				}
			}
		}
		sum[i]+=cnt;
		//cout<<"sum: "<<sum[i]<<" num "<<i<<endl;
	}
	for(int i=0;i<=n;i++)
	{
		//cout<<i<<": "<<endl;
		memset(t_2,0,sizeof(t_2));
		if(i==0)
		{
			sum[n-i]+=0;
			continue;
		}
		int cnt=0;
		for(int j=1;j<=m_2;j++)
		{
			int err=0;
			if(t_2[b[j].first]<i)
			{
				//cout<<b[j].first<<" "<<b[j].second<<" "<<j<<endl;
				cnt++;
				int now=b[j].first;
				while(now<=b[j].second)
				{
					t_2[now]++;
					if(t_2[now]>i)
					{
						//cout<<"break: "<<now<<endl;
						err=1;
						break;
					}
					now++;
				}
				if(err==1)
				{
					cnt--;
					continue;
				}
			}
		}
		sum[n-i]+=cnt;
		//cout<<"sum: "<<sum[n-i]<<" num "<<n-i<<endl;
	}
	for(int i=0;i<=n;i++)
	{
		//cout<<sum[i]<<endl;
		ans=max(ans,sum[i]);
	}
	cout<<ans<<endl;
	return 0;
}
