#include<bits/stdc++.h>
using namespace std;
const int maxn=1e6+5;
int n;
int a[maxn],b[maxn],c[maxn];
char s[maxn];
bool chk(int x,int l,int r)
{
	if(x>n*2)
	{
		for(int i=1;i<=n;i++)if(b[i]!=b[n*2-i+1])return 0;
		return 1;
	}
	s[x]='L';b[x]=a[l];
	if(chk(x+1,l+1,r))return 1;
	s[x]='R';b[x]=a[r];
	if(chk(x+1,l,r-1))return 1;
	return 0;
}
bool dfs(int x,int l,int r,int L,int R)
{
	if(x>n)return 1;
	if(L>=1&&a[l]==a[L]&&l!=L)
	{
		s[x]='L';s[n*2-x+1]='L';
		if(dfs(x+1,l+1,r,L-1,R))return 1;
	}
	if(R<=n*2&&a[l]==a[R]&&l!=R)
	{
		s[x]='L';s[n*2-x+1]='R';
		if(dfs(x+1,l+1,r,L,R+1))return 1;
	}
	if(L>=1&&a[r]==a[L]&&r!=L)
	{
		s[x]='R';s[n*2-x+1]='L';
		if(dfs(x+1,l,r-1,L-1,R))return 1;
	}
	if(R<=n*2&&a[r]==a[R]&&r!=R)
	{
		s[x]='R';s[n*2-x+1]='R';
		if(dfs(x+1,l,r-1,L,R+1))return 1;
	}
	return 0;
}
void print()
{
	for(int i=1;i<=n*2;i++)printf("%c",s[i]);
	printf("\n");
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int cas;
	scanf("%d",&cas);
	while(cas--)
	{
		scanf("%d",&n);
		for(int i=1;i<=n;i++)b[i]=0;
		for(int i=1;i<=n*2;i++)
		{
			scanf("%d",&a[i]);
			if(!b[a[i]])b[a[i]]=i;
			else c[b[a[i]]]=i,c[i]=b[a[i]];
		}
		if(n<=10)
		{
			if(chk(1,1,n*2))print();
			else printf("-1\n");
			continue;
		}
		s[1]=s[n*2]='L';if(dfs(2,2,n*2,c[1]-1,c[1]+1)){print();continue;}
		s[1]='R';s[n*2]='L';if(dfs(2,1,n*2-1,c[n*2]-1,c[n*2]+1)){print();continue;}
		printf("-1\n");
	}
	return 0;
}
