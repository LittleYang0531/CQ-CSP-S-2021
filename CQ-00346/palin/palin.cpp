#include <bits/stdc++.h>
using namespace std;
int T,n,flag,l,r;
int a[1000001],b[1000001],g[1000001];
bool pd(){//╩ьнд 
	for(int i=1;i<=n;i++)if(b[i]!=b[2*n-i+1])return 0;
	return 1;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)scanf("%d",&a[i]);
		memset(g,0,sizeof(g));
		while(1){
			l=1;r=2*n;
			for(int i=1;i<=2*n;i++){if(g[i]==0)b[i]=a[l++];else b[i]=a[r--];}
			if(pd()){for(int i=1;i<=2*n;i++)printf(g[i]==0?"L":"R");printf("\n");break;}
			g[2*n]++;
			for(int i=2*n;i>=2;i--)if(g[i]==2){g[i]=0;g[i-1]++;}
			if(g[1]==2){printf("-1");break;}
		}
	}
	return 0;
}
