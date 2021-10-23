#include<bits/stdc++.h>
using namespace std;
int T;
int N;
int n[1000005];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&N);
		for(int i=1;i<=2*N;i++){
			scanf("%d",&n[i]);
		}
		if(n[1]==n[N*2]){
			printf("L\n");
		}
		else printf("-1\n");
	}
	return 0;
}

