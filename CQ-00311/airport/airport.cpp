#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,insum[100001],oversum[100001],ans;
struct plane
{
	int st,ed;
}insea[100001],oversea[100001];
bool cmp(plane x,plane y)
{
	return x.st<y.st;
}
int max(int x,int y)
{
	return x>y?x:y;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for (int i=1;i<=m1;i++)scanf("%d%d",&insea[i].st,&insea[i].ed);
	for (int i=1;i<=m2;i++)scanf("%d%d",&oversea[i].st,&oversea[i].ed);
	sort(insea+1,insea+m1+1,cmp);
	sort(oversea+1,oversea+m2+1,cmp);
	for (int i=1;i<=n;i++)
	{
		priority_queue<int,vector<int>,greater<int> >q;
		int cnt=0;
		for (int j=1;j<=m1;j++)
		{
			while (!q.empty()&&q.top()<=insea[j].st)
			{
				q.pop();
				cnt--;
			}
			if (cnt<i)
			{
				q.push(insea[j].ed);
				insum[i]++;
				cnt++;
			}
		}
	}
	for (int i=1;i<=n;i++)
	{
		priority_queue<int,vector<int>,greater<int> >q;
		int cnt=0;
		for (int j=1;j<=m2;j++)
		{
			while (!q.empty()&&q.top()<=oversea[j].st)
			{
				q.pop();
				cnt--;
			}
			if (cnt<i)
			{
				q.push(oversea[j].ed);
				oversum[i]++;
				cnt++;
			}
		}
	}
	for (int i=1;(i<<1)<=n;i++)
	{
		insum[i]=max(insum[i-1],insum[i]);
		oversum[i]=max(oversum[i-1],oversum[i]);
	}
	for (int i=(n>>1)+1;i<=n;i++)
	{
		insum[i]=max(insum[i-1],insum[i]);
		oversum[i]=max(oversum[i-1],oversum[i]);
		ans=max(ans,max(insum[i]+oversum[n-i],oversum[i]+insum[n-i]));
	}
	cout<<ans;
}
//CCF Au coach sto sto ZZS orz orz
