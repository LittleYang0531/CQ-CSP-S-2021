#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
#define int long long
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
const int N=5e2+10,p=1e9+7;
void gmod(int &x){(x>=p)&&(x-=p);}
void hmod(int &x){x%=p;}
int f[N][N],n,lim;char s[N];
int xx[N];
#define ok(x,c) (s[x]==c||s[x]=='?')
#define all(l,r) (xx[r]-xx[l-1]==(r)-(l)+1)
signed main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),lim=read(),scanf("%s",s+1);
	memset(f,0,sizeof f);
	For(i,1,n-1)f[i][i+1]=ok(i,'(')&&ok(i+1,')');//()
	For(i,1,n)xx[i]=xx[i-1]+ok(i,'*');
	For(len,3,n)For(l,1,n-len+1){
		int r=l+len-1;
		if(ok(l,'(')&&ok(r,')')){
			if(r-l-1<=lim&&all(l+1,r-1))gmod(++f[l][r]);//(S)
			gmod(f[l][r]+=f[l+1][r-1]);//(A)
			For(k,l+1,min(r-2,l+lim))if(all(l+1,k))gmod(f[l][r]+=f[k+1][r-1]),assert(k-l<=lim);else break;//(SA)
			Rof(k,r-1,max(l+2,r-lim))if(all(k,r-1))gmod(f[l][r]+=f[l+1][k-1]),assert(r-k<=lim);else break;//(AS)
		}
		For(k,l,r-1)hmod(f[l][r]+=f[l][k]*f[k+1][r]);//AB
		For(L,l+1,r-1)For(R,L,r-1){//ASB
			if(!all(L,R)||R-L+1>lim)break;
			assert(R-L+1<=lim);
			hmod(f[l][r]+=f[l][L-1]*f[R+1][r]);
		}
	}
	cout<<f[1][n]<<endl;
	return 0;
}
