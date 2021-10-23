#include<bits/stdc++.h>
using namespace std;
const int p=1e9+7;
int n,T,ans=0;
int a[500005];
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++){
			scanf("%d",&a[i]);
		}
		if(a[1]==a[n*2]&&a[2]!=a[n*2-1]){
			puts("-1");
			continue;
		}
		for(int i=1;i<=2*n;i++){
			if(a[i]%2){
				printf("L");
			}
			else{
				printf("R");
			}
		}
		puts("");
	}
	fclose(stdin);
	fclose(stdout);
	return 0;
}
