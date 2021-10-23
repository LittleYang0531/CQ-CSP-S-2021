#include<bits/stdc++.h>
using namespace std;
int n,k;
const int max_n=500+5;
char S[max_n];
int Right[max_n];
const int mod=1e9+7;
inline void add(int &a,int b)
{
	a=a+b-(a+b>=mod?mod:0);
}
inline void sub(int &a,int b)
{
	a=a-b+(a<b?mod:0);
}
int dp[max_n][max_n][2],sl[max_n][max_n];
inline bool check(int pos,char x)
{
	return S[pos]==x||S[pos]=='?';
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
//	freopen("bracket1.txt","w",stderr);
	scanf("%d%d%s",&n,&k,S+1);
//	fprintf(stderr,"S=%s\n",S+1);
	for(int i=n;i>=1;--i)
	{
		if(check(i,'*'))
			Right[i]=Right[i+1]+1;
		else
			Right[i]=0;
//		fprintf(stderr,"i=%d Right[i]=%d\n",i,Right[i]);
	}
//	int x=-1,y=-1;
	for(int l=2;l<=n;++l)
		for(int i=1;i+l-1<=n;++i)
		{
			int j=i+l-1;
			if(check(i,'(')&&check(j,')')&&l-2<=k&&Right[i+1]>=l-2)
				dp[i][j][0]=1;
//			if(i==x&&j==y)
//				fprintf(stderr,"1 dp[i][j]=%d\n",dp[i][j]);
			for(int t=i;t+1<=j;++t)
			{
				dp[i][j][1]=(dp[i][j][1]+1ll*(dp[i][t][0]+dp[i][t][1])*dp[t+1][j][0])%mod;
//				if(i==x&&j==y)
//					fprintf(stderr,"t=%d dp[i][j]=%d\n",t,dp[i][j]);
			}
//			if(i==x&&j==y)
//				fprintf(stderr,"2 dp[i][j]=%d\n",dp[i][j]);
			for(int t=i;t+2<=j;++t)
			{
				int len=min(min(Right[t+1],j-1-t),k);
				dp[i][j][1]=(dp[i][j][1]+(dp[i][t][0]+dp[i][t][1])*(1ll*sl[(t+1)+1][j]-sl[(t+1)+len+1][j]+mod))%mod;
//				if(i==x&&j==y)
//					fprintf(stderr,"t=%d dp[i][j]=%d\n",t,dp[i][j]);
			}
//			if(i==x&&j==y)
//				fprintf(stderr,"3 dp[i][j]=%d\n",dp[i][j]);
			if(check(i,'(')&&check(j,')'))
			{
				if(l>2)
				{
					add(dp[i][j][0],dp[i+1][j-1][0]);
					add(dp[i][j][0],dp[i+1][j-1][1]);
				}
				for(int t=i+1;t+1<=j-1&&t-i<=k;++t)
				{
					if(!check(t,'*'))
						break;
					add(dp[i][j][0],dp[t+1][j-1][0]);
					add(dp[i][j][0],dp[t+1][j-1][1]);
				}
				for(int t=j-1;i+1<=t-1&&j-t<=k;--t)
				{
					if(!check(t,'*'))
						break;
					add(dp[i][j][0],dp[i+1][t-1][0]);
					add(dp[i][j][0],dp[i+1][t-1][1]);
				}
			}
//			if(i==x&&j==y)
//				fprintf(stderr,"4 dp[i][j]=%d\n",dp[i][j]);
			sl[i][j]=sl[i+1][j];
			add(sl[i][j],dp[i][j][0]);
//			fprintf(stderr,"i=%d j=%d dp[i][j]=%d\n",i,j,dp[i][j]);
		}
//	fprintf(stderr,"S=%s\n",S+1);
	printf("%d\n",(dp[1][n][0]+dp[1][n][1])%mod);
	return 0;
}

