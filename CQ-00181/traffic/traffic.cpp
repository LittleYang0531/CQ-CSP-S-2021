#include<algorithm>
#include<cstdio>
int n,m,q;
signed main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&q);
	for(int i=1;i<=n-1;i++){
		for(int j=1;j<=m;j++){
			int x;
			scanf("%d",&x);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<=m-1;j++){
			int x;
			scanf("%d",&x);
		}
	}
	for(int i=1;i<=q;i++){
		int k;
		scanf("%d",&k);
		int wzf,vf,xf,wzs,vs,xs;
		scanf("%d%d%d%d%d%d",&wzf,&vf,&xf,&wzs,&vs,&xs);
		if(xf==xs)printf("0\n");
		else printf("%d\n",vs+vf);
	}
	return 0;
}
/*
I've done my best.
*/
