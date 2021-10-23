#include<bits/stdc++.h>
using namespace std;
const int mod=1e9+7;
int n,k,sx[502],ans=0;
string s;
inline void dfs(int pos){
	if(pos>sx[0]){
		stack< pair<char,int> > stk;
		int gs=0,flag=0;
		if(s[0]!='('||s[n-1]!=')') return;
		for(int i=0;i<n;i++){
			if(s[i]=='('||s[i]=='*') stk.push(make_pair(s[i],i));
			if(s[i]=='(') flag=0;
			if(s[i]==')'){
				int num=0;
				while(!stk.empty()&&stk.top().first!='('){
					num++,stk.pop();
				}
				if(stk.empty()||num>k) return;
				if(s[stk.top().second+1]=='*'&&s[i-1]=='*'&&flag) return;
				if(!stk.empty()) stk.pop();
				flag=1;
			}
		}
		int num=0;
		while(!stk.empty()){
			if(stk.top().first!='*') return;
			stk.pop();num++;
		}
		if(num>k) return;
		ans++,ans%=mod;
		return;
	}
	s[sx[pos]]='(';dfs(pos+1);
	s[sx[pos]]=')';dfs(pos+1);
	s[sx[pos]]='*';dfs(pos+1);
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d %d",&n,&k);
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='?') sx[++sx[0]]=i;
	}
	dfs(1);
	printf("%d",ans);
	return 0;
}
