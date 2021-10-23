#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;(ch<'0'||ch>'9');ch=getchar()) if(ch=='-') f=-1;
	for(;(ch>='0'&&ch<='9');ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
int n,k;
int ans;
int q[30],cnt;
int fank[30];
string a;
inline int check(){
	int pq=0;cnt=0;
	memset(fank,0,sizeof(fank));
	for(int i=a.length()-1;i>=0;i--){
		if(a[i]==')') fank[i]=fank[i+1]+1;
		else fank[i]=fank[i+1];
	}
	for(int i=0;i<a.length();i++){
		if(a[i]=='*'){
			++pq;
			if(pq>k) return 0;
		}
		else {
			pq=0;
			if(a[i]=='('){
				q[++cnt]=i;
			}
			if(a[i]==')'){
				if(a[i+1]=='*'&&a[q[cnt]-1]=='*') return 0;
				if(a[q[cnt]-1]=='*'&&cnt==1) return 0;
				if(a[i+1]=='*'&&fank[i+1]==0) return 0;
				--cnt;
			}
		}
	}
	if(cnt!=0) return 0;
	return 1;
}
void dfs(int now){
	if(now==a.length()){
		ans+=check();
		return;
	}
	if(a[now]!='?') {
		dfs(now+1);
	}
	else {
		a[now]='(';
		dfs(now+1);
		a[now]='*';
		dfs(now+1);
		a[now]=')';
		dfs(now+1);
	}
}
int main(){
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read(),k=read();
	cin>>a;
	dfs(0);
	cout<<ans;
}
