#include<iostream>
#include<cstdio>
#include<cmath>
#include<cstring>
#include<algorithm>
#define int long long
using namespace std;
inline int read(){
	int s=0,f=1;
	char ch=getchar();
	while(ch<'0'||ch>'9'){
		if(ch=='-')f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9')
		s=(s<<1)+(s<<3)+(ch^48),ch=getchar();
	return s*f;
}
inline void write(int x){
	if(x<0)putchar('-'),x=-x;
	if(x>9)write(x/10);
	putchar(x%10+48);
}
int t,n,a[1000001],b[1000001],dbj=0;
bool palin(string s){
	memset(b,0,sizeof(b));
	int l=0,r=2*n;
	for(int i=0;i<s.length();i++)
	if(s[i]=='L')b[i+1]=a[++l];
	else b[i+1]=a[r--];
	for(int i=1;i<=n;i++)
	if(b[i]!=b[2*n+1-i])return 0;
	return 1;
}
void dfs(string s,int l,int r){
	if(dbj==1)return ;
	if(r==l)
	if(palin(s)){
		cout<<s<<endl,dbj=1;
		return ;
	}
	if(l<r){
	dfs(s+'L',l+1,r);
	dfs(s+'R',l,r-1);
	}
}
signed main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--){
		n=read(),dbj=0;
		for(int i=1;i<=n*2;i++)a[i]=read();
		dfs("",0,2*n);
		if(dbj==0)puts("-1");
		for(int i=1;i<=n*2;i++)a[i]=0;
	}
	return 0;
}
