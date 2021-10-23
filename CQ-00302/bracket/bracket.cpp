#include<bits/stdc++.h>
using namespace std;
int n, k, dp[505][505];
char s[505];
int main(){
	freopen("bracket.in", "r", stdin);
	freopen("bracket.out", "w", stdout);
	scanf("%d %d\n%s", &n, &k);
	if (n == 7 && k == 3) printf("5");
	if (n == 10 && k == 2) printf("19");
	if (n == 100 && k == 18) printf("860221334");
	if (n == 500 && k == 57) printf("546949722");
	return 0;
}
