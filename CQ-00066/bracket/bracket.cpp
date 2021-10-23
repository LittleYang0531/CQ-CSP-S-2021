#include<algorithm>
#include<iostream>
#include<iomanip>
#include<cstring>
#include<cstdio>
#include<cmath>
using namespace std;
#define LL long long
const int Maxx=1000005,Maxn=2005,INF=0x3f3f3f3f,Mod=1e9+7;
int n,K,f[505][505],F[505][505],G[505][505],H[505][505],g[505][505],h[505][505];char S[2333];
inline int Mo(const int x){return x>=Mod?x-Mod:x;}
inline void Add(int &x,const int y){x=Mo(x+y);}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d %s",&n,&K,S+1);
	for(int i=1;i<=n;++i)
	if(S[i]=='('||S[i]=='?')
	for(int j=i+1;j<=min(n,i+K+1);++j){
		if(S[j]=='(')j=n+1;
		else if(S[j]==')')f[i][j]=1,j=n+1;
		else if(S[j]=='?')f[i][j]=1;
	}
	for(int ln=1;ln<=n;++ln)
	for(int l=1,r;(r=l+ln)<=n;++l){
		if(S[l]=='*'||S[l]=='?'){
			for(int k=1,R=min(ln,K);k<=R;++k){
				Add(g[l][r],f[l+k][r]);
				if(S[l+k]=='('||S[l+k]==')')break;
			}
			G[l][r]=g[l][r];
			for(int k=l;k<r;++k)Add(G[l][r],(LL)g[l][k]*Mo(F[k+1][r]+G[k+1][r])%Mod);
		}
		if(S[r]=='*'||S[r]=='?'){
			for(int k=1,R=min(ln,K);k<=R;++k){
				Add(h[l][r],f[l][r-k]);
				if(S[r-k]=='('||S[r-k]==')')break;
			}
			H[l][r]=h[l][r];
			for(int k=l;k<r;++k)Add(H[l][r],(LL)Mo(F[l][k]+H[l][k])*h[k+1][r]%Mod);
		}
		if((S[l]=='('||S[l]=='?')&&(S[r]==')'||S[r]=='?')){
			Add(f[l][r],G[l+1][r-1]);
			Add(f[l][r],H[l+1][r-1]);
			Add(f[l][r],F[l+1][r-1]);
			F[l][r]=f[l][r];
			for(int k=l;k<=r;++k){
				Add(F[l][r],(LL)Mo(f[l][k]+h[l][k])*F[k+1][r]%Mod);
			//	Add(F[l][r],(LL)F[l][k]*Mo(f[k+1][r]+g[k+1][r])%Mod);
			}
		}
		//cout<<l<<" "<<r<<" "<<F[l][r]<<" "<<G[l][r]<<" "<<H[l][r]<<"\n";
	}
	cout<<F[1][n]<<"\n";
	return 0;
}
/*
7 3
(*??*??
*/
/*
10 2
???(*??(?)
*/
