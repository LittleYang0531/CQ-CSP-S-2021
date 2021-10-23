#include<bits/stdc++.h>
using namespace std;
int t,n,a[1005],b[1005];
bool pd;
char c[1005],ccc[1005];
int weizhi1[1005],weizhi2[1005],jilu[1005],jilu1[1005];
//2
//5
//4 1 2 4 5 3 1 2 3 5
//3
//3 2 1 2 1 3
bool pdd(int ggg)
{
	bool sss[1001];
	for(int i=1;i<=ggg;++i)
	sss[i]=0;
	for(int i=1;i<=ggg;++i)
	{
		if(sss[a[jilu[i]]]==1)return 0;
		else sss[a[jilu[i]]]=1;
	}
	return 1;
}
void ans(int l,int r,int s)
{
	if(pd==1||s>n+1)return;
	if(s==n+1&&pdd(n))
	{
//	cout<<1<<endl;
//	for(int i=1;i<=2*n;++i)
//	cout<<b[i]<<" ";
//	cout<<endl;
		//for(int i=1;i<=n;++i)
		//if(b[i]!=b[n*2+1-i])return;
		if(pd==0)
		{
		for(int i=1;i<=n;++i)
		{
			ccc[i]=c[i];
			printf("%c",c[i]);
		}
		for(int i=1;i<=n;++i)
		jilu1[i]=jilu[i];
		}
		pd=1;
		return;
	}
	if(weizhi1[a[l]]==l)
	if(abs(weizhi2[a[l]]-jilu[s-1])==1||abs(weizhi2[a[l]]-jilu[s-1])==s-1)
	{
	jilu[s]=weizhi2[a[l]];
	b[s]=a[l];
	c[s]='L';
	ans(l+1,r,s+1);
	}
	if(weizhi2[a[l]]==l)
	if(abs(weizhi1[a[l]]-jilu[s-1])==1||abs(weizhi1[a[l]]-jilu[s-1])==s-1)
	{
	jilu[s]=weizhi1[a[l]];
	b[s]=a[l];
	c[s]='L';
	ans(l+1,r,s+1);
	}
	if(weizhi1[a[r]]==r)
	if(abs(weizhi2[a[r]]-jilu[s-1])==1||abs(weizhi2[a[r]]-jilu[s-1])==s-1)
	{
	jilu[s]=weizhi2[a[r]];
	b[s]=a[r];
	c[s]='R';
	ans(l,r-1,s+1);
	}
	if(weizhi2[a[r]]==r)
	if(abs(weizhi1[a[r]]-jilu[s-1])==1||abs(weizhi1[a[r]]-jilu[s-1])==s-1)
	{
	jilu[s]=weizhi1[a[r]];
	b[s]=a[r];
	c[s]='R';
	ans(l,r-1,s+1);
	}
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		pd=0;
		scanf("%d",&n);
		memset(weizhi1,0,sizeof(weizhi1));
		memset(weizhi2,0,sizeof(weizhi2));
		memset(jilu,0,sizeof(jilu));
		for(int i=1;i<=n*2;++i)
		{
			scanf("%d",&a[i]);
			if(!weizhi1[a[i]])
			weizhi1[a[i]]=i;
			else
			weizhi2[a[i]]=i;
		}
		b[1]=a[1];
		c[1]='L';
		jilu[1]=weizhi2[a[1]];
		ans(2,n*2,2);
		b[1]=a[n*2];
		c[1]='R';
		jilu[1]=weizhi1[a[n*2]];
		ans(1,n*2-1,2);
		if(pd==1)
		{
			int fst=1,last=n*2;
			for(int i=1;i<=n;++i)
			{
				if(ccc[i]=='L')fst++;else last--;
			}
			//cout<<fst<<endl<<last<<endl;
			while(fst<=last)
			{
				if(fst==jilu1[n])
				{
					fst++;
					printf("L");
				}
				else
				{
					last--;
					printf("R");
				}
				n--;
			}
		}
		if(pd==0)
		printf("-1");
		printf("\n");
	}
	return 0;
}
