#include<bits/stdc++.h>
using namespace std;
const int N=1e6,INF=(1<<30);
int n,m1,m2,ans,sb[2][N+5],top[2];
int tmp1[N+5],tmp2[N+5],vis[N+5],zu1[2][N+5],zu2[2][N+5],val1[N+5],val2[N+5];
int ton1[N+5],ton2[N+5],sum1[N+5],sum2[N+5],sum[3][N+5];
struct node
{
	int l,r;
} a[N+5],b[N+5];
int cmp(node n1,node n2) {return n1.l<n2.l;}
void solve()
{
	tmp1[m1+1]=INF;int cnt=0;
	top[1]=0;sb[1][++top[1]]=INF;
	for(int i=1,opt=1; i<=m1; i++)
	{
		if(!vis[i]) ++cnt,opt^=1;else {continue;}
		int pos=i;top[opt]=0;
		while(pos!=m1+1)
		{
			vis[pos]=1;ton1[cnt]++;sb[opt][++top[opt]]=a[pos].l;
			int l=lower_bound(sb[opt^1]+1,sb[opt^1]+1+top[opt^1],a[pos].l)-sb[opt^1];l--;
			int r=lower_bound(sb[opt^1]+1,sb[opt^1]+1+top[opt^1],a[pos].r)-sb[opt^1];r--;
			zu1[opt][top[opt]]+=sum[opt^1][r]-sum[opt^1][l-1]+max(0,r-(l+1)-1);
			pos=lower_bound(tmp1+1,tmp1+1+m1+1,a[pos].r)-tmp1;
			sum[opt][top[opt]]=sum[opt][top[opt]-1]+zu1[opt][top[opt]];
		}
		val1[cnt]=sum[opt][top[opt]];
		sb[opt][++top[opt]]=INF;
	}
	memset(vis,0,sizeof vis);
	memset(sb,0,sizeof sb);
	cnt=0;tmp2[m2+1]=INF;
	top[1]=0;sb[1][++top[1]]=INF;
	for(int i=1,opt=1; i<=m2; i++)
	{
		if(!vis[i]) ++cnt,opt^=1;else {continue;}
		int pos=i;top[opt]=0;
		while(pos!=m2+1)
		{
			vis[pos]=1;ton2[cnt]++;sb[opt][++top[opt]]=b[pos].l;
			int l=lower_bound(sb[opt^1]+1,sb[opt^1]+1+top[opt^1],b[pos].l)-sb[opt^1];--l;
			int r=lower_bound(sb[opt^1]+1,sb[opt^1]+1+top[opt^1],b[pos].r)-sb[opt^1];--r;
			zu2[opt][top[opt]]+=sum[opt^1][r]-sum[opt^1][l-1]+max(0,r-(l+1)-1);
			pos=lower_bound(tmp2+1,tmp2+1+m2+1,b[pos].r)-tmp2;
			sum[opt][top[opt]]=sum[opt][top[opt]-1]+zu2[opt][top[opt]];
		}
		val2[cnt]=sum[opt][top[opt]];			
		sb[opt][++top[opt]]=INF;
	}
	for(int i=1; i<=n; i++) sum1[i]=sum1[i-1]+ton1[i]-val1[i];
	for(int i=1; i<=n; i++) sum2[i]=sum2[i-1]+ton2[i]-val2[i];
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1; i<=m1; i++) scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1; i<=m2; i++) scanf("%d%d",&b[i].l,&b[i].r);
	sort(a+1,a+1+m1,cmp);sort(b+1,b+1+m2,cmp);
	for(int i=1; i<=m1; i++) tmp1[i]=a[i].l;
	for(int i=1; i<=m2; i++) tmp2[i]=b[i].l;
	solve();
	for(int k=0; k<=n; k++) ans=max(ans,sum1[k]+sum2[n-k]);
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
*/
