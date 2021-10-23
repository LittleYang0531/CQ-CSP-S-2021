#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
using namespace std;
const int N=400005;
struct node{int l,r;
	bool operator <(node A)const{
		return l<A.l;
	}
}a[N],b[N];
int st[N],suma[N],sumb[N],ans,c[N],sa[N],sb[N],n,m1,m2,tp;
void Adv(int x,int v){
	for(;x;x-=(x&(-x)))c[x]+=v;
}
int Ask(int x){int sum=0;
	for(;x<N;x+=(x&-x))sum+=c[x];
	return sum;
}
int Deal(int x){
	int res=0;
	memset(c,0,sizeof(c));
	for(int i=1;i<=m1;i++){
		int na=Ask(a[i].l);
		if(na<x){res++,Adv(a[i].r,1);}
	}
	memset(c,0,sizeof(c));
	for(int i=1;i<=m2;i++){
		int nb=Ask(b[i].l);
		if(nb<n-x){res++,Adv(b[i].r,1);}
	}
	return res;
}
int main(){
	freopen("airport.in","r",stdin);
	freopen("airport.out","w",stdout);
	int i;
	scanf("%d%d%d",&n,&m1,&m2);
	for(i=1;i<=m1;i++)scanf("%d%d",&a[i].l,&a[i].r),st[++tp]=a[i].l,st[++tp]=a[i].r;
	for(i=1;i<=m2;i++)scanf("%d%d",&b[i].l,&b[i].r),st[++tp]=b[i].l,st[++tp]=b[i].r;
	sort(st+1,st+1+tp);
	for(i=1;i<=m1;i++){
		a[i].l=lower_bound(st+1,st+1+tp,a[i].l)-st;
		a[i].r=lower_bound(st+1,st+1+tp,a[i].r)-st;
	}
	for(i=1;i<=m2;i++){
		b[i].l=lower_bound(st+1,st+1+tp,b[i].l)-st;
		b[i].r=lower_bound(st+1,st+1+tp,b[i].r)-st;
	}
	sort(a+1,a+1+m1);sort(b+1,b+1+m2);
	/*
	for(i=1;i<=m1;i++){
		sa[i]=Ask(a[i].l);
	//	cout<<a[i].l<<','<<a[i].r<<':'<<sa[i]<<'\n';
		Adv(a[i].r,1);suma[sa[i]+1]++;
	}
	memset(c,0,sizeof(c));
	for(i=1;i<=m2;i++){
		sb[i]=Ask(b[i].l);
	//	cout<<b[i].l<<','<<b[i].r<<':'<<sb[i]<<'\n';
		Adv(b[i].r,1);sumb[sb[i]+1]++;
	}
	for(i=1;i<=m1;i++)suma[i]+=suma[i-1];
	for(i=1;i<=m2;i++)sumb[i]+=sumb[i-1];
	for(i=0;i<=n;i++){
		ans=max(ans,suma[i]+sumb[n-i]);
	}*/
	for(i=0;i<=n;i++){
		ans=max(ans,Deal(i));
	}
	printf("%d\n",ans);
}
