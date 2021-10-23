#include <bits/stdc++.h>
using namespace std;
int n,k,ans,sum[20];
string s;
bool flu(string s){
	for(int i=1;i<s.size()-1;i++){
		if(s[i]!='*') return 0;
	}
	return 1;
}
bool pd(string a){
	if(a.size()%2) return 0;
	if(a=="") return 0;
	if(a=="()") return 1;
	if(a[0]=='('&&a[a.size()-1]==')'){
		if((a.size()<=k-2&&flu(a))||pd(a)) return 1;
		int i;
		for(i=0;i<a.size();i++){
			if(a[i]!='*') break;
		}
		if(pd(a.substr(0,i))) return 1;
		for(i=a.size()-1;i>=0;i--){
			if(a[i]!='*') break;
		}
		if(pd(a.substr(0,i))) return 1;
		return 0;
	}
	for(int i=0;i<a.size();i++){
		if(a[i]=='*'){
			int j;
			for(j=i+1;j<a.size();j++){
				if(a[j]!='*') break;
			}
			if(pd(a.substr(0,i))&pd(a.substr(j,a.size()))) return 1;
		}
	}
	for(int i=1;i<a.size();i++){
		if(pd(a.substr(0,i))&&pd(a.substr(i,a.size()))) return 1;
	}
	return 0;
}
void dfs(int now){
	if(s[now]!='?') dfs(now+1);
	if(now==n){
		memset(sum,0,sizeof(sum));
		for(int i=1;i<=n;i++){
			sum[i]=sum[i-1]+(s[i]==')'?-1:1);
			if(sum[i]<0) return;
		}
		int last=1,i=1,fl=1;
		for(;;){
			if(i>n) break;
			while(s[i]=='*'){
				i++;
				if(i-last+1>k) return;
			}
			last=i;
		}
		ans++;
		return;
	}
	s[now]='(';
	dfs(now+1);
	s[now]=')';
	dfs(now+1);
	s[now]='*';
	dfs(now+1);
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin >> n >> k >> s;
	cout << pd(s) << endl;
	dfs(1);
	cout << ans;
	fclose(stdin);
	fclose(stdout);
	return 0;
}
