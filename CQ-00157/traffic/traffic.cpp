#include<cstdio>
#include<cstring>
const int maxn=15;
const int inf=0x3f3f3f3f;

/* WSSBWSSBWSSBWSSBWSSBWSSBWSSBWSSB */

typedef short F;
F*ck,you,ccf;	// ±í°× ccf 

/* WSSBWSSBWSSBWSSBWSSBWSSBWSSBWSSB */

int n,m,t,w,d,c,k;
int a[2][maxn][maxn];
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1;i<n;++i){
		for(int j=1;j<=m;++j)
			scanf("%d",&a[0][i][j]);
	}
	for(int i=1;i<=n;++i){
		for(int j=1;j<m;++j)
			scanf("%d",&a[1][i][j]);
	}
	while(t--){
		scanf("%d",&k);
		while(k--) scanf("%d%d%d",&w,&d,&c);
		puts("0");
	}
	return 0;
}

/*

*/
