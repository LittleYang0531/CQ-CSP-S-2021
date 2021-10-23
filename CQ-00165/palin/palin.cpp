#include <bits/stdc++.h>
using namespace std;
int t,n;
int a[1000010];
int ans[1000010];
string answ;
bool check(int x){
	for(int i=1;i<=n;i++){
		if(ans[i]!=ans[n+n-i+1]){
			return false;
		}
	}
	return true;
}
void dfs(int l,int r,string s,int ansr){
	if(ansr==n+n+1&&check(ansr)){
		if(answ==""){
			answ=s;
			return;
		}
		answ=min(answ,s);
		return;
	}
	if(l>n+n||l>r){
		return;
	}
	if(r<0||r<l){
		return;
	}
	ans[ansr]=a[l];
	dfs(l+1,r,s+'L',ansr+1);
	ans[ansr]=a[r];
	dfs(l,r-1,s+'R',ansr+1);
}
void solve(){
	cin>>n;
	for(int i=1;i<=n+n;i++){
		cin>>a[i];
	}
	dfs(1,n+n,"",1);
	if(answ==""){
		puts("-1");
	}
	else{
		cout<<answ<<endl;	
	}
	answ="";
	memset(ans,0,sizeof(ans));
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
