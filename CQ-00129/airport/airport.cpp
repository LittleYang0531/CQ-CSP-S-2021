#include<bits/stdc++.h>
using namespace std;
const int maxn=100005;
struct st
{
	int l,r;
}pl[maxn];
int ans1[maxn],ans2[maxn];
map<int,int>mp;
map<int,int>::iterator it;
int n,x,y;
bool cmp(st a,st b)
{
	return a.l<b.l;
}
int sj(int l,int r1,int w)
{
	int r=r1;
	while(l<r)
	{
		int mid=(l+r)>>1;
		if(pl[mid].l>w) r=mid;
		else l=mid; 
	}
	if(pl[l].l>=w) return l;
	return -1;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>x>>y;
	for(int i=1;i<=x;i++)
	{
		cin>>pl[i].l>>pl[i].r;
		mp[pl[i].l]=pl[i].r;
	}
	sort(pl+1,pl+x+1,cmp);
	int cnt1=0;
	for(int i=1;i<=x;i++)
	{
		if(mp.count(pl[i].l))
		{
			cnt1++;
			int p=0,cnt2=0;
			while(1)
			{
				it=mp.upper_bound(p);
				if(it==mp.end()) break;
				p=(*it).second;
				cnt2++;
				mp.erase((*it).first);
			}
			ans1[cnt1]=cnt2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans1[i]+=ans1[i-1];
	}
	for(int i=1;i<=y;i++)
	{
		cin>>pl[i].l>>pl[i].r;
		mp[pl[i].l]=pl[i].r;
	}
	sort(pl+1,pl+y+1,cmp);
	cnt1=0;
	for(int i=1;i<=y;i++)
	{
		if(mp.count(pl[i].l))
		{
			cnt1++;
			int p=0,cnt2=0;
			while(1)
			{
				it=mp.upper_bound(p);
				if(it==mp.end()) break;
				p=(*it).second;
				cnt2++;
				mp.erase((*it).first);
			}
			ans2[cnt1]=cnt2;
		}
	}
	for(int i=1;i<=n;i++)
	{
		ans2[i]+=ans2[i-1];
	}
	int ans=0;
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,ans1[i]+ans2[n-i]);
	}
	cout<<ans;
	return 0;
}
