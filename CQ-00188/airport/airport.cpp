#include<bits/stdc++.h>
#define r register
using namespace std;

const int maxn = 100005;
struct lx
{
	int j,c;
}sz[maxn],sz1[maxn];

int m1,m2;

int chang[maxn];
inline int init(int n)
{
	if(n==0) return 0;
	memset(chang,0,sizeof(chang));
	r int ans=0;
	for(r int i=1;i<=m1;++i)
	{
		for(r int j=1;j<=n;++j)
		{
			if(sz[i].j>chang[j])
			{
				chang[j]=sz[i].c;
				++ans;
				break;
			}
		}
	}
	return ans;
}

inline int init2(int n)
{
	if(n==0) return 0;
	memset(chang,0,sizeof(chang));
	r int ans=0;
	for(r int i=1;i<=m2;++i)
	{
		for(r int j=1;j<=n;++j)
		{
			if(sz1[i].j>chang[j])
			{
				chang[j]=sz1[i].c;
				++ans;
				break;
			}
		}
	}
	return ans;
}

inline bool ac(lx a,lx b)
{
	return a.j<b.j;
}
int lr1[maxn],lr2[maxn],dp[maxn];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	r int n,g1=0,g2=0;
	scanf("%d%d%d",&n,&m1,&m2);
	for(r int i=1;i<=m1;++i) scanf("%d%d",&sz[i].j,&sz[i].c);
	for(r int i=1;i<=m2;++i) scanf("%d%d",&sz1[i].j,&sz1[i].c);
	sort(sz+1,sz+1+m1,ac);
	sort(sz1+1,sz1+1+m2,ac);
	while(g1+g2<n)
	{
		//Q1 ++g1	
//		{
			r int mg1;
			if(lr1[g1+1]) mg1=lr1[g1+1];
			else mg1=init(g1+1);
			lr1[g1+1]=mg1;
			mg1-=lr1[g1];
			
//		}
		//Q2 ++g2
//		{
			r int mg2;
			if(lr2[g2+1]) mg2=lr2[g2+1];
			else mg2=init2(g2+1);
			lr2[g2+1]=mg2;
			mg2-=lr2[g2];
//		}
		if(mg1>=mg2) 
		{
			dp[g1+g2+1]=dp[g1+g2]+mg1;
			++g1;
		}
		else 
		{
			dp[g1+g2+1]=dp[g1+g2]+mg2;
			++g2;
		}
	}
	printf("%d",dp[n]);
	exit(0);
}
