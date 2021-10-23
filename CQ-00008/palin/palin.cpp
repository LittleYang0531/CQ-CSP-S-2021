#include<cstdio>
using namespace std;
int t,n,a[25],b[25],c[25];
bool flag;
void dfs(int x,int l,int r)
{
	if(flag) return;
	if(x==2*n+1)
	{
		for(int i=1;i<=2*n;i++)
			if(b[i]!=b[2*n-i+1]) return;
		flag=1;
		for(int i=1;i<=2*n;i++)
		{
			if(!c[i]) printf("L");
			else printf("R");
		}
		return;
	}
	c[x]=0;
	b[x]=a[l];
	dfs(x+1,l+1,r);
	c[x]=1;
	b[x]=a[r];
	dfs(x+1,l,r-1);
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++)
	{
		flag=0;
		scanf("%d",&n);
		for(int j=1;j<=2*n;j++) scanf("%d",&a[j]);
		dfs(1,1,2*n);
		if(flag) printf("\n");
		else printf("-1\n");
	}

	return 0;
}

