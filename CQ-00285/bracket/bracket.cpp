#include<bits/stdc++.h>
using namespace std;
long long dp[101][101][101];
int n,kk,ans,be;
char c;
int s[101],a[101],b[101],q[101];
bool ck()
{
	memset(q,0,sizeof(q));
	for(int i=1;i<=n;i++)
	{
		if(b[i]==1||b[i]==-1) q[i]+=b[i];
		if(b[i]==2&&b[i-1]==1&&b[i+1]==-1&&q[i]==0){
			return 0;
		}
		bool fp=0;
		for(int j=max(1,i-kk);j<=i;j++) if(b[i]!=2) {
			fp=1;break;
		}
		if(fp) return 0;
	}
	return 1;
}
void dfs(int k,int now)
{
	b[k]=now;
	if(k==n) {
		if(ck()) {ans++;}
		return;
	}
	if(!a[k+1]) {dfs(k+1,1);dfs(k+1,2);dfs(k+1,-1);}
	else dfs(k+1,a[k+1]);
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&kk);
	scanf("\n");
	for(int i=1;i<=n;i++) 
	{
		c=getchar();
		a[i]=(c=='('?1:c==')'?-1:c=='*'?2:0);
		s[i]=s[i-1]+a[i];
	}
	dfs(1,a[1]);
	printf("%lld",pow(3,n)%(1e9+7));
	return 0;
}

