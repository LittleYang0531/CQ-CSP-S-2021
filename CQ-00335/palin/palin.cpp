#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5+5;
int read() {
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-')f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9')x=x*10+c-'0',c=getchar();
	return x*f;
}
char ans1[maxn],ans2[maxn];
int n,a[maxn*2],p1[maxn],p2[maxn],t,shik;
bool pd;
void dfs(int L,int R,int l,int r,int stp) {
	if(pd)return;
//	if(++shik%1000000==0)cerr<<shik<<'\n';
	if(stp==n+1) {
		printf("%s%s\n",ans1+1,ans2+1);
		return pd=1,void();
	}
//	cout<<L<<' '<<R<<' '<<l<<' '<<r<<' '<<stp<<endl;
	if(!pd&&L<l-1&&a[L]==a[l-1])ans1[stp]='L',ans2[n-stp+1]='L',dfs(L+1,R,l-1,r,stp+1);
	if(!pd&&L<l&&r<R&&a[L]==a[r+1])ans1[stp]='L',ans2[n-stp+1]='R',dfs(L+1,R,l,r+1,stp+1);
	if(!pd&&r<R-1&&a[R]==a[r+1])ans1[stp]='R',ans2[n-stp+1]='R',dfs(L,R-1,l,r+1,stp+1);
	if(!pd&&r<R&&L<l&&a[R]==a[l-1])ans1[stp]='R',ans2[n-stp+1]='L',dfs(L,R-1,l-1,r,stp+1);
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	t=read();
	while(t--) {
		n=read(),pd=0;
		for(int i=1; i<=n; i++)p1[i]=p2[i]=0;
		ans1[n+1]=ans2[n+1]='\0';
		for(int i=1; i<=2*n; i++)a[i]=read(),(p1[a[i]]?p2[a[i]]:p1[a[i]])=i;
		ans1[1]='L',ans2[n]='L',dfs(2,2*n,p2[a[1]],p2[a[1]],2);
		if(!pd)ans1[1]='R',ans2[n]='L',dfs(1,n*2-1,p1[a[2*n]],p1[a[2*n]],2);
		if(!pd)puts("-1");
	}
	return 0;
}
//你是一个一个一个，一个一个一个哼哼啊啊啊啊啊啊啊啊啊啊啊啊啊1145141919810

