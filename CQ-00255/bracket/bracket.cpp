#include<bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define N 505
int n,m,f[2][N][N],g[N][N];char s[N];
//#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
//char buf[1<<21],*p1=buf,*p2=buf;
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	if(s[1]!='('&&s[1]!='?') return puts("0"),0;
	f[1][1][0]=1;
	for(int i=2;i<=n;i++){
		int t=i&1;
		memset(f[t],0,sizeof(f[t]));
		for(int j=0;j<=i;j++){
			(g[i][j]+=g[i-1][j])%=mod;
			for(int k=0;k<=i;k++){
				if(k>m) break;
				if(s[i]!='?'){
					if(s[i]=='('&&j){
						(f[t][j][0]+=f[t^1][j-1][k])%=mod;
						if(j>1&&k) (g[i][j]+=f[t^1][j-1][k])%=mod;
					}if(s[i]==')'){
						(f[t][j][0]+=f[t^1][j+1][k])%=mod;
					}if(s[i]=='*'&&k){
						(f[t][j][k]+=f[t^1][j][k-1])%=mod;
						if(s[i-1]==')'||(s[i-1]=='?'&&k==1)) (f[t][j][k]+=mod-g[i-2][j+1])%=mod;
					}
				}else{
					if(j) (f[t][j][0]+=f[t^1][j-1][k])%=mod;
					if(j>1&&k) (g[i][j]+=f[t^1][j-1][k])%=mod;
					if(k) (f[t][j][k]+=f[t^1][j][k-1])%=mod;
					if((k&&s[i-1]==')')||(s[i-1]=='?'&&k==1)) (f[t][j][k]+=mod-g[i-2][j+1])%=mod;
					(f[t][j][0]+=f[t^1][j+1][k])%=mod;
				}
			}
		}
	}printf("%d",f[n&1][0][0]);
	return 0;
}
