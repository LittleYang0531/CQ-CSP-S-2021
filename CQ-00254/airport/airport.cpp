#include<bits/stdc++.h>
using namespace std;
int f1[100005],f2[100005],maxx;
//f1[i]表示选I个国内区廊桥可以停多少架飞机，
//f2[i]表示选I个国际区廊桥可以停多少架飞机，
//inline int read()
//{
//	char c=getchar();
//	int x=0,fh=1;
//	while(c<'0'||c>'9')
//	{
//		if(c=='-')
//		fh=-1;
//		c=getchar();
//	}
//	while(c>='0'&&c<='9')
//	x=(x<<3)+(x<<1)+c-'0',c=getchar();
//	return x*fh;
//}
int n,m1,m2;
struct ab{
	int fst,last;
};
bool cmp(ab x,ab y)
{
	return x.fst<y.fst||(x.fst==y.fst&&x.last<y.last);
}
ab k1[100005],k2[100005];
bool pd1[100005],pd2[100005];
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;++i)
	scanf("%d%d",&k1[i].fst,&k1[i].last);
	for(int i=1;i<=m2;++i)
	scanf("%d%d",&k2[i].fst,&k2[i].last);
	sort(k1+1,k1+1+m1,cmp);
	sort(k2+1,k2+1+m2,cmp);
//	for(int i=1;i<=m1;++i)
//	cout<<k1[i].fst<<" "<<k1[i].last<<endl;
    int fst1=1,ccc=1;
    while(1)
    {
    	int sum1=0;
    	while(pd1[fst1]&&fst1<=m1)fst1++;
    	if(fst1>m1)break;
    	int shijian1=k1[fst1].last;
    	sum1++;
    	pd1[fst1]=1;
    	int dqwz1=fst1+1;
    	while(dqwz1<=m1)
    	{
    		while(pd1[dqwz1]||(dqwz1<=m1&&k1[dqwz1].fst<shijian1))dqwz1++;
    		if(dqwz1>m1)break;
    		pd1[dqwz1]=1;
    		sum1++;
    		shijian1=k1[dqwz1].last;
    		dqwz1++;
		}
		f1[ccc]=f1[ccc-1]+sum1;
		ccc++;
	}
//	for(int i=1;i<ccc;++i)
//	cout<<f1[i]<<" ";
//	cout<<endl;
	int fst2=1,ddd=1;
	while(1)
    {
    	int sum2=0;
    	while(pd2[fst2]&&fst2<=m2)fst2++;
    	if(fst2>m2)break;
    	int shijian2=k2[fst2].last;
    	sum2++;
    	pd2[fst2]=1;
    	int dqwz2=fst2+1;
    	while(dqwz2<=m2)
    	{
    		while(pd2[dqwz2]||(dqwz2<=m2&&k2[dqwz2].fst<shijian2))dqwz2++;
    		if(dqwz2>m2)break;
    		pd2[dqwz2]=1;
    		sum2++;
    		shijian2=k2[dqwz2].last;
    		dqwz2++;
		}
		f2[ddd]=f2[ddd-1]+sum2;
		ddd++;
	}
//	for(int i=1;i<ddd;++i)
//	cout<<f2[i]<<" ";
    for(int i=ccc;i<=n;++i)
    f1[i]=f1[i-1];
    for(int i=ddd;i<=n;++i)
    f2[i]=f2[i-1];
    for(int i=0;i<=n;++i)
    maxx=max(maxx,f1[i]+f2[n-i]);
    printf("%d",maxx);
	return 0;
}
