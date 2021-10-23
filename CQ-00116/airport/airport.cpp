#include<iostream>
#include<algorithm>
using namespace std;
const int N=100005;                                
int n,m1,m2,a1[N],b1[N],a2[N],b2[N],f1[N],f2[N];
int q1[N],q2[N],ans;
int main()
{
//	freopen("airport.in","r",stdin);
//	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&m1,&m2);
	for(int i=1;i<=m1;i++)
	scanf("%d%d",&a1[i],&b1[i]);
	for(int i=1;i<=m2;i++)
	scanf("%d%d",&a2[i],&b2[i]);
	for(int k1=1;k1<=m1;k1++)
	{
		f1[k1]=f1[k1-1]+1;
		q1[k1]=b1[f1[k1]];//把第f1[k1]个飞机放进去 
	    while(true)//从第fi[k1+1]个飞机开始放，看k1个位子能放多少个 
	    {
	    	sort(q1+1,q1+1+k1);
	    	if(q1[1]>a1[f1[k1]+1])break;
	    	int l=1,r=k1;//二分枚举，找到q中小于等于ai的最大数 
	    	while(l<r)
	    	{
	    		int x=(l+r+1)/2;
	    		if(a1[f1[k1]+1]<q1[x])
	    		{
	    		    r=x-1;
				}
				else
				{
				    l=x;
				}
			}
			//如果每个q都大于ai，则停止 
			q1[l]=b1[++f1[k1]];//找到了就放进去 
		}
		printf("%d\n",k1);
		for(int i=1;i<=k1;i++)
		{
			printf("%d ",q1[i]);
			printf("\n");
		}
	}
	for(int i=m1;i<=n;i++)
	f1[i]=m1;
	for(int k1=1;k1<=m2;k1++)
	{
		f2[k1]=f2[k1-1]+1;
		q2[k1]=b2[f2[k1]];
	    while(true)
	    {
	    	sort(q2+1,q2+1+k1);
	    	if(q2[1]>a1[f1[k1]+1])break;
	    	int l=1,r=k1+1;
	    	while(l<r)
	    	{
	    		int x=(l+r+1)/2;
	    		if(a2[f2[k1]+1]<q2[x])
	    		{
	    		    r=x-1;
				}
				else
				{
				     l=x;
				}
			}
				q2[l]=b2[++f2[k1]];
	        }
	}
	for(int i=m2;i<=n;i++)
	f2[i]=m2;
	for(int i=0;i<=n;i++)
	{
		ans=max(ans,f1[i]+f2[n-i]);
	}
	//for(int i=0;i<=n;i++)
	//printf("%d ",f1[i]); 
	//for(int i=0;i<=n;i++)
	//printf("%d ",f2[i]); 
	//printf("%d",ans);
	return 0;
}
