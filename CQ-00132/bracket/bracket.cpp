#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
#define ll long long
const int MAXN=505,MOD=1e9+7;
int k,f_[MAXN][MAXN],g_[MAXN][MAXN];
char c[MAXN];
int f(int l,int r);
int g(int l,int r);
int f(int l,int r) {
	if(l>=r)return 0;
	if(f_[l][r]!=-1)return f_[l][r];
	if(c[l]==')'||c[l]=='*'||c[r]=='('||c[r]=='*')return f_[l][r]=0;
	if(l+1==r)return f_[l][r]=1;
	ll ans=0;
	if(r-l-1<=k) {
		int bj=1;
		for(int i=l+1; i<r; i++)if(c[i]!='?'&&c[i]!='*')bj=0;
		ans+=bj;
	}
	for(int i=r-1; i-l>1&&r-i<=k; i--) {
		if(c[i]!='?'&&c[i]!='*')break;
		ans+=f(l+1,i-1)+g(l+1,i-1);
	}
	for(int i=l+1; r-i>1&&i-l<=k; i++) {
		if(c[i]!='?'&&c[i]!='*')break;
		ans+=f(i+1,r-1)+g(i+1,r-1);
	}
	ans+=f(l+1,r-1)+g(l+1,r-1);
	return f_[l][r]=ans%MOD;
}
int g(int l,int r) {
	if(l>=r)return 0;
	if(g_[l][r]!=-1)return g_[l][r];
	if(c[l]==')'||c[l]=='*'||c[r]=='('||c[r]=='*')return g_[l][r]=0;
	if(l+1==r)return g_[l][r]=0;
	ll ans=0;
//	for(int i=l+1; i<r; i++)ans+=(ll)(f(l,i)+g(l,i))*(f(i+1,r))%MOD;
	for(int i=l+1; i<r; i++)ans+=(ll)f(l,i)*(f(i+1,r)+g(i+1,r))%MOD;
	for(int i=l+1; i<r; i++) {
		int temp=f(l,i);
		ll tem=0;
		if(temp==0)continue;
		for(int j=i+1; j<r; j++) {
			if(c[j]!='*'&&c[j]!='?')break;
			tem+=f(j+1,r)+g(j+1,r);
		}
		ans+=tem%MOD*temp%MOD;
	}
	return g_[l][r]=ans%MOD;
}
int n;
//char ch[MAXN];
//void dfs(int x) {
//	if(x>n) {
//		memset(f_,-1,sizeof(f_));
//		memset(g_,-1,sizeof(g_));
//		int ans=f(1,n)+g(1,n);
//		if(ans)
//			cout<<c+1<<":"<<ans<<endl;
//		if(ans!=1&&ans!=0)cerr<<"!"<<ans<<endl;
//		return;
//	}
//	if(ch[x]=='?') {
//		c[x]='*';
//		dfs(x+1);
//		c[x]='(';
//		dfs(x+1);
//		c[x]=')';
//		dfs(x+1);
//	} else {
//		c[x]=ch[x];
//		dfs(x+1);
//	}
//}
int main() {
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	cin>>n>>k>>(c+1);
	memset(f_,-1,sizeof(f_));
	memset(g_,-1,sizeof(g_));
	int ans=f(1,n)+g(1,n);
	cout<<ans%MOD<<endl;
	return 0;
}
