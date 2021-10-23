#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
const long long mod=1000000007;
int n,k;
long long f[3][505][505],g[3][505][505];
string s;
void work1()  {
	for(int j=1;j<=k;j++) 
		for(int l=0;l<=n;l++) 
			f[0][j][l]=(f[0][j][l]+g[0][j-1][l])%mod;
	for(int l=0;l<=n;l++)f[0][1][l]=(f[0][1][l]+g[1][0][l])%mod;
	for(int l=0;l<=n;l++)f[0][1][l]=(f[0][1][l]+g[2][0][l])%mod;
}
void work2() {
	for(int j=0;j<=k;j++) 
		for(int l=1;l<=n;l++) 
			f[1][0][l]=(f[1][0][l]+g[0][j][l-1])%mod;
	for(int j=1;j<=n;j++)f[1][0][j]=(f[1][0][j]+g[1][0][j-1])%mod;
	for(int j=1;j<=n;j++)f[1][0][j]=(f[1][0][j]+g[2][0][j-1])%mod;
}
void work3() {
	for(int j=0;j<=k;j++) 
		for(int l=0;l<n;l++) 
			f[2][0][l]=(f[2][0][l]+g[0][j][l+1])%mod;
	for(int j=0;j<n;j++)f[2][0][j]=(f[2][0][j]+g[1][0][j+1])%mod;
	for(int j=0;j<n;j++)f[2][0][j]=(f[2][0][j]+g[2][0][j+1])%mod;	
}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	cin>>s;
	s=' '+s;
	f[1][0][1]=1;
	for(int i=2;i<=n;i++) {
		memcpy(g,f,sizeof(f));
		memset(f,0,sizeof(f));
		if(s[i]!='?') {
			if(s[i]=='*')work1();
			else if(s[i]=='(')work2();
			else work3();
		}else {
			work1();
			work2();
			work3();
		}
	}
	printf("%lld",f[2][0][0]%mod);
	return 0;
}
