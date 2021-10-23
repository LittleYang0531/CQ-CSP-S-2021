#include<bits/stdc++.h>
using namespace std;
string s;
stack<int> stk;
int n,k,sum;
bool check(string s);
int zuhe(string s,int i,int xinghao);
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k;
	cin>>s;
	for(int i=2;i<n-1;i++){
		if(s[i]=='?'){
			sum++;
		}
	}
	s[0]='(',s[n-1]=')';
	cout<<zuhe(s,sum,0);
	return 0;
}
int zuhe(string s,int i,int xinghao){
	if(i==0){
		if(check(s)==1){
			return 1;
		}else{
			return 0;
		}
	}
	int ans=0;
	for(int j=1;j<n-1;j++){
		if(s[j]=='?'){
			if(xinghao<k){
				s[j]='*';
				ans+=zuhe(s,i-1,xinghao+1);
			}
			s[j]='(';
			ans+=zuhe(s,i-1,xinghao);
			s[j]=')';
			ans+=zuhe(s,i-1,xinghao);
			break;
		}
	}
	return ans;
}
bool check(string s){
	int i=0,sumxing=0;
	while(i<n){
		if(s[i]=='('){
			stk.push(s[i]);
		}else if(s[i]==')'){
			if(stk.empty()){
				return 0;
			}else{
				stk.pop();
			}
		}else{
			sumxing++;
		}
		i++;
	}
	if(stk.empty()&&sumxing<=k){
		return 1;
	}else{
		while(!stk.empty()){
			stk.pop();
		}
		return 0;
	}
}

