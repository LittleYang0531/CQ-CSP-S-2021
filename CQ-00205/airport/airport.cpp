#include<bits/stdc++.h>
using namespace std;
int n,la,lb,ca[100001],cb[100001],sum=0;
struct dfg{int l,r;
}a[100001];
struct{int r,l;
}b[100001];
void da(int u)
{
	int cs[u],k=1;
	ca[u]+=u;
	for(int i=1;i<=u;i++)
	cs[i]=a[i].l;
	for(int i=u+1;i<=la;i++)
	{
		for(int k=1;k<=u;k++)
		if(a[i].r>=cs[k])
		{
			cs[k]=a[i].l;
			ca[u]++;
			break;
		}
	}
}
void db(int u)
{
	int cs[u],k=1;
	cb[u]+=u;
	for(int i=1;i<=u;i++)
	cs[i]=a[i].l;
	for(int i=u+1;i<=lb;i++)
	{
		for(int k=1;k<=u;k++)
		if(a[i].r>=cs[k])
		{
			cs[k]=a[i].l;
			cb[u]++;
			break;
		}
	}
}
bool cmp(dfg x,dfg y)
{
	if(x.r==y.r)return x.l<y.l;
	return x.r<y.r;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	cin>>n>>la>>lb;
	for(int i=1;i<=la;i++)
	cin>>a[i].r>>a[i].l;
	for(int i=1;i<=lb;i++)
	cin>>b[i].r>>b[1].r;
	sort(a+1,a+1+la,cmp);
	for(int i=1;i<=n;i++)
	{
		da(i);
		db(i);
	}
	ca[0]=0;
	cb[0]=0;
	sum=0;
	for(int i=0;i<=n;i++)
	{
		if(ca[i]+cb[n-i]>sum)
		{
			sum=ca[i]+cb[n-i];
		}
	}
	cout<<sum;
}
