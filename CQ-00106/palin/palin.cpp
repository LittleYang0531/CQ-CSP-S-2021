#include<bits/stdc++.h>
using namespace std;

int T,n,a[1000005],b[1000005],flag=0;
string res;

bool Check(string s){
	int l=1,r=2*n,cnt=0;
	for(int i=0;i<s.size();i++){
		if(s[i]=='L') b[++cnt]=a[l++];
		else b[++cnt]=a[r--];
	}
	for(int i=1;i<=cnt;i++){
		if(b[i]!=b[cnt-i+1]) return false;
 	}
 	return true;
}

bool can(string s1,string s2){
	bool flag=0;
	for(int i=0;i<s1.size();i++){
		if(s1[i]>s2[i]) return false;
		if(s1[i]!=s2[i]) flag=1;
	}
	return flag;
}

void dfs(int i,string s){
	if(i>=2*n){
		if(Check(s)){
			if(!flag) res=s,flag=1;
			else if(can(s,res)) res=s;
		}
		return ;
	}
	dfs(i+1,s+"L");
	dfs(i+1,s+"R");
}

int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&T);
	while(T--){
		flag=0;
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++) scanf("%d",&a[i]);
		dfs(0,"");
		if(flag) cout<<res<<endl;
		else puts("-1");
	}
	return 0;
}
