#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int mod=1e9+7;
int read(){
	int a=0;bool opt=0;char c=getchar();
	while(c<'0'||c>'9')opt|=c=='-',c=getchar();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=getchar();
	return opt?-a:a;
}
int Mod(int x){return x<mod?x:x-mod;}
void Add(int&x,int y){x=Mod(x+y);}
int n,k,f[505][505],p[505][505],s[505][505];char c[505];
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();k=read();scanf("%s",c+1);
	for(int i=1;i<=n;++i){
		s[i][i-1]=1;int opt=1;
		for(int j=i;j<=n;++j){
			if(c[j]!='?'&&c[j]!='*')opt=0;
			if(j-i+1>k)opt=0;s[i][j]=opt;
		}
	}
	for(int len=1;len<n;++len){
		for(int i=1;i+len<=n;++i){
			int j=i+len;
			if((c[i]=='('||c[i]=='?')&&(c[j]==')'||c[j]=='?')){
				f[i][j]=s[i+1][j-1];
				for(int k=i+1;k<j;++k)Add(f[i][j],1ll*f[i+1][k]*s[k+1][j-1]%mod);
				for(int k=j-1;k>i+1;--k)Add(f[i][j],1ll*f[k][j-1]*s[i+1][k-1]%mod);
			}
			p[i][j]=f[i][j];
			int tmp=0;
			for(int k=i,t=i;k<j;++k){
				while(t<j&&s[k+1][t]){
					Add(tmp,f[t+1][j]);++t;
				}
				if(k!=i)Add(tmp,mod-f[k][j]);
				Add(f[i][j],1ll*p[i][k]*tmp%mod);
			}
		}
	}
	cout<<f[1][n]<<"\n";
	return 0;
}
