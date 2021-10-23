#include<bits/stdc++.h>
using namespace std;
inline int Rd() {
	int s=0; char fl=0,c=getchar();
	while(c<'0'||c>'9') fl|=(c=='-'),c=getchar();
	while(c>='0'&&c<='9') s=(s<<3)+(s<<1)+(c^48),c=getchar();
	return fl?-s:s;
}

const int N=505,mod=1e9+7;

int n,K,f[N][N][3][2];
char c[N];

inline void cadd(int &x,int y) {x=((x+=y)>=mod?x-mod:x); }

inline int Judge(int i,int t) {
	if(t==1&&(c[i]=='?'||c[i]=='(')) return 1;
	if(t==2&&(c[i]=='?'||c[i]==')')) return 1;
	if(t==3&&(c[i]=='?'||c[i]=='*')) return 1;
	return 0;
}

inline int F(int l,int r,int pd,int kd) {
	if(l>r) return 1; 
	if(~f[l][r][pd][kd]) return f[l][r][pd][kd];
	f[l][r][pd][kd]=0;
	if(kd==0||kd==1) {
		if(Judge(l,1)&&Judge(r,c)) {
			cadd(f[l][r][pd][kd],F(l+1,r-1,0,0));
			cadd(f[l][r][pd][kd],F(l+1,r-1,0,1));
		}
		
		if(pd==0) {
			for(int i=l; i<=r; ++i) {
				if(Judge(i,3)) {
					cadd(f[l][r][pd][kd],F(i+1,r,1,0));
					cadd(f[l][r][pd][kd],F(i+1,r,1,1));
				}
				else break;
			}
			for(int i=r; i>=l; --i)	 {
				if(Judge(i,3)) {
					cadd(f[l][r][pd][kd],F(l,i-1,1,0));
					cadd(f[l][r][pd][kd],F(l,i-1,1,1));
				}
				else break;
			}
		}
	}
	if(kd==1) {
		for(int i=l; i<r; ++i) 
			cadd(f[l][r][pd][kd],1ll*(F(l,i,(pd==1?1:0),1))*F(i+1,r,(pd==2?2:0),0)%mod);
		
	}
	return f[l][r][pd][kd];
}

int main() {
//	system("fc bracket.out bracket.out");
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=Rd(),K=Rd(); scanf("%s",c+1);
	memset(f,-1,sizeof(f));
	printf("%d\n",F(1,n));
	return 0;
}

