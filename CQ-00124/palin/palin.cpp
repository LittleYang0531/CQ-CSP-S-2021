#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
#include <algorithm>
using namespace std;

const int N = 1000005;
int tmpwei[N][2];
int numans[N];
int wei[N];
bool ans[N];
bool wse[N];
int a[N];
int n,m;

inline void showans(){
	for(int k=1;k<=m;k++)
		putchar(ans[k]?'R':'L');
	putchar('\n');
}

inline bool getans(int l,int r){
	for(int k=2;k<=n;k++){
		if(!wse[l]&&(wse[wei[l]+1]||wse[wei[l]-1])){
			numans[k] = a[l];
			ans[k] = false;
			wse[wei[l]] = true;
			l++;
		}
		else if(!wse[r]&&(wse[wei[r]+1]||wse[wei[r]-1])){
			numans[k] = a[r];
			ans[k] = true;
			wse[wei[r]] = true;
			r--;
		}
		else
			return false;
	}
	for(int k=n+1;k<=m;k++){
		if(a[l]==numans[2*n-k+1]){
			ans[k] = false;
			l++;
		}
		else if(a[r]==numans[2*n-k+1]){
			ans[k] = true;
			r--;
		}
	}
	return true;
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int q;
	scanf("%d",&q);
	while(q--){
		scanf("%d",&n);
		for(int k=1;k<=n;k++)
			tmpwei[k][0] = tmpwei[k][1] = 0;
		memset(ans,false,sizeof(ans));
		m = n<<1;
		for(int k=1;k<=m;k++){
			scanf("%d",a+k);
			if(!tmpwei[a[k]][0])
				tmpwei[a[k]][0] = k;
			else
				tmpwei[a[k]][1] = k;
		}
		for(int k=1;k<=n;k++){
			wei[tmpwei[k][0]] = tmpwei[k][1];
			wei[tmpwei[k][1]] = tmpwei[k][0];
		}
		memset(wse,false,sizeof(wse));
		ans[1] = false;
		wse[wei[1]] = true;
		numans[1] = a[1];
		if(getans(2,m)){
			showans();
			continue;
		}
		memset(wse,false,sizeof(wse));
		ans[1] = true;
		wse[wei[m]] = true;
		numans[1] = a[m];
		if(getans(1,m-1)){
			showans();
			continue;
		}
		puts("-1");
	}
	return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3

1
20
2 10 13 6 15 5 20 12 1 18 8 9 11 14 17 17 14 11 9 8 18 16 4 12 20 5 19 15 7 6 13 10 2 1 3 3 16 4 19 7
*/
