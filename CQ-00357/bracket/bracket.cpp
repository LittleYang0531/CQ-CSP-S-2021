#include<bits/stdc++.h>
#define N 505
#define mod 1000000007
using namespace std;
int n,K,f[N][N],g[N],ans,fl[N][N];
char str[N];
inline void A(int&x,int y){x=(x+y)>=mod?x+y-mod:x+y;}
inline int F(int l,int r){//合法序列，但不一定是一整块 
	if(l==r+1)return 1;
	if(r==l)return 0;
	if(fl[l][r])return g[r-l+1];
	if(!((str[l]=='('||str[l]=='?')&&(str[r]==')'||str[r]=='?')))return 0;
	if(~f[l][r])return f[l][r];
	int i,j,res=0,sum=0,sum2=0,cnt;
	for(i=l+1;i<=r;++i)if((str[i]==')'||str[i]=='?')){
		sum=0;
		for(cnt=0,j=l+1;j<i;++j){if((!(str[j]=='*'||str[j]=='?'))||(++cnt>K))break;A(sum,F(j+1,i-1));}
		for(cnt=0,j=i-1;j>l+1;--j){if((!(str[j]=='*'||str[j]=='?'))||(++cnt>K))break;A(sum,F(l+1,j-1));}
		A(sum,F(l+1,i-1));
		if(i==r)A(res,sum);
		else{
			sum2=0;
			for(cnt=0,j=i+1;j<r;++j){if((!(str[j]=='*'||str[j]=='?'))||(++cnt>K))break;A(sum2,F(j+1,r));}
			A(sum2,F(i+1,r));
			res=(res+1ll*sum*sum2)%mod;
		}
	}
	return f[l][r]=res;
}
int main(void){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int i,j,k,res;scanf("%d%d%s",&n,&K,str+1);
	for(i=1;i<=n;++i)for(fl[i][i]=(str[i]=='?'),j=i+1;j<=n;++j)fl[i][j]=(fl[i][j-1]&&(str[j]=='?'));
	g[0]=1;
	for(i=2;i<=n;++i){//全?
		for(j=2;j<=i;++j)//前缀最长匹配串长度 
		{
			for(res=k=0;k<=min(j-2,K);++k)res=(res+((k==j-2||!k)?1ll:2ll)*g[j-2-k])%mod;
			if(j==i)g[i]=(g[i]+res)%mod;
			else {for(k=0;k<=min(i-j-1,K);++k)g[i]=(g[i]+1ll*g[i-j-k]*res)%mod;}
		}
	}
	if(fl[1][n])return printf("%d\n",g[n]),0;
	memset(f,-1,sizeof f);
	printf("%d\n",F(1,n));
	return 0;
}



