#include <bits/stdc++.h>
using namespace std;
const int maxn = 505;
typedef long long LL;
int readint(){
	int x=0,f=1;char s=getchar();
	#define sc (s=getchar())
	while(s<'0'||s>'9'){
		if(s=='-')
			f=-1;
		sc;
	}
	while(s>='0'&&s<='9'){
		x=(x<<3)+(x<<1)+(s^48);
		sc;
	}
	#undef sc
	return x*f;
}
bool colored[maxn][maxn];
int a[maxn][maxn];
int b[maxn][maxn];
int k;
int val[maxn<<2],ind[maxn<<2],ys[maxn<<2];
LL minx=0x3f3f3f3f3f3f3f3f;
int n,m;
void check(){
	LL ans=0;
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			if(colored[i][j]!=colored[i+1][j])
				ans+=a[i][j];
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			if(colored[i][j]!=colored[i][j+1])
				ans+=b[i][j];
		}
	}
	for(int i=1;i<=k;i++){
		if(ind[i]<=m){
			if(ys[i]!=colored[1][ind[i]])
				ans+=val[i];
		}
		else if(ind[i]<=m+n){
			if(ys[i]!=colored[ind[i]-m][m])
				ans+=val[i];
		}
		else if(ind[i]<=2*m+n){
			if(ys[i]!=colored[n][m-(ind[i]-m-n)+1])
				ans+=val[i];
		}
		else{
			if(ys[i]!=colored[n-(ind[i]-2*m-n)+1][1])
				ans+=val[i];
		}
	}
	minx=min(ans,minx);
}
void dfs(int x,int y){
	if(x==n&&y==m+1){
		check();
		return;
	}
	if(y==m+1)
		y=1,x++;
	colored[x][y]=0;
	dfs(x,y+1);
	colored[x][y]=1;
	dfs(x,y+1);
}
int main (){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=readint(),m=readint();
	int t=readint();
	for(int i=1;i<n;i++)
		for(int j=1;j<=m;j++){
			a[i][j]=readint();
		}
	for(int i=1;i<=n;i++)
		for(int j=1;j<m;j++)
			b[i][j]=readint();
	while(t--){
		k=readint();
		minx=0x3f3f3f3f3f3f3f3f;
		for(int i=1;i<=k;i++){
			val[i]=readint();
			ind[i]=readint();
			ys[i]=readint();
		}
		dfs(1,1);
		printf("%lld\n",minx);
	}
	return 0;
}
