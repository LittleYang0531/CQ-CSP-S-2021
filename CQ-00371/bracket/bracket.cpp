#include<bits/stdc++.h>
#define ll long long
using namespace std;
inline ll read(){
	ll x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9'){if(ch=='-')f=-1;ch=getchar();}
	while(ch>='0'&&ch<='9'){x=x*10+ch-'0';ch=getchar();}
	return x*f;
}
int n,k;
string s;
string p;
int ans=0;
inline void pd(){
	//stack<char> st;
	int kcnt=0,xcnt;
	for(int i=0;i<p.size();i++){
		if(p[i]=='*'&&kcnt==0)return;
		if(p[i]=='(')kcnt++,xcnt=0;
		if(p[i]==')')kcnt--,xcnt=0;
		if(p[i]=='*')xcnt++;
		if(xcnt>k)return;
	}
	if(kcnt!=0||xcnt!=0)return;
	cout<<p<<endl;
	ans++;
}
void dfs(int i){
	if(i==n){
		pd();
		return;
	}
	if(s[i]!='?'){
		dfs(i+1);
		return;
	}
	if(s[i]=='?')
	for(int j=0;j<=2;j++){
		if(j==0)p[i]='*';
		else if(j==1)p[i]='(';
		else p[i]=')';
		dfs(i+1);
	}
}
ll fuc(int x){
	int s=1;
	for(int i=1;i<=n;i++)s*=i;
	return s;
}
int main(){
	ios::sync_with_stdio(0);
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>s;
	p=s;
	//cout<<p<<" "<<s<<" "<<n<<" "<<k;
	dfs(0);
	cout<<ans;
}
