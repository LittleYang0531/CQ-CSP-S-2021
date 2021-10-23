#include <bits/stdc++.h>
using namespace std;
const int mxn=1e6;
int T,n,lt,rt,flag,a[mxn],b[mxn];
char s[mxn];
int read() {
	int x=0,f=1;char ch=getchar();
	while(ch<'0'||ch>'9') {
		if(ch=='-') f=-1;
		ch=getchar();
	}
	while(ch>='0'&&ch<='9') {
		x=(x<<1)+(x<<3)+(ch^48);
		ch=getchar();
	}
	return x*f;
}
int check() {
//	for(int i=1;i<=2*n;i++) printf("%d ",b[i]);
	for(int i=1;i<=n;i++) if(b[i]!=b[2*n-i+1]) return 0;
	return 1;
}
void work(int t) {
	if(t==2*n+1) {
		if(check()) flag=1;
		return ;
	}
	b[t]=a[lt++],s[t]='L';
	work(t+1);
	if(flag==1) return ;
	s[t]=0,b[t]=0,lt--;
	b[t]=a[rt--],s[t]='R';
	work(t+1);
	if(flag==1) return ;
	s[t]=0,b[t]=0,rt++;
}
int main() {
	freopen("palin.in","r",stdin);
	freopen("palin.out","w",stdout);
	T=read();
	while(T--) {
		n=read();
		for(int i=1;i<=2*n;i++)
			a[i]=read();
		lt=1,rt=2*n,flag=0;
		memset(b,0,sizeof(b));
		work(1);
		if(!flag) {printf("-1\n");continue;}
		for(int i=1;i<=2*n;i++) cout<<s[i];
		printf("\n");
	}
}
//the second
//16:17~16:36
//21pts
/*
2 5 
4 1 2 4 5 3 1 2 3 5
3
3 2 1 2 1 3
*/
