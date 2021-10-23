#include<stdio.h>
#include<algorithm>
using namespace std;
struct node{
	int f;
	int l;
};
node gn[100001];
node gw[100001];
int idxn[100001];
int idxw[100001];
int ans1[100001];
int ans2[100001];
bool flag1[10001];
bool flag2[10001];
long long maxx=-1;
long long s;
int f1(int x,int y)
{
	if(gn[x].f<gn[y].f)
	{
		return x>y;
	}
	else return x<y;
}
int f2(int x,int y)
{
	if(gn[x].f<gn[y].f)
	{
		return x>y;
	}
	else return x<y;
}

int main()
{
	freopen("airport.in","r",stdin);
    freopen("airport.out","w",stdout);
	int n,m1,m2;
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	{
		scanf("%d%d",&gn[i].f,&gn[i].l);
		idxn[i]=i;
	}
	sort(idxn+1,idxn+1+m1,f1);
	for(int i=1;i<=m2;i++)
	{
		scanf("%d%d",&gw[i].f,&gw[i].l);
		idxw[i]=i;
	}
	sort(idxw+1,idxw+1+m2,f2);
   
   for(int i=1;i<=n;i++)
   {
        int zl1=i;
        int zl2=i+1;
   	    if(flag1[idxn[i]]==0)
   	    {
   	    	ans1[i]++;
   	    	flag1[idxn[i]]=1;
	   	    while(zl2<=m1)
		   {
		   	 if(gn[idxn[zl2]].f>gn[idxn[zl1]].l)
		   	 {
		   	 	flag1[zl2]=1;
		   	 	ans1[i]++;
		   	  	zl1=zl2;
			 }
			 zl2++;
		   }	
		}
   }
   for(int i=1;i<=n;i++)
   {
   	    int zl1=i;
        int zl2=i+1;
   	    if(flag2[idxw[i]]==0)
   	    {
   	    	ans2[i]++;
   	    	flag2[idxw[i]]=1;
	   	    while(zl2<=m2)
		   {
		   	 if(gw[idxw[zl2]].f>gw[idxw[zl1]].l)
		   	 {
		   	 	flag1[zl2]=1;
		   	 	ans2[i]++;
		   	  	zl1=zl2;
			 }
			 zl2++;
		   }	
		}
   }
   for(int i=0;i<=n;i++)
   {
   	    for(int j=n-i;j>=0;j--)
   	    {
   	       s+=ans2[j];
		}
		for(int z=0;z<=i;z++)
		{
			s+=ans1[z];
		}
		maxx=max(maxx,s);
		s=0;
   }
   printf("%lld",maxx);
	fclose(stdin);
	fclose(stdout);
	return 0;
}
