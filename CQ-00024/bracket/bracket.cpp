#include<bits/stdc++.h>
using namespace std;
const int N=1005,mod=1e9+7;
inline int add(int a,int b){return a+b>=mod?a+b-mod:a+b;}
inline int mul(int a,int b){return 1ll*a*b%mod;}
int n,k,f[N][N],sum[N],s1[N],g[N][N];
char s[N];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	for(int i=1;i<=n;i++){
		sum[i]=sum[i-1];
		if(s[i]=='('||s[i]==')')sum[i]++;
	}
	for(int i=1;i<=n;i++)g[i][i-1]=1;
	for(int len=2;len<=n;len++){
		for(int l=1,r=len;r<=n;l++,r++){
			bool flag=0;
			if((s[l]=='?'||s[l]=='(')&&(s[r]=='?'||s[r]==')'))flag=1;
			if(flag)f[l][r]=g[l+1][r-1];
			s1[l-1]=0;
			for(int p=l;p<r;p++){
				s1[p]=add(s1[p-1],g[l][p]);
				if(flag&&p>l&&p<r-1){
					if(p-l<=k&&sum[p]-sum[l]==0)f[l][r]=add(f[l][r],g[p+1][r-1]);
					if(r-p-1<=k&&sum[r-1]-sum[p]==0)f[l][r]=add(f[l][r],g[l+1][p]);
				}
			}
			if(flag&&r-l-1>=1&&r-l-1<=k&&sum[r-1]-sum[l]==0)f[l][r]=add(f[l][r],1);
			g[l][r]=f[l][r];
			for(int p=l,q=l;p<r;p++){
				while(sum[p]-sum[q]>0||p-q>k)q++;
				g[l][r]=add(g[l][r],mul(f[p+1][r],add(s1[p],mod-s1[q-1])));	
			}
		}
	}
	cout<<g[1][n];
	return 0;
}
