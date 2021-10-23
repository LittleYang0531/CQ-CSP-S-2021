#include <cstdio>
#include <cstring>
#include <algorithm>
using namespace std;
void read(int &x)
{
	x=0;char c=getchar();int f=1;
	while(!('0'<=c&&c<='9')){if(f=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
int len,Ans,K;
char S[10005];
bool dp[45][45],Can[45][45];
int Bra[105];
bool check()
{
	memset(Can,0,sizeof(Can)); memset(dp,0,sizeof(dp));
	for(int i=1;i<=len;i++) Bra[i]=Bra[i-1]+(S[i]=='('||S[i]==')');
	for(int l=1;l<=len;l++)
	{
		for(int r=l;r<=len;r++)
		{
			if(r-l+1>K) break;
			Can[l][r]=(Bra[r]-Bra[l-1]==0);
		}
	}
	for(int l=1;l<=len;l++)
	{
		for(int r=l+1;r<=len;r++)
		{
			if(r-l+1>K+2) break;
			if(r==l+1&&(S[l]=='('||S[l]=='?')&&(S[r]==')'||S[r]=='?')) dp[l][r]++;
			if(r>l+1&&(S[l]=='('||S[l]=='?')&&(S[r]==')'||S[r]=='?')&&Bra[r-1]-Bra[l]==0) dp[l][r]++;
		}
	}
	for(int Len=3;Len<=len;Len++)
	{
		for(int l=1;l+Len-1<=len;l++)
		{
			int r=l+Len-1;
			for(int k1=l;k1<=r;k1++)
			{
				dp[l][r]=(dp[l][r]+dp[l][k1]*dp[k1+1][r]);
				for(int k2=k1+1;k2<=r;k2++)
				{
					if(k2-(k1+1)+1==0) continue;
					if(k2-(k1+1)+1>K) break;
					dp[l][r]=(dp[l][r]+Can[k1+1][k2]*dp[l][k1]*dp[k2+1][r]);
				}
			}
			if((S[l]=='('||S[l]=='?')&&(S[r]==')'||S[r]=='?'))
			{
				dp[l][r]=(dp[l][r]+dp[l+1][r-1]);
				for(int k=l+1;k<=r-1;k++)
				{
					if(k-(l+1)+1==0) continue;
					if(k-(l+1)+1>K) break;
					dp[l][r]=(dp[l][r]+Can[l+1][k]*dp[k+1][r-1]);
				}
				for(int k=r-1;k>=l-1;k--)
				{
					if(r-1-(k+1)+1==0) continue;
					if((r-1)-(k+1)+1>K) break;
					dp[l][r]=(dp[l][r]+dp[l+1][k]*Can[k+1][r-1]);
				}
			}
		}
	}
	return dp[1][len];
} 
void dfs(int t)
{
	if(t==len+1)
	{
		Ans+=check();
		return;
	}
	if(S[t]=='?')
	{
		S[t]='*'; dfs(t+1);
		S[t]='('; dfs(t+1);
		S[t]=')'; dfs(t+1);
		S[t]='?';
	}
	else dfs(t+1);
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d %s",&len,&K,S+1);
	dfs(1);
	printf("%d",Ans);
	return 0;
}
/*
#include <cstdio>
#include <algorithm>
#define ll long long
using namespace std;
void read(int &x)
{
	x=0;char c=getchar();int f=1;
	while(!('0'<=c&&c<='9')){if(f=='-')f=-1;c=getchar();}
	while('0'<=c&&c<='9'){x=x*10+c-'0';c=getchar();}
	x*=f;
}
char S[505];
const int MOD=1e9+7;
ll dp[505][505],Can[505][505];
int Bra[505];
int main() {
//	freopen("bracket.in","r",stdin);
//	freopen("bracket.out","w",stdout);
	int n,K;scanf("%d %d %s",&n,&K,S+1);
	for(int i=1;i<=n;i++) Bra[i]=Bra[i-1]+(S[i]=='('||S[i]==')');
	for(int l=1;l<=n;l++)
	{
		for(int r=l;r<=n;r++)
		{
			if(r-l+1>K) break;
			Can[l][r]=(Bra[r]-Bra[l-1]==0);
		}
	}
	for(int l=1;l<=n;l++)
	{
		for(int r=l+1;r<=n;r++)
		{
			if(r-1-(l+1)+1>K) break;
			if(r==l+1&&(S[l]=='('||S[l]=='?')&&(S[r]==')'||S[r]=='?')) dp[l][r]++;
			if(r>l+1&&(S[l]=='('||S[l]=='?')&&(S[r]==')'||S[r]=='?')&&Bra[r-1]-Bra[l]==0) dp[l][r]++;
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++) printf("[%d,%d]:%lld ",i,j,dp[i][j]);
		puts(""); 
	}
	for(int len=3;len<=n;len++)
	{
		for(int l=1;l+len-1<=n;l++)
		{
			int r=l+len-1;
			for(int k1=l;k1<=r;k1++)
			{
				dp[l][r]=(dp[l][r]+dp[l][k1]*dp[k1+1][r]%MOD)%MOD;
				if(l==2&&r==9&&dp[l][k1]*dp[k1+1][r]>0) printf("%d:%lld*%lld\n",k1,dp[l][k1],dp[k1+1][r]);
				for(int k2=k1+1;k2<=r;k2++)
				{
					if(k2-(k1+1)+1==0) continue;
					if(k2-(k1+1)+1>K) break;
					dp[l][r]=(dp[l][r]+Can[k1+1][k2]*dp[l][k1]*dp[k2+1][r]%MOD)%MOD;
					if(l==2&&r==9&&Can[k1+1][k2]*dp[l][k1]*dp[k2+1][r]>0) printf("%d %d£º%lld\n",k1,k2,Can[k1+1][k2]*dp[l][k1]*dp[k2+1][r]);
				}
			}
			if((S[l]=='('||S[l]=='?')&&(S[r]==')'||S[r]=='?'))
			{
				dp[l][r]=(dp[l][r]+dp[l+1][r-1])%MOD;
				for(int k=l+1;k<=r-1;k++)
				{
					if(k-(l+1)+1==0) continue;
					if(k-(l+1)+1>K) break;
					dp[l][r]=(dp[l][r]+Can[l+1][k]*dp[k+1][r-1]%MOD)%MOD;
				}
				for(int k=r-1;k>=l-1;k--)
				{
					if(r-1-(k+1)+1==0) continue;
					if((r-1)-(k+1)+1>K) break;
					dp[l][r]=(dp[l][r]+dp[l+1][k]*Can[k+1][r-1]%MOD)%MOD;
				}
			}
		}
	}
	for(int i=1;i<=n;i++)
	{
		for(int j=i+1;j<=n;j++) printf("[%d,%d]:%lld ",i,j,dp[i][j]);
		puts(""); 
	}
	printf("%lld",dp[1][n]);
	return 0;
}

*/


