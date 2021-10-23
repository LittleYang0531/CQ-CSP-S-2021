#include<bits/stdc++.h>
#define For(i,a,b) for(int i=(a),i##END=(b);i<=i##END;i++)
#define Rof(i,b,a) for(int i=(b),i##END=(a);i>=i##END;i--)
#define go(u) for(int i=head[u];i;i=nxt[i])
using namespace std;
inline int read(){
	int x=0,f=1;char ch=getchar();
	while(!isdigit(ch)){if(ch=='-')f=-1;ch=getchar();}
	while(isdigit(ch))x=(x<<3)+(x<<1)+(ch^48),ch=getchar();
	return x*f;
}
const int N=4e5+10;
int n,m1,m2;
struct node{
	int l,r,op;
	node(){}
	node(int L,int R,int OP){l=L,r=R,op=OP;}
	bool operator < (const node &x) const {
		return l<x.l;
	}
}a[N];
int s[N],tp;
#define find(x) (lower_bound(s+1,s+1+tp,x)-s)
int T,ok[N],in[N];
struct Tree{
	int t[N<<2];
	#define ls (k<<1)
	#define rs (k<<1|1)
	void mdf(int k,int l,int r,int x,int v){
		t[k]+=v;
		if(l==r)return;
		int m=l+r>>1;
		x<=m?mdf(ls,l,m,x,v):mdf(rs,m+1,r,x,v);
	}
	int get(int k,int l,int r,int ad=0){
		if(l==r)return l;
		int m=l+r>>1;
		return t[ls]+ad<m?get(ls,l,m,ad):get(rs,m+1,r,ad+t[ls]);
	}
}T0,T1;
int del[N][2];
signed main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	n=read(),m1=read(),m2=read();
	T=2*(m1+m2);
	For(i,1,m1){
		int l=read(),r=read();
		a[i]=node(l,r,0);
		s[++tp]=l,s[++tp]=r;
	}
	For(i,1,m2){
		int l=read(),r=read();
		a[i+m1]=node(l,r,1);
		s[++tp]=l,s[++tp]=r;
	}
	sort(s+1,s+1+tp);
	For(i,1,m1+m2)a[i].l=find(a[i].l),a[i].r=find(a[i].r);
	sort(a+1,a+1+m1+m2);
	For(i,1,m1+m2)in[a[i].l]=i;
	For(t,1,T){
		if(in[t]){
			int i=in[t],op=a[i].op;
			if(op==0){
				int v=T0.get(1,0,n+1);
				if(v<=n){
					T0.mdf(1,0,n+1,v,1);
					del[a[i].r][0]=v;
					ok[v]++;
				}
			}else{
				int v=T1.get(1,0,n+1);
				if(v<=n){
					T1.mdf(1,0,n+1,v,1);
					del[a[i].r][1]=v;
					ok[0]++,ok[n-v+1]--;
				}
			}
		}
		if(del[t][0])T0.mdf(1,0,n+1,del[t][0],-1);
		if(del[t][1])T1.mdf(1,0,n+1,del[t][1],-1);
	}
	int now=0,ans=0;
	For(k,0,n){
		now+=ok[k];
		ans=max(ans,now);
	}cout<<ans<<endl;
	return 0;
}
