#include<bits/stdc++.h>
#define N 100005
using namespace std;
struct node
{
	int a,b;
}pr1[N],pr2[N];
int n,mm1,mm2,tot1,tot2,ans=0,tp_ans;
bool vas[N];
bool cmp(node x,node y)
{
	return x.a<y.a;
}
void air(int tot,node a[],int m)
{
	memset(vas,0,sizeof(vas));
	if(tot==0)
	{
		return;
	}
	for(int i=1;i<=m;i++)
	{
		for(int j=1;j<i;j++)
		{
			if(a[i].a>a[j].b&&vas[j])
			{
				vas[j]=false;
				tot++;
			}
		}
		if(tot>=1)
		{
			tot--;
			vas[i]=true;
			tp_ans++;
//			cout<<"i:"<<i<<endl;
		}
	}
	return;
}
int main()
{
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&n,&mm1,&mm2);
	tot2=n;
	for(int i=1;i<=mm1;i++)
	{
		scanf("%d%d",&pr1[i].a,&pr1[i].b);
	}
	for(int i=1;i<=mm2;i++)
	{
		scanf("%d%d",&pr2[i].a,&pr2[i].b);
	}
	sort(pr1+1,pr1+1+n,cmp);
	sort(pr2+1,pr2+1+n,cmp);
	while(tot2>=0)
	{
		tp_ans=0;
		air(tot1,pr1,mm1);
//		cout<<"tp_ans1:"<<tp_ans<<endl;
		air(tot2,pr2,mm2);
//		cout<<"tp_ans2:"<<tp_ans<<endl;
		ans=max(ans,tp_ans);
//		cout<<"ans:"<<ans<<endl;
		tot1++;
		tot2--;
	}
	printf("%d",ans);
	return 0;
}

