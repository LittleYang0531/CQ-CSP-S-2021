#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
struct ok{
	int l,r;
}a[N],b[N];
int n,ma,mb,ans,biao1[N],biao2[N];
int ansa[N],ansb[N];
bool cmp(ok x,ok y) {return x.l<y.l;}
void check1()
{
	int tot=0,now=1;
	memset(biao1,0,sizeof(biao1));
	while(tot<ma)
	{
		for(int i=1;i<=ma;i++) if(!biao1[i])
		{
			int t=i;
			biao1[i]=now,tot++;
			while(a[i+1].l<a[t].r&&(i+1)<=ma) i++;
		}
		now++;
	}
	for(int i=1;i<=ma;i++) ansa[biao1[i]]++;
	for(int i=1;i<=n;i++) ansa[i]+=ansa[i-1];
}
void check2()
{
	int tot=0,now=1;
	memset(biao2,0,sizeof(biao2));
	while(tot<mb)
	{
		for(int i=1;i<=mb;i++) if(!biao2[i])
		{
			int t=i;
			biao2[i]=now,tot++;
			while(b[i+1].l<b[t].r&&(i+1)<=mb) i++;
		}
		now++;
	}
	for(int i=1;i<=mb;i++) ansb[biao2[i]]++;
	for(int i=1;i<=n;i++) ansb[i]+=ansb[i-1];
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&ma,&mb);
	for(int i=1;i<=ma;i++) scanf("%d%d",&a[i].l,&a[i].r);
	for(int i=1;i<=mb;i++) scanf("%d%d",&b[i].l,&b[i].r);
	sort(a+1,a+ma+1,cmp),sort(b+1,b+mb+1,cmp);
	check1(),check2();
	for(int i=0;i<=n;i++) ans=max(ans,ansa[i]+ansb[n-i]);
	printf("%d",ans);
	fclose(stdin);fclose(stdout);
	return 0;
}
