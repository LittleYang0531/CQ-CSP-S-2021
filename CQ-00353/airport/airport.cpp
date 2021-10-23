#include<bits/stdc++.h>
#define lowbit(x) (x&(-x))
using namespace std;
struct node
{
	int l,r;
} e1[100005],e2[100005];
bool cmp(node x,node y)
{
	if(x.l==y.l) return x.r<y.r;
	return x.l<y.l;
}
int lsh[3][100000005],lst,cnt1=0,cnt2=0,a[3][100005],b[3][100005],c[5][100005],f[3][100005];
int n,m1,m2,sum[3][100005],ans=-1;
inline void init()
{
	priority_queue<int> need1,need2;
	stack<int> n1,n2;
	queue<int> q1,q2;
	memset(c,0,sizeof(c));
	memset(sum,0,sizeof(sum));
	scanf("%d%d%d",&n,&m1,&m2);
	for(register int i=1; i<=m1; ++i)
	{
		scanf("%d%d",&a[1][i],&b[1][i]);
		need1.push(a[1][i]),need1.push(b[1][i]);
		e1[i]=(node){a[1][i],b[1][i]};
	}
	for(register int i=1; i<=m2; ++i)
	{
		scanf("%d%d",&a[2][i],&b[2][i]);
		need2.push(a[2][i]),need2.push(b[2][i]);
		e2[i]=(node)
		{
			a[2][i],b[2][i]
		};
	}
	sort(e1+1,e1+1+m1,cmp);
	sort(e2+1,e2+1+m2,cmp);
	while(need1.size())
		n1.push(need1.top()),need1.pop();
	while(need2.size())
		n2.push(need2.top()),need2.pop();
	lst=-1;
	while(n1.size())
	{
		q1.push(n1.top());
		if(n1.top()==lst)
		{
			n1.pop();
			continue;
		}
		lsh[1][n1.top()]=++cnt1;
		lst=n1.top();
		n1.pop();
	}
	lst=-1;
	while(n2.size())
	{
		q2.push(n2.top());
		if(n2.top()==lst)
		{
			n2.pop();
			continue;
		}
		lsh[2][n2.top()]=++cnt2;
		lst=n2.top();
		n2.pop();
	}
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	init();
	for(register int i=0; i<=n; ++i)
	{
		memset(c,0,sizeof(c));
		register int tans1=0,tans2=0;
		for(register int j=1; j<=m1; ++j)
		{
			if(c[1][lsh[1][e1[j].l]]>=i) continue;
			++tans1;
			for(register int k=lsh[1][e1[j].l]; k<=lsh[1][e1[j].r]; ++k)
				++c[1][k];
		}
		for(register int j=1; j<=m2; ++j)
		{
			if(c[2][lsh[2][e2[j].l]]>=n-i) continue;
			++tans2;
			for(register int k=lsh[2][e2[j].l]; k<=lsh[2][e2[j].r]; ++k)
				++c[2][k];
		}
		ans=max(ans,tans1+tans2);
	}
	printf("%d",ans);
	return 0;
}
