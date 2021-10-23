#include<bits/stdc++.h>
using namespace std;
const int MAX_N = 100000 + 5;
int k,n,m,d[MAX_N],Sum[MAX_N],lsh[MAX_N],cnt;
struct air{
	int l,r;
}a[MAX_N],b[MAX_N];
bool cmp(air x,air y){
	return x.l<y.l;//先来先到 
}
namespace BIT{
	const int MAX_C = 200000 + 5;
	#define lowbit(x) ((x)&(-(x)))
	int c[MAX_C];
	inline void clear(){memset(c,0,sizeof(c));}
	inline void add(int x,int d){
		for(;x<=cnt;x+=lowbit(x)) c[x]+=d;
	}
	inline int getsum(int x){
		int res=0;
		for(;x;x-=lowbit(x)) res+=c[x];
		return res;
	}
}
int solve(int x){
	int lv1=x,lv2=k-x,res=0;
	if(lv1){
		BIT::clear();
		for(int i=1;i<=n;i++){
			int used=BIT::getsum(a[i].l);
			if(used<lv1){
				res++;
				BIT::add(a[i].l,1);
				BIT::add(a[i].r+1,-1);
			}
		}
	}
	if(lv2){
		BIT::clear();
		for(int i=1;i<=m;i++){
			int used=BIT::getsum(b[i].l);
			if(used<lv2){
				res++;
				BIT::add(b[i].l,1);
				BIT::add(b[i].r+1,-1);
			}
		}
	}
	return res;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	scanf("%d%d%d",&k,&n,&m);
	for(int i=1;i<=n;i++) scanf("%d%d",&a[i].l,&a[i].r),lsh[++cnt]=a[i].l,lsh[++cnt]=a[i].r;
	for(int i=1;i<=m;i++) scanf("%d%d",&b[i].l,&b[i].r),lsh[++cnt]=b[i].l,lsh[++cnt]=b[i].r;
	sort(lsh+1,lsh+1+cnt);
	cnt=unique(lsh+1,lsh+1+cnt)-lsh-1;
	for(int i=1;i<=n;i++){
		a[i].l=lower_bound(lsh+1,lsh+1+cnt,a[i].l)-lsh;
		a[i].r=lower_bound(lsh+1,lsh+1+cnt,a[i].r)-lsh;
	}
	for(int i=1;i<=m;i++){
		b[i].l=lower_bound(lsh+1,lsh+1+cnt,b[i].l)-lsh;
		b[i].r=lower_bound(lsh+1,lsh+1+cnt,b[i].r)-lsh;
	}
	sort(a+1,a+1+n,cmp);
	sort(b+1,b+1+m,cmp);
//	for(int i=1;i<=n;i++){
//		printf("%d %d\n",a[i].l,a[i].r);
//	}
//	for(int i=1;i<=m;i++){
//		printf("%d %d\n",b[i].l,b[i].r);
//	}
	int ans=0,pos=0;
	int l=0,r=k;
	while(l<=r){
		int lmid=l+(r-l)/3;
		int rmid=r-(r-l)/3;
		int lval=solve(lmid);
		int rval=solve(rmid);
		if(lval<=rval){
//			ans=max(ans,rval);
			if(ans<rval) ans=rval,pos=rmid;
			l=lmid+1;
		}
		else if(lval>rval){
			if(ans<lval) ans=lval,pos=lmid;
//			ans=max(ans,lval);
			r=rmid-1;
		}
	}
	l=0,r=k;
	while(l<=r){
		int lmid=l+(r-l)/3;
		int rmid=r-(r-l)/3;
		int lval=solve(lmid);
		int rval=solve(rmid);
		if(lval<rval){
//			ans=max(ans,rval);
			if(ans<rval) ans=rval,pos=rmid;
			l=lmid+1;
		}
		else if(lval>=rval){
			if(ans<lval) ans=lval,pos=lmid;
//			ans=max(ans,lval);
			r=rmid-1;
		}
	}
//	cout<<pos<<endl;
	for(int i=pos;i>=max(0,pos-80);i--){
		int t=solve(i);
//		cout<<t<<endl;
		if(t>=ans) ans=t;
	}
	for(int i=pos;i<=min(pos+80,k);i++){
		int t=solve(i);
//		cout<<t<<endl;
		if(t>=ans) ans=t;
	}
	printf("%d\n",max(max(solve(0),solve(k)),ans));
	return 0;
}

