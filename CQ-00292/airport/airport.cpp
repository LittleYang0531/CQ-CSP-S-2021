#include<bits/stdc++.h>
using namespace std;
int n,m1,m2,tot,cnt1[100001],cnt2[100001],ans;
pair<int,int>a[100001],b[100001];
set< pair<int,int> >s1;
set<int>s2;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>n>>m1>>m2;
	for(int i=1;i<=m1;++i)
		cin>>a[i].first>>a[i].second;
	sort(a+1,a+m1+1);
	for(int i=1;i<=m2;++i)
		cin>>b[i].first>>b[i].second;
	sort(b+1,b+m2+1);
	for(int i=1;i<=m1;++i)
	{
		while(!s1.empty()&&(*s1.begin()).first<a[i].first)
		{
			s2.insert((*s1.begin()).second);
			s1.erase(s1.begin());
		}
		if(s2.empty())
			s2.insert(++tot);
		++cnt1[*s2.begin()];
		s1.insert(make_pair(a[i].second,*s2.begin()));
		s2.erase(s2.begin());
	}
	s1.clear();
	s2.clear();
	tot=0;
	for(int i=1;i<=m2;++i)
	{
		while(!s1.empty()&&(*s1.begin()).first<b[i].first)
		{
			s2.insert((*s1.begin()).second);
			s1.erase(s1.begin());
		}
		if(s2.empty())
			s2.insert(++tot);
		++cnt2[*s2.begin()];
		s1.insert(make_pair(b[i].second,*s2.begin()));
		s2.erase(s2.begin());
	}
	for(int i=1;i<=n;++i)
	{
		cnt1[i]+=cnt1[i-1];
		cnt2[i]+=cnt2[i-1];
	}
	for(int i=0;i<=n;++i)
		ans=max(ans,cnt1[i]+cnt2[n-i]);
	cout<<ans<<endl;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
