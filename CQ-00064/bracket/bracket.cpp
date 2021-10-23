#include<bits/stdc++.h>
#define mod 1000000007
#define int long long
using namespace std;
int n,k;
int a[105];
int ans;
string s;
inline void dfs(int x){
	if(x==n){
		int l=0,r=0,num=0,smax=0;
		for(int i=0;i<n;i++){
			if(a[i]==1){
				smax=max(smax,num);
				num=0;
				l++;
			}
			if(a[i]==2){
				smax=max(smax,num);
				num=0;
				r++;
			}
			if(a[i]==3)num++;
			if(l<r)return;
			if(smax>k)return;
		} 
		//cout<<l<<" "<<r<<endl;
		if(l!=r)return;
		/*for(int i=0;i<n;i++){
			if(a[i]==1)cout<<"(";
			else if(a[i]==2)cout<<")";
			else cout<<"*";
		}
		cout<<endl;*/
		ans++;
		ans%=mod;
		return;
	}
	if(s[x]!='?'){
		if(s[x]=='(')a[x]=1;
		if(s[x]==')')a[x]=2;
		if(s[x]=='*')a[x]=3;
		dfs(x+1);
	}else{
		a[x]=1;
		dfs(x+1);
		a[x]=2;
		dfs(x+1);
		a[x]=3;
		dfs(x+1);
	}
}
signed main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	std::ios::sync_with_stdio(false);
	cin.tie(0),cout.tie(0);
	cin>>n>>k;
	cin>>s;
	dfs(0);
	cout<<ans/2;
	return 0;
}
