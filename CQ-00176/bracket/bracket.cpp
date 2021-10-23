// MDR保佑，M99保佑，锉刀保佑，ayame保佑，夸哥保佑 
#include<bits/stdc++.h>
using namespace std;
int p1=1000000,p2=0;
char buf[1000005],wb[1000005];
int gc(){
	if(p1==1000000)fread(buf,1,1000000,stdin),p1=0;
	return buf[p1++];
}
#define gc getchar
#define Loli true
long long getint(){
	long long ret=0;
	int c=gc();
	bool flg=0;
	while(c<48||c>57)flg=c=='-',c=gc();
	while(c>=48&&c<=57)ret=(ret<<3)+(ret<<1)+(c^48),c=gc();
	return flg?-ret:ret;
}
void pc(int x){
	if(p2==1000000)fwrite(wb,1,1000000,stdout),p2=0;
	wb[p2++]=x;
}
void wrt(long long x){
	if(x==0)pc(48);
	if(x<0)pc('-'),x=-x;
	int c[32]={0};
	while(x)c[++c[0]]=x%10,x/=10;
	while(c[0])pc(c[c[0]--]^48);
}
const int mod = 1e9+7;
int MOD(int x){return x>=mod?x-mod:x;}
int n,k;
int f[505][505],g[505][505],hf[505],hg[505];
bool vft[505][505],vgt[505][505],vhf[505],vhg[505];
bool t[505][505],Ak[505][505];
char c[505];
int F(int l,int r);
int HF(int x);
int HG(int x);
int G(int l,int r){
	if(c[l]=='*'||c[l]==')')return 0;
	if(c[r]=='*'||c[r]=='(')return 0;
	if(l>=r)return 0;
	if(Ak[l][r])return HG(r-l+1);
	if(vgt[l][r])return g[l][r];
	vgt[l][r]=1;
	if(!t[l+1][r-1]&&(r-l-1)<=k)++g[l][r];
	g[l][r]=MOD(g[l][r]+F(l+1,r-1));
	for(int j=l+2;j<=min(l+k+1,r-1);j++)
		if(!t[l+1][j-1])g[l][r]=MOD(g[l][r]+F(j,r-1));
	for(int j=r-2;j>=max(r-k-1,l+1);j--)
		if(!t[j+1][r-1])g[l][r]=MOD(g[l][r]+F(l+1,j));
//	if(Ak[l][r])cerr<<"G:"<<g[l][r]<<" "<<hg[r-l+1]<<" "<<r-l+1<<endl;
	return g[l][r];
}
int F(int l,int r){
	if(c[l]=='*'||c[l]==')')return 0;
	if(c[r]=='*'||c[r]=='(')return 0;
	if(l>=r)return 0;
	if(Ak[l][r])return HF(r-l+1);
	if(vft[l][r])return f[l][r];
	vft[l][r]=1;
	if(!t[l+1][r-1]&&(r-l-1)<=k)++f[l][r];
	f[l][r]=MOD(f[l][r]+F(l+1,r-1));
	
	
	for(int j=l+2;j<=min(l+k+1,r-1);j++)
		if(!t[l+1][j-1]){
			f[l][r]=MOD(f[l][r]+F(j,r-1));
		}
	for(int j=r-2;j>=max(r-k-1,l+1);j--)
		if(!t[j+1][r-1]){
			f[l][r]=MOD(f[l][r]+F(l+1,j));
		}
	for(int j=1;l+j+1<r;j++){
		f[l][r]=MOD(f[l][r]+1ll*F(l,l+j)*G(l+j+1,r)%mod);
	}
	for(int len=1;len<=min(k,r-l+1);++len){
		for(int j=1;l+j+len+1<r;j++){
			if(!t[l+j+1][l+j+len]){
				f[l][r]=MOD(f[l][r]+1ll*F(l,l+j)*G(l+j+len+1,r)%mod);
			}
		}
	}
//	cerr<<l<<"<>"<<r<<endl;
//	if(Ak[l][r])cerr<<"F:"<<f[l][r]<<" "<<hf[r-l+1]<<" "<<r-l+1<<endl;
	return f[l][r];
}
int HG(int x){
	if(x<=1)return 0;
	if(vhg[x])return hg[x];
	vhg[x]=1;
	if(x-2<=k)++hg[x];
	int l=1,r=x;
	hg[x]=MOD(hg[x]+HF(x-2));
	for(int j=l+2;j<=min(l+k+1,r-1);j++)
		hg[x]=MOD(hg[x]+HF(r-1-j+1));
	for(int j=r-2;j>=max(r-k-1,l+1);j--)
		hg[x]=MOD(hg[x]+HF(j-l-1+1));
	return hg[x];
} 
int HF(int x){
	if(x<=1)return 0;
	if(vhf[x])return hf[x];
	vhf[x]=1;
	if(x-2<=k)++hf[x];
	int l=1,r=x;
	hf[x]=MOD(hf[x]+HF(x-2));
	for(int j=l+2;j<=min(l+k+1,r-1);j++)
		hf[x]=MOD(hf[x]+HF(r-1-j+1));
	for(int j=r-2;j>=max(r-k-1,l+1);j--)
		hf[x]=MOD(hf[x]+HF(j-l-1+1));
	for(int j=1;l+j+1<r;j++)
		hf[x]=MOD(hf[x]+1ll*HF(j+1)*HG(r-(l+j+1)+1)%mod);
		
	for(int len=1;len<=min(k,r-l+1);++len){
		for(int j=1;l+j+len+1<r;j++){
			hf[x]=MOD(hf[x]+1ll*HF(j+1)*HG(r-(l+j+len+1)+1)%mod);
		}
	}
	return hf[x];
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=getint(),k=getint();
	scanf("%s",c+1);
	for(int i=1;i<=n;i++)HF(i),HG(i);
//	cerr<<HF(i)<<" ";
//	cerr<<'\n';
	for(int i=1;i<=n;i++){
		t[i][i]=c[i]=='('||c[i]==')';
		Ak[i][i]=c[i]=='?';
		for(int j=i+1;j<=n;j++)t[i][j]=(t[i][j-1])||(c[j]=='(')||(c[j]==')'),Ak[i][j]=Ak[i][j-1]&(c[j]=='?');
//		cerr<<endl;
	}
	cout<<F(1,n)<<'\n';
	fwrite(wb,1,p2,stdout);
	return 0;
}
/*
7 3
(*??*??

10 2
???(*??(?)

7 2
(??(*?)

???(*??(?)

内 3个 
(((**))())
(()(**)())
(()(*)*())

前后缀 3个 
(*((*))()) 
(**(**)()) 
(**(*)*())

1<>2 2各 
()((**)())
()((*)*())

1<>3 1
(*)(*()())

1<>6 2
(*)(*)(())
()*(*)(())

1<>7 5
(()(*))(*)
(**(*))(*)
()((*))(*)
(*)(**)(*)
()*(**)(*)

1<>2
???(*??(?)

()*
()*
()*
*/
