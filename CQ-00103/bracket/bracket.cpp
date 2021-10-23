#include<bits/stdc++.h>
using namespace std;
const int N=510,mod=1e9+7;
int n,k;
string a;
int ans;
int f[N][N];
bool check(string s)
{
	memset(f,false,sizeof f);
	int l,r;
	for(int i=0;i<s.size();i++)
	{
		if(s[i]=='(') l=i;
		else if(s[i]==')')
		{
			r=i;
			break;
		}
	}
	if(r-l+1>k)
		return false;
	f[l][r]=true;
	
	return true;
}
void dfs(int u)
{
	if(u==a.size())
	{
		if(check(a))
			ans=(ans+1)%mod;
		return;
	}
	int t=u+1;
	while(t<a.size()&&a[t]!='?')
		t++;
	a[u]='(' , dfs(t);
	a[u]=')' , dfs(t);
	a[u]='*' , dfs(t);
	a[u]='?';
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>a;
	int t=0;
	while(t<a.size()&&a[t]!='?')
		t++;
	if(t==a.size());
	{
		if(check(a)) cout<<"1";
		else cout<<"0";
		return 0;
	}
	dfs(t);
	printf("%d",ans);
	return 0;
}
