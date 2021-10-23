#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
const int NN=505;

int n,k;
string s;
long long ans;
int dfs(int m,int k)
{
	if(m<=1)
		return 0;
	if(m==2)
		return 1;
	if(m==3&&k>=1)
		return 1;
	for(int i=2;i<m;i++)
	{
		int n1=i;
		int n2=m-n1;
		int t1=(dfs(n1,k)*1ll)%mod;
		int t2=(dfs(n2,k)*1ll)%mod;
		if(t1==0||t2==0)
			continue;
		ans=(ans+t1+t2)%mod;
	}
}

int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracker.out","w",stdout);
	ios::sync_with_stdio(false);
	
	cin>>n>>k;//×î¶àk¸ö"*" 
	cin>>s;
	int t=s.size();
	dfs(t,k);
	cout<<ans%mod;	
	return 0;
}
