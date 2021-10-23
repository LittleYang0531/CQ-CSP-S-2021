#include<bits/stdc++.h>
using namespace std;
char s[100005];
int n,k,ans=0;
void dfs(int x){
	if(x==n+1){
		stack<int>ss;
		int rp=0;
		printf("%s\n",s+1);
		for(int i=1;i<=n;i++){
			if(s[i]=='('){
				ss.push(s[i+1]=='*');
			}
			if(s[i]==')'){
				if(ss.size()==0){
					return;
				}
				int u=ss.top();
				ss.pop();
				if(u==1&&s[i-1]=='*'){
					return;
				}
			}
			if(s[i]=='*'){
				rp++;
				if(rp>k)return;
			}else rp=0;
		}
		if(ss.size())return;
		ans++;
		return;
	} 
	if(s[x]=='?'){
		s[x]=')';
		dfs(x+1);
		s[x]='(';
		dfs(x+1);
		s[x]='*';
		dfs(x+1);
		s[x]='?';
	}else{
		dfs(x+1);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	scanf("%d%d",&n,&k);
	scanf("%s",s+1);
	if(s[1]=='?')s[1]='(';
	if(s[1]!='('){
		printf("0");
		return 0;
	}
	if(s[n]=='?')s[n]=')';
	if(s[n]!=')'){
		printf("0");
		return 0;
	}
	dfs(1);
	printf("%d\n",ans);
	return 0;
}
/*
7 3
(*??*??
*/

