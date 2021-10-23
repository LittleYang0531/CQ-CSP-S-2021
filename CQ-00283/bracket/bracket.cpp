#include <bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){ll a=0;int b=1;char c=getchar();while(c<'0'||c>'9'){if(c=='-')b=-1;c=getchar();}while(c>='0'&&c<='9'){a=(a<<1)+(a<<3)+(c^48);c=getchar();}return a*b;}
const int _ = 1e9 + 7;
const int MAX_N = 509;
int k,n;
string s;
int ans;
stack<bool> sta;
bool vis[MAX_N];
inline bool check(){
	bool f=0;
	while(sta.size()) sta.pop();
	for(int i=0;i<s.size();++i){
		if(s[i]=='('){
			if(i==0)sta.push(0);
			else if(s[i-1]=='*')sta.push(1);
			else sta.push(0);
		}
		if(s[i]==')'){
			bool t = sta.top();
			sta.pop();
			if(i!=s.size()-1&&s[i+1]=='*'&&t) return 0;
		}
	}
	return 1;
}
inline void dfs(int now,int cnt,int star){
	if(star > k) return;
	if(cnt > (n - now) || cnt < 0) return;
	if(now == n){
		if(!cnt && !star && check()) ans = (ans + 1) % _ ;//, cout << s << '\n';
		return;
	}
	if(s[now] == '(') dfs(now+1,cnt+1,0);
	else if(s[now] == ')') dfs(now+1,cnt-1,0);
	else if(now != 0 && s[now] == '*') dfs(now+1,cnt,star+1);
	else{
		s[now] = '(';
		dfs(now+1,cnt+1,0);
		if(now != 0) s[now] = ')';
		if(now != 0) dfs(now+1,cnt-1,0);
		if(now != 0) s[now] = '*';
		if(now != 0) dfs(now+1,cnt,star+1);
		s[now] = '?';
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n = read();
	k = read();
	cin >> s;
	dfs(0,0,0);
	printf("%d\n",ans);
	return 0;
}
