#include <bits/stdc++.h>
using namespace std;

const int mod = 1000000007;
int n,a[500005],q[500005],cnt;
char ans[500005];
bool flag = false;

int dfs(int now,int l,int r)
{
//	printf("%d %d\n",l,r);
	if(now == 2 * n && q[now] == q[2 * n - now + 1])
	{
		for(int i = 1;i <= now;i++) printf("%c",ans[i]);
		printf("\n");
		return 1;
	}
	else if(now <= n)
	{
		ans[++cnt] = 'L';
		q[cnt] = a[l];
		if(dfs(now + 1,l + 1,r)) return 1;
		q[cnt] = a[r];
		ans[now] = 'R';
		if(dfs(now + 1,l,r - 1)) return 1;
		cnt--;
	}
	else
	{
		if(q[now] == q[2 * n - now + 1])
		{
			q[++cnt] = a[l];
			ans[cnt] = 'L';
			if(dfs(now + 1,l + 1,r)) return 1;
			q[cnt] = a[r];
			ans[cnt] = 'R';
			if(dfs(now + 1,l,r - 1)) return 1;
			cnt--;
		}
	}
	return 0;
}

int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		for(int i = 1;i <= 2 * n;i++)
		{
			scanf("%d",&a[i]);
		}
		deque<int> q;
		dfs(0,1,2 * n);
	}
	return 0;
}
