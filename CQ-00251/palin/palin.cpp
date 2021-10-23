#include<bits/stdc++.h>
using namespace std;
const int N=5e5+10;
int t,n,a[N<<1],b[N<<1];
bool can;
string ans;
bool check()
{
	for(int i=1;i<=n;i++) if(b[i]!=b[(n<<1)+1-i]) return false;
	return true;
}
void dfs(int l,int r,int now,string x)
{
	if(now>(n<<1))
	{
		if(check()) ans=x,can=true;
		return;
	}
	if(can) return;
	b[now]=a[l];
	dfs(l+1,r,now+1,x+"L");
	if(can) return;
	b[now]=a[r];
	dfs(l,r-1,now+1,x+"R");
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--)
	{
		scanf("%d",&n);
		ans="",can=false;
		for(int i=1;i<=(n<<1);i++) scanf("%d",a+i);
		dfs(1,(n<<1),1,"");
		if(!can) printf("-1\n");
		else cout<<ans<<'\n';
	}
	fclose(stdin);fclose(stdout);
	return 0;
}
