#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
typedef unsigned long long ULL;
typedef unsigned int Uint;
LL n,m1,m2;		//langqiao;international,country


struct t
{
	Uint start;
	Uint end;
}inter[99999],cou[99999];

bool cmp(t & a,t & b)
{
	return a.start < b.start;
}

int main()	
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%lld %lld %lld",&n,&m1,&m2);
	for(int i = 1;i<=m1;i++)
	{
		scanf("%d %d",&cou[i].start,&cou[i].end);
	}
	
	for(int i = 1;i<=m2;i++)
	{
		scanf("%d %d",&inter[i].start,&inter[i].end);
	}
	sort(cou+1,cou+m1+1,cmp);
	sort(inter+1,inter+m2+1,cmp);
	t tem1[99999];
	t tem2[99999];
	
	memcpy(tem1,cou,sizeof(cou));
	memcpy(tem2,inter,sizeof(inter));
	ULL cnt1 = 0;
	ULL cnt2 = 0;
	
	ULL ans = 0;
	for(int i =0;i <= n;i++)
	{
		memcpy(cou,tem1,sizeof(tem1));
		memcpy(inter,tem2,sizeof(tem2));
		cnt1 = 0;
		cnt2 = 0;
		int first_pop = 1;
		int s;
		for(s = 1;s <= m1;s++)
		{
			if(cnt1 < i)	
			{
				cnt1++;
				if(cou[first_pop].end < cou[s].end){
					first_pop = s;
				}
			}
			if(cnt1 >= i){
				break;
			}
		}
		for(s; s <= m1 ; s++)
		{
			if(cou[s].start >= cou[first_pop].end){
				cnt1++;
				cou[first_pop].start = cou[s].start;
				cou[first_pop].end = cou[s].end;
			}
			for(int j = 1;j <= i;j++)
			{
				if(cou[first_pop].end > cou[j].end)
				{
					first_pop = j;
				}
			}
		}
		first_pop = 1;
		for(s = 1;s <= m2;s++)
		{
			if(cnt2 < n-i)	
			{
				cnt2++;
				if(inter[first_pop].end < inter[s].end)
				{
					first_pop = s;
				}
			}
			if(cnt2 >= n-i)	break;
		}
		for(s;s<=m2;s++)
		{
			if(inter[s].start >= inter[first_pop].end)
			{
				cnt2++;
				inter[first_pop].start = inter[s].start;
				inter[first_pop].end = inter[s].end;
			}
			for(int j = 1;j <= n-i;j++)
			{
				if(inter[first_pop].end > inter[j].end)
				{
					first_pop = j;
				}
			}
		}
		ans = max(ans,cnt1+cnt2);
	}
	cout << ans;
	
	cin.get();
	cin.get();
	return 0;
}
