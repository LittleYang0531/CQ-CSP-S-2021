#include<bits/stdc++.h>
using namespace std;
int n,m,mm,ans;
struct node{int x,y;}a[100010],b[100010];
priority_queue<node>q;
bool operator<(node x,node y){return x.y>y.y;}
bool cmpx(node x,node y){return x.x<y.x;}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m,&mm);
	for(int i=1;i<=m;i++) scanf("%d%d",&a[i].x,&a[i].y);
	for(int j=1;j<=mm;j++) scanf("%d%d",&b[j].x,&b[j].y);
	sort(a+1,a+1+m,cmpx);
	sort(b+1,b+1+mm,cmpx);
	bool flag=0;
	for(int k=0,kk=n;k<=n;k++,kk--)
	{
		int cnt=0;
		for(int i=1;i<=k&&i<=m;i++) q.push(a[i]),++cnt;
		if(!q.empty())
		{
			for(int i=k+1;i<=m;i++)
				if(a[i].x>q.top().y)
				{
					q.pop();
					q.push(a[i]);
					++cnt;
				}
			while(!q.empty()) q.pop();
		}
		for(int j=1;j<=kk&&j<=mm;j++) q.push(b[j]),++cnt;
		if(!q.empty())
		{
			for(int j=kk+1;j<=mm;j++)
				if(b[j].x>q.top().y)
				{
					q.pop();
					q.push(b[j]);
					++cnt;
				}
			while(!q.empty()) q.pop();
		}
//		if(ans>=cnt) flag=1;
//		if(flag&&ans<cnt){printf("error\n");return 0;}
//		printf("%d %d\n",k,cnt);
		ans=max(ans,cnt);
	}
	printf("%d\n",ans);
	return 0;
}
/*
3 5 4
1 5
3 8
6 10
9 14
13 18
2 11
4 15
7 17
12 16

2 4 6
20 30
40 50
21 22
41 42
1 19
2 18
3 4
5 6
7 8
9 10
*/
