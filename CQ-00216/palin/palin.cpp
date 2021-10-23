#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;
int t,n,b[1000005],a[1000005];
char ans[1000005];
bool bj=0;
void dfs(int k,int l,int r)
{
	if(k==2*n+1)
	{
		for(int i=1;i<=n;i++)
			if(b[i]!=b[2*n-i+1]) return;
		for(int i=1;i<=2*n;i++) printf("%c",ans[i]);
		printf("\n");
		bj=1; return;
	}
	b[k]=a[l]; ans[k]='L'; dfs(k+1,l+1,r);
	if(bj) return;
	b[k]=a[r]; ans[k]='R'; dfs(k+1,l,r-1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(~scanf("%d",&n))
	{
		if(n<=20)
		{
			bj=0;
			for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
			dfs(1,1,2*n);
			if(!bj) printf("-1\n");
		}
		else
		{
			for(int i=1;i<=2*n;i++) printf("L");
			printf("\n");
		}
	}
	return 0;
}
