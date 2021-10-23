#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
//typedef 
int n,m1,m2,ans,sum=1;
int res1[N],res2[N];
int cnt1[N],cnt2[N];
bool st[N];
struct node
{
	int a,b;
}a1[N],a2[N];
bool cmp(node x,node y)
{
	return x.a<y.a;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;i++)
		cin>>a1[i].a>>a1[i].b;
	for(int i=1;i<=m2;i++)
		cin>>a2[i].a>>a2[i].b;
	sort(a1+1,a1+m1+1,cmp);
	sort(a2+1,a2+m2+1,cmp);
	res1[1]=res2[1]=1;
	cnt1[1]=cnt2[1]=1;
	int cnt=1;
	for(int i=2;i<=m1;i++)
	{
		memset(st,0,sizeof st);
		cnt1[i]=99999999;
		for(int j=i-1;j>0;j--)
		{
			if(!st[cnt1[j]]&&a1[i].a>a1[j].b)
				cnt1[i]=min(cnt1[i],cnt1[j]);
			st[cnt1[j]]=1;
		}
		if(cnt1[i]==99999999)cnt1[i]=++cnt;
//		cout<<cnt1[i]<<" ";
		res1[cnt1[i]]++;
	}
	cnt=1;
	for(int i=2;i<=m2;i++)
	{
		memset(st,0,sizeof st);
		cnt2[i]=99999999;
		for(int j=i-1;j>0;j--)
		{
			if(!st[cnt2[j]]&&a2[i].a>a2[j].b)
				cnt2[i]=min(cnt2[i],cnt2[j]);
			st[cnt2[j]]=1;
		}
		if(cnt2[i]==99999999)cnt2[i]=++cnt;
		//cout<<cnt2[i]<<" ";
		res2[cnt2[i]]++;
		if(cnt2[i]<=n)sum++;
	}
	int sum2=0;
	for(int i=0;i<=n;i++)
	{
		sum2+=res1[i];
		ans=max(ans,sum+sum2);
//		cout<<sum+sum2<<" ";
		sum-=res2[n-i];
	}
	cout<<ans;
	return 0;
}
/*


*/
