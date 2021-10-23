#include<bits/stdc++.h>
using namespace std;
int t,l,n,p;
string a,b,r;
bool f;
void dfs(int layer,int a1,int a2,string s,string m){
	if(layer == 2*n){
		if(m[0] != m[2*n-1])
			return;
		printf("%s\n",s.c_str());
		f = 0;
		return;
	}
	if(layer-1 >= n)
		if(m[layer-1] != m[2*n-layer])
			return;
	if(f)
		dfs(layer+1,a1+1,a2,s+'L',m+a[a1]);
	if(f)
		dfs(layer+1,a1,a2-1,s+'R',m+a[a2]);
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	scanf("%d",&t);
	while(t--){
		a.clear();
		r.clear();
		b.clear();
		scanf("%d",&n);
		for(int i = 0;i < 2*n;i++){
			scanf("%d",&l);
			a += char(l+'0');
		}
		f = 1;
		dfs(0,0,2*n-1,r,b);
		if(f)
			printf("-1\n");
	}	
	return 0;
}

