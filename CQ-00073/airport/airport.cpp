#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,m1,m2,cnt1,cnt2;
struct flight{
	ll L,R;
}A[100005],B[100005];
struct save{
	ll tot,ml;
}P[100005],Q[100005];
ll pre1[100005],pre2[100005];
bool cmp(flight x,flight y){return x.L<y.L;}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld%lld%lld",&N,&m1,&m2);
	for(ll i=1;i<=m1;i++)
		scanf("%lld%lld",&A[i].L,&A[i].R);
	for(ll i=1;i<=m2;i++)
		scanf("%lld%lld",&B[i].L,&B[i].R);
	sort(A+1,A+m1+1,cmp);
	sort(B+1,B+m2+1,cmp);
	for(ll i=1;i<=m1;i++)
	{
		ll t=-1;
		for(ll j=1;j<=cnt1;j++)
		{
			if(A[i].L>P[j].ml)
			{
				t=j;
				break;
			}
		}
		if(t==-1)
		{
			++cnt1;
			P[cnt1].tot=1,P[cnt1].ml=A[i].R;
		}
		else P[t].ml=A[i].R,++P[t].tot;
	}
	for(ll i=1;i<=m2;i++)
	{
		ll mx=0,t=-1;
		for(ll j=1;j<=cnt2;j++)
		{
			if(B[i].L>Q[j].ml)
			{
				t=j;
				break;
			}
		}
		if(t==-1)
		{
			++cnt2;
			Q[cnt2].tot=1,Q[cnt2].ml=B[i].R;
		}
		else Q[t].ml=B[i].R,++Q[t].tot;
	}
	ll tot=0;
	for(ll i=1;i<=cnt1;i++)
		pre1[i]=pre1[i-1]+P[i].tot;
	for(ll i=1;i<=cnt2;i++)
		pre2[i]=pre2[i-1]+Q[i].tot;
	for(ll i=0;i<=min(cnt1,N);i++)
		tot=max(tot,pre1[i]+pre2[min(N-i,cnt2)]);
	printf("%lld\n",tot);
}
