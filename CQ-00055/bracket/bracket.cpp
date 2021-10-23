#include<bits/stdc++.h>
using namespace std;
inline int read(){
	int t=0;char v=getchar();
	while(v<'0')v=getchar();
	while(v>='0')t=(t<<3)+(t<<1)+v-48,v=getchar();
	return t;
}
const int M=1e9+7;
inline void add(int &x,int y){(x+=y)>=M?x-=M:x;}
int f[502][502],n,k,g[502][502],R[502],H[502][502];
char s[502];
inline bool ck(int x,char y){
	return (s[x]=='?')||(s[x]==y);
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	scanf("%s",s+1);
	R[n+1]=n+1;
	for(int i=n;i;--i){
		if(!ck(i+1,'*'))R[i]=i+1;
		else R[i]=R[i+1];
	}
	for(int i=2;i<=n;++i)
		for(int l=1;l+i-1<=n;++l){
			int r=l+i-1;
			if(ck(l,'(')&&ck(r,')')&&r-l-1<=k){
				bool ia=1;
				for(int o=l+1;o<=r-1;++o)ia&=ck(o,'*');
				g[l][r]=ia;
			}
			if(ck(l,'(')&&ck(r,')')){
				for(int o=l+1;o<r&&o<=l+k+1;++o){
					add(g[l][r],f[o][r-1]);
					if(!ck(o,'*'))break;
				}
				if(ck(r-1,'*')){
					for(int o=r-2;o>l&&o>=r-k-1;--o){
						add(g[l][r],f[l+1][o]);
						if(!ck(o,'*'))break;
					}
				}
			}
			for(int ll=l;ll<=r;++ll){
				int pr=min(min(ll+k+1,r),R[ll]);
				add(f[l][r],1ll*g[l][ll]*(H[ll+1][r]-H[pr+1][r]+M)%M);
			}
			add(f[l][r],g[l][r]),H[l][r]=f[l][r],add(H[l][r],H[l+1][r]);
		}
	printf("%d",f[1][n]);
}

