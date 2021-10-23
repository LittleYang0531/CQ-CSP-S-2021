#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505,mod=1e9+7;
struct node{
	int l,r,s;
};
string s;
int n,p,k;
int a[N];
int cnt[N];
int dfn[N];
int dfk[N];
int aa[N];
ll res;
bool cheak()
{
	for(int i=1;i<=n;i++)
		if(dfn[i]>k)
			return 1;
	return 0;
}
int bfs(int u)
{
	for(int i=u;i<=p+1;i++)
	{
		for(int j=1;j<=3;j++)
		{
			if(j==1)
			{
				a[cnt[i]]=1;
				bfs(i+1);
				a[cnt[i]]=0;
			}
			else if(j==2)
			{
				a[cnt[i]]=-1;
				bfs(i+1);
				a[cnt[i]]=0;
			}
			else if(j==3)
			{
				a[cnt[i]]=0;
				dfn[cnt[i]]=1;
				bfs(i+1);
				dfn[cnt[i]]=0;
			}
		}
	}
	if(u==p+1)
	{
		for(int i=1;i<=n;i++)
		{
			dfk[i]=dfn[i];
			aa[i]=a[i];
		//	cout<<dfn[i]<<" ";
		}
		//cout<<endl;
		//for(int i=1;i<=n;i++)
		//cout<<a[i]<<" ";
		//cout<<endl;
		bool o;
		for(int i=1;i<=n;i++)
		{
			dfk[i]=dfn[i];
			aa[i]=a[i];
		}
		for(int i=1;i<=n;i++)
		if(dfk[i]!=0)
			dfk[i]+=dfk[i-1];
		for(int i=1;i<=n;i++)
		if(dfk[i]>k)
			o=1;
		for(int i=1;i<=n;i++)
		aa[i]+=aa[i-1];
		if(aa[n]==0&&!o)
			res++;
		res%=mod;
	}
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	for(int i=1;i<=n;i++)
		cin>>s[i];
	for(int i=1;i<=n;i++)	
	{
		if(s[i]=='(')
		{
			a[i]=1;
		}
		if(s[i]==')')
		{
			a[i]=-1;
		}
		if(s[i]=='?')
		{
			a[i]=0;
			p++;
			cnt[p]=i;
		}
		if(s[i]=='*')
			dfn[i]=1;
	}
	cout<<bfs(1)<<endl;
	return 0;
}
