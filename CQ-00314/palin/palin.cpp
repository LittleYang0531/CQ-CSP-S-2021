#include<bits/stdc++.h>
using namespace std;
const int MAXN=1000005;
int t,n,a[MAXN],now[MAXN];
bool inc[MAXN];
char tempans[MAXN];
bool dfs(int i,int l,int r)
{
	if(i==2*n+1)
	{
		for(int j=1;j<=2*n;j++)
			printf("%c",tempans[j]);
		printf("\n");
		return 1;
	}
	bool j=0;
	if((i<=n&&!inc[a[l]])||(i>n&&now[2*n+1-i]==a[l])) tempans[i]='L',now[i]=a[l],inc[a[l]]=1,j=dfs(i+1,l+1,r),inc[a[l]]=0,now[i]=0,tempans[i]='z';
	if(j) return 1;
	if((i<=n&&!inc[a[r]])||(i>n&&now[2*n+1-i]==a[r])) tempans[i]='R',now[i]=a[r],inc[a[r]]=1,j=dfs(i+1,l,r-1),inc[a[r]]=0,now[i]=0,tempans[i]='z';
	if(j) return 1;
	return 0;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		memset(inc,0,sizeof(inc));
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		bool j=dfs(1,1,2*n);
		if(!j) printf("-1\n");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

LRRLLRRRRL
-1


*/
