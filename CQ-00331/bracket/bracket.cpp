#include<bits/stdc++.h>
using namespace std;
const int MOD=1e9+7;
char a[505];
int dp[505][505];
int n,m;
inline bool p(int x,char h){return a[x]==h||a[x]=='?';}
int dfs(int i,int j){
	if(i>=j)return 0;
	if(i+1==j)return p(i,'(')&&p(j,')');
	if(dp[i][j]!=-1)return dp[i][j];
	if(a[i]=='*'||a[j]=='*'||a[i]==')'||a[j]=='(')return 0;
	int val=0;
	//1.(***(.))
	for(int k=i+1;k<=j-1&&k<=i+m;++k){
		if(p(k,'*'))val+=dfs(k+1,j-1),val%=MOD;
		else break;
	}
	//2.((.)***)
	for(int k=j-1;k>=i+1&&k>=j-m;--k){
		if(p(k,'*'))val+=dfs(i+1,k-1),val%=MOD;
		else break;
	}
	//3.((.))
	val+=dfs(i+1,j-1),val%=MOD;
	//4.(.)**(.)
	vector<int>sum(j-i+2);
	for(int k=j-1;k>i&&k>=j-m-1;--k){
		sum[k-i]=sum[k+1-i]+dfs(k,j),sum[k-i]%=MOD;
	}
	for(int k=i+2;k<=j-1;++k){
		val+=(sum[k-i]-sum[min(k+m,j)-i])*1ll*dfs(i,k-1)%MOD,val%=MOD;
	}
	val+=(j-i==3&&p(i,'(')&&p(i+1,')')&&p(i+2,'(')&&p(i+3,')'));
	bool fl=1;
	for(int k=i+1;k<j;++k)fl&=p(k,'*');
	return dp[i][j]=val+((j-i-1<=m&&fl));
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d\n%s",&n,&m,a+1);
	memset(dp,-1,sizeof dp);
	printf("%d\n",dfs(1,n));
//	for(int i=1;i<=n;++i){
//		for(int j=1;j<=n;++j){
//			if(dp[i][j]==-1)cout<<"K ";
//			else cout<<dp[i][j]<<" ";
//		}
//		cout<<endl;
//	}
	return 0;
}//About ZMQ,He has dead.
