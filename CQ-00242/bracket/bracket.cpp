#include<bits/stdc++.h>
#define int long long
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
using namespace std;
bool ppp;
const int N=1010;
const int p=1e9+7;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int f[N][N],g[N][N];//f是大的，g是几个拼在一起的 
int L[N][N],R[N][N];
int mx[N],mxx[N];
char s[N];
int n,k;
bool check(int x,int y){return ((s[x]=='?'||s[x]=='(')&&(s[y]=='?'||s[y]==')'));}
void init(){
	For(i,1,n)For(j,i,n+1)
		if((s[j]!='*'&&s[j]!='?')||j-i+1>k){mx[i]=j-1;break;}
	For(i,1,n)Rof(j,i,0)
		if((s[j]!='*'&&s[j]!='?')||i-j+1>k){mxx[i]=j+1;break;}
	return;
}
bool pppp;
signed main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();scanf("%s",s+1);init();
	rep(i,n)if(check(i,i+1))f[i][i+1]=g[i][i+1]=L[i][i+1]=R[i][i+1]=1;
	For(qwe,2,n)For(l,1,n){
		int r=l+qwe;if(r>n)break;
		if(check(l,r)){
			f[l][r]=(f[l][r]+g[l+1][r-1])%p;
			if(s[l+1]=='*'||s[l+1]=='?')f[l][r]=(f[l][r]+(R[l+2][r-1]-R[min(r,mx[l+1]+1)+1][r-1]))%p;
//			For(j,l+1,r-1){
//				if(s[j]!='*'&&s[j]!='?')break;if(j-l>k)break;
//				f[l][r]=(f[l][r]+g[j+1][r-1])%p;
//			}
			if(s[r-1]=='*'||s[r-1]=='?')f[l][r]=(f[l][r]+(L[l+1][r-2]-L[l+1][max(l+1-1,mxx[r-1]-1)-1]))%p;
//			Rof(j,r-1,l+1){
//				if(s[j]!='*'&&s[j]!='?')break;if(r-j>k)break;
//				f[l][r]=(f[l][r]+g[l+1][j-1])%p;
//			}
			if(mx[l+1]>=r-1)f[l][r]=(f[l][r]+1)%p;
		}
		
		For(mid,l+1,r-1){
			if(mid<=min(mx[mid+1],r-1))g[l][r]=(g[l][r]+f[l][mid]*(R[mid+1][r]-R[min(mx[mid+1],r-1)+2][r]))%p;
//			if(l==4&&r==10&&f[l][mid]*g[len+1][r])cout<<l<<" "<<mid<<" "<<f[l][mid]<<" "<<len+1<<" "<<r<<" "<<g[len+1][r]<<endl;
		}
		g[l][r]=(g[l][r]+f[l][r])%p;
		L[l][r]=(L[l][r-1]+g[l][r])%p;R[l][r]=(R[l+1][r]+g[l][r])%p;
	}
	cout<<(g[1][n]%p+p)%p<<endl;
	return 0;
}

