#include<bits/stdc++.h>
using namespace std;
#define N 1000005
#define gc() (p1==p2&&(p2=(p1=buf)+fread(buf,1,1<<21,stdin),p1==p2)?EOF:*p1++)
char buf[1<<21],*p1=buf,*p2=buf;
inline int rd(){
	int x=0;char c=gc();
	for(;c<'0'||c>'9';c=gc());
	for(;c>='0'&&c<='9';c=gc()) x=x*10+c-48;
	return x;
}int n,a[N],b[N],c[N],mk,us[N];
void dfs(int x,int l,int r){
	if(x>=n) if(us[b[x+1]]>1) return;
	if(x<n) if(b[x+1]!=b[2*n-x]) return;
	if(!x){
		for(int i=1;i<=n*2;i++) c[i]==1?putchar('L'):putchar('R');
		mk=1;return;
	}if(mk) return;
	b[2*n-x+1]=a[l];c[2*n-x+1]=1;us[a[l]]++;
	dfs(x-1,l+1,r);us[a[l]]--;
	if(mk) return;
	b[2*n-x+1]=a[r];c[2*n-x+1]=2;us[a[r]]++;
	dfs(x-1,l,r-1);us[a[r]]--;
}int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	int T;T=rd();
	while(T--){
		n=rd();
		for(int i=1;i<=n*2;i++) a[i]=rd();
		mk=0;dfs(2*n,1,n*2);
		mk?puts(""):puts("-1");
	}return 0;
}
