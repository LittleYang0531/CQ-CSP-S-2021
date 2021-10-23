#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int mod=1e9+7;
int f[505][505],g[505][505],vst[505][505],L[505],n,m;
char a[505];
bool Can(int p,char x){return a[p]==x||a[p]=='?';}
void dp(int l,int r){
	if(l>=r)return ;
	if(vst[l][r])return ;
	vst[l][r]=1,f[l][r]=g[l][r]=0;
	if(Can(l,'(')&&Can(r,')')){
		if(l+1==r)f[l][r]=(f[l][r]+1)%mod;
		if(l+1<r&&L[r-1]<=l+1)f[l][r]=(f[l][r]+1)%mod;
		if(l+1<r)dp(l+1,r-1),f[l][r]=(f[l][r]+f[l+1][r-1])%mod;
		//[l+1,i]都是*
		for(int i=l+1;i<r;i++)if(L[i]<=l+1)dp(i+1,r-1),f[l][r]=(f[l][r]+f[i+1][r-1])%mod;
		//[i,r-1]都是* 
		for(int i=l+1;i<r;i++)if(L[r-1]<=i)dp(l+1,i-1),f[l][r]=(f[l][r]+f[l+1][i-1])%mod;
	}
	g[l][r]=f[l][r];
	int sum=0;
	for(int i=l+1,j=l+1;i<=r;i++){//第二个串是[i,r],i-1能延伸到j 
		dp(l,i-1),sum=(sum+f[l][i-1])%mod;
		while(L[i-1]>j)sum=(sum-f[l][j-1]+mod)%mod,j++;
		dp(i,r),f[l][r]=(f[l][r]+1ll*sum*g[i][r])%mod;
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>m>>a+1;
	for(int i=1;i<=n;i++){
		int p;
		for(p=i;p>=1;p--)if(!Can(p,'*'))break;
		L[i]=max(p+1,i-m+1);//i填*，作为右端点，最左能到哪里 
	}
	dp(1,n),cout<<f[1][n];
	return 0;
}
