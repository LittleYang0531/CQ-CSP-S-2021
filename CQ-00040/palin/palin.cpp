#include<bits/stdc++.h>
using namespace std;
const int N=1e6+5;
int n,a[N],b[N];
char s[N];
bool dfs(int k,int l,int r)
{
	if(r<l)
	{
		for(int i=1;i<=n;i++)
			if(b[i]!=b[(n<<1)-i+1])
				return 0;
		return 1;
	}
	s[k]='L';
	b[k]=a[l];
	if(dfs(k+1,l+1,r))
		return 1;
	s[k]='R';
	b[k]=a[r];
	if(dfs(k+1,l,r-1))
		return 1;
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
		for(int i=1;i<=(n<<1);i++)
			scanf("%d",&a[i]);
		if(dfs(1,1,n<<1))
			for(int i=1;i<=(n<<1);i++)
				printf("%c",s[i]);
		else
			printf("-1");
		printf("\n");
	}
}
