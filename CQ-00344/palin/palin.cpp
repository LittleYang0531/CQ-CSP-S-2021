#include <iostream>
#include <stdio.h>
#include <algorithm>
using namespace std;
long long T,n,a[1000005];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>T;
	while(T--){
		scanf("%lld",&n);
		int op=0;
		for(int i=1; i<=n*2; i++) scanf("%lld",&a[i]);
		for(int i=1; i<=n; i++){
			if(a[i]!=a[2*n+1-i]){
				op=1;
				continue;
			}
		}
		if(op) printf("-1\n");
		else{
			for(int j=1; j<=n*2; j++){
				printf("L");
			}
			printf("\n");
		}
	}
	return 0;
}
