#include<bits/stdc++.h>
using namespace std;
string s;
string ts;
int n,K;
const int maxn=50;
int st[maxn];
int ans=0;
int sta[maxn],tp=0,ct=0,yct=0;
void dfs(int now){
//	cout<<ts<<endl;
	if(now==s.size()){
//		cout<<ts<<endl;
		int sz=0;
		int cnt=0; 
		if((ts[0]!='('&&ts[0]!='?')||(ts[ts.size()-1]!=')'&&ts[ts.size()-1]!='?'))return ;
		for(int i=0;i<ts.size();i++){
			if(ts[i]=='*'){
				cnt++;
				continue;
			}
			if(cnt>K){
				return ;
			}
			if(ts[i]=='('){
				cnt=0;	
				st[++sz]=0;
				i++; 
				while(ts[i]=='*')st[sz]++,i++;
				i--;
				if(st[sz]>K)return ;
			}
			else{
				if(cnt&&st[sz]){ 
					return ;
				}
				cnt=0;
				sz--;
				if(sz<0)return ;
			}
		} 
		if(sz!=0)return ; 
		ans++;
		return ;
	}
	yct=ct;
	if(s[now]=='?'){ 
		ts[now]='*'; 
		ts[now]='(';
		tp++;
		ct=0; 
		dfs(now+1);
		tp--;
		ct=yct;  
		ts[now]=')';
		if(tp==0)return ;
		tp++; 
		ct=0;
		dfs(now+1);
		tp--;
		ct=yct; 
	}
	else{
		if(s[now]=='('){
			tp++;
			ct=0;
		}
		else if(s[now]==')'){
			ct=0;
			tp--;
			if(tp<0){
				tp++;
				return ;
			}
		}
		else{
			ct++;
		}
		dfs(now+1); 
		if(s[now]=='('){ 
			ct=yct;
			tp--;
		}
		else if(s[now]==')'){
			ct=yct;
			tp++; 
		}
		else{
			ct--;
		}
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	ans=0; 
	tp=0;ct=0;yct=0;
	cin>>n>>K;
	cin>>s;
	ts=s;
	ct=0;
	dfs(0); 
	cout<<ans<<endl;
	return 0;
}
