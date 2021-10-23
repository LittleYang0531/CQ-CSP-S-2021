#include<iostream>
using namespace std;
int n,m,t,a[501][501],b[501][501],g1,g2;
int main() {
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d%d%d",&n,&m,&t);
	for(int i=1; i<n; i++) for(int j=1; j<=m; j++) scanf("%d",a[i][j]);
	for(int i=1; i<=n; i++) for(int j=1; j<m; j++) scanf("%d",b[i][j]);
	for(int k,i=1; i<=t; i++) {
		scanf("%d",&k);
		int x1,x2,y1,y2,z1,z2;
		if(k<=1) {
			scanf("%d%d%d",&x1,&y1,&z1);
			printf("0\n");
			continue;
		} else {
			scanf("%d%d%d",&x2,&y2,&z2);
			printf("%d\n",max(x1,x2));
		}
	}
}
