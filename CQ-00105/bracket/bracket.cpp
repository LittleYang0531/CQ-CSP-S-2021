#include<iostream>
#include<cstdio>
#include<cstring>
#include<cmath>
#include<algorithm>
#include<queue>
#define ll long long
using namespace std;

const int mod=1e9+7;
int n,k,f[505][505],g[505][505],v[505][505],vvi[505][505],vis[505][505];
int t[505][505],ans[505][505];
string s;
int read()
{
	int x=0,f=1;
	char ch=getchar();
	while(ch>'9'||ch<'0'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9'){
		x=(x<<3)+(x<<1)+ch-'0';
		ch=getchar();
	}
	return x*f;
}
inline int Mod(int x,int y){
	if(x+y>=mod)return x+y-mod;
	return x+y;
}
int F(int l,int r)
{
	if(l>=r)return 0;
	if(v[l][r])return f[l][r];
/*
	for(int k=l+1;k<r;k++){
		f[l][r]=Mod(f[l][r],1ll*F(l,k)*F(k+1,r)%mod);
//		if(l==1&&r==9)cout<<k<<" "<<F(l,k)<<" "<<F(k+1,r)<<"%\n";
	}
*/
//	if(l==1&&r==9)cout<<f[l][r]<<"%%%\n";
	for(int k=l+1;k<r;k++)
		for(int p=k+1;p<r;p++)
			if(g[k+1][p])f[l][r]=Mod(f[l][r],1ll*F(l,k)*F(p+1,r)%mod);
	v[l][r]=1;
	if(s[l]==')'||s[l]=='*'||s[r]=='('||s[r]=='*')
		return f[l][r];
	f[l][r]=Mod(F(l+1,r-1),f[l][r]);
	f[l][r]=Mod((r==l+1)?1:0,f[l][r]);
	if(l+1<=r-1){
		if(g[l+1][r-1])f[l][r]=Mod(f[l][r],1);
	}
	for(int k=l+1;k<r;k++){
		if(g[k+1][r-1])f[l][r]=Mod(f[l][r],F(l+1,k));
		if(g[l+1][k])f[l][r]=Mod(f[l][r],F(k+1,r-1));
//		if(l==4&&r==10)cout<<k<<" "<<F(k+1,r-1)<<" "<<g[l+1][k]<<"$$\n";
	}
	return f[l][r];
}
int T(int l,int r)
{
	if(l>=r)return 0;
	if(vvi[l][r])return t[l][r];
	for(int k=l+1;k<r;k++){
		t[l][r]=Mod(t[l][r],1ll*T(l,k)*F(k+1,r)%mod);
		t[l][r]=Mod(t[l][r],1ll*F(l,k)*F(k+1,r)%mod);
	}
	vvi[l][r]=1;
	return t[l][r];
}
int ANS(int l,int r)
{
	if(l>=r)return 0;
	if(vis[l][r])return ans[l][r];
	ans[l][r]=T(l,r);
	for(int k=l+1;k<r;k++)
		for(int p=k+1;p<r;p++)
			if(g[k+1][p])ans[l][r]=Mod(ans[l][r],1ll*ANS(l,k)*ANS(p+1,r)%mod);
	vis[l][r]=1;
	if(s[l]==')'||s[l]=='*'||s[r]=='('||s[r]=='*')
		return ans[l][r];
	ans[l][r]=Mod(ANS(l+1,r-1),ans[l][r]);
	ans[l][r]=Mod((r==l+1)?1:0,ans[l][r]);
	if(l+1<=r-1){
		if(g[l+1][r-1])ans[l][r]=Mod(ans[l][r],1);
	}
	for(int k=l+1;k<r;k++){
		if(g[k+1][r-1])ans[l][r]=Mod(ans[l][r],ANS(l+1,k));
		if(g[l+1][k])ans[l][r]=Mod(ans[l][r],ANS(k+1,r-1));
	}
	return ans[l][r];
}
int main()
{
	freopen("bracket.in","r",stdin);
	freopen("bracket.out","w",stdout);
	n=read();
	k=read();
	cin>>s;
	s=' '+s;
	for(int i=1;i<=n;i++)
		for(int j=i;j<=n;j++)g[i][j]=1;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='('||s[i]==')')g[i][i]=0;
		for(int j=i+1;j<=n;j++){
			if(s[j]=='('||s[j]==')')g[i][j]=0;
			if(j-i+1>k)g[i][j]=0;
			g[i][j]&=g[i][j-1];
		}
	}
	cout<<ANS(1,n);
	return 0;
}
/*
7 3
(*??*??

10 2
???(*??(?)
*/
