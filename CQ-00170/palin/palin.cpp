#include<bits/stdc++.h>
using namespace std;
const int maxn=5e5*2;
int t,n,a[maxn],b[maxn];
string s;
inline bool check(){
	for(int i=1;i<=n;i++)
		if(b[i]!=b[2*n+1-i])
			return 0;
	return 1;
}
inline bool dfs(int now,int l,int r){
	if(now>2*n)
		return 1;
	if(now<=n||(now>n&&a[l]==b[2*n+1-now])){
		b[now]=a[l];
		if(dfs(now+1,l+1,r)){
			s+='L';
			return 1;
		}
	}
	if(now<=n||(now>n&&a[r]==b[2*n+1-now])){
		b[now]=a[r];
		if(dfs(now+1,l,r-1)){
			s+='R';
			return 1;
		}
	}
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	for(int i=1;i<=t;i++){
		s="\0";
		scanf("%d",&n);
		for(int i=1;i<=2*n;i++)
			scanf("%d",&a[i]),b[i]=0;
		if(dfs(1,1,2*n)){
			for(int i=1;i<=2*n;i++)
				putchar(s[i]);
		} else
			putchar('-'),putchar('1');
		putchar('\n');
	}
	return 0;
}
