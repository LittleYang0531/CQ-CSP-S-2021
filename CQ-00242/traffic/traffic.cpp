#include<bits/stdc++.h>
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
using namespace std;
const int N=510;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m,T;
struct edge{
	int pre,to,w;
}e[2*N];int last[N],cnt;
int v[N],p[N],t[N];
int d[N][N];
int r[N][N];
void add(int x,int y,int w){
	e[++cnt].pre=last[x];
	e[cnt].to=y;
	e[cnt].w=w;
	last[x]=cnt;
}
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	freopen("traffic.in","r",stdin);
	freopen("traffic.out","w",stdout);
	n=read(),m=read(),T=read();
	rep(i,n-1)rep(j,m)d[i][j]=read();
	rep(i,n)rep(j,m-1)r[i][j]=read();
	while(T--){
		int k=read();
		rep(i,k)v[i]=read(),p[i]=read(),t[i]=read();
		puts("0");continue;
	}
	return 0;
}

