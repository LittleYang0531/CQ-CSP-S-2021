#include<bits/stdc++.h>
using namespace std;
#define N 1000005
int t;
int n;
int flag;
int a[N],l,r;
int sta[N],len;
int ans[N],num[N];
char put[5]={"LR"};
int bfs(int now,int l,int r,int lr)
{
	if(flag==1)return 0;
	if(now==2*n)
	{
		for(int i=1;i<=n;i++)
			if(num[i]!=num[2*n+1-i])return 0;
		for(int i=1;i<=n;i++)
			cout<<put[ans[i]];
	}
	ans[now]=0;num[now]=a[l];bfs(now+1,l+1,r,0);
	ans[now]=1;num[now]=a[r];bfs(now+1,l,r-1,1);
}
int work()
{
	flag=0;
	scanf("%d",&n);
	for(int i=1;i<=2*n;i++)
		scanf("%d",&a[i]);
	bfs(1,2,2*n,0);
	bfs(1,1,2*n-1,1);
	if(!flag)printf("-1");
	printf("\n");
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)work();
	return 0;
}
