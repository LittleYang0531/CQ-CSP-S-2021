#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll n,m1,m2,c1[1000001],c2[1000001],_max;
struct s
{
	ll a,b;
}e1[1000001],e2[1000001];
inline bool operator<(s x,s y)
{
	return x.a<y.a;
}
inline ll solve(ll x1,ll x2)
{
	ll s1=0ll,s2=0ll;
	for(ll j=0ll;j<x1;j++)
		c1[j]=0ll;
	for(ll i=0ll;i<m1;i++)
		for(ll j=0ll;j<x1;j++)
			if(c1[j]<e1[i].a)
			{
				c1[j]=e1[i].b,s1++;
				break;
			}
	for(ll j=0ll;j<x2;j++)
		c2[j]=0ll;
	for(ll i=0ll;i<m2;i++)
		for(ll j=0ll;j<x2;j++)
			if(c2[j]<e2[i].a)
			{
				c2[j]=e2[i].b,s2++;
				break;
			}
	return s1+s2;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&n,&m1,&m2);
	for(ll i=0ll;i<m1;i++)
		scanf("%lld%lld",&e1[i].a,&e1[i].b);
	for(ll i=0ll;i<m2;i++)
		scanf("%lld%lld",&e2[i].a,&e2[i].b);
	sort(e1,e1+m1),sort(e2,e2+m2);
	for(ll i=0ll;i<=n;i++)
		_max=max(_max,solve(i,n-i));
	printf("%lld",_max);
	return 0;
}
