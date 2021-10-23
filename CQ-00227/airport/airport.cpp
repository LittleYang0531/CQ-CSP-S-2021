#include<bits/stdc++.h>
using namespace std;
#define re register int

const int N=2e5+5;
struct node{
	int x, y;
	bool operator<(const node&p)const{
		return x < p.x;
	}
}a[N], b[N];

int n, m1, m2;
int ans1[N], ans2[N];
int L[N], R[N];
inline void merge(int x, int y){
	R[x]=y;L[y]=x;
}

signed main()
{
	freopen("airport.in", "r", stdin);
	freopen("airport.out", "w", stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(re i=1;i<=m1;++i) scanf("%d%d",&a[i].x,&a[i].y);
	for(re i=1;i<=m2;++i) scanf("%d%d",&b[i].x,&b[i].y);
	sort(a+1, a+1+m1);
	sort(b+1, b+1+m2);
	
	R[0]=1;
	for(re i=1;i<=m1;++i)
	{
		L[i]=i-1;
		R[i]=i+1;
	}
	for(re t=0;t<=n;++t)
	{
		if(t==0){ans1[t]=0;continue;}
		ans1[t]=ans1[t-1];
		int lst=0;
		for(re i=R[0];1<=i&&i<=m1;i=R[i])
		{
			if(lst < a[i].x)
			{
				lst=a[i].y;
				ans1[t]++;
				merge(L[i], R[i]);
			}
		}
	}
	
	memset(L, 0, sizeof L);
	memset(R, 0, sizeof R);
	R[0]=1;
	for(re i=1;i<=m2;++i)
	{
		L[i]=i-1;
		R[i]=i+1;
	}
	for(re t=0;t<=n;++t)
	{
		if(t==0){ans2[t]=0;continue;}
		ans2[t]=ans2[t-1];
		int lst=0;
		for(re i=R[0];1<=i && i<=m2;i=R[i])
		{
			if(lst < b[i].x)
			{
				lst=b[i].y;
				ans2[t]++;
				merge(L[i], R[i]);
			}
		}
	}
	int ret=0;
	for(re i=0;i<=n;++i)ret=max(ret, ans1[i]+ans2[n-i]);
	printf("%d", ret);
	return 0;
}
