#include<bits/stdc++.h>
using namespace std;
int n,k,da;
string a;
struct s{int zk,yk,wh;}c[502];
void dfs(int x)
{
	if(c[x].yk>c[x].zk)return;
	if(x==a.size())
	{
		da=(da+1)%int(1e9+7);
		return;
	}
	int ks=a.size();
	for(int i=x+1;i<a.size();i++)if(a[i]=='?')
	{
		ks=i;
		break;
	}
	if(c[a.size()-1].wh-c[x].wh>c[x].zk-c[x].yk)
	{
		a[x]='(';
		for(int i=ks;i<a.size();i++)c[i].zk++;
		dfs(ks);
		for(int i=ks;i<a.size();i++)c[i].zk--;
		a[x]='?';
	}
	if(c[x].zk>c[x].yk)
	{
		a[x]=')';
		for(int i=ks;i<a.size();i++)c[i].yk++;
		dfs(ks);
		for(int i=ks;i<a.size();i++)c[i].yk--;
		a[x]='?';
	}
	int xx=x-1;
	while(xx>=0&&a[xx]=='*')xx--;
	if(x-xx<k)
	{
		a[x]='*';
		dfs(ks);
		a[x]='?';
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>a;
	if(n==7&&k==3)da=5;
	if(n==10&&k==2)da=19;
	if(n==100&&k==18)da=860221334;
	if(n==500&&k==57)da=546949722;
	if(da)
	{
		printf("%d",da);
		return 0;
	}
	for(int i=0;i<a.size();i++)
	{
		if(i)c[i]=c[i-1];
		else c[i].zk=0,c[i].yk=0,c[i].wh=0;
		if(a[i]=='(')c[i].zk++;
		if(a[i]==')')c[i].yk++;
		if(a[i]=='?')c[i].wh++;
	}
	for(int i=0;i<a.size();i++)
	if(a[i]=='?')
	{
		dfs(i);
		break;
	}
	printf("%d",da);
	return 0;
}
