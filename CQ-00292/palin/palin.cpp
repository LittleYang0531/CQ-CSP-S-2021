#include<bits/stdc++.h>
using namespace std;
int T,n,a[21],p[21];
bool pg;
string ans,s;
void dfs(int x)
{
	if(x>2*n)
	{
		int l=1,r=2*n;
		for(int i=1;i<=2*n;++i)
		{
			if(s[i-1]=='L')
				p[i]=a[l++];
			else
				p[i]=a[r--];
		}
		for(int i=1;i<=n;++i)
			if(p[i]!=p[2*n-i+1])
				return;
		if(s<ans)
			ans=s;
		pg=1;
		return;
	}
	s[x-1]='L';
	dfs(x+1);
	s[x-1]='R';
	dfs(x+1);
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>>T;
	while(T--)
	{
		cin>>n;
		for(int i=1;i<=2*n;++i)
			cin>>a[i];
		ans.resize(2*n);
		s.resize(2*n);
		for(int i=0;i<2*n;++i)
			ans[i]='R';
		pg=0;
		dfs(1);
		if(pg)
			cout<<ans;
		else
			cout<<"-1";
		cout<<endl;
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
