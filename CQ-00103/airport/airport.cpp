#include<bits/stdc++.h>
#define x first
#define y second
using namespace std;
typedef long long ll;
typedef pair<int,int> pii;
const int N=1e5+10;
int n,m1,m2;
pii a1[N],a2[N];
int id[N];
int Size[N],cnt;
ll s[N];
int ans;
bool cmp(pii a,pii b)
{
	return a.x<b.x;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&a1[i].x,&a1[i].y);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&a2[i].x,&a2[i].y);
	sort(a1+1,a1+m1+1,cmp);
	sort(a2+1,a2+m2+1,cmp);
	for(int i=1;i<=m1;i++)
	{
		if(id[i]==0)
			id[i]=++cnt;
		Size[id[i]]++;
		int j=i+1;
		while(j<=m1 && (a1[i].y>a1[j].x || id[j]!=0))
			j++;
		if(j>m1) continue;
		id[j]=id[i];
	}
	for(int i=m1+1;i<=m1+m2;i++)
	{
		if(id[i]==0)
			id[i]=++cnt;
		Size[id[i]]++;
		int j=i+1;
		while(j<=m1+m2 && (a2[i-m1].y>a2[j-m1].x || id[j]!=0))
			j++;
		if(j>m1+m2) continue;
		id[j]=id[i];
	}
	for(int i=1;i<=cnt;i++)
		s[i]=s[i-1]+Size[i];
	for(int i=0;i<=n;i++)
	{
		int t=min(cnt,id[m1+1]+n-i-1);
		int res=s[i]-s[id[m1+1]-1]+s[t];
		ans=max(ans,res);
	}
	printf("%d",ans);
	return 0;
}
