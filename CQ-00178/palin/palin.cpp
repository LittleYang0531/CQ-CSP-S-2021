#include<bits/stdc++.h>
using namespace std;

int t = 0, n = 0, a[500001] = {}, b[500001] = {}, c[500001] = {}, flag = 0;

bool che(int x){
	for(int i = 0; i + n < x; i++){
		if(b[n - i - 1] != b[n + i]){
			return 1;
		}
	}
	return 0;
}

void dfs(int lb, int dt, int dw){
	int is = che(lb);
	if(lb == 2 * n){
		flag = 1;
		return;
	}
	if(lb > n && is || dt > dw || flag){
		return;
	}
	b[lb] = a[dt];
	c[lb] = 1;
	dfs(lb + 1, dt + 1, dw);
	if(flag){
		return;
	}
	b[lb] = a[dw];
	c[lb] = 2;
	dfs(lb + 1, dt, dw - 1);
	if(flag){
		return;
	}
	c[lb] = 0;
	b[lb] = 0;
}

int main(){
	freopen("palin.in", "r", stdin);
	freopen("palin.out", "w", stdout);
	scanf("%d", &t);
	while(t--){
		flag = 0;
		scanf("%d", &n);
		for(int i = 0; i < n * 2; i++){
			scanf("%d", &a[i]);
		}
		dfs(0, 0, n * 2 - 1);
		if(!flag){
			printf("-1\n");
			continue;
		}
		for(int i = 0; i < n * 2; i++){
			if(c[i] == 1){
				printf("L");
			}
			else{
				printf("R");
			}
		}
		printf("\n");
	}
	return 0;
}
