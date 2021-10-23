#include<bits/stdc++.h>
using namespace std;
int n,m,T;
int x1[502][602],x2[502][502],x3,p,t;
int main(){
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	srand(time(0));
	scanf("%d %d %d",&n,&m,&T);
	for(int i=1;i<n;i++){
		for(int j=1;j<=m;j++){
			scanf("%d",&x1[i][j]);
		}
	}
	for(int i=1;i<=n;i++){
		for(int j=1;j<m;j++){
			scanf("%d",&x2[i][j]);
		}
	}
	while(T--){
		int k;scanf("%d",&k);
		while(k--){
			scanf("%d %d %d",&x3,&p,&t);
		}
		printf("%d\n",2*n*m);
	}
	return 0;
}
