#include <bits/stdc++.h>
using namespace std;
struct node{
	int arr,lea,sto;
}aa[100001],ab[100001];
int n,ma,mb,ans;
bool cmp(node a,node b)
{
	return a.arr<b.arr;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	std::cin>>n>>ma>>mb;
	for(int i=1;i<=ma;i++)
		std::cin>>aa[i].arr>>aa[i].lea;
	for(int i=1;i<=mb;i++)
		std::cin>>ab[i].arr>>ab[i].lea;
	sort(aa+1,aa+ma+1,cmp);
	sort(ab+1,ab+mb+1,cmp);
	for(int t=0;t<=n;t++)
	{
		int acnt=1,bcnt=1;
		int an=t,bn=n-t;
		int air=0;
		for(int i=1;i<=ma;i++) aa[i].sto=0;
		for(int i=1;i<=mb;i++) ab[i].sto=0;
		for(int i=1;i<=std::max(aa[ma].lea,ab[mb].lea);i++)
		{
			if(aa[acnt].arr==i&&an>0)
				air++,an--,aa[acnt++].sto=1;
			else if(aa[acnt].arr==i) acnt++;
			if(ab[bcnt].arr==i&&bn>0)
				air++,bn--,ab[bcnt++].sto=1;
			else if(ab[bcnt].arr==i) bcnt++;
			for(int j=1;j<=acnt-1;j++)
			{
				if(!aa[j].sto) continue;
				if(aa[j].lea==i) an++;
			}
			for(int j=1;j<=bcnt-1;j++)
			{
				if(!ab[j].sto) continue;
				if(ab[j].lea==i) bn++;
			}
		}
		ans=std::max(ans,air);
	}
	std::cout<<ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
