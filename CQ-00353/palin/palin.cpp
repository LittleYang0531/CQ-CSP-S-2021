#include<bits/stdc++.h>
using namespace std;
int T,n,a[10005],b[10005],h,t,num[105][10005];
char ans[10005];
bool check()
{
	
	for(int i=1;i<=n;++i) if(num[T][i]!=num[T][(t|1)-i]) return 0;
//	puts("");
//	for(int i=1;i<=n*2;++i) cout<<num[T][i];
	return 1;
}
bool dfs(int cnt,int l,int r)
{
//	cout<<cnt<<" "<<h<<" "<<t<<endl;
	if(cnt == n*2)
	{
//		cout<<endl;
//		for(int i=1;i<=n*2;++i) cout<<ans[i];
//		cout<<endl;
//		for(int i=1;i<=n*2;++i) cout<<num[T][i]<<" ";
//		system("pause");
		return check();
	}
	ans[cnt+1]='L';
	num[T][cnt+1]=a[l];
	if(dfs(cnt+1,l+1,r))
	{
		h--;
		return 1;
	}
	ans[cnt+1]='R';
	num[T][cnt+1]=a[r];
	if(dfs(cnt+1,l,r-1))
	{
		++t;
		return 1;
	}
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	memset(num,0,sizeof(num));
	while(T--)
	{
		scanf("%d",&n);
		h=1,t=n<<1;
		for(register int i=1;i<=t;++i)
			scanf("%d",&a[i]);
		if(dfs(0,1,t))
		{
			for(int i=1;i<=n*2;++i) cout<<ans[i];
			puts("");
			continue;
		}
		if(dfs(0,1,t))
		{
			for(int i=1;i<=n*2;++i) cout<<ans[i];
			puts("");
		}
		else puts("-1");
	}
	return 0;
}

