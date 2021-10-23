#include<bits/stdc++.h>
#define N 100005
using namespace std;
int n,m1,m2;
struct zjhzs
{
	int l,r;
}a[N],b[N];
bool cmp(zjhzs x,zjhzs y)
{
	return x.l<y.l;
}
int fa[N],fb[N];
int main()
{
freopen("airport.in","r",stdin);
freopen("airport.out","w",stdout);
scanf("%d%d%d",&n,&m1,&m2);
for(int i=1;i<=m1;i++)scanf("%d%d",&a[i].l,&a[i].r);
sort(a+1,a+m1+1,cmp);

priority_queue<pair<int,int> > q1;
priority_queue<int> q2;
int cnt=1;
q1.push(make_pair(-a[1].r,1));
fa[1]=1;
for(int i=2;i<=m1;i++)
{
	while(!q1.empty()&&-q1.top().first<a[i].l)
	{
		q2.push(-q1.top().second);
		q1.pop();
	}
	int id;
	if(q2.empty())
		id=++cnt;
	else
	{
		id=-q2.top();
		q2.pop();
	}
	fa[id]++;
	q1.push(make_pair(-a[i].r,id));
}
for(int i=1;i<=n;i++)fa[i]+=fa[i-1];

for(int i=1;i<=m2;i++)scanf("%d%d",&b[i].l,&b[i].r);
sort(b+1,b+m2+1,cmp);

while(!q1.empty())q1.pop();
while(!q2.empty())q2.pop();
cnt=1;
q1.push(make_pair(-b[1].r,1));
fb[1]=1;
for(int i=2;i<=m2;i++)
{
	while(!q1.empty()&&-q1.top().first<b[i].l)
	{
		q2.push(-q1.top().second);
		q1.pop();
	}
	int id;
	if(q2.empty())
		id=++cnt;
	else
	{
		id=-q2.top();
		q2.pop();
	}
	fb[id]++;
	q1.push(make_pair(-b[i].r,id));
}
for(int i=1;i<=n;i++)fb[i]+=fb[i-1];

//for(int i=0;i<=n;i++)cout<<fa[i]<<' ';
//puts("");
//for(int i=0;i<=n;i++)cout<<fb[i]<<' ';
//puts("");

int ans=0;
for(int i=0;i<=n;i++)
ans=max(ans,fa[i]+fb[n-i]);

printf("%d",ans);

return 0;
}
