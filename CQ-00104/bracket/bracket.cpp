#include <bits/stdc++.h>
#define ll long long
#define rep(i,l,r) for(int i=l;i<=r;i++)
using namespace std;
const int mod=1e9+7;
char a[505],b[505];
int n,k,tot;
ll ans;
void dfs(int x){
	//cout << x << endl;
	if(x==n+1){
		stack <char> s;
		int lionstar=1;//连续的'*'数量 
		rep(i,1,n){
			if(b[i]=='*' && b[i-1]=='*'){
				lionstar++;
			}
		//	cout << lionstar << ":" << b[i] << " ";
			if(lionstar>k) {return;}
			if(b[i]=='('){
				lionstar=1;
				s.push('(');
			}else if(b[i]==')'){
				lionstar=1;
				if(b[i-2]=='*' && b[i-1]=='(' && b[i+1]=='*') return;
				if(s.empty()) {return;}
				else s.pop();
			}
		}
		if(s.empty()){
			++ans;
			ans%=mod;
			//rep(i,1,n) cout << b[i];
			//cout << endl;
		}
		return;
	}else{
		if(a[x]=='?'){
			if(x==1) b[x]='(',dfs(x+1);
			else if(x==n) b[x]=')',dfs(x+1);
			else{
				b[x]='*',dfs(x+1);
				b[x]='(',dfs(x+1);
				b[x]=')',dfs(x+1);
			}	
		}else b[x]=a[x],dfs(x+1);
	}
}
int main() {
	freopen("bracket.in","r",stdin);	
	freopen("bracket.out","w",stdout);
	cin >> n >> k;
	rep(i,1,n) cin >> a[i];
	rep(i,1,n) if(a[i]=='?') ++tot;
	if(tot<30) dfs(1);
	cout << ans << endl;
	return 0;
}

//10 2 ???(*??(?)

