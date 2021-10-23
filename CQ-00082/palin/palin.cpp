#include <bits/stdc++.h>
#define int long long
using namespace std;
int t, n, a[100005], ans[100005], pd;
string qwq;
void check(string now){
//	for(int i = 1; i <= 2*n; ++i)
//		cout<<ans[i]<<" ";
//	cout<<"\n"<<now<<"\n";
	for(int i = 1; i <= 2*n; ++i)
		if(ans[i] != ans[2*n-i+1])
			return ;
	qwq=min(qwq,now);
}
void dfs(int l, int r, int x, string now){
	if(x == 2*n){
		ans[x]=a[l];
		now+="L";
		check(now);
		return ;
	}
	ans[x]=a[l];
	dfs(l+1,r,x+1,now+"L");
	ans[x]=a[r];
	dfs(l,r-1,x+1,now+"R");
}
signed main() {
	freopen("palin2.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		qwq = "ZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZZ";
		scanf("%d",&n);
		for(int i = 1; i <= n*2; ++i)
			scanf("%d",&a[i]);
		dfs(1,n*2,1,"");
		
		if(qwq.size() == 2*n)
			cout<<qwq<<"\n";
		else
			cout<<-1<<"\n";
	}
	return 0;
}
