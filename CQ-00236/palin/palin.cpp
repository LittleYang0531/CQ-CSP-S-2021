#include<bits/stdc++.h>
#define N ((int)4e5+2)
#define nullptr 0
using namespace std;
inline void io(){cin.tie(nullptr),cout.tie(nullptr);}
int n,a[N],tmp[N];
bool ans[N],fg;
deque<int> q;
bool real_ans[N];
inline bool check(){
	for(int i=1;i<=n;++i) q.push_back(a[i]);
	for(int i=1;i<=n;++i){
		if(ans[i]) tmp[i]=q.front(),q.pop_front();
		else tmp[i]=q.back(),q.pop_back();
	}
	for(int i=1;i<=(n>>1);++i) if(tmp[i]!=tmp[n-i+1]) return false;
	return true;
}
inline void dfs(int p){
	if(fg) return;
	if(p==n+1){
		fg=check();
		if(fg) for(int i=1;i<=n;++i) real_ans[i]=ans[i];
		return;
	}
	ans[p]=true;
	dfs(p+1);
	ans[p]=false;
	dfs(p+1);
}
inline void freo(){freopen("palin.in","r",stdin),freopen("palin.out","w",stdout);}
signed main(){
	freo();
	io();
	int T;
	cin>>T;
	while(T--){
		fg=false;
		cin>>n;
		n<<=1;
		for(int i=1;i<=n;++i) scanf("%d",&a[i]);
		dfs(1);
		if(!fg) cout<<-1<<'\n';
		else for(int i=1;i<=n;++i) cout<<((real_ans[i])?'L':'R');
		cout<<'\n';
	}
return 0;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
