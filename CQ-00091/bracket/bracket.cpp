#include<cstdio>
#include<queue>
#include<iostream>
#include<algorithm>
#include<cstring>
#include<map>
#include<set>
#include<cmath>
#include<vector>
using namespace std;
int read(){
	int x=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(isdigit(ch)){
		x=x*10+(ch-48);
		ch=getchar();
	}
	return x*f;
}
void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x)write(x/10);
	putchar(x%10+48);
}
const int mod=1e9+7;
int n,N,tot,K,ans,dp[105][2][105][1005][2][2];
char s[505]; 
bool vis[505];
int add(int x,int y){
	return (x+y)%mod;
}
int f(int x){
	return x+500;
}
signed main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
//((**()*(*))*)(***)
	//691135332
	//782278985
	n=read(),K=read();
	scanf("%s",s+1);
	dp[0][0][0][f(0)][0][0]=1;
	if(s[1]==')'||s[1]=='*'){
		puts("0");
		return 0;
	}
	if(s[n]=='('||s[n]=='*'){
		puts("0");
		return 0;
	} 
	for(int i=0;i<n;i++){
		for(int j=0;j<=1;j++){
			for(int k=0;k<=n;k++){
				for(int Sum=-n;Sum<=n;Sum++){
					for(int op=0;op<=1;op++)
						for(int X=0;X<=1;X++){
							if(dp[i][j][k][f(Sum)][op][X]){
								int res=dp[i][j][k][f(Sum)][op][X]; 
								if(s[i+1]=='?'){
									if(i==0){
										int sta=op;
										dp[i+1][0][k+1][f(Sum+1)][sta][X]=add(dp[i+1][0][k+1][f(Sum+1)][sta][X],res);
										continue;
									}
									if(i==n-1){
										int sta=op|(Sum-1<0);
										if(k>=1)dp[i+1][0][k-1][f(Sum-1)][sta][X]=add(dp[i+1][0][k-1][f(Sum-1)][sta][X],res);
										continue;
									}
									int sta=op;
									dp[i+1][0][k+1][f(Sum+1)][sta][X]=add(dp[i+1][0][k+1][f(Sum+1)][sta][X],res);
									if(k>=1){
										sta=op|(Sum-1<0);
										dp[i+1][0][k-1][f(Sum-1)][sta][X]=add(dp[i+1][0][k-1][f(Sum-1)][sta][X],res);
									}
									bool F=1;
									if(j==1)F=0;
									if(X==1&&op==0&&Sum==0)F=0;
									
									if(F){
										for(int l=i+1;l<=n;l++){
											if(s[l]=='('||s[l]==')'||l-i>K)break;
											dp[l][1][k][f(0)][0][X|1]=add(dp[l][1][k][f(0)][0][X|1],res);
										}
									}
									
									if(X==1&&op==0&&Sum==0&&j==0){
										for(int l=i+1;l<n;l++){
											if(s[l]=='('||s[l]==')'||l-i>K)break;
											if(l+1==n)continue;
											if(s[l+1]=='('||s[l+1]=='?')
											dp[l+1][0][k+1][f(1)][0][X|1]=add(dp[l+1][0][k+1][f(1)][0][X|1],res);
										}
									}
									
								}else if(s[i+1]=='('){
									int sta=op;
									dp[i+1][0][k+1][f(Sum+1)][sta][X]=add(dp[i+1][0][k+1][f(Sum+1)][sta][X],res);
								}else if(s[i+1]==')'){
									int sta=op|(Sum-1<0);
									if(k>=1)dp[i+1][0][k-1][f(Sum-1)][sta][X]=add(dp[i+1][0][k-1][f(Sum-1)][sta][X],res);
								}else if(s[i+1]=='*'){
									bool F=1;
									if(j==1)F=0;
									if(X==1&&op==0&&Sum==0)F=0;
									if(F){
										int r=i+1;
										while(r+1<=n&&s[r+1]=='*')r++;
										if(r-i>K){
											puts("0");
											return 0;
										}
										dp[r][1][k][f(0)][0][X|1]=add(dp[r][1][k][f(0)][0][X|1],res);
										for(int l=r+1;l<=n;l++){
											if(s[l]=='('||s[l]==')'||l-i>K)break;
											dp[l][1][k][f(0)][0][X|1]=add(dp[l][1][k][f(0)][0][X|1],res);
										}
									}
									
									if(X==1&&op==0&&Sum==0&&j==0){
										int r=i+1;
										while(r+1<=n&&s[r+1]=='*')r++;
										if(r-i>K){
											puts("0");
											return 0;
										}
										for(int l=r;l<n;l++){
											if(s[l]=='('||s[l]==')'||l-i>K)break;
											if(l+1==n)continue;
											if(s[l+1]=='('||s[l+1]=='?')
											dp[l+1][0][k+1][f(1)][0][X|1]=add(dp[l+1][0][k+1][f(1)][0][X|1],res);
										}	
									}
									
								}
							}		
						}
				}
			}
		}
	}
	/*
	for(int i=1;i<=n;i++){
		for(int j=0;j<=i;j++){
			for(int k=0;k<=n;k++){
				cout<<i<<" "<<j<<" "<<k<<" "<<dp[i][j][k]<<endl; 
			}
		}
	}
	*/
	for(int i=-n;i<=n;i++)ans=(ans+dp[n][0][0][f(i)][0][0])%mod,ans=(ans+dp[n][0][0][f(i)][0][1])%mod,ans=(ans+dp[n][0][0][f(i)][1][0])%mod,ans=(ans+dp[n][0][0][f(i)][1][1])%mod;
	printf("%d",ans); 
	return 0;	
}
/*
7 3
(*??*??
定义dp[i][j][k] 表示前i位字符前一位*在j和为k 
一个S的左右两边必须得有括号围着 
*/

