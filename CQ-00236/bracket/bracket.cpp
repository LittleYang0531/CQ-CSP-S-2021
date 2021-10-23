#include<bits/stdc++.h>
#define N ((int)1e5+2)
#define nullptr 0
#define INF 0x3f3f3f3f
using namespace std;
int n,k;
inline void io(){cin.tie(nullptr),cout.tie(nullptr);}
char s[N];
int ans;
vector<int> v;
int vsize;
char ch[3]={'(',')','*'};
stack<int> stk;
inline bool check(){
	bool fg=true,fg2=true,fg3=true;
	while(!stk.empty()) stk.pop();
	for(int i=1;i<=n;++i){
		if(s[i]=='('){
			fg2=false;
			if(!stk.empty()&&stk.top()) stk.pop(),stk.push(-INF);
			stk.push(0),fg=true;
		}
		else if(s[i]=='*'){
			if(fg2) return false;
			if(stk.empty()){
				if(!fg3) return false;
				fg=false;
				if(s[i+1]!='*') fg3=false;
				continue;
			}
			int tmp=stk.top();
			if(tmp==-INF) return false;
			stk.pop();
			stk.push(tmp+1);
		}
		else if(s[i]==')'){
			if(stk.empty()) return false;
			int tmp=stk.top();
			if(tmp>k) return false;
			stk.pop();
		}
	}
	if(!stk.empty()||!fg) return false;
	return true;
}
inline void dfs(int p){
	if(p==vsize){
		ans+=check();
		return;
	}
	for(int i=0;i<3;++i){
		s[v[p]]=ch[i];
		dfs(p+1);
		s[v[p]]='?';
	}
}
inline void freo(){freopen("bracket.in","r",stdin),freopen("bracket.out","w",stdout);}
signed main(){
	freo();
	io();
	cin>>n>>k;
	scanf("%s",s+1);
	for(int i=1;i<=n;++i) if(s[i]=='?') v.push_back(i);
	vsize=v.size();
	dfs(0);
	cout<<ans<<'\n';
return 0;
}
/*
7 3
(*??*??
*/
/*
10 2
???(*??(?)
*/
