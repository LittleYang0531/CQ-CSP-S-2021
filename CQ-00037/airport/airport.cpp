#include<bits/stdc++.h>
using namespace std;
const int N=2e5+5;
int n,m1,m2,ans;
struct seg
{
	int l,r;
};
seg a[N],b[N];
bool vis1[N],vis2[N];
int R,cnt;
int w1,w2;
int f[N],g[N];//f[i]/g[i]:两个航班用i个廊桥能停靠的最多的飞机数量 
bool cmp(seg x,seg y)
{
	if(x.l==y.l)
		return x.r<y.r;
	return x.l<y.l;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
		scanf("%d%d",&a[i].l,&a[i].r);
	sort(a+1,a+m1+1,cmp);
	for(int i=1;i<=m2;i++)
		scanf("%d%d",&b[i].l,&b[i].r);
	sort(b+1,b+m2+1,cmp);
	f[0]=g[0]=0;
	cnt=0;
	while(cnt<m1)
	{
		R=0;
		for(int i=1;i<=m1;i++)
			if(!vis1[i]&&a[i].l>R)
			{
				R=a[i].r;
				cnt++;
				vis1[i]=1;
			}
		w1++;
		f[w1]=cnt;
	}
	cnt=0;
	while(cnt<m2)
	{
		R=0;
		for(int i=1;i<=m2;i++)
			if(!vis2[i]&&b[i].l>R)
			{
				R=b[i].r;
				cnt++;
				vis2[i]=1;
			}
		w2++;
		g[w2]=cnt;
	} 
	for(int i=w1;i<=n;i++)
		f[i]=m1;
	for(int i=w2;i<=n;i++)
		g[i]=m2;
	for(int i=0;i<=n;i++)
		ans=max(ans,f[i]+g[n-i]);
	printf("%d\n",ans);
	return 0;
}
