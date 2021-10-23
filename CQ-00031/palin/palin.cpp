#include<iostream>
#include<stdio.h>
#include<string.h>
using namespace std;
const int N=5e5+7;
inline int read(){
	int x=0,f=1;char ch=getchar();
	for(;(ch<'0'||ch>'9');ch=getchar()) if(ch=='-') f=-1;
	for(;(ch>='0'&&ch<='9');ch=getchar()) x=x*10+ch-'0';
	return x*f;
}
int a[N<<1];
char ans[N<<1];
int fl[N];
int b[N];
int rr;
int n,T;
int dfs(int now,int l,int r){
	int y=-1;
	if(now==2*n+1){
		for(int i=1;i<now;i++){
			printf("%c",ans[i]);
		}
		printf("\n");
		return 1;
	}
	if(now<=n){
		if(!fl[a[l]]){
			fl[a[l]]=1;
			ans[now]='L';
			b[++rr]=a[l];
			y=dfs(now+1,l+1,r);
			--rr;
			fl[a[l]]=0;
		}
		if(y==1) return 1;
		if(!fl[a[r]]){
			fl[a[r]]=1;
			ans[now]='R';
			b[++rr]=a[r];
			y=dfs(now+1,l,r-1);
			--rr;
			fl[a[r]]=0;
		}
		if(y==1) return 1;
	}
	else {
		if(b[rr]==a[l]){
			ans[now]='L';
			--rr;
			y=dfs(now+1,l+1,r);
			++rr;
		}
		if(y==1) return 1;
		if(b[rr]==a[r]){
			ans[now]='R';
			--rr;
			y=dfs(now+1,l,r-1);
			++rr;
		}
		if(y==1) return 1;
	}
	return 0;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		for(int i=1;i<=2*n;i++){
			a[i]=read();
		}
		memset(fl,0,sizeof(fl));
		if(dfs(1,1,2*n)==0){
			cout<<-1<<endl;
		}
	}
}
