#include<bits/stdc++.h>
using namespace std;
typedef long long LL;
#define MAXN 505
const int mo=1e9+7;
template<typename _T>
void read(_T &x){
	_T f=1;x=0;char s=getchar();
	while('0'>s||s>'9'){if(s=='-')f=-1;s=getchar();}
	while('0'<=s&&s<='9'){x=(x<<3)+(x<<1)+(s^48);s=getchar();}
	x*=f;
}
int add(int x,int y,int p){return x+y<p?x+y:x+y-p;}
void Add(int &x,int y,int p){x=add(x,y,p);}
int n,k,dp[MAXN][MAXN],g[MAXN][MAXN],f[MAXN][MAXN],h[MAXN][MAXN];
char str[MAXN];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	read(n);read(k);scanf("%s",str+1);
	for(int i=1;i<=n;i++)
		for(int j=i;j<min(i+k,n+1);j++)
			if(str[j]=='*'||str[j]=='?')g[i][j]=1;
			else break;
	for(int len=1;len<=n;len++)
		for(int l=1,r=len;r<=n;l++,r++){
			if(l!=r&&(str[l]=='('||str[l]=='?')&&(str[r]==')'||str[r]=='?')){
				if(l==r-1)Add(dp[l][r],1,mo);
				else{
					Add(dp[l][r],dp[l+1][r-1],mo);
					Add(dp[l][r],g[l+1][r-1],mo);
					for(int i=1;i<r-l-1;i++)
						Add(dp[l][r],g[l+1][l+i]*dp[l+i+1][r-1],mo),
						Add(dp[l][r],g[r-i][r-1]*dp[l+1][r-i-1],mo);
				}
			}
			h[l][r]=dp[l][r];
			//printf("included case:%d\n",dp[l][r]);
			for(int mid=l;mid<r;mid++){
				Add(dp[l][r],1ll*dp[l][mid]*h[mid+1][r]%mo,mo),
				Add(dp[l][r],1ll*f[l][mid]*h[mid+1][r]%mo,mo),
				Add(f[l][r],1ll*dp[l][mid]*g[mid+1][r]%mo,mo);
				//if(l==1&&r==n)printf("mid %d contribute %d to answer\n",mid,1ll*dp[l][mid]*dp[mid+1][r]);	
			}
			//if(l==1||r==n)printf("dp[%d][%d]:%d %d\n",l,r,dp[l][r],f[l][r]);
		}
	printf("%d\n",dp[1][n]);
	return 0;
}
/*
???(*??
()*(**)
(*)(**)
(**(*))
(()(*))
()((*))

(*)(*)*
()*(*)*
*/
