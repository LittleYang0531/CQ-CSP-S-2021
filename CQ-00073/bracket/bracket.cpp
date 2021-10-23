#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
ll N,K,L,mod=1000000007;
ll dp[505][505],cnt[505][505][4];
char s[505];
bool check(ll L,ll R){return ((cnt[L][R][0]+cnt[L][R][3]<=K)&&(cnt[L][R][0]+cnt[L][R][3]==R-L+1));}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket,out","w",stdout);
	scanf("%lld%lld%s",&N,&K,s+1);
	L=strlen(s+1);
	for(ll i=1;i<=L;i++)
	{
		if(s[i]=='?') cnt[i][i][0]=1;
		if(s[i]=='(') cnt[i][i][1]=1;
		if(s[i]==')') cnt[i][i][2]=1;
		if(s[i]=='*') cnt[i][i][3]=1;
		for(ll j=i+1;j<=L;j++)
		{
			cnt[i][j][0]=cnt[i][j-1][0];
			cnt[i][j][1]=cnt[i][j-1][1];
			cnt[i][j][2]=cnt[i][j-1][2];
			cnt[i][j][3]=cnt[i][j-1][3];
			if(s[j]=='?') ++cnt[i][j][0];
			if(s[j]=='(') ++cnt[i][j][1];
			if(s[j]==')') ++cnt[i][j][2];
			if(s[j]=='*') ++cnt[i][j][3];
		}
	}
	for(ll i=1;i<L;i++)
		dp[i][i+1]=(s[i]!=')')&&(s[i+1]!='(')&&(s[i]!='*')&&(s[i+1]!='*');
	for(ll len=3;len<=L;len++)
	{
		for(ll l=1;l<=L-len+1;l++)
		{
			ll r=l+len-1;
			if(s[l]==')'||s[l]=='*'||s[r]=='('||s[r]=='*')
				continue;
			dp[l][r]=dp[l+1][r-1]%mod;
			if(check(l+1,r-1))
				++dp[l][r];
			for(ll i=l;i<r;i++)
				dp[l][r]=(dp[l][r]%mod+dp[l][i]*dp[i+1][r]%mod)%mod;
			for(ll i=l+1;i<r-1;i++)
			{
				if(!check(l+1,i)) break;
				dp[l][r]=(dp[l][r]%mod+dp[i+1][r-1]%mod)%mod;
			}
			for(ll i=r-1;i>l+1;i--)
			{
				if(!check(i,r-1)) break;
				dp[l][r]=(dp[l][r]%mod+dp[l+1][i-1]%mod)%mod;
			}
			for(ll i=l+1;i<r;i++)
			{
				for(ll j=i;j<r;j++)
				{
					if(!check(i,j)) break;
					dp[l][r]=(dp[l][r]%mod+dp[l][i-1]*dp[j+1][r]%mod)%mod;
				}
			}
		}
	}
	printf("%lld",dp[1][L]);
	ll a,b;
	while(cin>>a>>b) cout<<dp[a][b]<<endl;
}
