#include<iostream>
#include<stdio.h>
#include<algorithm>
#include<string.h>
#include<math.h>
#define maxn 500005
using namespace std;
inline int read(){
	register int x=0,f=1;
	register char c=getchar();
	while(c<'0' or c>'9'){
		if(c=='-') f=-1;
		c=getchar();
	}
	while(c>='0' and c<='9') x=(x<<3)+(x<<1)+c-'0',c=getchar();
	return x*f;
}
int T,n;
int head=1,tail=0;
int a[maxn],b[maxn];
int queue[maxn*2];
char f[maxn];
bool flag=false;
bool check(int a[]){
	for(int i=1;i<=n;i++) if(a[i]!=a[2*n+1-i]) return false;
	return true;
}
void dfs(int k){
	if(k==n*2+1){
		if(check(b)){
			for(int i=1;i<=n*2;i++) printf("%c",f[i]);
			flag=true;
		}
		return;
	}
	b[k]=queue[head];
	head++;
	f[k]='L';
	dfs(k+1);
	head--;
	if(flag==true) return;
	
	b[k]=queue[tail];
	tail--;
	f[k]='R';
	dfs(k+1);
	tail++;
	if(flag==true) return;
}
int main(){
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--){
		n=read();
		flag=false;
		for(int i=1;i<=n*2;i++){
			a[i]=read();
			queue[++tail]=a[i];
		}
		dfs(1);
		if(flag==false) printf("-1");
		else printf("\n");
	}
	return 0;
}
