#include<bits/stdc++.h>
using namespace std;
const int M=500+5,mod=1e9+7;
int n,k,sum[M];
char s[M];
long long dp[M][M][3];
long long solve(int l,int r,int o){
	if(l==r){
		if(s[l]!='?'){
			if(s[l]==')'&&o==1) return dp[l][r][o]=1;
			if(s[l]=='('&&o==0) return dp[l][r][o]=1;
			if(o==2&&s[l]=='*') return dp[l][r][o]=1;
			return dp[l][r][o]=0;
		}
		else{
			return dp[l][r][o]=1;
		}
	}
	if(o==2&&l>r) return 1;
	if(l>r)return 0;
	if(dp[l][r][o]) return dp[l][r][o];
	long long res=0;
	
	for(int i=l;i<=r;i++){
		if(o==2){
			if(s[i]=='?'){
				res+=solve(l,i-1,0)*solve(i+1,r,2)%mod;
				res%=mod;
				res+=solve(l,i-1,2)*solve(i+1,r,1)%mod;
				res%=mod;
			//	res+=solve(l,i-1,2)*solve(i+1,r,2);
			}
			else if(s[i]==')'){
				res+=solve(l,i-1,0)*solve(i+1,r,2)%mod;
				res%=mod;
			}
			else if(s[i]=='('){
				res+=solve(l,i-1,2)*solve(i+1,r,1)%mod;
				res%=mod;
			}
			else{
			//	res+=solve(l,i-1,2)*solve(i+1,r,2);
			}
		}
		else{
			if(o==0){
				if(s[i]=='?'||s[i]=='(')
				res+=solve(l,i-1,2)*solve(i+1,r,2)%mod;
				res%=mod;
			}
			else{
				if(s[i]=='?'||s[i]==')')
				res+=solve(l,i-1,2)*solve(i+1,r,2)%mod;
				res%=mod;
			}
		}
	}
//	res/=2ll;	
	if(r-l+1<=k&&o==2&&sum[r]-sum[l-1]==0) res++;
	return dp[l][r][o]=res;
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1];
		if(s[i]!='*'&&s[i]!='?'){
			sum[i]++;
		}
	}
	printf("%lld",solve(2,n-1,2));
	return 0;
}
