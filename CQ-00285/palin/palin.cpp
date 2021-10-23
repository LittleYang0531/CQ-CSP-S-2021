#include<bits/stdc++.h>
using namespace std;
int t,n,dn;
bool fl;
int a[1001],loc[1001],op[1001];
void dfs(int l,int r,int cnt)
{
	if(l==r) {
		op[cnt]=1;
		fl=1;return;
	}
	if(!loc[a[l]]) {
		loc[a[l]]=cnt;
		op[cnt]=1;
		dfs(l+1,r,cnt+1);
		loc[a[l]]=0;
	}
	else{
		if(loc[a[l]]+cnt-1==dn) {
			op[cnt]=1;
			dfs(l+1,r,cnt+1);
		}
		else return;
	}
	if(fl) return;
	if(!loc[a[r]]){
		loc[a[r]]=cnt;
		op[cnt]=2;
		dfs(l,r-1,cnt+1);
		loc[a[r]]=0;
	}
	else{
		if(loc[a[r]]+cnt-1==dn){
			op[cnt]=2;
			dfs(l,r-1,cnt+1);
		}
		else return;
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		fl=0;memset(loc,0,sizeof(loc));
		dn=n<<1;
		for(int i=1;i<=dn;i++) scanf("%d",&a[i]);
		dfs(1,dn,1);
		if(fl) {for(int i=1;i<=dn;i++) op[i]==1?printf("L"):printf("R");puts("");}
		else puts("-1");
	}
	return 0;
}

