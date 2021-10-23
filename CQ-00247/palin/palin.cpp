#include<iostream>
#include<stdio.h>
#include<cmath>
#include<algorithm>
#include<cstring>
#define FOR(i,a,b) for(int i=a;i<=b;i++)
const int N=5e5+5,INF=0x3f3f3f3f,mod=1e9+7;
int read()
{
	int r=0,f=1;
	char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch)) r=r*10+(ch^48),ch=getchar();
	return r*f;
}
using namespace std;
int n,a[N<<1],jl[N],lcn,rcn,flag;
char ch[N<<1];
void check(int i,int lcnt,int rcnt)
{
	if(flag) return ;
	if(i==0)
	{
		FOR(i,1,n*2) putchar(ch[i]);
		flag=1;
		return ;
	}
	if(a[lcnt]==jl[i]) ch[n*2-i+1]='L',check(i-1,lcnt+1,rcnt);
	if(a[rcnt]==jl[i]) ch[n*2-i+1]='R',check(i-1,rcnt-1,rcnt);
	return ;
}
void dfs(int now,int lcn,int rcn)
{
	if(flag) return ;
	if(now-1==n)
	{
		check(n,lcn,rcn);
		return ;
	}
	ch[now]='L';jl[now]=a[lcn];
	dfs(now+1,lcn+1,rcn);
	ch[now]='R';jl[now]=a[rcn];
	dfs(now+1,lcn,rcn-1);
}
int main()
{
	freopen("palin.in","r",stdin);
		freopen("palin.out","w",stdout);
	int T;
	T=read();
	while(T--)
	{
		n=read();
		flag=0;
		FOR(i,1,n*2) a[i]=read();
		dfs(1,1,n*2);
		if(!flag) puts("-1");
	}
	return 0;
}


