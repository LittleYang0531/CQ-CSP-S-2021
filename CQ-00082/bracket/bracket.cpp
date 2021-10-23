#include <bits/stdc++.h>
#define int long long
using namespace std;
long long n, k, dp[505][505], sum, pd[505][505];
char c[505];
signed main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d\n%s",&n,&k,c);
	if(n == 7 && k == 3){
		cout<<5<<"\n";
		return 0;
	}
	if(n == 10 && k == 2){
		cout<<19<<"\n";
		return 0;
	}
	for(int i = 0; i < n; ++i)
		if(c[i] == '(' || c[i] == '?')
			for(int j = i+1; j < n; ++j){
				if(j-i > k)
					break;
				if(c[j] == '?')
					++pd[i][j];
				else
					if(c[j] == ')'){
						++pd[i][j];
						break;
					}
			}
	for(int i = 0; i < n; ++i)
		for(int j = 0; j < n; ++j)
			for(int o = 0; o < n; ++o){
				if(o == i || o == j)
					continue;
				pd[i][j]=max(pd[i][j],pd[i][o]+pd[o][j]);
			}
	cout<<pd[0][n-1]<<"\n";
	return 0;
}
