#include<stdio.h>
#define R register int
#define P 1000000007
int f[501][501][2],g[501],len[501];
char s[502];
inline void Add(int&x,const int y){
	x+=y;
	if(x>=P){
		x-=P;
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	int n,m;
	scanf("%d%d",&n,&m);
	scanf("%s",s+1);
	for(R i=1;i<=n;i++){
		if(s[i]=='*'||s[i]=='?'){
			len[i]=len[i-1]+1;
		}
	}
	for(R i=2;i<=n;i++){
		if(s[i-1]!=')'&&s[i-1]!='*'&&s[i]!='('&&s[i]!='*'){
			f[i-1][i][0]=1;
		}
	}
	for(R i=2;i!=n;i++){
		for(R j=i+1;j<=n;j++){
			if((s[j-i]=='('||s[j-i]=='?')&&(s[j]==')'||s[j]=='?')){
				f[j-i][j][0]=f[j-i+1][j-1][0];
				Add(f[j-i][j][0],f[j-i+1][j-1][1]);
				for(R k=1;k<=m&&k<i-2;k++){
					if(s[j-i+k]!='*'&&s[j-i+k]!='?'){
						break;
					}
					Add(f[j-i][j][0],f[j-i+k+1][j-1][0]);
					Add(f[j-i][j][0],f[j-i+k+1][j-1][1]);
				}
				for(R k=1;k<=m&&k<i-2;k++){
					if(s[j-k]!='*'&&s[j-k]!='?'){
						break;
					}
					Add(f[j-i][j][0],f[j-i+1][j-k-1][0]);
					Add(f[j-i][j][0],f[j-i+1][j-k-1][1]);
				}
				if(i<m+2){
					bool tag=true;
					for(R k=j-i+1;k!=j;k++){
						if(s[k]!='?'&&s[k]!='*'){
							tag=false;
							break;
						}
					}
					if(tag==true){
						Add(f[j-i][j][0],1);
					}
				}
				g[j-i]=0;
				for(R k=j-i+1;k!=j-1;k++){
					g[k]=f[j-i][k][0];
					Add(g[k],f[j-i][k][1]);
					if(s[k]=='*'||s[k]=='?'){
						Add(g[k],g[k-1]);
					}
				}
				for(R k=j-1;k!=j-i+1;k--){
					int x=0;
					if(len[k-1]>m){
						int l=k-m-2;
						if(l<j-i){
							l=j-i;
						}
						x=g[l];
					}
					f[j-i][j][1]=((long long)(g[k-1]-x+P)*f[k][j][0]+f[j-i][j][1])%P;
				}
			}
		}
	}
	int ans=f[1][n][0];
	Add(ans,f[1][n][1]);
	printf("%d",ans);
	return 0;
}
