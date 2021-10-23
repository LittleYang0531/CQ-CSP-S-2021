#include<bits/stdc++.h>
using namespace std;
int T,n,a[1000005],w[1000005],t[1000005],c[1000005],b[1000005],ans[1000005],bj=0;
int read(){
	int w=0;
	char c=getchar();
	while(c<'0'||c>'9') c=getchar();
	while(c>='0'&&c<='9'){
		w=w*10+c-'0';
		c=getchar(); 
	}
	return w;
}
int print(){
//	for(int i=1;i<=n;i++) cout<<ans[i];
	int l=1,r=n*2;
	for(int i=n;i>=1;i--){
		while(t[l]) l++;
		while(t[r]) r--;
		if(a[l]==ans[i]){
			cout<<'L';
			t[l]=1;
		}
		else{
			cout<<'R';
			t[r]=1;
		}
	}
	cout<<endl;
}
int dfs(int x,string s,int l,int r,int c){ 
	if(bj) return 0;
	int L,R;
	ans[c]=a[x];
	if(c==n){
		bj=1;
		cout<<s;
		print();
		return 0;
	}
	c++;
	while(t[l]) l++;
	while(t[r]) r--;
	
	L=x-1;R=x+1;
	while(b[L]||t[L]) L--;
	while(b[R]||t[L]) R++;
//	cout<<x<<" "<<s<<" "<<l<<" "<<r<<" "<<L<<" "<<R<<" "<<w[L]<<" "<<w[R]<<endl;
	b[x]=1;
	
	t[w[L]]=1;
	if(w[L]==l) dfs(L,s+'L',l,r,c);
	t[w[L]]=0;
	
	t[w[R]]=1;
	if(w[R]==l) dfs(R,s+'L',l,r,c);
	t[w[R]]=0;
	
	t[w[L]]=1;
	if(w[L]==r) dfs(L,s+'R',l,r,c);
	t[w[L]]=0;
	
	t[w[R]]=1;
	if(w[R]==r) dfs(R,s+'R',l,r,c);
	t[w[R]]=0;
	
	b[x]=0;
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		memset(t,0,sizeof(t));
		memset(b,0,sizeof(b));
		memset(w,0,sizeof(w));
		memset(c,0,sizeof(c));
		bj=0;
		n=read();
		for(int i=1;i<=n*2;i++){
			a[i]=read();
			if(c[a[i]]){
				w[i]=c[a[i]];
				w[c[a[i]]]=i;
			}
			else c[a[i]]=i;
		}
//		for(int i=1;i<=n*2;i++) cout<<w[i]<<" "; 
		t[1]=1;
		dfs(w[1],"L",1,n*2,1);
		t[1]=0;
		t[n*2]=1;
		dfs(w[n*2],"R",1,n*2,1);
		t[n*2]=0;
		if(bj==0) cout<<-1<<endl;
	}
}
