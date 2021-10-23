#include <bits/stdc++.h>
using namespace std;
const int N=100005;
int n,m1,m2,ans=0;
struct node {
	int re,le;
}a[5][N];
bool cmp(node x,node y){return x.re<y.re;}
priority_queue<int,vector<int>,greater<int> >s1,s2;
int main ()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)scanf("%d%d",&a[1][i].re,&a[1][i].le);
	for(int i=1;i<=m2;i++)scanf("%d%d",&a[2][i].re,&a[2][i].le);
	sort(a[1]+1,a[1]+m1+1,cmp),sort(a[2]+1,a[2]+m2+1,cmp);
	for(int i=0;i<=n;i++)
	{
		int j=n-i,sum1=0,sum2=0;
		for(int k=1;k<=m1;k++)
		{
			while(!s1.empty()&&s1.top()<a[1][k].re)s1.pop();
			if(s1.size()<i)sum1++,s1.push(a[1][k].le);
	    }
	    for(int k=1;k<=m2;k++)
	    {
	    	while(!s2.empty()&&s2.top()<a[2][k].re)s2.pop();
	    	if(s2.size()<j)sum2++,s2.push(a[2][k].le);
		}
		ans=max(ans,sum1+sum2);
		while(!s1.empty())s1.pop();
		while(!s2.empty())s2.pop();
		printf("%d %d\n",sum1,sum2);
	}
	printf("%d",ans);
	return 0;
}
