#include<iostream>
#include<iomanip>
#include<cmath>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int Mxdt=100000;
char gc(){
	static char buf[Mxdt],*p1=buf,*p2=buf;
	return p1==p2&&(p2=(p1=buf)+fread(buf,1,Mxdt,stdin),p1==p2)?EOF:*p1++;
}
int read(){
	int a=0;bool opt=0;char c=gc();
	while(c<'0'||c>'9')opt|=c=='-',c=gc();
	while(c>='0'&&c<='9')a=(a<<3)+(a<<1)+(c^48),c=gc();
	return opt?-a:a;
}
int n,m1,m2,Max,ans[200005],f[200005],g[200005];
int sum,a[200005];
void add(int x,int v){
	if(!x)sum+=v;
	for(;x<=n;x+=x&-x)a[x]+=v;
}
int ask(int x){
	int ans=0;
	for(;x;x-=x&-x)ans+=a[x];
	return ans+sum;
}
struct node{
	int l,r,id;
	bool operator<(const node&a)const{
		return l<a.l;
	}
}t[200005];
struct opp{
	int l,r,id;
	bool operator<(const opp&a)const{
		return r<a.r;
	}
}b[200005];
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read();m1=read();m2=read();
	for(int i=1;i<=m1;++i){
		t[i].l=b[i].l=read();
		t[i].r=b[i].r=read();
		t[i].id=b[i].id=i;
	}
	sort(t+1,t+m1+1);sort(b+1,b+m1+1);
	for(int i=1,j=1;i<=m1;++i){
		while(j<i&&b[j].r<=t[i].l){
			add(ans[b[j].id],-1);++j;
		}
		int l=0,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(ask(mid)<mid)r=mid-1;
			else l=mid+1;
		}
		add(r+1,1);ans[t[i].id]=r+1;++f[r+1];
	}
	for(int i=1;i<=n;++i)f[i]+=f[i-1];
	memset(a,0,sizeof(a));sum=0;
	for(int i=1;i<=m2;++i){
		t[i].l=b[i].l=read();
		t[i].r=b[i].r=read();
		t[i].id=b[i].id=i;
	}
	sort(t+1,t+m2+1);sort(b+1,b+m2+1);
	for(int i=1,j=1;i<=m2;++i){
		while(j<i&&b[j].r<=t[i].l){
			add(ans[b[j].id],-1);++j;
		}
		int l=0,r=n;
		while(l<=r){
			int mid=l+r>>1;
			if(ask(mid)<mid)r=mid-1;
			else l=mid+1;
		}
		add(r+1,1);ans[t[i].id]=r+1;++g[r+1];
	}
	for(int i=1;i<=n;++i)g[i]+=g[i-1];
	for(int i=0;i<=n;++i)Max=max(Max,f[i]+g[n-i]);
	cout<<Max<<"\n";
	return 0;
}
