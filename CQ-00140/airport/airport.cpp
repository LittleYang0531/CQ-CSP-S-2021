#include<bits/stdc++.h>
#define R register int
#define I inline
#define ll long long
using namespace std;
const int N=2e5+3;
int l[N],r[N];
struct node
{
	int id,l;
	I bool operator<(const node &t)const{return l<t.l;}
};
set<node>S;
int ra[N],rb[N];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(R i=1;i<=m1+m2;i++)
		scanf("%d%d",l+i,r+i);
	for(R i=1;i<=m1;i++)S.insert((node){i,l[i]});
	for(R i=1;i<=n;i++)
	{
		int c=0,p=0;
		while(1)
		{
			auto it=S.lower_bound((node){0,p});
			if(it==S.end())break;
//			printf("! %d %d %d\n",i,it->id,it->l);
			S.erase(it);
			++c;
			p=r[it->id];
		}
		ra[i]=ra[i-1]+c;
	}
	S.clear();
	for(R i=m1+1;i<=m1+m2;i++)S.insert((node){i,l[i]});
	for(R i=1;i<=n;i++)
	{
		int c=0,p=0;
		while(1)
		{
			auto it=S.lower_bound((node){0,p});
			if(it==S.end())break;
//			printf("! %d %d %d\n",i,it->id,it->l);
			S.erase(it);
			++c;
			p=r[it->id];
		}
		rb[i]=rb[i-1]+c;
	}
	int ans=0;
	for(R i=0;i<=n;i++)
	{
		ans=max(ans,ra[i]+rb[n-i]);
//		printf("%d %d %d\n",i,ra[i],rb[n-i]);
	}
	printf("%d\n",ans);
}
