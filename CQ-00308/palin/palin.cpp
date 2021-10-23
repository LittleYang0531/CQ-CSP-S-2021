#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=5*1e5+10;

int n,t,q=0;
int a[N],b[N],cnt[N];
int res=0;
void dfs(int l,int r)
{
	if(l>r||q>n)
	return ;
	q++;
//	cout<<q<<endl;
	b[q]=a[l];
//	cout<<b[q]<<" ";
	dfs(l+1,r);
	l++;
	b[q]=a[r];
//	cout<<b[q]<<" ";
	dfs(l-1,r+1);
	r++;
	if(q>=2*n)
	{
		bool o=0;
		for(int i=1;i<=n;i++)
		{
			if(b[i]!=b[2*n-i])
				o=1;
		}
		if(!o)
		res++;
	}	
}
int main()
{
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--)
	{
		int p=0;
		cin>>n;
		memset(b,0,sizeof b);
		memset(a,0,sizeof a);
		memset(cnt,0,sizeof cnt);
		for(int i=1;i<=2*n;i++)
		cin>>a[i];
		if(a[1]==a[2*n])
		{
			cout<<-1<<endl;
			return 0;
		}	
		int l=1,r=2*n;
		res=0;
		dfs(l,r);
		for(int i=1;i<=2*n;i++)
		{
			cout<<(b[i]==a[i]?'l':'R');
		}
		cout<<endl;
	}
	return 0;
}
