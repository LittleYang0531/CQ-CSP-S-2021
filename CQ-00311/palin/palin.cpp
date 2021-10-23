#include<bits/stdc++.h>
using namespace std;
int T,a[1000001],cnt[500001],n,n2;
bool have;
string ans,ans2;
int find(int pos,int x)
{
	for (int i=1;i<=n2;i++)
		if (a[i]==x&&i!=pos)
			return i;
}
void dfs(int nowl,int nowr,int l,int r,int x)
{
	if (l==x-1&&r==x+n)
	{
		have=1;
		return;
	}
	if (l>=x&&nowl<=x-1&&a[nowl]==a[l])
	{
		string ansc=ans,ans2c=ans2;
		ans+='L';
		ans2='L'+ans2;
		dfs(nowl+1,nowr,l-1,r,x);
		if (have)return;
		else
		{
			ans=ansc;
			ans2=ans2c;
		}
	}
	if (r<=x+n-1&&nowl<=x-1&&a[nowl]==a[r])
	{
		string ansc=ans,ans2c=ans2;
		ans+='L';
		ans2='R'+ans2;
		dfs(nowl+1,nowr,l,r+1,x);
		if (have)return;
		else
		{
			ans=ansc;
			ans2=ans2c;
		}
	}
	if (l>=x&&nowr>=x+n&&a[nowr]==a[l])
	{
		string ansc=ans,ans2c=ans2;
		ans+='R';
		ans2='L'+ans2;
		dfs(nowl,nowr-1,l-1,r,x);
		if (have)return;
		else
		{
			ans=ansc;
			ans2=ans2c;
		}
	}
	if (r<=x+n-1&&nowr>=x+n&&a[nowr]==a[r])
	{
		string ansc=ans,ans2c=ans2;
		ans+='R';
		ans2='R'+ans2;
		dfs(nowl,nowr-1,l,r+1,x);
		if (have)return;
		else
		{
			ans=ansc;
			ans2=ans2c;
		}
	}
	return;
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while (T--)
	{
		have=0;
		scanf("%d",&n);
		n2=n<<1;
		memset(cnt,0,n2+2<<1);
		for (int i=1;i<=n2;i++)scanf("%d",&a[i]);
		for (int i=n+1;i<=n2;i++)cnt[a[i]]++;
		set<int>s;
		vector<int>v;
		for (int i=1;i<=n;i++)
			if (cnt[i]!=1)
				s.insert(i);
		if (s.empty())v.push_back(n+1);
		for (int i=n;i;i--)
		{
			cnt[a[i+n]]--;
			if (cnt[a[i+n]]==1)s.erase(s.find(a[i+n]));
			else if (!cnt[a[i+n]])s.insert(a[i+n]);
			cnt[a[i]]++;
			if (cnt[a[i]]==1)s.erase(s.find(a[i]));
			else if (cnt[a[i]]==2)s.insert(a[i]);
			if (s.empty())v.push_back(i);
		}
		if (v.empty())
		{
			printf("-1\n");
			continue;
		}
		int sz=v.size();
		for (int i=0;i<sz;i++)
		{
			ans="";
			ans2="";
			int x=v[i],l,r;
			if (x!=1)
			{
				l=find(1,a[1]);
				r=l;
				ans="L";
				ans2="L";
				l--;
				r++;
				dfs(2,n2,l,r,x);
			}
			if (!have&&x!=n+1)
			{
				l=find(n2,a[n2]);
				r=l;
				ans="R";
				ans2="L";
				l--;
				r++;
				dfs(1,n2-1,l,r,x);
			}
			if (have)
			{
				cout<<ans<<ans2<<'\n';
				break;
			}
		}
		if (!have)printf("-1\n");
	}
}
//CCF Au coach sto sto ZZS orz orz
