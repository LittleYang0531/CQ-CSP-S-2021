#include<bits/stdc++.h>
using namespace std;
int n,a[1000010],b[1000010];
char ans[1000010];
bool flag;
void dfs(int x)
{
	if(x==n)
	{
		int l=1,r=n;
		for(int i=1;i<=n;i++)
		{
			if(ans[i]=='L') b[i]=a[l++];
			else b[i]=a[r--];
		}
		for(int i=(n>>1)+1;i<=n;i++) if(b[i]!=b[n-i+1]) return;
		flag=1;
		return;
	}
	++x;
	ans[x]='L';dfs(x);
	if(flag) return;
	ans[x]='R';dfs(x);
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;
	scanf("%d",&T);
	while(T--)
	{
		scanf("%d",&n);
		n<<=1;
		for(int i=1;i<=n;i++) scanf("%d",&a[i]);
		flag=0;
		dfs(0);
		if(!flag) printf("-1\n");
		else
		{
			ans[n+1]=0;
			printf("%s\n",ans+1);
		}
	}
	return 0;
}
