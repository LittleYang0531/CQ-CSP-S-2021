#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long s,ans;
int n,m,k,k1,k2,t,p,cnt,tot;
int a[500005],c[500005],c2[500005],f[500005];
int bj[500005],d1[500005],d2[500005];
void dfs2(int l,int r,int num)
{
	if(num==n)
	{
		if(a[l]==c[1]) ans=min(ans,(s<<1));
//		for(int i=1;i<=n;i++)
//		cout<<c[i]<<" ";
//		cout<<endl;
		return ;
	}
	if(a[l]==c[n-num+1]) s=(s<<1),dfs2(l+1,r,num+1),s>>=1;
	if(a[r]==c[n-num+1]) s=(s<<1)+1,dfs2(l,r-1,num+1),s>>=1;
}
void dfs(int l,int r)
{
	if(cnt==n) 
	{
		dfs2(l,r,1);
		return ;
	}
	if(!bj[a[l]]) c[++cnt]=a[l],bj[a[l]]=1,s=(s<<1),dfs(l+1,r),cnt--,s>>=1,bj[a[l]]=0;
	if(!bj[a[r]]) c[++cnt]=a[r],bj[a[r]]=1,s=(s<<1)+1,dfs(l,r-1),cnt--,s>>=1,bj[a[r]]=0;
}
bool pd()
{
	int l=1,r=n*2,bjj=0,k=0,vk;
	if(a[l]==a[l+1])
	{
		k=a[l];
		l+=2;
		for(int i=r;i>=(r+l)/2;i--)
		if(a[i]!=a[r-i+l])
		{
			bjj=1;
			printf("-1");
			return 0;
		}
		else if(a[i]>k) vk=l;
		for(int i=r;i>=l;i--)
		{
			if(i==vk) printf("L");
			if(i==l+r-vk-1) printf("L");
			printf("R");
		}
		printf("\n");
		return 1;
	}
	if(a[r]==a[r-1])
	{
		k=a[r];
		r-=2;
		for(int i=l;i<=(r+l)/2;i++)
		if(a[i]!=a[r-i+l])
		{
			bjj=1;
			printf("-1");
			return 0;
		}
		else if(a[i]>k) vk=i;
		for(int i=l;i<=r;i++)
		{
			if(i==vk) printf("R");
			if(i==l+r-vk+1) printf("R");
			printf("L");
		}
		printf("\n");
		return 1;
	}
	for(int i=l;i<=(r+l)/2;i++)
	if(a[i]!=a[r-i+l])
	{
		bjj=1;
		printf("-1");
		return 0;
	}
	for(int i=l;i<=r;i++)
	printf("L");
	return 1;
}
void print(long long s,int num)
{
	if(num==0) return ;
	print(s>>1,num-1);
	if(s&1) printf("R");
	else printf("L");
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans=(1ll<<50);
		for(int i=1;i<=n*2;i++)
		{
			scanf("%d",&a[i]);
			bj[i]=0;
		}
		if(n>=30)
		{
//			printf("-1");
			pd();
			continue;
		}
//		cout<<k1<<"___"<<k2<<endl;
		dfs(1,n*2);
		if(ans==(1ll<<50)) 
		{
			printf("-1\n");
			continue;
		}
//		cout<<ans<<endl;
		print(ans,n*2);
		puts("");
//		for(int i=1;i<=k1;i++)
//		c1[a[i]]=min(i,n-i+1),c2[a[i]]=n;
//		for(int i=n;i>=k2;i--)
//		ci[a[i]]=min(i,n-i+1),c2[a[i]]=n;
//		for(int i=k1+1;i<=n;i++)
	}
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
