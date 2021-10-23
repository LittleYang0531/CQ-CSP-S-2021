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
	for(register int len=2;len<=n;len++){ //ö�����䳤�� 
		for(register int l=1;l<=n-len+1;l++){ //ö����˵� 
			int r=l+len-1; //�Ҷ˵�
			if(check(l,r)){ //�˵����Ϊ()
				dp[l][r]=(dp[l][r]+dp[l+1][r-1])%MOD;
				if(arr[r-1]!='*'){ //ֻ��һ�������� * 
					for(register int t=l+1;t<r-2;t++){
						if(t-l>k) break; //���Ϸ� 
						if(arr[t]=='('||arr[t]==')') break; //������ 
						dp[l][r]=(dp[l][r]+dp[t+1][r-1])%MOD;
					}
				}
				if(arr[l+1]!='*'){
					for(register int t=r-1;t>l+2;t--){
						if(r-t>k) break; //���Ϸ� 
						if(arr[t]=='('||arr[t]==')') break;
						dp[l][r]=(dp[l][r]+dp[t-1][l+1])%MOD; 
					}
				}
				bool flag=true;
				for(register int t=l+1;t<=r-1;t++)
					if(arr[t]=='('||arr[t]==')') { flag=false; break; }
				if(flag&&r-l-1<=k) dp[l][r]=(dp[l][r]+1)%MOD; //����S 
			}
			for(register int x=l+1;x<=r-2;x++)
				dp[l][r]=(dp[l][r]+dp[l][x]*dp[x+1][r]%MOD)%MOD;
		}
		for(register int l=1;l<=min(len-4,k);l++){ //ö�ٳ��� 
			int sum=len-l; //���������ߵ�ֵ 
			for(register int x=3;x<=n-l-1;x++){ //ö����� 
				bool flag=true;
				for(register int t=x;t<=x+l-1;t++)
					if(arr[t]=='('||arr[t]==')') { flag=false; break; } //����Ϊ*
				if(!flag) continue; 
				for(register int y=max((int)2,x+sum+l-n-1);y<=x-1;y++){ //ö����߷��� 
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
