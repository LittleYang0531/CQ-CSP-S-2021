#include<bits/stdc++.h>
#define IT set<node>::iterator
#define For(i,a,b) for(int i=a,i##end=b;i<=i##end;i++)
#define rep(i,  b) for(int i=1,i##end=b;i<=i##end;i++)
#define Rof(i,a,b) for(int i=a,i##end=b;i>=i##end;i--)
using namespace std;
const int N=2e5+9;
int read(){
	int f=0,x=0;
	char ch=getchar();
	while(!isdigit(ch)){f|=(ch=='-');ch=getchar();}
	while(isdigit(ch)){x=x*10+ch-'0';ch=getchar();}
	return f?-x:x;
}
int n,m1,m2;
struct node{
	int l,r;
	node(int ll=0,int rr=0):l(ll),r(rr){}
	bool operator<(const node&x)const{
		return (l!=x.l)?l<x.l:(r<x.r);
	}
}a[2][N];
set<node>s[2];
int top,ans;
int sum[2][N],sumb[N];
void solve(int op){
	IT it;int j=0,res=0,now;
	while(s[op].begin()!=s[op].end()){
		++j;res=1;it=s[op].begin();now=it->r;s[op].erase(it);
		while(1){
			it=s[op].lower_bound(node(now,0));
			if(it!=s[op].end()){
				now=it->r;res++;
				s[op].erase(it);
			}else break;
		}
		sum[op][j]+=res;
	}
}
int main(){
//	printf("%.5lf",(&pppp-&ppp)/1024.0/1024.0);
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	rep(i,m1)a[0][i].l=read(),a[0][i].r=read();
	rep(i,m2)a[1][i].l=read(),a[1][i].r=read();
	rep(i,m1)s[0].insert(a[0][i]);
	rep(i,m2)s[1].insert(a[1][i]);
	solve(0);solve(1);
	rep(i,n)sum[0][i]+=sum[0][i-1],sum[1][i]+=sum[1][i-1];
	For(i,0,n)ans=max(ans,sum[0][i]+sum[1][n-i]);
	cout<<ans<<endl;
	return 0;
}

