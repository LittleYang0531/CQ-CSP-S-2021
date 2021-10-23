#include <bits/stdc++.h>
#define int long long
using namespace std;
const int N=5e2+10,MOD=1e9+7;
inline int read()
{
	int s=0,w=1;
	char ch=getchar();
	while(ch<'0'||ch>'9') { if(ch=='-') w*=-1; ch=getchar(); }
	while(ch>='0'&&ch<='9') s=s*10+ch-'0',ch=getchar();
	return s*w;	
}
int n,k;
int dp[N][N];
char arr[N];
inline bool check(int l,int r){
	if(arr[l]=='('&&arr[r]==')') return true;
	if(arr[l]=='('&&arr[r]=='?') return true;
	if(arr[l]=='?'&&arr[r]==')') return true;
	if(arr[l]=='?'&&arr[r]=='?') return true;
	return false;
}
signed main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	cin>>arr+1;
	for(register int len=2;len<=n;len++){ //枚举区间长度 
		for(register int l=1;l<=n-len+1;l++){ //枚举左端点 
			int r=l+len-1; //右端点
			if(check(l,r)){ //端点可以为()
				dp[l][r]=(dp[l][r]+dp[l+1][r-1])%MOD;
				if(arr[r-1]!='*'){ //只有一边允许有 * 
					for(register int t=l+1;t<r-2;t++){
						if(t-l>k) break; //不合法 
						if(arr[t]=='('||arr[t]==')') break; //不连续 
						dp[l][r]=(dp[l][r]+dp[t+1][r-1])%MOD;
					}
				}
				if(arr[l+1]!='*'){
					for(register int t=r-1;t>l+2;t--){
						if(r-t>k) break; //不合法 
						if(arr[t]=='('||arr[t]==')') break;
						dp[l][r]=(dp[l][r]+dp[t-1][l+1])%MOD; 
					}
				}
				bool flag=true;
				for(register int t=l+1;t<=r-1;t++)
					if(arr[t]=='('||arr[t]==')') { flag=false; break; }
				if(flag&&r-l-1<=k) dp[l][r]=(dp[l][r]+1)%MOD; //考虑S 
			}
			for(register int x=l+1;x<=r-2;x++)
				dp[l][r]=(dp[l][r]+dp[l][x]*dp[x+1][r]%MOD)%MOD;
		}
		for(register int l=1;l<=min(len-4,k);l++){ //枚举长度 
			int sum=len-l; //分配在两边到值 
			for(register int x=3;x<=n-l-1;x++){ //枚举起点 
				bool flag=true;
				for(register int t=x;t<=x+l-1;t++)
					if(arr[t]=='('||arr[t]==')') { flag=false; break; } //不能为*
				if(!flag) continue; 
				for(register int y=max((int)2,x+sum+l-n-1);y<=x-1;y++){ //枚举左边方案 
					int z=sum-y;
					dp[x-y][x+l+z-1]=(dp[x-y][x+l+z-1]+dp[x-y][x-1]*dp[x+l][x+l+z-1]%MOD)%MOD;
				}
			}
		}
	}
//	for(register int len=1;len<=n;len++){
//		printf("len: %lld\n",len);
//		for(register int l=1;l<=n-len+1;l++){
//			int r=l+len-1;
//			printf("%lld %lld %lld\n",l,r,dp[l][r]);
//		}
//		puts("");
//	}
	printf("%lld\n",dp[1][n]);
	return 0;
}
