#include<bits/stdc++.h>
using namespace std;
const int maxn=1e5+5;
struct node
{
	int l,r;
}a[maxn],b[maxn];
bool cmp(node tx,node ty){return tx.l<ty.l;}
int n,m1,m2,ans;
int f[maxn],g[maxn],k1[maxn],k2[maxn];
priority_queue<int,vector<int>,greater<int> > q;
set<pair<int,int> > s;
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d %d %d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d %d",&a[i].l,&a[i].r);
	for(int i=1;i<=m2;i++)scanf("%d %d",&b[i].l,&b[i].r);
	sort(a+1,a+m1+1,cmp);sort(b+1,b+m2+1,cmp);
	for(int i=1;i<=m1;i++)q.push(i);
	for(int i=1;i<=m1;i++)
	{
		while(!s.empty()&&s.begin()->first<a[i].l)q.push(s.begin()->second),s.erase(s.begin());
		f[i]=q.top(),q.pop();
		s.insert(make_pair(a[i].r,f[i]));
	}
	while(!q.empty())q.pop();s.clear();
	for(int i=1;i<=m2;i++)q.push(i);
	for(int i=1;i<=m2;i++)
	{
		while(!s.empty()&&s.begin()->first<b[i].l)q.push(s.begin()->second),s.erase(s.begin());
		g[i]=q.top(),q.pop();
		s.insert(make_pair(b[i].r,g[i]));
	}
	for(int i=1;i<=m1;i++)k1[f[i]]++;
	for(int i=1;i<=max(m1,n);i++)k1[i]+=k1[i-1];
	for(int i=1;i<=m2;i++)k2[g[i]]++;
	for(int i=1;i<=max(m2,n);i++)k2[i]+=k2[i-1];
	for(int i=0;i<=n;i++)ans=max(ans,k1[i]+k2[n-i]);
	printf("%d",ans);
	return 0;
}
