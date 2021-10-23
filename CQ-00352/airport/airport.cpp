#include<bits/stdc++.h>
using namespace std;
long long n,m_1,m_2,ans=0;
struct ZFC{
	long long st,en;
};
ZFC A1[100005],A2[100005];
bool cmp(ZFC a,ZFC b)
{
	return a.st<b.st;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m_1>>m_2;
	for(int i=1;i<=m_1;i++)
		scanf("%d%d",&A1[i].st,&A1[i].en);
	for(int i=1;i<=m_2;i++)
		scanf("%d%d",&A2[i].st,&A2[i].en);
	sort(A1+1,A1+1+m_1,cmp);
	sort(A2+1,A2+1+m_2,cmp);	
	for(int i=0;i<=n;i++)
	{
		queue<ZFC>q1;
		queue<ZFC>q2;
		long long ans1=0;
		for(int j=1;j<=m_1;j++)
		{
			if(i==1) break;
			if(q1.size()<i)
			{
				q1.push(A1[j]);
				ans1++;
			}
			else
			{
				ZFC a1=q1.front();
				if(a1.en<A1[j].st)
				{
					q1.pop();
					q1.push(A1[j]);
					ans1++;
				}
			}
		}
		for(int j=1;j<=m_2;j++)
		{
			if(i==n) break;
			if(q2.size()<n-i)
			{
				q2.push(A2[j]);
				ans1++;
			}
			else
			{
				ZFC a2=q2.front();
				if(a2.en<A2[j].st)
				{
					q2.pop();
					q2.push(A2[j]);
					ans1++;
				}
			}
		}
		ans=max(ans,ans1);
	}
	cout<<ans;
	return 0;
}
