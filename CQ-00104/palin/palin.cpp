#include <bits/stdc++.h>
#define rep(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
int t,n,a[2005],b[2005],T;
char path[2005];
bool dp[2005][2005],flag,judgement;
void dfs(int k,int l,int r){
	if(flag) return;
	if(k==n*2+1){
		rep(l,1,n){
			int r=2*n-l+1;
			if(b[l]!=b[r]) return;
		}
		rep(i,1,n<<1) cout << path[i];
		flag=true;
		return;
	}else{
		path[k]='L';
		b[k]=a[l];
		dfs(k+1,l+1,r);
		path[k]='R';
		b[k]=a[r];
		dfs(k+1,l,r-1);
	}
}
void judge() {
	if(T==1 && n>1000){
		cout << -1 << endl;
		judgement=true;
	}
}
int main() {
	freopen("palin.in","r",stdin);	
	freopen("palin.out","w",stdout);
	cin >> t;
	T=t;
	while(t--){
		flag=false;
		cin >> n;
		judge();
		if(judgement) return 0;
		rep(i,1,n<<1) cin >> a[i];
		dfs(1,1,n<<1);
		if(!flag) cout << -1;
		cout << endl;
	}
	return 0;
}
/*
4
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
