#include<bits/stdc++.h>
using namespace std;
#define maxn 1005
int t,n;
bool flag;
string ans;
string a[maxn];
void dfs(string s,int l,int r,string caozuo);
bool check(string s);
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	cin>>t;
	while(t--){
		string test;
		flag=0;	
		cin>>n;
		for(int i=1;i<=n*2;i++){
			cin>>a[i];
			test+=a[i];
		}
		if(check(test)==1){
			for(int i=1;i<=2*n;i++){
				cout<<"L";
			}
			continue;
		}
		if(n<10){
			string s,caozuo;
			dfs(s,1,n*2,caozuo);
			if(flag==0){
				cout<<"-1"<<endl;
			}
		}
	}
	return 0;
}
void dfs(string s,int l,int r,string caozuo){
	if(flag==1){
		return;
	}
	if(l>r){
		if(check(s)==1){
			cout<<caozuo<<endl;
			flag=1;
			return;
		}
		return;
	}
	dfs(s+a[l],l+1,r,caozuo+"L");	
	dfs(s+a[r],l,r-1,caozuo+"R");	
}
bool check(string s){
	for(int i=0,j=s.length()-1;i<j;i++,j--){
		if(s[i]!=s[j]){
			return 0;
		}
	}
	return 1;
}
/*
2
5
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
