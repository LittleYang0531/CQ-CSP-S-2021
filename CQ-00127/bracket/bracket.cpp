#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N=505;
const ll MOD=1e9+7;
char a[N];int r[N];
ll dp1[N][N],dp2[N][N],s[N][N];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,m;
	scanf("%d %d",&n,&m);
	scanf("%s",a+1);
	for(int i=1;i<=n;++i)
		for(r[i]=i+1;;++r[i]){
			if(r[i]-i-1>m){
				--r[i];
				break;
			}
			if(a[r[i]]!='?'&&a[r[i]]!='*')
				break;
		}
	for(int len=2;len<=n;++len)
		for(int i=1;i+len-1<=n;++i){
			int j=i+len-1;
			if((a[i]=='?'||a[i]=='(')&&(a[j]=='?'||a[j]==')')){
				bool flg=1;
				for(int k=i+1;k<j;++k)
					if(a[k]!='?'&&a[k]!='*'){
						flg=0;
						break;
					}
				if(flg&&(j-i-1)<=m)	++dp1[i][j];
				for(int k=i+1;k<j;++k){
					if(k-i-1>m)	break;
					dp1[i][j]=(dp1[i][j]+dp1[k][j-1]+dp2[k][j-1])%MOD;
					if(a[k]!='?'&&a[k]!='*')
						break;
				}
				for(int k=j-1;k>i;--k){
					if(j-k-1>m)	break;
					if(k!=j-1)
						dp1[i][j]=(dp1[i][j]+dp1[i+1][k]+dp2[i+1][k])%MOD;
					if(a[k]!='?'&&a[k]!='*')
						break;
				}
			}
			for(int k=i+1;k<j;++k)
				dp2[i][j]=(dp2[i][j]+dp1[i][k]*(s[k+1][j]-s[r[k]+1][j]))%MOD;
			s[i][j]=(s[i+1][j]+dp1[i][j]+dp2[i][j])%MOD;
		}
	printf("%lld",((dp1[1][n]+dp2[1][n])%MOD+MOD)%MOD);
	return 0;
}
