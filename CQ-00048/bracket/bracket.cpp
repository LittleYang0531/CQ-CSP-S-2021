#include<bits/stdc++.h>
using namespace std;
const long long mod=1e9+7;
long long dp[503][503],ans[503][503];
bool check[503][503];
char a[503];
int n,kk,nxt[503];
int main(){
	freopen("bracket.in","r",stdin);
     freopen("bracket.out","w",stdout);
    cin>>n>>kk;
    scanf("%s",a);
    bool flag=false;
    for(int i=n;i>=1;i--){
    	a[i]=a[i-1];
    	if(a[i]!='?')flag=true;
	}
    for(int i=1;i<=n;i++){
    	for(int j=i+1;j<=n;j++){
    		if((a[i]=='('||a[i]=='?')&&(a[j]==')'||a[j]=='?')){
    			bool flag=true;
				for(int k=i+1;k<j;k++)
				if(a[k]=='('||a[k]==')')flag=false;
				if(flag&&(j-1)-(i+1)+1<=kk)dp[i][j]=1ll;
			}
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=i;j<=n;j++){
			bool flag=true;
			for(int k=i;k<=j;k++)
			if(a[k]=='('||a[k]==')')flag=false;
			if(j-i+1>kk)flag=false;
			check[i][j]=flag;
		}
	}
	for(int Len=1;Len<=n;Len++){
		for(int j=Len;j<=n;j++){
			int i=j-Len+1;
			for(int k=i+1;k<j-1;k++)
			dp[i][j]+=dp[i][k]*dp[k+1][j]%mod,dp[i][j]%=mod;  
			for(int k=i+1;k<j-1;k++)
			 for(int l=k+2;l<j;l++){
			 	if(check[k+1][l-1]&&(l-1)-(k+1)+1<=kk){
			  	dp[i][j]+=dp[i][k]*dp[l][j]%mod,dp[i][j]%=mod;
			    }
			 } 
			if((a[i]=='('||a[i]=='?')&&(a[j]==')'||a[j]=='?')){
    			dp[i][j]+=dp[i+1][j-1];
    			dp[i][j]%=mod;
				bool flag=true;
				for(int k=j-1;k>i+2;k--){
					if(a[k]=='('||a[k]==')')flag=false;
					if(flag&&j-1-k+1<=kk)dp[i][j]+=dp[i+1][k-1],dp[i][j]%=mod;
				} 
				flag=true;
				for(int k=i+1;k<j-2;k++){
					if(a[k]=='('||a[k]==')')flag=false;
					if(flag&&k-(i+1)+1<=kk)dp[i][j]+=dp[k+1][j-1],dp[i][j]%=mod;
				}
			}
		}
    }
    cout<<dp[1][n]<<endl;
	return 0;
}
