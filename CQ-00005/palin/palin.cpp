#include<bits/stdc++.h>
using namespace std;
int T,n,o,a[30],L,R,p[30],t[30];char s[30],ans[30];
void dfs(int x){
	if(x==2*n+1){
		for(int i=1;i<=n;i++)
		if(p[i]!=p[2*n-i+1])return;
		if(o){
			for(int i=1;i<=2*n;i++){
				if(t[i]<p[i])return;
				if(t[i]>p[i])break;
			}	
		}
		for(int i=1;i<=2*n;i++)
		ans[i]=s[i],t[i]=p[i];
		o=1;return;
	}
	p[x]=a[++L];s[x]='L';dfs(x+1);L--;
	p[x]=a[--R];s[x]='R';dfs(x+1);R++;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	for(scanf("%d",&T);T--;){
		scanf("%d",&n);o=0;L=0,R=2*n+1;
		for(int i=1;i<=n*2;i++)
		scanf("%d",a+i);
		dfs(1);
		if(!o)puts("-1");
		else printf("%s",ans+1);
	}
	return 0;
}

