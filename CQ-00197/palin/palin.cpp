#include<bits/stdc++.h>
using namespace std;
const int N=4e5+10;
int n,T;
int a[N];
int pos[N][2];
bool st[N];
string ans;
vector<int>res;
bool flag;
bool check()
{
	bool flag;
	vector<int> s2;
	for(int i=0;i<2*n;i++)
		s2.push_back(res[i]);
	reverse(res.begin(),res.end());
	flag = (s2==res);
	reverse(res.begin(),res.end());
	return flag;
}
bool dfs(int l,int r)
{
	if(l > r)
	{
		if(check())
			return true;
		return false;
	}
	string tmp=ans;
	if(l == r)
	{
		ans+='L',res.push_back(a[l]);
		if(dfs(l+1,r))
			return true;
		ans=tmp,res.pop_back();
	}
	else
	{
		ans+='L',res.push_back(a[l]);
		if(dfs(l+1,r))
			return true;
		ans=tmp,res.pop_back();
		ans+='R',res.push_back(a[r]);
		if(dfs(l,r-1))
			return true;
		ans=tmp,res.pop_back();
	}
	
	return false;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	
	cin>>T;
	while(T--)
	{
		scanf("%d",&n);
		res.clear();
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]);
		memset(pos,0,sizeof pos);
		ans="";
		dfs(1,2*n);
		if(!check()) cout<<-1<<endl;
		else cout<<ans<<endl;
	}
	//cout<<check("1221");
	return 0;
}
