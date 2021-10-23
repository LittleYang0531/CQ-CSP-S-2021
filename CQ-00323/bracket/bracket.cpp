#include<bits/stdc++.h>
#define loop(i,from,to) for(int i=(from);i<=(to);++i)
using namespace std;
using ll=long long;
const int maxn=500,mod=1e9+7;
int n,k,rbound[maxn+1],f[maxn+1][maxn+1],g[maxn+1][maxn+1],sumf[maxn+1][maxn+1];
char s[maxn+2];
bool available[maxn+1][maxn+1];
inline bool fit(char x,char t){return x=='?'||x==t;}
inline bool in(int x,int y){return y-x+1<=k;}
int main(){
	freopen("bracket.in","r",stdin),freopen("bracket.out","w",stdout);
	scanf("%d%d%s",&n,&k,s+1);
	loop(i,1,n)if(fit(s[i],'*')){
		available[i][i]=true;
		loop(j,1,i-1)available[j][i]=available[j][i-1];
	}
	loop(i,1,n){
		rbound[i]=i-1;
		while(rbound[i]<n&&available[i][rbound[i]+1])++rbound[i];
	}
	loop(len,2,n)loop(i,1,n-len+1){
		int j=i+len-1;
		if(fit(s[i],'(')&&fit(s[j],')')){
			if(in(i+1,j-1)&&(i+1==j||available[i+1][j-1]))f[i][j]=1;//()/(S)
			f[i][j]=(f[i][j]+f[i+1][j-1])%mod;//(A)
			loop(l,i+1,j-1){
				if(in(i+1,l-1)&&available[i+1][l-1])f[i][j]=(f[i][j]+f[l][j-1])%mod;//(SA)
				if(in(l,j-1)&&available[l][j-1])f[i][j]=(f[i][j]+f[i+1][l-1])%mod;//(AS)
			}
			g[i][j]=f[i][j];
			loop(l1,i,j-1){
				int l2_r=min(rbound[l1+1]+1,min(j,l1+k+1));
				f[i][j]=(f[i][j]+(ll)g[i][l1]*(sumf[l1+1][j]+mod-sumf[l2_r+1][j]))%mod;//ASA/AA
			}
		}
		sumf[i][j]=(sumf[i+1][j]+f[i][j])%mod;
	}
	printf("%d",f[1][n]);
	return 0;
}
