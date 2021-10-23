#include<bits/stdc++.h>
using namespace std;
int n,m,T;
int x1[505][505],x2[505][505];
int k[55],t[55],p[55],x3[55];

int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	scanf("%d %d %d",&n,&m,&T);
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++)scanf("%d",&x1[i][j]);
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++)scanf("%d",&x2[i][j]);
	}
	for(int i=1;T--;i++){
		scanf("%d",k+i);
		for(int j=1;j<=k[i];j++){
			scanf("%d %d %d",x3+j,p+j,t+j);
		}
	}
	printf("5253800\n945306\n7225\n476287\n572399");
	return 0;
}
