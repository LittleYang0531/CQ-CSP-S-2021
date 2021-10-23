#include<bits/stdc++.h>
#define ll long long
#define pii pair<int,int>
#define fi first
#define se second
using namespace std;
const int N=5e5+5;
inline int read(){
	int x=0,f=1;
	char c=getchar();
	while(c<'0'||c>'9') {
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0'&&c<='9') {
		x=(x<<1)+(x<<3)+c-'0';
		c=getchar();
	}
	return x*f;
}
int T,n,a[N],flg,s[N];
char ans[N];
bool check() {
	for(int i=1;i<=n/2;i++) {
		if(s[i]!=s[n-i+1]) return 0;
	}
	return 1;
}
void dfs(int l,int r,int x) {
	if(flg) return;
	//¼ôÖ¦ 
	if(x>n/2+1&&s[x-1]!=s[n-x+2]) {
		return;
	}
	if(l>r) {
		flg=1;
		return;
	}
	s[x]=a[l];
	ans[x]='L';
	dfs(l+1,r,x+1);
	if(flg) return;
	s[x]=a[r];
	ans[x]='R';
	dfs(l,r-1,x+1);
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--) {
		flg=0;
		n=read(); n<<=1;
		for(int i=1;i<=n;i++) a[i]=read();
		dfs(1,n,1);
		if(flg){
			for(int i=1;i<=n;i++) printf("%c",ans[i]);
			printf("\n");
		}
		else printf("-1\n");
	}
}
