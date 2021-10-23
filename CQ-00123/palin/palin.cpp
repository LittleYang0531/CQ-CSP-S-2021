#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
bool ff;
char _min[1000001],s[1000001];
ll n,e[1000001],link[1000001][3],ls=1ll;
inline void solve(ll l1,ll r1,ll l2,ll r2)
{
	if(ls==n)
	{
		strcpy(_min,s),ff=1;
		return;
	}
	if(l1<r1&&e[l1]==e[r1])
		s[ls++]='L',s[2*n-ls]='L',solve(l1+1ll,r1-1ll,l2,r2),ls--;
	else if(l1<=r1&&e[l1]==e[l2])
		s[ls++]='L',s[2*n-ls]='R',solve(l1+1ll,r1,l2+1ll,r2),ls--;
	else;
	if(ff)
		return;
	if(l2<=r2&&e[r1]==e[r2])
		s[ls++]='R',s[2*n-ls]='L',solve(l1,r1-1ll,l2,r2-1ll),ls--;
	else if(l2<r2&&e[l2]==e[r2])
		s[ls++]='R',s[2*n-ls]='R',solve(l1,r1,l2+1ll,r2-1ll),ls--;
	else;
	return;
}
int main()
{
	freopen("palin2.in","r",stdin);
	freopen("palin.out","w",stdout);
	bool f;
	ll t;
	scanf("%lld",&t);
	while(t--)
	{
		scanf("%lld",&n),_min[0]='z',s[0]='\0',ff=0;
		for(ll i=1ll;i<=n;i++)
			link[i][0]=link[i][1]=0ll;
		for(ll i=1ll;i<=2ll*n;i++)
		{
			scanf("%lld",e+i),s[i]=_min[i]='\0';
			if(link[e[i]][0])
				link[e[i]][1]=i;
			else
				link[e[i]][0]=i;
		}
		if(e[1]==e[2*n])
		{
			f=1;
			for(ll i=1ll;i<=n;i++)
				if(e[i]^e[2*n-i+1])
				{
					puts("-1"),f=0;
					break;
				}
			if(f)
			{
				for(ll i=1ll;i<=2ll*n;i++)
					printf("L");
				puts("");
			}
		}
		else
		{
			s[0]=s[2*n-1]='L',solve(2ll,link[e[1]][1]-1ll,link[e[1]][1]+1ll,2ll*n);
			if(_min[0]^'z')
				puts(_min);
			else
			{
				s[0]='R',solve(1ll,link[e[2*n]][0]-1ll,link[e[2*n]][0]+1ll,2ll*n-1ll);
				if(_min[0]^'z')
					puts(_min);
				else
					puts("-1");
			}
		}
	}
	return 0;
}
