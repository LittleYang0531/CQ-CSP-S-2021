#include<bits/stdc++.h>
#define File(s) freopen(s".in","r",stdin),freopen(s".out","w",stdout)
#ifdef GTRAKIOI
#define defrog(...) fprintf(stderr,__VA_ARGS__)
#else
#define defrog(...) 1
#endif
typedef long long ll;
typedef std::vector<int> vi;
typedef std::pair<int,int> pii;
#define Tp template<typename T>

const int N=505,M=1000000007;
Tp inline T increase(const T&a){return a<M?a:a-M;}
Tp inline T reduce(const T&a){return a+(a>>(8*sizeof(T)-1)&M);}
int f[N][N],dp[N][N],sdp[N][N],iss[N][N],nxt[N];

signed main(){
	File("bracket");
	assert(increase(M+1)==1);
	assert(increase(M-1)==M-1);
	assert(reduce(-1)==M-1);
	assert(reduce(-1ll)==M-1ll);
	
	int n,k;
	std::cin>>n>>k;
	std::string s;
	std::cin>>s;
	for(int i=1;i<=n;i++)iss[i][i]=(s[i-1]=='*'||s[i-1]=='?');
	for(int len=2;len<=k;++len){
		for(int l=1,r;(r=l+len-1)<=n;l++){
			iss[l][r]=iss[l][r-1]&&iss[r][r];
//			if(iss[l][r])defrog("[%d,%d] is *\n",l,r);
		}
	}
	for(int i=0;i<=n;i++){
		iss[i+1][i]=1;
	}
	
	nxt[n+1]=n+1;
	for(int i=n;i>=1;--i){
		nxt[i]=!iss[i][i]?i:nxt[i+1];
//		defrog("%d %d\n",i,nxt[i]);
	}
	
	for(int len=2;len<=n;++len){
		for(int l=1,r;(r=l+len-1)<=n;l++){
//			if(l==3&&r==4)defrog("visited [%d,%d]\n",l,r);
//			if(l==2&&r==4)defrog("visited [%d,%d]\n",l,r);
			
			if((s[l-1]=='('||s[l-1]=='?')&&(s[r-1]==')'||s[r-1]=='?')){
				//case 1
				if(iss[l+1][r-1])f[l][r]=increase(f[l][r]+1);
				
				//case 3
				f[l][r]=increase(f[l][r]+f[l+1][r-1]);
				for(int i=l+2;i<r;++i)if(iss[l+1][i-1]){
					f[l][r]=increase(f[l][r]+f[i][r-1]);
				}
				for(int i=l+1;i<r-1;++i)if(iss[i+1][r-1]){
					f[l][r]=increase(f[l][r]+f[l+1][i]);
				}
				dp[l][r]=f[l][r];
//				defrog("dp[%d,%d]=%d\n",l,r,dp[l][r]);
			}
			sdp[l][r]=increase(sdp[l+1][r]+dp[l][r]);
			
			//case 2
			for(int i=l;i<r;++i){
				/*for(int j=i+1;j<=r&&(j-1)-(i+1)+1<=k;++j)if(iss[i+1][j-1]){
					f[l][r]=(f[l][r]+f[l][i]*(ll)dp[j][r])%M;
					
				}*/
				/*int sum=0;
				for(int j=i+1;j<std::min(std::min(nxt[i+1]+1,k+i+2),r+1);++j){
					assert(iss[i+1][j-1]);
					sum=increase(sum+dp[j][r]);
				}
				f[l][r]=(f[l][r]+f[l][i]*(ll)sum)%M;*/
//				defrog("[%d,%d) %d:%d %d\n",i+1,std::min(std::min(nxt[i+1]+1,k+i+2),r+1),r,sum,sdp[i+1][r]-sdp[std::min(std::min(nxt[i+1]+1,k+i+2),r+1)][r]);
				f[l][r]=(f[l][r]+f[l][i]*(ll)reduce(sdp[i+1][r]-sdp[std::min(std::min(nxt[i+1]+1,k+i+2),r+1)][r]))%M;
			}
			
//			defrog("f[%d,%d]=%d\n",l,r,f[l][r]);
		}
	}
//	defrog("%d %d %d\n",sdp[2][4],sdp[3][4],sdp[5][4]);
//	defrog("%d\n",f[1][n]);
	printf("%d\n",f[1][n]);
	return 0;
}
